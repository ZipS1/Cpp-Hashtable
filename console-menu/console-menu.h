#pragma once
#include <iostream>
#include <string>
#include <vector>

namespace ConsoleMenu
{	
	template <typename... Args> 
	class ConsoleMenu
	{
	public:
		ConsoleMenu(std::vector<std::string> const& menuItems, std::vector<void (*)(Args...)> funcs);
		void run();
		

	private:
		const std::vector<std::string> menuItems;
		const std::vector<void (*)(Args... args)> functions;

		bool checkValidInput(size_t userChoice);
		size_t getChoice();
	};
}