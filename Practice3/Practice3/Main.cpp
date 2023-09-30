#include "HashTable.h"


int main() {
	setlocale(LC_ALL, "rus");
	int coefA, coefB, choise = -1, keyNumber;
	BankAccount found;
	std::string fileName, fullName, address;
	std::cout << "������� ������������ ������������� ������������: ";
	std::cin >> coefA >> coefB;
	HashTable hashTable(coefA, coefB);
	std::cout << "\n����.\n1 - ������ ������ � �����\n2 - �������� �������\n3 - ������� �������\n4 - ����� �������\n5 - ������� ���-�������\n0 - �����\n\n";
	while (choise != 0) {
		std::cin >> choise;
		switch (choise) {
		case 0:
			break;
		case 1:
			std::cout << "������� �������� �����: ";
			std::getline(std::cin, fileName);
			std::getline(std::cin, fileName);
			hashTable.readFromFile(fileName);
			std::cout << "������� ���������.\n";
			break;
		case 2:
			std::cout << "������� ���� ������: ";
			std::cin >> keyNumber;
			std::cout << "������� ���: ";
			getline(std::cin, fullName);
			getline(std::cin, fullName);
			std::cout << "������� �����: ";
			getline(std::cin, address);
			if (hashTable.add(BankAccount(keyNumber, fullName, address))) {
				std::cout << "������ ���������.\n";
			}
			else {
				std::cout << "���� ������ ������ ���� ����������.\n";
			}
			break;
		case 3:
			std::cout << "������� ���� ������: ";
			std::cin >> keyNumber;
			if (hashTable.remove(keyNumber)) {
				std::cout << "������ �������.\n";
			}
			else {
				std::cout << "������ ����� ���.\n";
			}
			break;
		case 4:
			std::cout << "������� ���� ������: ";
			std::cin >> keyNumber;
			found = hashTable.find(keyNumber);
			if (found.keyNumber != 0) {
				std::cout << "��������� ������: |" << found.keyNumber << "|\t|" << found.fullName << "|\t|" << found.address << "|\n";
			}
			else {
				std::cout << "������ ����� ���.\n";
			}
			break;
		case 5:
			hashTable.print();
			break;
		default:
			std::cout << "�������� ����.\n";
			break;
		}
	}
		

	return 0;
}