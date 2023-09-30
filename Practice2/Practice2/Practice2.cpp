#include "Header.h"


int main()
{
    setlocale(LC_ALL, "Russian");
    unsigned int n, key, shift;

    std::cout << "Кол-во записей: ";
    std::cin >> n;
    generateFile(n);
    std::vector<std::pair<unsigned int, unsigned int>> table = createTable();
    std::cout << "Файл и таблица созданы.\n\nЛинейный поиск.\nКлюч:\t";

    std::cin >> key;
    auto start = std::chrono::steady_clock::now();
    std::cout << "Запись:\t" << linearSearch(key) << "\n";
    auto end = std::chrono::steady_clock::now();
    std::cout << "Время:\t" << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / 1000.0 << "ms\n\nБинарный поиск.\nКлюч:\t";

    std::cin >> key;
    start = std::chrono::steady_clock::now();
    shift = binarySearch(table, key);
    std::cout << "Запись:\t" << getName(shift) << "\n";
    end = std::chrono::steady_clock::now();
    std::cout << "Время:\t" << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / 1000.0 << "ms\n";

    return 0;
}