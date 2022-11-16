// FCAI –CS213: Object Oriented Programming – 2022 - Assignment 2 - task 1
// Program Name: A2_task1_S23_20210059_20210424_20210436_BigReal.h
// Last Modification Date: 15/11/2022
// Author1 and ID and Section: Nahla Hesham Moustafa           20210424        S23
// Author2 and ID and Section: Arwa Elsaadawy Abdellatif       20210059        S23
// Author3 and ID and Section: Nourhan Elsayed Hassan          20210436        S23
// Purpose: develop a new C++ type (class) that can hold unlimited Real numbers values and performs arithmetic operations on them.
#ifndef BIGREAL_H_INCLUDED
#define BIGREAL_H_INCLUDED

#include <iostream>
#include <regex>
#include <string>
#include <algorithm>
#include "BigDecimalIntClass.h"
using namespace std;

class BigReal
{
private:
    	string beforePoint, afterPoint, wholeNum;
	int beforePointSize, afterPointSize;
	char numSign;
protected:
	bool isValidStrNum(const string& num);
	BigReal addTwoStrNums(const BigReal& anotherDec);
	BigReal setBigReal(char& sign, string& number);
	BigReal removeZeroes(BigReal& number);
public:
	BigReal();
	BigReal (double realNumber); // Default constructor
	BigReal (const string& realNumber);
	BigReal ( BigDecimalInt& bigInteger);
	BigReal (const BigReal& other);  // Copy constructor
	BigReal (BigReal&& other)noexcept;   // Move constructor
	BigReal operator= (const BigReal& other); // Assignment operator
	BigReal& operator= (BigReal&& other)noexcept; // Move assignment
	BigReal operator+ (const BigReal& other);
	BigReal operator- (const BigReal& other);
	bool operator<  (const BigReal& anotherReal);
	bool operator>  (const BigReal& anotherReal);
	bool operator== (const BigReal& anotherReal);
	int size();
	int sign();
	friend ostream& operator << (ostream& out, const BigReal& num);
	friend istream& operator >> (istream& out, BigReal& num);
};


#endif // BIGREAL_H_INCLUDED
