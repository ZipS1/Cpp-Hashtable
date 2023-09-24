#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <exception>


namespace ConsoleMenu
{	
	class DifferentVectorSizesException : public std::exception
	{
	public:
		const char* what() const override
		{
			return "Vector of menu items and functions for them should be equal";
		}
	};

	template <typename... Args> 
	class ConsoleMenu
	{
	public:
		ConsoleMenu(std::vector<std::string> const& menuItems, std::vector<void (*)(Args...)> const funcs)
			: menuItems(menuItems), functions(funcs)
		{
			if (menuItems.size() != funcs.size())
				throw DifferentVectorSizesException();
			const_cast<std::vector<std::string>&>(this->menuItems).push_back("Exit");
		}

		void run(Args... args)
		{
			while (true)
			{
				std::cout << "// --- MENU --- //" << std::endl;
				for (size_t i = 0; i < menuItems.size(); i++)
					std::cout << i + 1 << " - " << menuItems[i] << std::endl;
				size_t choice = getChoice();
				if (choice == menuItems.size())
					return;

				functions[choice - 1](args...);
				std::cout << std::endl;
			}
		}
		
	private:
		const std::vector<std::string> menuItems;
		const std::vector<void (*)(Args...)> functions;

		bool checkValidInput(size_t userChoice)
		{
			bool isValid = userChoice > 0 && userChoice <= menuItems.size();
			if (isValid == false)
				std::cout << "Invalid input!" << std::endl;
			return isValid;
		}

		size_t getChoice()
		{
			size_t choice;
			bool isValid = false;

			while (isValid == false)
			{
				std::cout << ": ";
				std::cin >> choice;
				isValid = checkValidInput(choice);
			}

			std::cout << std::endl;
			return choice;
		}
	};
}