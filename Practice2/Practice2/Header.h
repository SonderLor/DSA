#ifndef HEADER_H


#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <chrono>
#include <ctime>


void generateFile(unsigned int);
std::string linearSearch(unsigned int);
std::vector<std::pair<unsigned int, unsigned int>> createTable();
int binarySearch(std::vector<std::pair<unsigned int, unsigned int>>, unsigned int);
std::string getName(int shift);


#endif