#pragma once

#include <mcpe/app/AppPlatformListener.h>
#include <mcpe/render/Color.h>

class Textures;
class Font : public AppPlatformListener {
public:
	Font();
	virtual ~Font();
	virtual void onAppSuspended();
	int width(const std::string &);
	int height(const std::string &, int);
	float getPixelLength(const std::string &) const;
	void drawTransformed(std::string const&, float, float, Color const&, float, float, bool, float);
	int getLineLength(std::string const&) const;
};
