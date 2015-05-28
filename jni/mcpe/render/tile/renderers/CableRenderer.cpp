#include "CableRenderer.h"

void CableRenderer::render(const TilePos& pos, Tile* tile, TileTessellator* tess) {
	int x = pos.x, y = pos.y, z = pos.z;
	TileSource* ts = tess->region;
	
	bool front = ts->getTile(x + 1, y, z) == tile->id;
	bool back = ts->getTile(x - 1, y, z) == tile->id;
	bool left = ts->getTile(x, y, z + 1) == tile->id;
	bool right = ts->getTile(x, y, z - 1) == tile->id;
	bool bottom = ts->getTile(x, y - 1, z) == tile->id;
	bool top = ts->getTile(x, y + 1, z) == tile->id;
	
	tess->useForcedUV = true;
	tess->forcedUV = tile->getTexture(0, 0);
	
	tess->setRenderBounds(0.4, 0.4, 0.4, 0.6, 0.6, 0.6);
	tess->tessellateBlockInWorld(tile, {x, y, z});
	
	if(front) {
		tess->setRenderBounds(0.6, 0.4, 0.4, 1, 0.6, 0.6);
		tess->tessellateBlockInWorld(tile, {x, y, z});
	}
	
	if(back) {
		tess->setRenderBounds(0, 0.4, 0.4, 0.4, 0.6, 0.6);
		tess->tessellateBlockInWorld(tile, {x, y, z});
	}
	
	if(left) {
		tess->setRenderBounds(0.4, 0.4, 0.6, 0.6, 0.6, 1);
		tess->tessellateBlockInWorld(tile, {x, y, z});
	}
	
	if(right) {
		tess->setRenderBounds(0.4, 0.4, 0, 0.6, 0.6, 0.4);
		tess->tessellateBlockInWorld(tile, {x, y, z});
	}
	
	if(bottom) {
		tess->setRenderBounds(0.4, 0, 0.4, 0.6, 0.4, 0.6);
		tess->tessellateBlockInWorld(tile, {x, y, z});
	}
	
	if(top) {
		tess->setRenderBounds(0.4, 0.6, 0.4, 0.6, 1, 0.6);
		tess->tessellateBlockInWorld(tile, {x, y, z});
	}
	tess->useForcedUV = false;
}
