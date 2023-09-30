#ifndef HASHTABLE_H


#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>


struct BankAccount {
public:
	int keyNumber;
	std::string fullName;
	std::string address;
	BankAccount();
	BankAccount(int keyNumber, std::string fullName, std::string address);
};


class HashTable {
private:
	BankAccount* hashTable;
	int coefA, coefB;
	int length, size;
	int hashFunc(int keyNumber);
	void resize();
public:
	HashTable();
	HashTable(int coefA, int coefB);
	~HashTable();
	void readFromFile(std::string filename);
	bool add(BankAccount bankAccount);
	bool remove(int keyNumber);
	BankAccount find(int keyNumber);
	void print();
};


#endif