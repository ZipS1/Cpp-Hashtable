#include <iostream>
#include "hash-table.h"

int main()
{
	HashTable::StringHashTable table;
	HashTable::Record record1{ "1", "adr1" };
	HashTable::Record record2{ "2", "adr2" };
	HashTable::Record record3{ "3", "adr3" };
	HashTable::Record record4{ "4", "adr4" };
	HashTable::Record record5{ "5", "adr5" };
	HashTable::Record record6{ "6", "adr6" };

	table.insert(record1);
	table.insert(record2);
	table.insert(record3);
	table.insert(record4);
	table.insert(record5);
	table.insert(record6);


	auto rec = table.getValue("6");

	auto it = table.begin();
	for (auto record : table)
		std::cout << record.phoneNumber << " || " << record.address << std::endl;
}