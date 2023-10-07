#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <windows.h>
#include <ctime>


bool firstTask() {
	std::string text;
	char temp;

	std::ifstream file("test1.txt");
	std::getline(file, text);
	file.close();

	std::cout << "Исходная строка:\n" << text << "\n\n";

	for (int i = 0; i < text.length(); i++) {
		temp = text[i];
		if (!isalpha(temp) && !isdigit(temp) && temp != ' ') {
			if (temp == '.') {
				text.replace(i, 1, " ");
			}
			else {
				text.replace(i, 1, "");
			}
		}
	}

	std::cout << "Полученная строка:\n" << text << "\n";

	return true;
}


bool secondTask() {
	std::string text;

	std::ifstream file("test2.txt");
	std::getline(file, text);
	file.close();

	std::cout << "Исходная строка:\n" << text << "\n\n";

	int n = text.length(), j;
	std::vector<int> prefix(n);

	for (int i = 1; i < n; i++) {
		j = prefix[i - 1];
		while (j > 0 && text[i] != text[j]) {
			j = prefix[j - 1];
		}
		if (text[i] == text[j]) {
			j++;
		}
		prefix[i] = j;
	}

	std::cout << "Полученный префикс-массив:\n";
	for (int i = 0; i < n; i++) {
		std::cout << prefix[i] << " ";
	}
	std::cout << "\n";

	return true;
}


void generateFile(int length) {
	srand(time(nullptr));
	std::ofstream file("test2.txt");
	char sym;
	for (int i = 0; i < length; i++) {
		sym = 65 + rand() % 3;
		file << sym;
	}
	file.close();
}


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	generateFile(100);
	secondTask();

	return 0;
}