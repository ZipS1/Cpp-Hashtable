#include <iostream>
#include "hash-table.h"
#include "console-menu.h"
using namespace std;

#pragma region FuncDeclarations
void insert(HashTable::StringHashTable&);
void remove(HashTable::StringHashTable&);
void getSize(HashTable::StringHashTable&);
void getValue(HashTable::StringHashTable&);
void showAll(HashTable::StringHashTable&);
#pragma endregion

int main()
{
	// Arrange
	HashTable::StringHashTable table;
	HashTable::Record record1{ "1", "adr1" };
	HashTable::Record record2{ "2", "adr2" };
	HashTable::Record record3{ "3", "adr3" };
	HashTable::Record record4{ "4", "adr4" };
	HashTable::Record record5{ "5", "adr5" };
	table.insert(record1);
	table.insert(record2);
	table.insert(record3);
	table.insert(record4);
	table.insert(record5);

	// Act
	for (auto it = table.begin(); it != table.end(); it++)
		cout << it->phoneNumber << " || " << it->address << endl;

	/*vector<string> menuItems{"Insert", "Remove", "Get size", "Get value", "Show all"};
	vector<void (*)(HashTable::StringHashTable&)> funcs{ &insert, &remove, &getSize, &getValue, &showAll };

	ConsoleMenu::ConsoleMenu<HashTable::StringHashTable&> menu(menuItems, funcs);
	HashTable::StringHashTable table;
	menu.run(table);*/
}

void insert(HashTable::StringHashTable& table)
{
	string phoneNumber;
	string address;
	cout << "Enter record: " << endl;;
	cout << "Phone number - ";
	cin >> phoneNumber;
	cout << "Address - ";
	cin >> address;
	table.insert({ phoneNumber, address });
}

void remove(HashTable::StringHashTable& table)
{
	string phoneNumber;
	cout << "Enter phone number to remove: ";
	cin >> phoneNumber;
	table.remove(phoneNumber) ?
		cout << "Record removed successfully!" << endl :
		cout << "No such key in hashtable!" << endl;
}

void getSize(HashTable::StringHashTable& table)
{
	cout << "Size: " << table.getSize() << endl;
}

void getValue(HashTable::StringHashTable& table)
{
	string phoneNumber;
	cout << "Enter phone number: ";
	cin >> phoneNumber;
	if (table.exists(phoneNumber))
	{
		auto record = table.getValue(phoneNumber);
		cout << "Phone number - " << record.phoneNumber << endl;
		cout << "Address - " << record.address << endl;
	}
	else
		cout << "No such key in hashtable!" << endl;
}

void showAll(HashTable::StringHashTable& table)
{
	for (auto record : table)
		cout << record.phoneNumber << " - " << record.address << endl;
}

