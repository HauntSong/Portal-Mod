#include "PortalGunItem.h"

int PortalGunItem::_id = 460;
PortalGunItem* PortalGunItem::itemPortalGun = NULL;

PortalGunItem::PortalGunItem(int id): Item(id - 256) {
	setNameID("portalGun");
	setIcon("apple", 0);
	setMaxStackSize(1);
	handEquipped();
	setCategory(3);
}

bool PortalGunItem::requiresInteract() {
	return true;
}

std::string PortalGunItem::getInteractText(void) {
	return "Shoot";
}

void PortalGunItem::use(ItemInstance & i, Player & p) {
	i.count++;
}
