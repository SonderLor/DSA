#include "HashTable.h"


BankAccount::BankAccount() {
	keyNumber = 0;
	fullName = "";
	address = "";
}

BankAccount::BankAccount(int keyNumber, std::string fullName, std::string address) : keyNumber(keyNumber), fullName(fullName), address(address) {}


HashTable::HashTable() {
	length = 1;
	size = 0;
	coefA = 2;
	coefB = 1;
	hashTable = new BankAccount[length];
}

HashTable::HashTable(int coefA, int coefB) {
	length = 1;
	size = 0;
	this->coefA = coefA;
	this->coefB = coefB;
	hashTable = new BankAccount[length];
}

void HashTable::readFromFile(std::string filename) {
	std::ifstream file(filename);
	int keyNumber;
	std::string line, fullName, address;
	while (!file.eof()) {
		std::getline(file, line);
		keyNumber = stoi(line.substr(0, line.find(", ")));
		fullName = line.substr(line.find(", ") + 2, line.rfind(", ") - line.find(", ") - 2);
		address = line.substr(line.rfind(", ") + 2, line.length() - line.rfind(", ") - 2);
		add(BankAccount(keyNumber, fullName, address));
	}
	file.close();
}

HashTable::~HashTable() {
	delete[] hashTable;
}

int HashTable::hashFunc(int keyNumber) {
	int hash = 0, i = 1;
	while (keyNumber != 0)
	{
		hash += i * keyNumber % 10;
		i++;
		keyNumber /= 10;
	}
	hash += i;
	hash %= length;
	return hash;
}

void HashTable::resize() {
	BankAccount* temp = new BankAccount[size];
	for (int i = 0; i < size; i++) {
		temp[i] = hashTable[i];
	}
	length *= 2;
	hashTable = new BankAccount[length];
	for (int i = 0; i < size; i++) {
		add(temp[i]);
		size--;
	}
	delete[] temp;
}

bool HashTable::add(BankAccount bankAccount) {
	if ((double)size / length >= 0.75) {
		resize();
	}
	if (find(bankAccount.keyNumber).keyNumber != 0) {
		return false;
	}
	int i = 0, hash = hashFunc(bankAccount.keyNumber);
	while (hashTable[(hash + coefA * i + coefB * i * i) % length].keyNumber != 0) {
		i++;
	}
	hashTable[(hash + coefA * i + coefB * i * i) % length] = bankAccount;
	size++;
	return true;
}

bool HashTable::remove(int keyNumber) {
	if (size == 0) {
		return false;
	}
	int i = 0, hash = hashFunc(keyNumber), delta = 1;
	while (hashTable[(hash + coefA * i + coefB * i * i) % length].keyNumber != keyNumber && hashTable[(hash + coefA * i + coefB * i * i) % length].keyNumber != 0) {
		i++;
	}
	if (hashTable[(hash + coefA * i + coefB * i * i) % length].keyNumber == 0) {
		return false;
	}
	i++;
	while (hashTable[(hash + coefA * i + coefB * i * i) % length].keyNumber != 0) {
		if (hashFunc(hashTable[(hash + coefA * i + coefB * i * i) % length].keyNumber) != hash) {
			delta++;
			i++;
			continue;
		}
		hashTable[(hash + coefA * (i - delta) + coefB * (i - delta) * (i - delta)) % length] = hashTable[(hash + coefA * i + coefB * i * i) % length];
		delta = 1;
		i++;
	}
	hashTable[(hash + coefA * (i - delta) + coefB * (i - delta) * (i - delta)) % length] = BankAccount();
	return true;
}

BankAccount HashTable::find(int keyNumber) {
	if (size == 0) {
		return BankAccount();
	}
	int i = 0, hash = hashFunc(keyNumber);
	while (hashTable[(hash + coefA * i + coefB * i * i) % length].keyNumber != keyNumber && hashTable[(hash + coefA * i + coefB * i * i) % length].keyNumber != 0) {
		i++;
	}
	return hashTable[(hash + coefA * i + coefB * i * i) % length];
}

void HashTable::print() {
	if (size == 0) {
		std::cout << "Пусто.\n";
	}
	for (int i = 0; i < length; i++) {
		if (hashTable[i].keyNumber != 0) {
			std::cout << i + 1 << ") \t|" << hashTable[i].keyNumber << "|\t|" << std::setw(31) << hashTable[i].fullName << "|\t|" << std::setw(40) << hashTable[i].address << "|\n";
		}
	}
}