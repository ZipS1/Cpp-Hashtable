#include "pch.h"
using namespace std;

template<typename ...Args>
ConsoleMenu::ConsoleMenu<Args...>::ConsoleMenu(std::vector<std::string> const& menuItems, std::vector<void(*)(Args...)> funcs)
	: menuItems(menuItems), functions(funcs)
{
	const_cast<vector<std::string>&>(this->menuItems).push_back("Exit");
}

template <typename... Args>
void ConsoleMenu::ConsoleMenu<Args...>::run()
{
	while (true)
	{
		for (size_t i = 0; i < menuItems.size(); i++)
			cout << i + 1 << " - " << menuItems[i] << endl;
		size_t choice = getChoice();
		if (choice == menuItems.size())
			return;

		functions[choice - 1]();
		cout << endl;
	}	
}

template <typename... Args>
bool ConsoleMenu::ConsoleMenu<Args...>::checkValidInput(size_t userChoice)
{
	bool isValid = userChoice > 0 && userChoice <= menuItems.size();
	if (isValid == false)
		cout << "Invalid input!" << endl;
	return isValid;
}

template<typename ...Args>
size_t ConsoleMenu::ConsoleMenu<Args...>::getChoice()
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
