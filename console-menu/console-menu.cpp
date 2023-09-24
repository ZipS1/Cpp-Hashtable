#include "pch.h"
using namespace std;

ConsoleMenu::ConsoleMenu::ConsoleMenu(std::vector<std::string> const& menuItems, vector<void (*)()> funcs) :
	menuItems(menuItems), funcs(funcs)
{
	const_cast<vector<std::string>&>(this->menuItems).push_back("Exit");
}

void ConsoleMenu::ConsoleMenu::run()
{
	while (true)
	{
		for (size_t i = 0; i < menuItems.size(); i++)
			cout << i + 1 << " - " << menuItems[i] << endl;
		size_t choice = getChoice();
		if (choice == menuItems.size())
			return;

		funcs[choice - 1]();
		cout << endl;
	}	
}

size_t ConsoleMenu::ConsoleMenu::getChoice()
{
	size_t choice;
	bool isValid = false;

	while (isValid == false)
	{
		cout << ": ";
		cin >> choice;
		isValid = checkValidInput(choice);
	}

	cout << endl;
	return choice;
}

bool ConsoleMenu::ConsoleMenu::checkValidInput(size_t userChoice)
{
	bool isValid = userChoice > 0 && userChoice <= menuItems.size();
	if (isValid == false)
		cout << "Invalid input!" << endl;
	return isValid;
}
