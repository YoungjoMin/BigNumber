# include "BigUnsignedInt.hpp"
# include <iostream>
# include <fstream>
# include <ctime>
#include <Windows.h>

int testSpeed()
{
	clock_t sclock;
	clock_t eclock;
	BigUnsignedInt num1 = 1;
	std::string result;
	num1 <<= 10000;
	//num1 -= 1;
	sclock = clock();
	result = num1.getDexStr();
	eclock = clock();
	std::cout << result << std::endl;

	std::cout << "time : " << (double)(eclock - sclock) / CLOCKS_PER_SEC << "sec" << std::endl;
	std::getchar(); std::getchar();
	return 0;
}
/*
int testCorrect()
{
clock_t sclock1, eclock1;
clock_t sclock2, eclock2;
BigUnsignedInt num1 = 1;
std::string result1;
std::string result2;
num1 <<= 38000;

sclock1 = clock();
result1 = num1.getDexStr2();
eclock1 = clock();
sclock2 = clock();
result2 = num1.getDexStr3();
eclock2 = clock();
if (result1 != result2) {
std::cout << "something wrong" << std::endl;
std::cout << "answer is :" << result1 << std::endl;
std::cout << "but returned :" << result2 << std::endl;
}
else
std::cout << "result : " << result1 << std::endl;
std::cout << "time : " << (eclock1 - sclock1) << std::endl;
std::cout << "time : " << (eclock2 - sclock2) << std::endl;
std::getchar(); std::getchar();
return 0;
}
*/
void main()
{
	testSpeed();
	return;
}