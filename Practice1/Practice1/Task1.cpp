#include "Header.h"


void task_1_1(unsigned char x)
{
	unsigned char m = 1;
	x &= (~(m << 4));
	std::cout << "Результат: " << static_cast<int>(x) << "\n";
}


void task_1_2(unsigned char x)
{
	unsigned char m = 1;
	x |= ((m << 6));
	std::cout << "Результат: " << static_cast<int>(x) << "\n";
}


void task_1_3()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	unsigned int x = 25;
	const int n = sizeof(int) * 8;
	unsigned maska = (1 << n - 1);
	std::cout << "Haчальный вид маски: " << std::bitset<n>(maska) << "\n";
	std::cout << "Peзyльтат: ";
	for (int i = 1; i <= n; i++)
	{
		std::cout << ((x & maska) >> (n - i));
		maska = maska >> 1;
	}
	std::cout << "\n";
	system("pause");
}