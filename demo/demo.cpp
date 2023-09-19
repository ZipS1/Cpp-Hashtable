#include <iostream>
#include "hash-table.h"

int main()
{
    std::cout << "Hello World!\n";
    HashTable::StringHashTable table;
    table.insert("1", "adr1");
    table.insert("2", "adr2");
    table.insert("3", "adr3");
    table.insert("4", "adr4");
    table.insert("5", "adr5");

    auto exists1 = table.exists("1");
    auto exists3 = table.exists("3");
    auto exists5 = table.exists("5");
    auto exists6 = table.exists("6");

    auto s1 = table.getValue("1");
    auto s2 = table.getValue("3");
    auto s5 = table.getValue("5");

    table.remove("1");
    auto exists = table.exists("1");

    table.insert("1", "adrnew");
    auto existsnew = table.exists("1");
    auto snew = table.getValue("1");

}