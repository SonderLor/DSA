#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <ctime>
#include <locale>

std::vector<int> findLISSlowVersion(std::vector<int> a) {
    int n = a.size();
    std::vector<int> prev(n, -1);
    std::vector<int> d(n, 1);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (a[j] < a[i] && d[j] + 1 > d[i]) {
                d[i] = d[j] + 1;
                prev[i] = j;
            }
        }
    }

    int pos = 0;
    int length = d[0];
    for (int i = 0; i < n; ++i) {
        if (d[i] > length) {
            pos = i;
            length = d[i];
        }
    }

    std::vector<int> answer;
    while (pos != -1) {
        answer.push_back(a[pos]);
        pos = prev[pos];
    }
    std::reverse(answer.begin(), answer.end());

    return answer;
}

std::vector<int> findLISFastVersion(std::vector<int> a) {
    int n = a.size();
    const int INF = 1e9;
    std::vector<int> d(n + 1, INF);
    std::vector<int> pos(n + 1);
    std::vector<int> prev(n, -1);
    int length = 0;

    pos[0] = -1;
    d[0] = -INF;
    for (int i = 0; i < n; ++i) {
        int j = std::lower_bound(d.begin(), d.end(), a[i]) - d.begin();
        if (d[j - 1] < a[i] && a[i] < d[j]) {
            d[j] = a[i];
            pos[j] = i;
            prev[i] = pos[j - 1];
            length = std::max(length, j);
        }
    }

    std::vector<int> answer;
    int p = pos[length];
    while (p != -1) {
        answer.push_back(a[p]);
        p = prev[p];
    }
    std::reverse(answer.begin(), answer.end());

    return answer;
}


int main() {
    std::locale::global(std::locale(""));
    srand(std::time(0));

    int n;
    std::cout << "Введите размер последовательности: ";
    std::cin >> n;
    std::vector<int> sequence;
    for (int i = 0; i < n; ++i) {
        sequence.push_back(rand() % 2001 - 1001);
    }
    std::ofstream inputFile("input.txt");
    if (inputFile.is_open()) {
        for (int num : sequence) {
            inputFile << num << " ";
        }
        inputFile.close();
    }

    auto startSlow = std::chrono::steady_clock::now();
    std::vector<int> slowResult = findLISSlowVersion(sequence);
    auto endSlow = std::chrono::steady_clock::now();
    std::chrono::duration<double, std::micro> slowDuration = endSlow - startSlow;

    auto startFast = std::chrono::steady_clock::now();
    std::vector<int> fastResult = findLISFastVersion(sequence);
    auto endFast = std::chrono::steady_clock::now();
    std::chrono::duration<double, std::micro> fastDuration = endFast - startFast;


    std::cout << "----------------------" << std::endl;
    std::cout << "Медленный метод (LIS), сложность O(N^2):" << std::endl;
    for (int num : slowResult) {
        std::cout << num << " ";
    }
    std::cout << "\nРазмер подпоследовательности: " << slowResult.size() << std::endl;
    std::cout << "(Время: " << slowDuration.count() << " мкс)" << std::endl;

    std::cout << "----------------------" << std::endl;
    std::cout << "Быстрый метод (LIS), сложность O(NlogN):" << std::endl;
    for (int num : fastResult) {
        std::cout << num << " ";
    }
    std::cout << "\nРазмер подпоследовательности: " << fastResult.size() << std::endl;
    std::cout << "(Время: " << fastDuration.count() << " мкс)" << std::endl;

    std::cout << "----------------------" << std::endl;
    std::cout << "Начальную последовательность можно посмотреть в файле input.txt" << std::endl;

    return 0;
}