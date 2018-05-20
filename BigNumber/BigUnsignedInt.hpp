#pragma once
# include <memory>
# include <algorithm>
# include <string>
# include <iostream>
# include <cmath>


class BigUnsignedInt
{
	using BaseData = unsigned long long;
private:
	static bool isOutStringHexMode; //default false
	constexpr static size_t BaseDataLen = sizeof(BaseData) * 8;

	BaseData * data;
	unsigned int dataSize;
	unsigned int numLength; // number of using data block

	void IncreaseDataSize(unsigned int newSize);
	bool getNthBit(unsigned int n) const;

public:
	BigUnsignedInt(); // default numeric value = 0
	BigUnsignedInt(int num); //using negative number throws underflow error
	BigUnsignedInt(unsigned int num);
	BigUnsignedInt(long long num); //using negative number throws underflow error
	BigUnsignedInt(unsigned long long num);
	BigUnsignedInt(const BigUnsignedInt& num);
	BigUnsignedInt(BigUnsignedInt && num);
	BigUnsignedInt(const std::string& str);

	virtual ~BigUnsignedInt();

	unsigned int floorLog2() const; // if this class == 0 then returns (unsigned int)-1
	static void stringConversionHexMod(bool sign = false);

	friend BigUnsignedInt operator+(const BigUnsignedInt& num1, const BigUnsignedInt& num2);
	friend BigUnsignedInt operator-(const BigUnsignedInt& num1, const BigUnsignedInt& num2);
	friend BigUnsignedInt operator*(const BigUnsignedInt& num1, const BigUnsignedInt& num2);
	friend BigUnsignedInt operator/(const BigUnsignedInt& num1, const BigUnsignedInt& num2);
	friend BigUnsignedInt operator%(const BigUnsignedInt& num1, const BigUnsignedInt& num2);


	BigUnsignedInt& operator++();
	BigUnsignedInt& operator--(); // num = 0 then throws underflow error

	BigUnsignedInt operator++(int);
	BigUnsignedInt operator--(int); // num = 0 then throws underflow error

	BigUnsignedInt& operator=(const BigUnsignedInt& num);
	BigUnsignedInt& operator=(BigUnsignedInt && num);

	BigUnsignedInt& operator+=(const BigUnsignedInt& num);
	BigUnsignedInt& operator-=(const BigUnsignedInt& num); // num is bigger then throws underflow error
	BigUnsignedInt& operator*=(const BigUnsignedInt& num);
	BigUnsignedInt& operator/=(const BigUnsignedInt& num);
	BigUnsignedInt& operator%=(const BigUnsignedInt& num);

	friend BigUnsignedInt operator<<(const BigUnsignedInt& num, unsigned int k);
	friend BigUnsignedInt operator<<(const BigUnsignedInt& num, int k);
	friend BigUnsignedInt operator>>(const BigUnsignedInt& num, unsigned int k);
	friend BigUnsignedInt operator>>(const BigUnsignedInt& num, int k);
	friend BigUnsignedInt operator&(const BigUnsignedInt& num1, const BigUnsignedInt& num2);
	friend BigUnsignedInt operator|(const BigUnsignedInt& num, const BigUnsignedInt& num2);
	friend BigUnsignedInt operator^(const BigUnsignedInt& num, const BigUnsignedInt& num2);

	BigUnsignedInt& operator<<=(unsigned int k);
	BigUnsignedInt& operator<<=(int k);
	BigUnsignedInt& operator>>=(unsigned int k);
	BigUnsignedInt& operator>>=(int k);
	BigUnsignedInt& operator&=(const BigUnsignedInt& num);
	BigUnsignedInt& operator|=(const BigUnsignedInt& num);
	BigUnsignedInt& operator^=(const BigUnsignedInt& num);//xor function

	friend bool operator<(const BigUnsignedInt& num1, const BigUnsignedInt& num2);
	friend bool operator>(const BigUnsignedInt& num1, const BigUnsignedInt& num2);
	friend bool operator<=(const BigUnsignedInt& num1, const BigUnsignedInt& num2);
	friend bool operator>=(const BigUnsignedInt& num1, const BigUnsignedInt& num2);
	friend bool operator==(const BigUnsignedInt& num1, const BigUnsignedInt& num2);
	friend bool operator!=(const BigUnsignedInt& num1, const BigUnsignedInt& num2);

	friend std::ostream& operator<<(std::ostream& os, const BigUnsignedInt& num);
	friend std::istream& operator>>(std::istream& is, BigUnsignedInt& num);

	operator int() const = delete;
	bool operator!() const;
	operator bool() const;
	operator std::string() const;


	BigUnsignedInt pow(const BigUnsignedInt& base, unsigned int exp);
	BigUnsignedInt pow(const BigUnsignedInt& base, const BigUnsignedInt& exp);
	BigUnsignedInt hyperOperation(const BigUnsignedInt& num1, const BigUnsignedInt& num2, int k);

	std::string getHexStr() const;
	std::string getDexStr() const;
};