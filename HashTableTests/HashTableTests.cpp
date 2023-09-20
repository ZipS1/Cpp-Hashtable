#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace HashTableTests
{
	TEST_CLASS(InsertionTests)
	{
	public:
		
		TEST_METHOD(LightInsertionTest)
		{
			// Arrange
			HashTable::StringHashTable table;
			HashTable::Record expected1 = { "1", "adr1" };
			HashTable::Record expected2 = { "10", "adr10" };
			HashTable::Record expected3 = { "20", "adr20" };

			// Act
			table.insert(expected1);
			table.insert(expected2);
			table.insert(expected3);

			// Assert
			Assert::AreEqual(expected1, table[expected1.phoneNumber]);
			Assert::AreEqual(expected2, table[expected2.phoneNumber]);
			Assert::AreEqual(expected3, table[expected3.phoneNumber]);
		}

		TEST_METHOD(MediumInsertionTest)
		{
			// Arrange
			HashTable::StringHashTable table;
			HashTable::Record expected1 = { "1", "adr1" };
			HashTable::Record expected2 = { "10", "adr10" };
			HashTable::Record expected3 = { "20", "adr20" };
			HashTable::Record expected4 = { "20", "adr20" };
			HashTable::Record expected5 = { "20", "adr20" };
			HashTable::Record expected6 = { "20", "adr20" };
			HashTable::Record expected7 = { "20", "adr20" };
			HashTable::Record expected8 = { "20", "adr20" };
			HashTable::Record expected9 = { "20", "adr20" };
			HashTable::Record expected10 = { "20", "adr20" };
			HashTable::Record expected11 = { "20", "adr20" };
			HashTable::Record expected12 = { "20", "adr20" };
			HashTable::Record expected13 = { "20", "adr20" };
			HashTable::Record expected14 = { "20", "adr20" };
			HashTable::Record expected15 = { "20", "adr20" };
			HashTable::Record expected16 = { "20", "adr20" };
			HashTable::Record expected17 = { "20", "adr20" };
			HashTable::Record expected18 = { "20", "adr20" };
			HashTable::Record expected19 = { "20", "adr20" };
			HashTable::Record expected20 = { "20", "adr20" };
			HashTable::Record expected21 = { "20", "adr20" };
			HashTable::Record expected22 = { "20", "adr20" };
			HashTable::Record expected23 = { "20", "adr20" };
			HashTable::Record expected24 = { "20", "adr20" };
			HashTable::Record expected25 = { "20", "adr20" };

			// Act
			table.insert(expected1);
			table.insert(expected2);
			table.insert(expected3);
			table.insert(expected4);
			table.insert(expected5);
			table.insert(expected6);
			table.insert(expected7);
			table.insert(expected8);
			table.insert(expected9);
			table.insert(expected10);
			table.insert(expected11);
			table.insert(expected12);
			table.insert(expected13);
			table.insert(expected14);
			table.insert(expected15);
			table.insert(expected16);
			table.insert(expected17);
			table.insert(expected18);
			table.insert(expected19);
			table.insert(expected20);
			table.insert(expected21);
			table.insert(expected22);
			table.insert(expected23);
			table.insert(expected24);
			table.insert(expected25);

			// Assert
			Assert::AreEqual(expected1, table[expected1.phoneNumber]);
			Assert::AreEqual(expected2, table[expected2.phoneNumber]);
			Assert::AreEqual(expected3, table[expected3.phoneNumber]);
			Assert::AreEqual(expected4, table[expected4.phoneNumber]);
			Assert::AreEqual(expected5, table[expected5.phoneNumber]);
			Assert::AreEqual(expected6, table[expected6.phoneNumber]);
			Assert::AreEqual(expected7, table[expected7.phoneNumber]);
			Assert::AreEqual(expected8, table[expected8.phoneNumber]);
			Assert::AreEqual(expected9, table[expected9.phoneNumber]);
			Assert::AreEqual(expected10, table[expected10.phoneNumber]);
			Assert::AreEqual(expected11, table[expected11.phoneNumber]);
			Assert::AreEqual(expected12, table[expected12.phoneNumber]);
			Assert::AreEqual(expected13, table[expected13.phoneNumber]);
			Assert::AreEqual(expected14, table[expected14.phoneNumber]);
			Assert::AreEqual(expected15, table[expected15.phoneNumber]);
			Assert::AreEqual(expected16, table[expected16.phoneNumber]);
			Assert::AreEqual(expected17, table[expected17.phoneNumber]);
			Assert::AreEqual(expected18, table[expected18.phoneNumber]);
			Assert::AreEqual(expected19, table[expected19.phoneNumber]);
			Assert::AreEqual(expected20, table[expected20.phoneNumber]);
			Assert::AreEqual(expected21, table[expected21.phoneNumber]);
			Assert::AreEqual(expected22, table[expected22.phoneNumber]);
			Assert::AreEqual(expected23, table[expected23.phoneNumber]);
			Assert::AreEqual(expected24, table[expected24.phoneNumber]);
			Assert::AreEqual(expected25, table[expected25.phoneNumber]);
		}

		TEST_METHOD(HardInsertionTest)
		{
			// Arrange
			HashTable::StringHashTable table;
			HashTable::Record expected1 = { "1", "adr1" };
			HashTable::Record expected2 = { "10", "adr10" };
			HashTable::Record expected3 = { "20", "adr20" };
			HashTable::Record expected4 = { "20", "adr20" };
			HashTable::Record expected5 = { "20", "adr20" };
			HashTable::Record expected6 = { "20", "adr20" };
			HashTable::Record expected7 = { "20", "adr20" };
			HashTable::Record expected8 = { "20", "adr20" };
			HashTable::Record expected9 = { "20", "adr20" };
			HashTable::Record expected10 = { "20", "adr20" };
			HashTable::Record expected11 = { "20", "adr20" };
			HashTable::Record expected12 = { "20", "adr20" };
			HashTable::Record expected13 = { "20", "adr20" };
			HashTable::Record expected14 = { "20", "adr20" };
			HashTable::Record expected15 = { "20", "adr20" };
			HashTable::Record expected16 = { "20", "adr20" };
			HashTable::Record expected17 = { "20", "adr20" };
			HashTable::Record expected18 = { "20", "adr20" };
			HashTable::Record expected19 = { "20", "adr20" };
			HashTable::Record expected20 = { "20", "adr20" };
			HashTable::Record expected21 = { "20", "adr20" };
			HashTable::Record expected22 = { "20", "adr20" };
			HashTable::Record expected23 = { "20", "adr20" };
			HashTable::Record expected24 = { "20", "adr20" };
			HashTable::Record expected25 = { "20", "adr20" };

			// Act
			table.insert(expected1);
			table.insert(expected2);
			table.insert(expected3);
			table.insert(expected4);
			table.insert(expected5);
			table.insert(expected6);
			table.insert(expected7);
			table.insert(expected8);
			table.insert(expected9);
			table.insert(expected10);
			table.insert(expected11);
			table.insert(expected12);
			table.insert(expected13);
			table.insert(expected14);
			table.insert(expected15);
			table.insert(expected16);
			table.insert(expected17);
			table.insert(expected18);
			table.insert(expected19);
			table.insert(expected20);
			table.insert(expected21);
			table.insert(expected22);
			table.insert(expected23);
			table.insert(expected24);
			table.insert(expected25);

			// Assert
			Assert::AreEqual(expected1, table[expected1.phoneNumber]);
			Assert::AreEqual(expected2, table[expected2.phoneNumber]);
			Assert::AreEqual(expected3, table[expected3.phoneNumber]);
			Assert::AreEqual(expected4, table[expected4.phoneNumber]);
			Assert::AreEqual(expected5, table[expected5.phoneNumber]);
			Assert::AreEqual(expected6, table[expected6.phoneNumber]);
			Assert::AreEqual(expected7, table[expected7.phoneNumber]);
			Assert::AreEqual(expected8, table[expected8.phoneNumber]);
			Assert::AreEqual(expected9, table[expected9.phoneNumber]);
			Assert::AreEqual(expected10, table[expected10.phoneNumber]);
			Assert::AreEqual(expected11, table[expected11.phoneNumber]);
			Assert::AreEqual(expected12, table[expected12.phoneNumber]);
			Assert::AreEqual(expected13, table[expected13.phoneNumber]);
			Assert::AreEqual(expected14, table[expected14.phoneNumber]);
			Assert::AreEqual(expected15, table[expected15.phoneNumber]);
			Assert::AreEqual(expected16, table[expected16.phoneNumber]);
			Assert::AreEqual(expected17, table[expected17.phoneNumber]);
			Assert::AreEqual(expected18, table[expected18.phoneNumber]);
			Assert::AreEqual(expected19, table[expected19.phoneNumber]);
			Assert::AreEqual(expected20, table[expected20.phoneNumber]);
			Assert::AreEqual(expected21, table[expected21.phoneNumber]);
			Assert::AreEqual(expected22, table[expected22.phoneNumber]);
			Assert::AreEqual(expected23, table[expected23.phoneNumber]);
			Assert::AreEqual(expected24, table[expected24.phoneNumber]);
			Assert::AreEqual(expected25, table[expected25.phoneNumber]);
		}
};
	};
}
