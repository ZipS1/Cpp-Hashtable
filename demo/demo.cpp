#include <iostream>
#include "hash-table.h"
#include "console-menu.h"
using namespace std;

#pragma region FuncDeclarations
void insert(HashTable::StringHashTable&);
void bar2(HashTable::StringHashTable&);
void bar3(HashTable::StringHashTable&);
void bar4(HashTable::StringHashTable&);
void bar5(HashTable::StringHashTable&);
#pragma endregion

int main()
{
	vector<string> menuItems{ "Insert", "Remove", "Get Size", "Get Value", "Show all" };
	vector<void (*)(HashTable::StringHashTable&)> funcs{ &insert, &bar2, &bar3, &bar4, &bar5 };

	ConsoleMenu::ConsoleMenu<HashTable::StringHashTable&> menu(menuItems, funcs);
	HashTable::StringHashTable table;
	menu.run(table);
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

void bar2(HashTable::StringHashTable& table)
{
	cout << "bar2" << endl;
}

void bar3(HashTable::StringHashTable& table)
{
	cout << "bar3" << endl;
}

void bar4(HashTable::StringHashTable& table)
{
	cout << "bar4" << endl;
}

void bar5(HashTable::StringHashTable& table)
{
	cout << "bar5" << endl;
}

