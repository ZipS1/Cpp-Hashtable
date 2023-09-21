#include "pch.h"
using namespace std;


HashTable::StringHashTable::StringHashTable()
{
	table = new HashNode * [capacity] {};
}

bool HashTable::StringHashTable::insert(Record const& record)
{
	exists(record.phoneNumber) ? 
		insertExistingKey(record):
		insertNewKey(record);

	return true;
}

bool HashTable::StringHashTable::remove(std::string const& key)
{
	IndexSearchResult searchResult = findIndex(key);
	if (searchResult.isFound && table[searchResult.index]->status == NodeStatus::Filled)
		table[searchResult.index]->status = NodeStatus::Deleted;
	else
		return false;

	size--;
	return true;
}

bool HashTable::StringHashTable::exists(std::string const& key)
{
	IndexSearchResult searchResult = findIndex(key);
	return searchResult.isFound;
}

HashTable::Record HashTable::StringHashTable::getValue(std::string const& key)
{
	IndexSearchResult searchResult = findIndex(key);
	return searchResult.isFound ?
		table[searchResult.index]->record :
		throw KeyNotExistsException();
}

HashTable::StringHashTable::~StringHashTable()
{
	for (size_t i = 0; i < capacity; i++) {
		if (table[i] != nullptr) {
			delete table[i];
		}
	}
	delete[] table;
}

void HashTable::StringHashTable::insertExistingKey(Record const& record)
{
	auto searchResult = findIndex(record.phoneNumber);
	if (record.address != table[searchResult.index]->record.address)
		table[searchResult.index]->record.address = record.address;
}

void HashTable::StringHashTable::insertNewKey(Record const& record)
{
	IndexSearchResult searchResult = findEmptyIndex(record.phoneNumber);
	if (searchResult.isFound)
	{
		HashNode* hashNode = new HashNode{ record, NodeStatus::Filled };
		if (table[searchResult.index] != nullptr)
			delete table[searchResult.index];
		table[searchResult.index] = hashNode;
		size++;
		checkRebuild();
	}
	else
		throw EmptyIndexNotFoundException();
}

HashTable::IndexSearchResult HashTable::StringHashTable::findIndex(std::string const& key)
{
	for (int i = 0; i < capacity; i++)
	{
		size_t hash = getHash(key, i);
		if (isIndexExists(hash) && table[hash]->record.phoneNumber == key)
			return { true, hash };
	}
	return { false, 0 };
}

HashTable::IndexSearchResult HashTable::StringHashTable::findEmptyIndex(std::string const& key)
{
	for (int i = 0; i < capacity; i++)
	{
		size_t hash = getHash(key, i);
		if (isIndexEmpty(hash))
			return { true, hash };
	}
	return { false, 0 };
}

bool HashTable::StringHashTable::isIndexExists(size_t const index)
{
	if (table[index] == nullptr)
		return false;

	if (table[index]->status == NodeStatus::Deleted)
		return false;

	return true;
}

bool HashTable::StringHashTable::isIndexEmpty(size_t const index)
{
	return table[index] == nullptr || table[index]->status == NodeStatus::Deleted;
}

size_t HashTable::StringHashTable::getHash(std::string const& key, size_t const& i)
{
	return (getAsciiSum(key) + c * i + d * i * i) % capacity;
}

size_t HashTable::StringHashTable::getAsciiSum(std::string str)
{
	size_t sum = 0;
	for (char chr : str)
		sum += size_t(chr);
	return sum;
}

bool HashTable::StringHashTable::checkRebuild()
{
	if ((float)size / capacity < rebuidlLoadFactor)
		return false;

	rehash();
	return true;
}

void HashTable::StringHashTable::rehash()
{
	size_t oldCapacity = capacity;
	HashNode** oldTable = table;
	capacity *= 2;
	size = 0;
	table = new HashNode * [capacity] {};

	for (size_t i = 0; i < oldCapacity; i++)
	{
		if (oldTable[i] != nullptr)
		{
			insert(oldTable[i]->record);
			delete oldTable[i];
		}
	}
	delete[] oldTable;
}