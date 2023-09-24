#include <iostream>
#include "hash-table.h"
#include "console-menu.h"

int main()
{
	std::vector<std::string> menuItems{ "Insert", "Remove", "Get Value", "Show all" };
	ConsoleMenu::ConsoleMenu menu(menuItems);

	menu.run();

}