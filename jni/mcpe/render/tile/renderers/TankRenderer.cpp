#include "TankRenderer.h"

void TankRenderer::render(const TilePos& pos, Tile* tile, TileTessellator* tess) {
	int x = pos.x, y = pos.y, z = pos.z;
	
	//Tank
	tess->setRenderBounds(0.125, 0, 0.125, 0.875, 1, 0.875);
	tess->tessellateBlockInWorld(tile, {x, y, z});
	
	//Water
	tess->useForcedUV = true;
	tess->forcedUV = tile->getTexture(6, 0);
	tess->setRenderBounds(0.1875, 0, 0.1875, 0.625, 0.5, 0.625);
	tess->tessellateBlockInWorld(tile, {x, y, z});
	tess->useForcedUV = false;
}
