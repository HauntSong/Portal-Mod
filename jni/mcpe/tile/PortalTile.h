#pragma once

#include "Tile.h"
#include <mcpe/level/TileSource.h>
#include <mcpe/item/TileItem.h>
#include <mcpe/level/TileSource.h>
#include <string>

class PortalTile: public Tile {
public:
	static int _id;
	static PortalTile* tilePortal;
	
public:
	PortalTile(int id);
	const TextureUVCoordinateSet& getTexture(signed char, int);
	
public:
	TextureUVCoordinateSet secondary_tex;
};
