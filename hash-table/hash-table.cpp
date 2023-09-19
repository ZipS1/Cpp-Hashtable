#include "pch.h"
#include "framework.h"
#include "hash-table.h"
using namespace std;


HashTable::StringHashTable::StringHashTable()
{
	table = new HashNode*[capacity];
}

bool HashTable::StringHashTable::insert(std::string const& phoneNumber, std::string const& address)
{
	IndexSearchResult searchResult = findEmptyIndex(phoneNumber);
	if (searchResult.isFound)
	{
		HashNode* hashNode = new HashNode{ phoneNumber, address, NodeStatus::Filled };
		table[searchResult.index] = hashNode;
	}
	else
		throw EmptyIndexNotFoundException();

	size++;
	checkRebuild();
	return true;
}

bool HashTable::StringHashTable::remove(std::string const& key)
{
	IndexSearchResult searchResult = findIndex(key);
	if (searchResult.isFound)
		table[searchResult.index]->status = NodeStatus::Deleted;
	else
		throw KeyNotExistsException();

	size--;
	return true;

}

bool HashTable::StringHashTable::exists(std::string const& key)
{
	IndexSearchResult searchResult = findIndex(key);
	return searchResult.isFound;
}

HashTable::HashNode HashTable::StringHashTable::getValue(std::string const& key)
{
	IndexSearchResult searchResult = findIndex(key);
	return searchResult.isFound ?
		*table[searchResult.index] :
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

HashTable::IndexSearchResult HashTable::StringHashTable::findIndex(std::string const& key)
{
	for (int i = 0; i < capacity; i++)
	{
		size_t hash = getHash(key, i);
		if (isIndexExists(hash))
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
	return table[index] == nullptr;
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
	table = new HashNode*[capacity];

	for (size_t i = 0; i < oldCapacity; i++)
	{
		if (oldTable[i] != nullptr)
		{
			insert(oldTable[i]->phoneNumber, oldTable[i]->address);
			delete oldTable[i];
		}
	}
	delete[] oldTable;
}
