#include "Header.h"


void generateFile(unsigned int n)
{
	std::ofstream outf("text.bin");
	srand(time(0));
	std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
	unsigned int randomNumber;
	std::vector<unsigned int> numbers;
	for (int i = 0; i < n; i++)
	{
		randomNumber = 100000 + rand() * 33 + rand();
		while (std::count(numbers.begin(), numbers.end(), randomNumber) != 0 || randomNumber > 1000000)
		{
			randomNumber = 100000 + rand() * 33 + rand();
		}
		numbers.push_back(randomNumber);
		outf << std::to_string(randomNumber) << "\t";
		for (int j = 0; j < 5 + rand() % 10; j++)
		{
			outf << alphabet[rand() % 26];
		}
		outf << "\n";
	}
	outf.close();
}


std::string linearSearch(unsigned int key)
{
	std::ifstream inf("text.bin");
	std::string line, stringNumber, name;
	for (std::getline(inf, line); !inf.eof(); std::getline(inf, line))
	{
		stringNumber = line.substr(0, 6);
		if (std::stoi(stringNumber) == key)
		{
			name = line.substr(7);
			inf.close();
			return name;
		}
	}
	inf.close();
	return "-";
}


bool compare(std::pair<unsigned int, unsigned int> p1, std::pair<unsigned int, unsigned int> p2)
{
	return p1.first < p2.first;
}


std::vector<std::pair<unsigned int, unsigned int>> createTable()
{
	std::ifstream inf("text.bin");
	std::string line, stringNumber;
	std::vector<std::pair<unsigned int, unsigned int>> table;
	unsigned int shift = 0;
	for (std::getline(inf, line); !inf.eof(); std::getline(inf, line))
	{
		stringNumber = line.substr(0, 6);
		table.push_back(std::pair<unsigned int, unsigned int>(stoi(stringNumber), shift));
		shift = inf.tellg();
	}
	sort(table.begin(), table.end(), compare);
	inf.close();
	return table;
}


int binarySearch(std::vector<std::pair<unsigned int, unsigned int>> table, unsigned int key)
{
	unsigned int i = table.size() / 2, shift = table.size() / 2;
	while (shift != 0)
	{
		if (key < table[i].first)
		{
			i -= (shift + 1) / 2;
			shift /= 2;
		}
		else if (key > table[i].first)
		{
			i += (shift + 1) / 2;
			shift /= 2;
		}
		if (key == table[i].first)
		{
			return table[i].second;
		}
	}
	return -1;
}


std::string getName(int shift)
{
	if (shift == -1)
	{
		return "-";
	}
	std::string line, name;
	std::ifstream inf("text.bin");
	inf.seekg(shift);
	getline(inf, line);
	name = line.substr(7);
	inf.close();
	return name;
}