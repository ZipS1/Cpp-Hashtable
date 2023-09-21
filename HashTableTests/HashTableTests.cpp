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

		TEST_METHOD(MultipleRemoval)
		{
			// Arrange
			HashTable::StringHashTable table;
			HashTable::Record record1{ "1", "adr1" };
			HashTable::Record record2{ "2", "adr2" };
			HashTable::Record record3{ "3", "adr3" };
			HashTable::Record record4{ "4", "adr4" };
			HashTable::Record record5{ "5", "adr5" };
			size_t expectedSize = 0;
			size_t expectedCapacity = 100;
			table.insert(record1);
			table.insert(record2);
			table.insert(record3);
			table.insert(record4);
			table.insert(record5);

			// Act
			bool isOk1 = table.remove(record1.phoneNumber);
			bool isOk2 = table.remove(record2.phoneNumber);
			bool isOk3 = table.remove(record3.phoneNumber);
			bool isOk4 = table.remove(record4.phoneNumber);
			bool isOk5 = table.remove(record5.phoneNumber);


			// Assert
			Assert::IsTrue(isOk1);
			Assert::IsTrue(isOk2);
			Assert::IsTrue(isOk3);
			Assert::IsTrue(isOk4);
			Assert::IsTrue(isOk5);
			Assert::IsFalse(table.exists(record1.phoneNumber));
			Assert::IsFalse(table.exists(record2.phoneNumber));
			Assert::IsFalse(table.exists(record3.phoneNumber));
			Assert::IsFalse(table.exists(record4.phoneNumber));
			Assert::IsFalse(table.exists(record5.phoneNumber));
			Assert::IsFalse(table.remove(record1.phoneNumber));
			Assert::IsFalse(table.remove(record2.phoneNumber));
			Assert::IsFalse(table.remove(record3.phoneNumber));
			Assert::IsFalse(table.remove(record4.phoneNumber));
			Assert::IsFalse(table.remove(record5.phoneNumber));
			Assert::AreEqual(expectedSize, table.getSize());
			Assert::AreEqual(expectedCapacity, table.getCapacity());
		}

		TEST_METHOD(HeavyRemovalAfterRehashing)
		{
			// Arrange
			HashTable::StringHashTable table;
			HashTable::Record record1 = { "1", "adr1" };
			HashTable::Record record2 = { "10", "adr10" };
			HashTable::Record record3 = { "20", "adr20" };
			HashTable::Record record4 = { "30", "adr20" };
			HashTable::Record record5 = { "40", "adr20" };
			HashTable::Record record6 = { "50", "adr20" };
			HashTable::Record record7 = { "60", "adr20" };
			HashTable::Record record8 = { "70", "adr20" };
			HashTable::Record record9 = { "80", "adr20" };
			HashTable::Record record10 = { "100", "adr20" };
			HashTable::Record record11 = { "300", "adr20" };
			HashTable::Record record12 = { "400", "adr20" };
			HashTable::Record record13 = { "500", "adr20" };
			HashTable::Record record14 = { "2", "adr20" };
			HashTable::Record record15 = { "3", "adr20" };
			HashTable::Record record16 = { "4", "adr20" };
			HashTable::Record record17 = { "5", "adr20" };
			HashTable::Record record18 = { "6", "adr20" };
			HashTable::Record record19 = { "7", "adr20" };
			HashTable::Record record20 = { "8", "adr20" };
			HashTable::Record record21 = { "9", "adr20" };
			HashTable::Record record22 = { "0", "adr20" };
			HashTable::Record record23 = { "12", "adr20" };
			HashTable::Record record24 = { "13", "adr20" };
			HashTable::Record record25 = { "14", "adr20" };
			HashTable::Record record26 = { "15", "adr20" };
			HashTable::Record record27 = { "16", "adr20" };
			HashTable::Record record28 = { "17", "adr20" };
			HashTable::Record record29 = { "18", "adr20" };
			HashTable::Record record30 = { "19", "adr20" };
			HashTable::Record record31 = { "141", "adr20" };
			HashTable::Record record32 = { "142", "adr20" };
			HashTable::Record record33 = { "143", "adr20" };
			HashTable::Record record34 = { "144", "adr20" };
			HashTable::Record record35 = { "145", "adr20" };
			HashTable::Record record36 = { "146", "adr20" };
			HashTable::Record record37 = { "147", "adr20" };
			HashTable::Record record38 = { "148", "adr20" };
			HashTable::Record record39 = { "149", "adr20" };
			HashTable::Record record40 = { "1410", "adr20" };
			HashTable::Record record41 = { "1411", "adr20" };
			HashTable::Record record42 = { "1412", "adr20" };
			HashTable::Record record43 = { "1413", "adr20" };
			HashTable::Record record44 = { "1414", "adr20" };
			HashTable::Record record45 = { "1415", "adr20" };
			HashTable::Record record46 = { "1416", "adr20" };
			HashTable::Record record47 = { "1417", "adr20" };
			HashTable::Record record48 = { "1418", "adr20" };
			HashTable::Record record49 = { "1419", "adr20" };
			HashTable::Record record50 = { "1420", "adr20" };
			HashTable::Record record51 = { "1421", "adr20" };
			HashTable::Record record52 = { "1422", "adr20" };
			HashTable::Record record53 = { "1423", "adr20" };
			HashTable::Record record54 = { "1424", "adr20" };
			HashTable::Record record55 = { "14226", "adr20" };
			size_t expectedSize = 0;
			size_t expectedCapacity = 200;
			table.insert(record1);
			table.insert(record2);
			table.insert(record3);
			table.insert(record4);
			table.insert(record5);
			table.insert(record6);
			table.insert(record7);
			table.insert(record8);
			table.insert(record9);
			table.insert(record10);
			table.insert(record11);
			table.insert(record12);
			table.insert(record13);
			table.insert(record14);
			table.insert(record15);
			table.insert(record16);
			table.insert(record17);
			table.insert(record18);
			table.insert(record19);
			table.insert(record20);
			table.insert(record21);
			table.insert(record22);
			table.insert(record23);
			table.insert(record24);
			table.insert(record25);
			table.insert(record26);
			table.insert(record27);
			table.insert(record28);
			table.insert(record29);
			table.insert(record30);
			table.insert(record31);
			table.insert(record32);
			table.insert(record33);
			table.insert(record34);
			table.insert(record35);
			table.insert(record36);
			table.insert(record37);
			table.insert(record38);
			table.insert(record39);
			table.insert(record40);
			table.insert(record41);
			table.insert(record42);
			table.insert(record43);
			table.insert(record44);
			table.insert(record45);
			table.insert(record46);
			table.insert(record47);
			table.insert(record48);
			table.insert(record49);
			table.insert(record50);
			table.insert(record51);
			table.insert(record52);
			table.insert(record53);
			table.insert(record54);
			table.insert(record55);

			// Act
			bool isOk1 = table.remove(record1.phoneNumber);
			bool isOk2 = table.remove(record2.phoneNumber);
			bool isOk3 = table.remove(record3.phoneNumber);
			bool isOk4 = table.remove(record4.phoneNumber);
			bool isOk5 = table.remove(record5.phoneNumber);
			bool isOk6 = table.remove(record6.phoneNumber);
			bool isOk7 = table.remove(record7.phoneNumber);
			bool isOk8 = table.remove(record8.phoneNumber);
			bool isOk9 = table.remove(record9.phoneNumber);
			bool isOk10 = table.remove(record10.phoneNumber);
			bool isOk11 = table.remove(record11.phoneNumber);
			bool isOk12 = table.remove(record12.phoneNumber);
			bool isOk13 = table.remove(record13.phoneNumber);
			bool isOk14 = table.remove(record14.phoneNumber);
			bool isOk15 = table.remove(record15.phoneNumber);
			bool isOk16 = table.remove(record16.phoneNumber);
			bool isOk17 = table.remove(record17.phoneNumber);
			bool isOk18 = table.remove(record18.phoneNumber);
			bool isOk19 = table.remove(record19.phoneNumber);
			bool isOk20 = table.remove(record20.phoneNumber);
			bool isOk21 = table.remove(record21.phoneNumber);
			bool isOk22 = table.remove(record22.phoneNumber);
			bool isOk23 = table.remove(record23.phoneNumber);
			bool isOk24 = table.remove(record24.phoneNumber);
			bool isOk25 = table.remove(record25.phoneNumber);
			bool isOk26 = table.remove(record26.phoneNumber);
			bool isOk27 = table.remove(record27.phoneNumber);
			bool isOk28 = table.remove(record28.phoneNumber);
			bool isOk29 = table.remove(record29.phoneNumber);
			bool isOk30 = table.remove(record30.phoneNumber);
			bool isOk31 = table.remove(record31.phoneNumber);
			bool isOk32 = table.remove(record32.phoneNumber);
			bool isOk33 = table.remove(record33.phoneNumber);
			bool isOk34 = table.remove(record34.phoneNumber);
			bool isOk35 = table.remove(record35.phoneNumber);
			bool isOk36 = table.remove(record36.phoneNumber);
			bool isOk37 = table.remove(record37.phoneNumber);
			bool isOk38 = table.remove(record38.phoneNumber);
			bool isOk39 = table.remove(record39.phoneNumber);
			bool isOk40 = table.remove(record40.phoneNumber);
			bool isOk41 = table.remove(record41.phoneNumber);
			bool isOk42 = table.remove(record42.phoneNumber);
			bool isOk43 = table.remove(record43.phoneNumber);
			bool isOk44 = table.remove(record44.phoneNumber);
			bool isOk45 = table.remove(record45.phoneNumber);
			bool isOk46 = table.remove(record46.phoneNumber);
			bool isOk47 = table.remove(record47.phoneNumber);
			bool isOk48 = table.remove(record48.phoneNumber);
			bool isOk49 = table.remove(record49.phoneNumber);
			bool isOk50 = table.remove(record50.phoneNumber);
			bool isOk51 = table.remove(record51.phoneNumber);
			bool isOk52 = table.remove(record52.phoneNumber);
			bool isOk53 = table.remove(record53.phoneNumber);
			bool isOk54 = table.remove(record54.phoneNumber);
			bool isOk55 = table.remove(record55.phoneNumber);


			// Assert
			Assert::IsTrue(isOk1);
			Assert::IsTrue(isOk2);
			Assert::IsTrue(isOk3);
			Assert::IsTrue(isOk4);
			Assert::IsTrue(isOk5);
			Assert::IsTrue(isOk6);
			Assert::IsTrue(isOk7);
			Assert::IsTrue(isOk8);
			Assert::IsTrue(isOk9);
			Assert::IsTrue(isOk10);
			Assert::IsTrue(isOk11);
			Assert::IsTrue(isOk12);
			Assert::IsTrue(isOk13);
			Assert::IsTrue(isOk14);
			Assert::IsTrue(isOk15);
			Assert::IsTrue(isOk16);
			Assert::IsTrue(isOk17);
			Assert::IsTrue(isOk18);
			Assert::IsTrue(isOk19);
			Assert::IsTrue(isOk20);
			Assert::IsTrue(isOk21);
			Assert::IsTrue(isOk22);
			Assert::IsTrue(isOk23);
			Assert::IsTrue(isOk24);
			Assert::IsTrue(isOk25);
			Assert::IsTrue(isOk26);
			Assert::IsTrue(isOk27);
			Assert::IsTrue(isOk28);
			Assert::IsTrue(isOk29);
			Assert::IsTrue(isOk30);
			Assert::IsTrue(isOk31);
			Assert::IsTrue(isOk32);
			Assert::IsTrue(isOk33);
			Assert::IsTrue(isOk34);
			Assert::IsTrue(isOk35);
			Assert::IsTrue(isOk36);
			Assert::IsTrue(isOk37);
			Assert::IsTrue(isOk38);
			Assert::IsTrue(isOk39);
			Assert::IsTrue(isOk40);
			Assert::IsTrue(isOk41);
			Assert::IsTrue(isOk42);
			Assert::IsTrue(isOk43);
			Assert::IsTrue(isOk44);
			Assert::IsTrue(isOk45);
			Assert::IsTrue(isOk46);
			Assert::IsTrue(isOk47);
			Assert::IsTrue(isOk48);
			Assert::IsTrue(isOk49);
			Assert::IsTrue(isOk50);
			Assert::IsTrue(isOk51);
			Assert::IsTrue(isOk52);
			Assert::IsTrue(isOk53);
			Assert::IsTrue(isOk54);
			Assert::IsTrue(isOk55);
			Assert::IsFalse(table.exists(record1.phoneNumber));
			Assert::IsFalse(table.exists(record2.phoneNumber));
			Assert::IsFalse(table.exists(record3.phoneNumber));
			Assert::IsFalse(table.exists(record4.phoneNumber));
			Assert::IsFalse(table.exists(record5.phoneNumber));
			Assert::IsFalse(table.exists(record6.phoneNumber));
			Assert::IsFalse(table.exists(record7.phoneNumber));
			Assert::IsFalse(table.exists(record8.phoneNumber));
			Assert::IsFalse(table.exists(record9.phoneNumber));
			Assert::IsFalse(table.exists(record10.phoneNumber));
			Assert::IsFalse(table.exists(record11.phoneNumber));
			Assert::IsFalse(table.exists(record12.phoneNumber));
			Assert::IsFalse(table.exists(record13.phoneNumber));
			Assert::IsFalse(table.exists(record14.phoneNumber));
			Assert::IsFalse(table.exists(record15.phoneNumber));
			Assert::IsFalse(table.exists(record16.phoneNumber));
			Assert::IsFalse(table.exists(record17.phoneNumber));
			Assert::IsFalse(table.exists(record18.phoneNumber));
			Assert::IsFalse(table.exists(record19.phoneNumber));
			Assert::IsFalse(table.exists(record20.phoneNumber));
			Assert::IsFalse(table.exists(record21.phoneNumber));
			Assert::IsFalse(table.exists(record22.phoneNumber));
			Assert::IsFalse(table.exists(record23.phoneNumber));
			Assert::IsFalse(table.exists(record24.phoneNumber));
			Assert::IsFalse(table.exists(record25.phoneNumber));
			Assert::IsFalse(table.exists(record26.phoneNumber));
			Assert::IsFalse(table.exists(record27.phoneNumber));
			Assert::IsFalse(table.exists(record28.phoneNumber));
			Assert::IsFalse(table.exists(record29.phoneNumber));
			Assert::IsFalse(table.exists(record30.phoneNumber));
			Assert::IsFalse(table.exists(record31.phoneNumber));
			Assert::IsFalse(table.exists(record32.phoneNumber));
			Assert::IsFalse(table.exists(record33.phoneNumber));
			Assert::IsFalse(table.exists(record34.phoneNumber));
			Assert::IsFalse(table.exists(record35.phoneNumber));
			Assert::IsFalse(table.exists(record36.phoneNumber));
			Assert::IsFalse(table.exists(record37.phoneNumber));
			Assert::IsFalse(table.exists(record38.phoneNumber));
			Assert::IsFalse(table.exists(record39.phoneNumber));
			Assert::IsFalse(table.exists(record40.phoneNumber));
			Assert::IsFalse(table.exists(record41.phoneNumber));
			Assert::IsFalse(table.exists(record42.phoneNumber));
			Assert::IsFalse(table.exists(record43.phoneNumber));
			Assert::IsFalse(table.exists(record44.phoneNumber));
			Assert::IsFalse(table.exists(record45.phoneNumber));
			Assert::IsFalse(table.exists(record46.phoneNumber));
			Assert::IsFalse(table.exists(record47.phoneNumber));
			Assert::IsFalse(table.exists(record48.phoneNumber));
			Assert::IsFalse(table.exists(record49.phoneNumber));
			Assert::IsFalse(table.exists(record50.phoneNumber));
			Assert::IsFalse(table.exists(record51.phoneNumber));
			Assert::IsFalse(table.exists(record52.phoneNumber));
			Assert::IsFalse(table.exists(record53.phoneNumber));
			Assert::IsFalse(table.exists(record54.phoneNumber));
			Assert::IsFalse(table.exists(record55.phoneNumber));
			Assert::IsFalse(table.remove(record1.phoneNumber));
			Assert::IsFalse(table.remove(record2.phoneNumber));
			Assert::IsFalse(table.remove(record3.phoneNumber));
			Assert::IsFalse(table.remove(record4.phoneNumber));
			Assert::IsFalse(table.remove(record5.phoneNumber));
			Assert::IsFalse(table.remove(record6.phoneNumber));
			Assert::IsFalse(table.remove(record7.phoneNumber));
			Assert::IsFalse(table.remove(record8.phoneNumber));
			Assert::IsFalse(table.remove(record9.phoneNumber));
			Assert::IsFalse(table.remove(record10.phoneNumber));
			Assert::IsFalse(table.remove(record11.phoneNumber));
			Assert::IsFalse(table.remove(record12.phoneNumber));
			Assert::IsFalse(table.remove(record13.phoneNumber));
			Assert::IsFalse(table.remove(record14.phoneNumber));
			Assert::IsFalse(table.remove(record15.phoneNumber));
			Assert::IsFalse(table.remove(record16.phoneNumber));
			Assert::IsFalse(table.remove(record17.phoneNumber));
			Assert::IsFalse(table.remove(record18.phoneNumber));
			Assert::IsFalse(table.remove(record19.phoneNumber));
			Assert::IsFalse(table.remove(record20.phoneNumber));
			Assert::IsFalse(table.remove(record21.phoneNumber));
			Assert::IsFalse(table.remove(record22.phoneNumber));
			Assert::IsFalse(table.remove(record23.phoneNumber));
			Assert::IsFalse(table.remove(record24.phoneNumber));
			Assert::IsFalse(table.remove(record25.phoneNumber));
			Assert::IsFalse(table.remove(record26.phoneNumber));
			Assert::IsFalse(table.remove(record27.phoneNumber));
			Assert::IsFalse(table.remove(record28.phoneNumber));
			Assert::IsFalse(table.remove(record29.phoneNumber));
			Assert::IsFalse(table.remove(record30.phoneNumber));
			Assert::IsFalse(table.remove(record31.phoneNumber));
			Assert::IsFalse(table.remove(record32.phoneNumber));
			Assert::IsFalse(table.remove(record33.phoneNumber));
			Assert::IsFalse(table.remove(record34.phoneNumber));
			Assert::IsFalse(table.remove(record35.phoneNumber));
			Assert::IsFalse(table.remove(record36.phoneNumber));
			Assert::IsFalse(table.remove(record37.phoneNumber));
			Assert::IsFalse(table.remove(record38.phoneNumber));
			Assert::IsFalse(table.remove(record39.phoneNumber));
			Assert::IsFalse(table.remove(record40.phoneNumber));
			Assert::IsFalse(table.remove(record41.phoneNumber));
			Assert::IsFalse(table.remove(record42.phoneNumber));
			Assert::IsFalse(table.remove(record43.phoneNumber));
			Assert::IsFalse(table.remove(record44.phoneNumber));
			Assert::IsFalse(table.remove(record45.phoneNumber));
			Assert::IsFalse(table.remove(record46.phoneNumber));
			Assert::IsFalse(table.remove(record47.phoneNumber));
			Assert::IsFalse(table.remove(record48.phoneNumber));
			Assert::IsFalse(table.remove(record49.phoneNumber));
			Assert::IsFalse(table.remove(record50.phoneNumber));
			Assert::IsFalse(table.remove(record51.phoneNumber));
			Assert::IsFalse(table.remove(record52.phoneNumber));
			Assert::IsFalse(table.remove(record53.phoneNumber));
			Assert::IsFalse(table.remove(record54.phoneNumber));
			Assert::IsFalse(table.remove(record55.phoneNumber));
			Assert::AreEqual(expectedSize, table.getSize());
			Assert::AreEqual(expectedCapacity, table.getCapacity());
		}

		TEST_METHOD(NotExistingKeyRemoval)
		{
			// Arrange
			HashTable::StringHashTable table;
			HashTable::Record record{ "1", "adr1" };
			size_t expectedSize = 0;
			size_t expectedCapacity = 100;

			// Act
			bool isOk = table.remove(record.phoneNumber);

			// Assert
			Assert::IsFalse(isOk);
			Assert::IsFalse(table.exists(record.phoneNumber));
			Assert::AreEqual(expectedSize, table.getSize());
			Assert::AreEqual(expectedCapacity, table.getCapacity());
		}
	};

	TEST_CLASS(ExistsTests)
	{
	public:
		TEST_METHOD(ExistsOnInsertion)
		{
			// Arrange
			HashTable::StringHashTable table;
			HashTable::Record record{ "1", "adr1" };
			table.insert(record);

			// Act
			bool isExists = table.exists(record.phoneNumber);

			// Assert
			Assert::IsTrue(isExists);
		}

		TEST_METHOD(ExistsOnRemoval)
		{
			// Arrange
			HashTable::StringHashTable table;
			HashTable::Record record{ "1", "adr1" };
			table.insert(record);
			table.remove(record.phoneNumber);

			// Act
			bool isExists = table.exists(record.phoneNumber);

			// Assert
			Assert::IsFalse(isExists);
		}

		TEST_METHOD(ExistsOnNull)
		{
			// Arrange
			HashTable::StringHashTable table;
			HashTable::Record record{ "1", "adr1" };

			// Act
			bool isExists = table.exists(record.phoneNumber);

			// Assert
			Assert::IsFalse(isExists);
		}
	};

	TEST_CLASS(GetValueTests)
	{
	public:
		TEST_METHOD(GetValueOnInsertion)
		{
			// Arrange
			HashTable::StringHashTable table;
			HashTable::Record expectedRecord{ "1", "adr1" };
			table.insert(expectedRecord);

			// Act
			HashTable::Record actualRecord = table.getValue(expectedRecord.phoneNumber);

			// Assert
			Assert::AreEqual(expectedRecord, actualRecord);
		}

		TEST_METHOD(GetValueOnRemoval)
		{
			// Arrange
			HashTable::StringHashTable table;
			HashTable::Record record{ "1", "adr1" };
			table.insert(record);
			table.remove(record.phoneNumber);

			// Act
			auto func = [&] { table.getValue(record.phoneNumber); };

			// Assert
			Assert::ExpectException<HashTable::KeyNotExistsException>(func);
		}

		TEST_METHOD(GetValueOnNull)
		{
			// Arrange
			HashTable::StringHashTable table;
			HashTable::Record record{ "1", "adr1" };

			// Act
			auto func = [&] { table.getValue(record.phoneNumber); };

			// Assert
			Assert::ExpectException<HashTable::KeyNotExistsException>(func);
		}
	};

	TEST_CLASS(IteratorTests)
	{
	public:
		TEST_METHOD(IteratorBeginElement)
		{
			// Arrange
			HashTable::StringHashTable table;
			HashTable::Record expectedRecord{ "1", "adr1" };
			HashTable::Record record2{ "2", "adr2" };
			HashTable::Record record3{ "3", "adr3" };
			table.insert(expectedRecord);
			table.insert(record2);
			table.insert(record3);

			// Act
			auto it = table.begin();

			// Assert
			Assert::AreEqual(expectedRecord, *it);
		}

		TEST_METHOD(IteratorMiddleElement)
		{
			// Arrange
			HashTable::StringHashTable table;
			HashTable::Record record1{ "1", "adr1" };
			HashTable::Record record2{ "2", "adr2" };
			HashTable::Record record3{ "3", "adr3" };
			HashTable::Record expectedRecord{ "3", "adr3" };
			HashTable::Record record5{ "3", "adr3" };
			HashTable::Record record6{ "3", "adr3" };
			table.insert(record1);
			table.insert(record2);
			table.insert(record3);
			table.insert(expectedRecord);
			table.insert(record5);
			table.insert(record6);
			size_t forwardAmount = 3;

			// Act
			auto it = table.begin();
			for (size_t i = 0; i < forwardAmount; i++)
				it++;

			// Assert
			Assert::AreEqual(expectedRecord, *it);
		}

		TEST_METHOD(IteratorLastElement)
		{
			// Arrange
			HashTable::StringHashTable table;
			HashTable::Record record1{ "1", "adr1" };
			HashTable::Record record2{ "2", "adr2" };
			HashTable::Record expectedRecord{ "3", "adr3" };
			table.insert(record1);
			table.insert(record2);
			table.insert(expectedRecord);

			// Act
			HashTable::Record record;
			for (auto it = table.begin(); it != table.end(); it++)
				record = *it;

			// Assert
			Assert::AreEqual(expectedRecord, record);
		}

		TEST_METHOD(IteratorForLoop)
		{
			// Arrange
			HashTable::StringHashTable table;
			HashTable::Record record1{ "yui", "adr1" };
			HashTable::Record record2{ "trt", "adr2" };
			HashTable::Record record3{ "hgf", "adr3" };
			HashTable::Record record4{ "mnb", "adr4" };
			HashTable::Record record5{ "oki", "adr5" };
			table.insert(record1);
			table.insert(record2);
			table.insert(record3);
			table.insert(record4);
			table.insert(record5);
			size_t expectedCounter = table.getSize();

			// Act
			size_t actualCounter = 0;
			for (auto it = table.begin(); it != table.end(); it++)
				actualCounter++;

			// Assert
			Assert::AreEqual(expectedCounter, actualCounter);
		}

		TEST_METHOD(IteratorForEach)
		{
			// Arrange
			HashTable::StringHashTable table;
			HashTable::Record record1{ "yui", "adr1" };
			HashTable::Record record2{ "trt", "adr2" };
			HashTable::Record record3{ "hgf", "adr3" };
			HashTable::Record record4{ "mnb", "adr4" };
			HashTable::Record record5{ "oki", "adr5" };
			table.insert(record1);
			table.insert(record2);
			table.insert(record3);
			table.insert(record4);
			table.insert(record5);
			size_t expectedCounter = table.getSize();

			// Act
			size_t actualCounter = 0;
			for (auto record : table)
				actualCounter++;

			// Assert
			Assert::AreEqual(expectedCounter, actualCounter);
		}
	};
}
