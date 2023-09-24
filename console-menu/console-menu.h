#pragma once
#include <iostream>
#include <string>
#include <vector>

namespace ConsoleMenu
{
	class ConsoleMenu
	{
	public:
		ConsoleMenu(std::vector<std::string> const& menuItems, std::vector<void (*)()> funcs);
		void run();
		

	private:
		const std::vector<std::string> menuItems;
		const std::vector<void (*)()> funcs;

		bool checkValidInput(size_t userChoice);
		size_t getChoice();

	};
}