#pragma once

#include "Item.h"
#include "ItemInstance.h"

class PortalGunItem: public Item {
public:
	static int _id;
	
	static PortalGunItem* itemPortalGun;
	PortalGunItem(int);
	
	bool requiresInteract();
	std::string getInteractText(void);
	void use(ItemInstance &, Player &);
	void interactEnemy(ItemInstance *,Mob *,Player *);
};
