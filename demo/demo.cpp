#include <iostream>
#include "..\hash-table\hash-table.h"
#include "..\console-menu\console-menu.h"
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
	vector<string> menuItems{"Insert/Change", "Remove", "Get size", "Get value", "Show all"};
	vector<void (*)(HashTable::StringHashTable&)> funcs{ &insert, &remove, &getSize, &getValue, &showAll };

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

	bool isRecordExists = table.exists(phoneNumber);
	table.insert({ phoneNumber, address });
	isRecordExists ?
		cout << "Record changed successfully!" << endl :
		cout << "Record inserted successfully!" << endl;
}

void remove(HashTable::StringHashTable& table)
{
	string phoneNumber;
	cout << "Enter phone number to remove: ";
	cin >> phoneNumber;
	table.remove(phoneNumber) ?
		cout << "Record removed successfully!" << endl :
		cout << "No such phone number in hashtable!" << endl;
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
		cout << "No such phone number in hashtable!" << endl;
}

void showAll(HashTable::StringHashTable& table)
{
	cout << "Table records:" << endl;
	for (auto record : table)
		cout << record.phoneNumber << " - " << record.address << endl;
}

