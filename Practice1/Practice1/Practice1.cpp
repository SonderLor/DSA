#include "Header.h"


int main()
{
    setlocale(LC_ALL, "Russian");
    int answer = 1;
    unsigned int x, begin, end;
    std::cout << "Введите номер задания:\n"
        "1 - установить 5-й бит произвольного целого числа в 0\n"
        "2 - установить 7-й бит произвольного целого числа в 1\n"
        "3 - код листинга 1\n"
        "4 - сортировка с помощью битового массива в виде числа типа unsigned char (значения от 0 до 7)\n"
        "5 - сортировка с помощью битового массива в виде числа типа unsigned long long (значения от 0 до 63)\n"
        "6 - сортировка с помощью битового массива чисел типа unsigned char (значения от 0 до 63)\n"
        "7 - сортировка с помощью битового массива файла с числами\n";
    while (answer != 0)
    {
        std::cin >> answer;
        switch (answer)
        {
        case 1:
            std::cout << "Введите число от 0 до 255: ";
            std::cin >> x;
            while (x < 0 || x > 255)
            {
                std::cout << "Попробуйте ещё раз: ";
                std::cin >> x;
            }
            task_1_1(x);
            break;
        case 2:
            std::cout << "Введите число от 0 до 255: ";
            std::cin >> x;
            while (x < 0 || x > 255)
            {
                std::cout << "Попробуйте ещё раз: ";
                std::cin >> x;
            }
            task_1_2(x);
            break;
        case 3:
            task_1_3();
            break;
        case 4:
            std::cout << "Введите количество элементов массива от 2 до 8: ";
            std::cin >> x;
            while (x < 2 || x > 8)
            {
                std::cout << "Попробуйте ещё раз: ";
                std::cin >> x;
            }
            task_2_1(x);
            break;
        case 5:
            std::cout << "Введите количество элементов массива от 2 до 64: ";
            std::cin >> x;
            while (x < 2 || x > 64)
            {
                std::cout << "Попробуйте ещё раз: ";
                std::cin >> x;
            }
            task_2_2(x);
            break;
        case 6:
            std::cout << "Введите количество элементов массива от 2 до 64: ";
            std::cin >> x;
            while (x < 2 || x > 64)
            {
                std::cout << "Попробуйте ещё раз: ";
                std::cin >> x;
            }
            task_2_3(x);
            break;
        case 7:
            std::cout << "Введите количество чисел в файле: ";
            std::cin >> x;
            std::cout << "Введите диапазон чисел (начальное и конечное значения): ";
            std::cin >> begin >> end;
            generateFileWithNumbers(x, begin, end);
            std::cout << "Файл сгенерирован\n";
            task_3_1(begin + x + 1);
            break;
        default:
            break;
        }
    }
    
    return 0;
}