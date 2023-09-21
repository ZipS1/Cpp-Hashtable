#include "pch.h"
#include "hash-table.h"
#include <codecvt>
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#pragma region FrameworkUtilityCode
namespace Microsoft {
	namespace VisualStudio {
		namespace CppUnitTestFramework {
			template <>
			static std::wstring ToString<HashTable::Record>(const HashTable::Record& record) {
				std::string outString = record.phoneNumber + ", " + record.address;
				std::wstring wstr(outString.begin(), outString.end());
				return wstr;
			}

		}
	}
}
#pragma endregion

namespace HashTableTests
{
	TEST_CLASS(InsertionTests)
	{
	public:	
		TEST_METHOD(LightInsertion)
		{
			// Arrange
			HashTable::StringHashTable table;
			HashTable::Record expected1 = { "1", "adr1" };
			HashTable::Record expected2 = { "10", "adr10" };
			HashTable::Record expected3 = { "20", "adr20" };
			size_t expectedSize = 3;
			size_t expectedCapacity = 100;

			// Act
			table.insert(expected1);
			table.insert(expected2);
			table.insert(expected3);

			// Assert
			Assert::AreEqual(expected1, table[expected1.phoneNumber]);
			Assert::AreEqual(expected2, table[expected2.phoneNumber]);
			Assert::AreEqual(expected3, table[expected3.phoneNumber]);
			Assert::AreEqual(expectedSize, table.getSize());
			Assert::AreEqual(expectedCapacity, table.getCapacity());
		}

		TEST_METHOD(MediumInsertion)
		{
			// Arrange
			HashTable::StringHashTable table;
			HashTable::Record expected1 = { "1", "adr1" };
			HashTable::Record expected2 = { "10", "adr10" };
			HashTable::Record expected3 = { "20", "adr20" };
			HashTable::Record expected4 = { "30", "adr20" };
			HashTable::Record expected5 = { "40", "adr20" };
			HashTable::Record expected6 = { "50", "adr20" };
			HashTable::Record expected7 = { "60", "adr20" };
			HashTable::Record expected8 = { "70", "adr20" };
			HashTable::Record expected9 = { "80", "adr20" };
			HashTable::Record expected10 = { "100", "adr20" };
			HashTable::Record expected11 = { "300", "adr20" };
			HashTable::Record expected12 = { "400", "adr20" };
			HashTable::Record expected13 = { "500", "adr20" };
			HashTable::Record expected14 = { "2", "adr20" };
			HashTable::Record expected15 = { "3", "adr20" };
			HashTable::Record expected16 = { "4", "adr20" };
			HashTable::Record expected17 = { "5", "adr20" };
			HashTable::Record expected18 = { "6", "adr20" };
			HashTable::Record expected19 = { "7", "adr20" };
			HashTable::Record expected20 = { "8", "adr20" };
			HashTable::Record expected21 = { "9", "adr20" };
			HashTable::Record expected22 = { "0", "adr20" };
			HashTable::Record expected23 = { "12", "adr20" };
			HashTable::Record expected24 = { "13", "adr20" };
			HashTable::Record expected25 = { "14", "adr20" };
			size_t expectedSize = 25;
			size_t expectedCapacity = 100;

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
			Assert::AreEqual(expectedSize, table.getSize());
			Assert::AreEqual(expectedCapacity, table.getCapacity());
		}

		TEST_METHOD(HeavyInsertionWithRehashing)
		{
			// Arrange
			HashTable::StringHashTable table;
			HashTable::Record expected1 = { "1", "adr1" };
			HashTable::Record expected2 = { "10", "adr10" };
			HashTable::Record expected3 = { "20", "adr20" };
			HashTable::Record expected4 = { "30", "adr20" };
			HashTable::Record expected5 = { "40", "adr20" };
			HashTable::Record expected6 = { "50", "adr20" };
			HashTable::Record expected7 = { "60", "adr20" };
			HashTable::Record expected8 = { "70", "adr20" };
			HashTable::Record expected9 = { "80", "adr20" };
			HashTable::Record expected10 = { "100", "adr20" };
			HashTable::Record expected11 = { "300", "adr20" };
			HashTable::Record expected12 = { "400", "adr20" };
			HashTable::Record expected13 = { "500", "adr20" };
			HashTable::Record expected14 = { "2", "adr20" };
			HashTable::Record expected15 = { "3", "adr20" };
			HashTable::Record expected16 = { "4", "adr20" };
			HashTable::Record expected17 = { "5", "adr20" };
			HashTable::Record expected18 = { "6", "adr20" };
			HashTable::Record expected19 = { "7", "adr20" };
			HashTable::Record expected20 = { "8", "adr20" };
			HashTable::Record expected21 = { "9", "adr20" };
			HashTable::Record expected22 = { "0", "adr20" };
			HashTable::Record expected23 = { "12", "adr20" };
			HashTable::Record expected24 = { "13", "adr20" };
			HashTable::Record expected25 = { "14", "adr20" };
			HashTable::Record expected26 = { "15", "adr20" };
			HashTable::Record expected27 = { "16", "adr20" };
			HashTable::Record expected28 = { "17", "adr20" };
			HashTable::Record expected29 = { "18", "adr20" };
			HashTable::Record expected30 = { "19", "adr20" };
			HashTable::Record expected31 = { "141", "adr20" };
			HashTable::Record expected32 = { "142", "adr20" };
			HashTable::Record expected33 = { "143", "adr20" };
			HashTable::Record expected34 = { "144", "adr20" };
			HashTable::Record expected35 = { "145", "adr20" };
			HashTable::Record expected36 = { "146", "adr20" };
			HashTable::Record expected37 = { "147", "adr20" };
			HashTable::Record expected38 = { "148", "adr20" };
			HashTable::Record expected39 = { "149", "adr20" };
			HashTable::Record expected40 = { "1410", "adr20" };
			HashTable::Record expected41 = { "1411", "adr20" };
			HashTable::Record expected42 = { "1412", "adr20" };
			HashTable::Record expected43 = { "1413", "adr20" };
			HashTable::Record expected44 = { "1414", "adr20" };
			HashTable::Record expected45 = { "1415", "adr20" };
			HashTable::Record expected46 = { "1416", "adr20" };
			HashTable::Record expected47 = { "1417", "adr20" };
			HashTable::Record expected48 = { "1418", "adr20" };
			HashTable::Record expected49 = { "1419", "adr20" };
			HashTable::Record expected50 = { "1420", "adr20" };
			HashTable::Record expected51 = { "1421", "adr20" };
			HashTable::Record expected52 = { "1422", "adr20" };
			HashTable::Record expected53 = { "1423", "adr20" };
			HashTable::Record expected54 = { "1424", "adr20" };
			HashTable::Record expected55 = { "14226", "adr20" };
			size_t expectedSize = 55;
			size_t expectedCapacity = 200;

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
			table.insert(expected26);
			table.insert(expected27);
			table.insert(expected28);
			table.insert(expected29);
			table.insert(expected30);
			table.insert(expected31);
			table.insert(expected32);
			table.insert(expected33);
			table.insert(expected34);
			table.insert(expected35);
			table.insert(expected36);
			table.insert(expected37);
			table.insert(expected38);
			table.insert(expected39);
			table.insert(expected40);
			table.insert(expected41);
			table.insert(expected42);
			table.insert(expected43);
			table.insert(expected44);
			table.insert(expected45);
			table.insert(expected46);
			table.insert(expected47);
			table.insert(expected48);
			table.insert(expected49);
			table.insert(expected50);
			table.insert(expected51);
			table.insert(expected52);
			table.insert(expected53);
			table.insert(expected54);
			table.insert(expected55);

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
			Assert::AreEqual(expected26, table[expected26.phoneNumber]);
			Assert::AreEqual(expected27, table[expected27.phoneNumber]);
			Assert::AreEqual(expected28, table[expected28.phoneNumber]);
			Assert::AreEqual(expected29, table[expected29.phoneNumber]);
			Assert::AreEqual(expected30, table[expected30.phoneNumber]);
			Assert::AreEqual(expected31, table[expected31.phoneNumber]);
			Assert::AreEqual(expected32, table[expected32.phoneNumber]);
			Assert::AreEqual(expected33, table[expected33.phoneNumber]);
			Assert::AreEqual(expected34, table[expected34.phoneNumber]);
			Assert::AreEqual(expected35, table[expected35.phoneNumber]);
			Assert::AreEqual(expected36, table[expected36.phoneNumber]);
			Assert::AreEqual(expected37, table[expected37.phoneNumber]);
			Assert::AreEqual(expected38, table[expected38.phoneNumber]);
			Assert::AreEqual(expected39, table[expected39.phoneNumber]);
			Assert::AreEqual(expected40, table[expected40.phoneNumber]);
			Assert::AreEqual(expected41, table[expected41.phoneNumber]);
			Assert::AreEqual(expected42, table[expected42.phoneNumber]);
			Assert::AreEqual(expected43, table[expected43.phoneNumber]);
			Assert::AreEqual(expected44, table[expected44.phoneNumber]);
			Assert::AreEqual(expected45, table[expected45.phoneNumber]);
			Assert::AreEqual(expected46, table[expected46.phoneNumber]);
			Assert::AreEqual(expected47, table[expected47.phoneNumber]);
			Assert::AreEqual(expected48, table[expected48.phoneNumber]);
			Assert::AreEqual(expected49, table[expected49.phoneNumber]);
			Assert::AreEqual(expected50, table[expected50.phoneNumber]);
			Assert::AreEqual(expected51, table[expected51.phoneNumber]);
			Assert::AreEqual(expected52, table[expected52.phoneNumber]);
			Assert::AreEqual(expected53, table[expected53.phoneNumber]);
			Assert::AreEqual(expected54, table[expected54.phoneNumber]);
			Assert::AreEqual(expected55, table[expected55.phoneNumber]);
			Assert::AreEqual(expectedSize, table.getSize());
			Assert::AreEqual(expectedCapacity, table.getCapacity());
		}

		TEST_METHOD(ExistingRecordInsertion)
		{
			// Arrange
			HashTable::StringHashTable table;
			HashTable::Record record{ "1", "adr1" };
			table.insert(record);
			size_t expectedSize = 1;
			size_t expectedCapacity = 100;

			// Act
			table.insert(record);

			// Assert
			Assert::AreEqual(record, table[record.phoneNumber]);
			Assert::AreEqual(expectedSize, table.getSize());
			Assert::AreEqual(expectedCapacity, table.getCapacity());
		}

		TEST_METHOD(ExistingKeyInsertion)
		{
			// Arrange
			HashTable::StringHashTable table;
			HashTable::Record record{ "1", "adr1" };
			HashTable::Record editedRecord{ "1", "adredited" };
			table.insert(record);
			size_t expectedSize = 1;
			size_t expectedCapacity = 100;

			// Act
			table.insert(editedRecord);

			// Assert
			Assert::AreEqual(editedRecord, table[record.phoneNumber]);
			Assert::AreEqual(expectedSize, table.getSize());
			Assert::AreEqual(expectedCapacity, table.getCapacity());
		}
	};

	TEST_CLASS(RemovalTests)
	{
	public:
		TEST_METHOD(SingleRemoval)
		{
			// Arrange
			HashTable::StringHashTable table;
			HashTable::Record record{ "1", "adr1" };
			size_t expectedSize = 0;
			size_t expectedCapacity = 100;
			table.insert(record);

			// Act
			bool isOk = table.remove(record.phoneNumber);


			// Assert
			Assert::IsTrue(isOk);
			Assert::IsFalse(table.exists(record.phoneNumber));
			Assert::IsFalse(table.remove(record.phoneNumber));
			Assert::AreEqual(expectedSize, table.getSize());
			Assert::AreEqual(expectedCapacity, table.getCapacity());
		}
	};
}
