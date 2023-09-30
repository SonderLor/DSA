#include "Header.h"


void task_3_1(unsigned int n)
{
	auto start = std::chrono::steady_clock::now();
	unsigned char mask;
	std::string stringNumber;
	unsigned char* x = new unsigned char[n / 8 + 1] {};
	std::ifstream fileIn("Numbers.txt");
	for (fileIn >> stringNumber; !fileIn.eof(); fileIn >> stringNumber)
	{
		mask = 1;
		for (int j = 0; j < std::stoi(stringNumber) % 8; j++)
		{
			mask <<= 1;
		}
		x[std::stoi(stringNumber) / 8] |= mask;
	}
	fileIn.close();
	std::ofstream fileOut("SortedNumbers.txt");
	for (int j = 0, i = 0; i < n / 8 + 1; i++)
	{
		for (int number = 0; x[i] != 0; x[i] >>= 1, number++)
		{
			if ((x[i] & 1) == 1)
			{
				fileOut << std::to_string(number + 8 * i) << "\n";
				j++;
			}
		}
	}
	fileOut.close();
	auto end = std::chrono::steady_clock::now();
	std::cout << "Файл отсортирован, время выполнения - " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms\n";
	if (n / 8 + 1 > 1024)
	{
		std::cout << "Объём памяти, использованной массивом, - " << (double) sizeof(unsigned char) * (n / 8 + 1) / 1024 << "Кбайт\n";
	}
	else if (n / 8 + 1 > 1024 * 1024)
	{
		std::cout << "Объём памяти, использованной массивом, - " << (double) sizeof(unsigned char) * (n / 8 + 1) / (1024 * 1024) << "Мбайт\n";
	}
	else
	{
		std::cout << "Объём памяти, использованной массивом, - " << sizeof(unsigned char) * (n / 8 + 1) << "байт\n";
	}
}


void generateFileWithNumbers(unsigned int n, unsigned int begin, unsigned int end)
{
	std::srand(std::time(nullptr));
	std::vector<int> nums;
	for (int i = 0; i < n && begin <= end; i++, begin++)
	{
		nums.push_back(begin);
	}
	auto rng = std::default_random_engine{};
	std::shuffle(nums.begin(), nums.end(), rng);
	std::ofstream fileOut("Numbers.txt");
	for (int num : nums)
	{
		fileOut << std::to_string(num) << "\n";
	}
	fileOut.close();
}