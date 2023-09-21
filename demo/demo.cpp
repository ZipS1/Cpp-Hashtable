#include <iostream>
#include "hash-table.h"

int main()
{
	HashTable::StringHashTable table;
	table.insert({"1", "adr1"});
	table.insert({"2", "adr2"});
	table.insert({"3", "adr3"});
	for (auto it = table.begin(); it != table.end(); it++)
		std::cout << (*it).phoneNumber << " || " << (*it).address << std::endl;

}