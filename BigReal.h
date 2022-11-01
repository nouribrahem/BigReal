#ifndef BIGREAL_H_INCLUDED
#define BIGREAL_H_INCLUDED

#include <iostream>
#include <regex>
#include <string>
#include <algorithm>

using namespace std;

class BigReal
{
private:
        string beforePoint, afterPoint;
	int beforePointSize, afterPointSize;
	char numSign;
protected:
	bool isValidStrNum(const string& num);
	BigReal addTwoStrNums(const BigReal& anotherDec);
	BigReal removeZeroes(BigReal& number);
public:
	BigReal (double realNumber = 0.0); // Default constructor
	BigReal (const string& realNumber);
	//BigReal (const BigDecimalInt& bigInteger);
	BigReal (const BigReal& other);  // Copy constructor
	BigReal (BigReal&& other);   // Move constructor
	BigReal& operator= (const BigReal& other); // Assignment operator
	BigReal& operator= (BigReal&& other); // Move assignment
	BigReal operator+ (const BigReal& other);
	BigReal operator- (const BigReal& other);
	bool operator<  (const BigReal& anotherReal);
	bool operator>  (const BigReal& anotherReal);
	bool operator== (const BigReal& anotherReal);
	int size();
	int sign();
	friend ostream& operator << (ostream& out, const BigReal& num);
	friend istream& operator >> (istream& out, const BigReal& num);
};


#endif // BIGREAL_H_INCLUDED
