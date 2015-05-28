#include "Tile.h"
#include "Material.h"
#include "PortalTile.h"

PortalTile* PortalTile::tilePortal = NULL;
int PortalTile::_id = 176;

PortalTile::PortalTile(int id): Tile(id, &Material::portal) {
	Tile::solid[id] = false;
	Tile::lightBlock[id] = 0;
	
	init();
	tex = getTextureUVCoordinateSet("dirt", 0);
	secondary_tex = getTextureUVCoordinateSet("stone", 0);
	
	setNameId("portal");
	setCategory(2);
	
	new TileItem(id - 256);
}

const TextureUVCoordinateSet& PortalTile::getTexture(signed char side, int data) {
	return data == 0 ? tex : secondary_tex;
}
