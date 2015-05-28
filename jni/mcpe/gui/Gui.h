#pragma once

class Gui {
public:
	void init();
	void render(float, bool, int, int);
	void displayClientMessage(std::string const&);
	void displayChatMessage(std::string const&, std::string const&);
	void displayLocalizableMessage(std::string const&, std::vector<std::string, std::allocator<std::string>> const&);
};
