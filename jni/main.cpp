#include <jni.h>
#include <dlfcn.h>
#include <android/log.h>
#include <stdlib.h>
#include <Substrate.h>

#include <mcpe/tile/Tile.h>
#include <mcpe/item/Item.h>

#include <mcpe/tile/PortalTile.h>

#include <mcpe/item/PortalGunItem.h>

#include <mcpe/app/AppPlatform.h>
#include <mcpe/gui/Font.h>
#include <mcpe/gui/Button.h>
#include <mcpe/gui/Gui.h>
#include <mcpe/client/MinecraftClient.h>

#define LOG_TAG "portalgun"

#define LOGI(...) ((void)__android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__))

static Font* font;
static Gui* gui;
static MinecraftClient* mcClient;
static Button* btn;

static void (*Item_initItems_real)();
static void Item_initItems_hook() {
	Item_initItems_real();
	PortalGunItem::itemPortalGun = new PortalGunItem(PortalGunItem::_id);
}

static void (*MCClient_init_real)(MinecraftClient*);
static void MCClient_init_hook(MinecraftClient* c) {
	MCClient_init_real(c);
	mcClient = c;
}

static void (*Gui_render_real)(Gui*);
static void Gui_render_hook(Gui* g) {
	Gui_render_real(g);
	
	if(!btn) {
		float pixels = AppPlatform::getPixelsPerMillimeter();
		int width = AppPlatform::getScreenWidth() / pixels * 3 + 25;
		int height = AppPlatform::getScreenHeight() / pixels * 3 + 25;
		
		std::string s = "Shoot";
		
		btn = new Button(0, width / 2, (height / 4) * 3, 36, 18, s, true);
	}
	
	btn->render(mcClient, 100, 0);
}

static void (*Font_Font_real)(Font*, Options*, std::string const&, Textures*);
static void Font_Font_hook(Font* f, Options* super, std::string const& mario, Textures* bros) {
	Font_Font_real(f, super, mario, bros);
	font = f;
}

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved) {
	void *handle = dlopen("libminecraftpe.so", RTLD_LAZY);
	
	MSHookFunction((void*) &Item::initItems, (void*) &Item_initItems_hook, (void**) &Item_initItems_real);
	MSHookFunction((void*) &MinecraftClient::init, (void*) &MCClient_init_hook, (void**) &MCClient_init_real);
	MSHookFunction((void*) &Gui::render, (void*) &Gui_render_hook, (void**) &Gui_render_real);
	
	MSHookFunction(dlsym(handle, "_ZN4FontC1EP7OptionsRKSsP8Textures"), (void*) &Font_Font_hook, (void**) &Font_Font_real);
	
	return JNI_VERSION_1_2;
}
