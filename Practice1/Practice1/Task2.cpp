#include "Header.h"


void task_2_1(unsigned short n)
{
	std::cout << "Введите цифры в количестве " << n << " штук со значениями от 0 до 7 (все цифры должны быть разными): ";
	unsigned char x = 0, mask;
	std::vector<int> a(n, -1);
	for (int i = 0; i < n; i++)
	{
		mask = 1;
		std::cin >> a[i];
		while (a[i] < 0 || a[i] > 7 || std::count(a.begin(), a.end(), a[i]) != 1)
		{
			std::cout << "Попробуйте ещё раз: ";
			for (int j = 0; j < i; j++)
			{
				std::cout << a[j] << " ";
			}
			std::cin >> a[i];
		}
		for (int j = 0; j < a[i]; j++)
		{
			mask <<= 1;
		}
		x |= mask;
	}
	for (int i = 0, number = 0; x != 0; x >>= 1, number++)
	{
		if ((x & 1) == 1)
		{
			a[i] = number;
			i++;
		}
	}
	std::cout << "Отсортированный массив: ";
	for (int i = 0; i < n; i++)
	{
		std::cout << a[i] << " ";
	}
	std::cout << "\n";
}


void task_2_2(unsigned short n)
{
	std::cout << "Введите цифры в количестве " << n << " штук со значениями от 0 до 63 (все цифры должны быть разными): ";
	unsigned long long x = 0, mask;
	std::vector<int> a(n, -1);
	for (int i = 0; i < n; i++)
	{
		mask = 1;
		std::cin >> a[i];
		while (a[i] < 0 || a[i] > 63 || std::count(a.begin(), a.end(), a[i]) != 1)
		{
			std::cout << "Попробуйте ещё раз: ";
			for (int j = 0; j < i; j++)
			{
				std::cout << a[j] << " ";
			}
			std::cin >> a[i];
		}
		for (int j = 0; j < a[i]; j++)
		{
			mask <<= 1;
		}
		x |= mask;
	}
	for (int i = 0, number = 0; x != 0; x >>= 1, number++)
	{
		if ((x & 1) == 1)
		{
			a[i] = number;
			i++;
		}
	}
	std::cout << "Отсортированный массив: ";
	for (int i = 0; i < n; i++)
	{
		std::cout << a[i] << " ";
	}
	std::cout << "\n";
}


void task_2_3(unsigned short n)
{
	std::cout << "Введите цифры в количестве " << n << " штук со значениями от 0 до 63 (все цифры должны быть разными): ";
	unsigned char mask;
	std::vector<unsigned char> x(8, 0);
	std::vector<int> a(n, -1);
	for (int i = 0; i < n; i++)
	{
		mask = 1;
		std::cin >> a[i];
		while (a[i] < 0 || a[i] > 63 || std::count(a.begin(), a.end(), a[i]) != 1)
		{
			std::cout << "Попробуйте ещё раз: ";
			for (int j = 0; j < i; j++)
			{
				std::cout << a[j] << " ";
			}
			std::cin >> a[i];
		}
		for (int j = 0; j < a[i] % 8; j++)
		{
			mask <<= 1;
		}
		x[a[i] / 8] |= mask;
	}
	for (int j = 0, i = 0; i < x.size(); i++)
	{
		for (int number = 0; x[i] != 0; x[i] >>= 1, number++)
		{
			if ((x[i] & 1) == 1)
			{
				a[j] = number + 8 * i;
				j++;
			}
		}
	}
	std::cout << "Отсортированный массив: ";
	for (int i = 0; i < n; i++)
	{
		std::cout << a[i] << " ";
	}
	std::cout << "\n";
}