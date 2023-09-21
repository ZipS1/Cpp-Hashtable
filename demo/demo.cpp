#include <iostream>
#include "hash-table.h"

int main()
{
	HashTable::StringHashTable table;
	HashTable::Record record1{ "1", "adr1" };
	HashTable::Record record2{ "2", "adr2" };
	HashTable::Record record3{ "3", "adr3" };
	HashTable::Record record4{ "3", "adr3" };
	HashTable::Record record5{ "3", "adr3" };
	HashTable::Record record6{ "3", "adr3" };
	table.insert(record1);
	table.insert(record2);
	table.insert(record3);
	table.insert(record4);
	table.insert(record5);
	table.insert(record6);
	size_t forwardAmount = 3;

	auto it = table.begin();
	for (size_t i = 0; i < forwardAmount; i++)
		it++;

	std::cout << it->phoneNumber << " || " << it->address << std::endl;
}