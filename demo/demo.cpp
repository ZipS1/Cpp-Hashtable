#include <iostream>
#include "hash-table.h"

int main()
{
	HashTable::StringHashTable table;
	std::cout << table.getSize() << std::endl;
	std::cout << std::boolalpha << (table.begin() == table.end()) << std::endl;
	std::cout << table.getSize() << std::endl;

}