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
	inline static BaseData lo(BaseData num) {return (((BaseData)1 << (BaseDataLen / 2)) - 1)&num;}
	inline static BaseData hi(BaseData num) { return (num >> (BaseDataLen / 2)); }
	static bool isOutStringHexMode; //default false
	constexpr static size_t BaseDataLen = sizeof(BaseData) * 8;

	BaseData * data;
	unsigned int dataSize;
	unsigned int numLength; // number of using data block

	void IncreaseDataSize(unsigned int newSize);
	bool getNthBit(unsigned int n) const;
	void CalculateNumLengthFrom(unsigned int n);
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
	friend BigUnsignedInt operator>>(const BigUnsignedInt& num, unsigned int k);
	friend BigUnsignedInt operator&(const BigUnsignedInt& num1, const BigUnsignedInt& num2);
	friend BigUnsignedInt operator|(const BigUnsignedInt& num, const BigUnsignedInt& num2);
	friend BigUnsignedInt operator^(const BigUnsignedInt& num, const BigUnsignedInt& num2);//xor function

	BigUnsignedInt& operator<<=(unsigned int k);
	BigUnsignedInt& operator>>=(unsigned int k);
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

	operator std::string() const;

	std::string getHexStr() const;
	std::string getDexStr() const;
	friend BigUnsignedInt pow(const BigUnsignedInt& base, const BigUnsignedInt& exp);
};
