#include "HashTable.h"


int main() {
	setlocale(LC_ALL, "rus");
	int coefA, coefB, choise = -1, keyNumber;
	BankAccount found;
	std::string fileName, fullName, address;
	std::cout << "Введите коэффициенты квадратичного пробирования: ";
	std::cin >> coefA >> coefB;
	HashTable hashTable(coefA, coefB);
	std::cout << "\nМеню.\n1 - ввести данные с файла\n2 - добавить элемент\n3 - удалить элемент\n4 - найти элемент\n5 - вывести хэш-таблицу\n0 - выйти\n\n";
	while (choise != 0) {
		std::cin >> choise;
		switch (choise) {
		case 0:
			break;
		case 1:
			std::cout << "Введите название файла: ";
			std::getline(std::cin, fileName);
			std::getline(std::cin, fileName);
			hashTable.readFromFile(fileName);
			std::cout << "Таблица заполнена.\n";
			break;
		case 2:
			std::cout << "Введите ключ записи: ";
			std::cin >> keyNumber;
			std::cout << "Введите ФИО: ";
			getline(std::cin, fullName);
			getline(std::cin, fullName);
			std::cout << "Введите адрес: ";
			getline(std::cin, address);
			if (hashTable.add(BankAccount(keyNumber, fullName, address))) {
				std::cout << "Запись добавлена.\n";
			}
			else {
				std::cout << "Ключ записи должен быть уникальным.\n";
			}
			break;
		case 3:
			std::cout << "Введите ключ записи: ";
			std::cin >> keyNumber;
			if (hashTable.remove(keyNumber)) {
				std::cout << "Запись удалена.\n";
			}
			else {
				std::cout << "Такого ключа нет.\n";
			}
			break;
		case 4:
			std::cout << "Введите ключ записи: ";
			std::cin >> keyNumber;
			found = hashTable.find(keyNumber);
			if (found.keyNumber != 0) {
				std::cout << "Найденная запись: |" << found.keyNumber << "|\t|" << found.fullName << "|\t|" << found.address << "|\n";
			}
			else {
				std::cout << "Такого ключа нет.\n";
			}
			break;
		case 5:
			hashTable.print();
			break;
		default:
			std::cout << "Неверный ввод.\n";
			break;
		}
	}
		

	return 0;
}