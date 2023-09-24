#pragma once
#include <iostream>
#include <string>
#include <vector>

namespace ConsoleMenu
{
	class ConsoleMenu
	{
	public:
		ConsoleMenu(std::vector<std::string> const& menuItems);
		void run();
		

	private:
		const std::vector<std::string> menuItems;

		bool checkValidInput(size_t userChoice);
		size_t getChoice();
	};
}