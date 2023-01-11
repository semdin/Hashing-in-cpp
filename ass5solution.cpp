#include <iostream>
#include <string>
#include <math.h>

#include "intSLList.h"

using namespace std;

IntSLList hashTable[10];
IntSLList hashLoc[10];

// Function initial declarations
void pleaseHelpMeWithHashValues();
void insertIntoHashTable(int input);
void insertIntoHashTable(const char* input);
bool searchInHashTable(int input);
bool searchInHashTable(const char* input);
void printHashTable();

// Hashing function for integer inputs.
// This function should insert an element only
// if there are no duplicates within the table.
void insertIntoHashTable(int input) {

	int hashAddress = input % 10;

	if (!searchInHashTable(input)) {
		hashTable[hashAddress].addToTail(input);
		hashLoc[hashAddress].addToTail(0);
	}

	return;
}

// This may be helpful for your coding.
void pleaseHelpMeWithHashValues() {
	cout << "Printable ASCII [48..90]:\n";
	for (char i = '0'; i <= 'Z'; ++i) {
		cout << i << ((i % 16 == 15) ? '\n' : ' ');
	}
	cout << endl << "ASCII val. of 'A' is: " << (int)'A' << endl;
	cout << "Value 65 equals to character: " << (char)65 << endl;
}

// Hashing function for string inputs.
// Remember, one of the best features of C++ is function overloading,
// as long as the function signatures are different
// you can have two different functions with the same name.
void insertIntoHashTable(const char* input) {
	// Hint: The largest integer that C++ supports is 2147483647
	// Let's go with 4-character string support then.
	int hashedString = 0;
	string s = input;
	for (int i = 0; i < s.size(); i++) {
        hashedString += ((int)s[i] * pow(100, i));
    }

	int hashAddress = hashedString % 10;

	if (!searchInHashTable(hashedString)) {
		hashTable[hashAddress].addToTail(hashedString);
		hashLoc[hashAddress].addToTail(1);
	}
}

// Function to return whether a value is in our hash table or not.
bool searchInHashTable(int input) {

	int hashAddress = input % 10;

	return hashTable[hashAddress].isInList(input);
}

bool searchInHashTable(const char* input) {

	int hashedString = 0;
	string s = input;
	for (int i = 0; i < s.size(); i++) {
        hashedString += ((int)s[i] * pow(100, i));
    }

	int hashAddress = hashedString % 10;

	return hashTable[hashAddress].isInList(hashedString);
}

void printHashTable() {
	for (int i = 0; i < 10; i++) {
		cout << "\tPrinting hash table for hash " << i << ":" << endl;
		cout << "Hash Table values are: ";
		hashTable[i].printAll();
		cout << "Value types are (0 for int, 1 for string): ";
		hashLoc[i].printAll();
	}
}

int main() {
	
	insertIntoHashTable(1);
	insertIntoHashTable(11);
	insertIntoHashTable(6);
	insertIntoHashTable(121);
	insertIntoHashTable("AAA");
	insertIntoHashTable("Y");
	insertIntoHashTable("30E");
	printHashTable();
	cout << "search begin:" << endl;
	cout << searchInHashTable(11) << endl;
	cout << searchInHashTable(10) << endl;
	cout << searchInHashTable(66) << endl;
	cout << searchInHashTable("AAA") << endl;
	cout << searchInHashTable("AA") << endl;
	pleaseHelpMeWithHashValues();

	return 0;
}