#include "BigReal.h"
#include "BigDecimalIntClass.h"

//string beforePoint, afterPoint;
//int beforePointSize, afterPointSize;
//char numSign;

bool BigReal::isValidStrNum(const string& num)
{
    regex match("[+-]?[0-9]?[.][0-9]+");
    if (regex_match(num, match))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
BigReal::BigReal()
{
    
}
BigReal :: BigReal (double realNumber){
    string strReal = to_string(realNumber);
    int index = strReal.find('.');
    if (strReal[0]== '+' || strReal[0] =='-'){
        wholeNum = strReal.substr(1);
        numSign = strReal[0];
        beforePoint = strReal.substr(1,index);
        afterPoint = strReal.substr(index+1);
        beforePointSize = strReal.substr(1,index).size();
        afterPointSize = strReal.substr(index+1).size();
    }
    else{
        numSign ='+';
        beforePoint = strReal.substr(0,index);
        afterPoint = strReal.substr(index+1);
        beforePointSize = strReal.substr(0,index).size();
        afterPointSize = strReal.substr(index+1).size();
    }
    cout << numSign << beforePoint << '.'<< afterPoint<<'\n';

}
BigReal :: BigReal (const string& realNumber){
    int index = realNumber.find('.');
//+12.2345
    if (realNumber[0]== '+' || realNumber[0] =='-'){
        numSign = realNumber[0];
        wholeNum = realNumber.substr(1);
        beforePoint = realNumber.substr(1,index-1);
        afterPoint = realNumber.substr(index+1);
        beforePointSize = realNumber.substr(1,index-1).size();
        afterPointSize = realNumber.substr(index+1).size();
    }
    else{
        numSign ='+';
        wholeNum = realNumber.substr(0);
        beforePoint = realNumber.substr(0,index);
        afterPoint = realNumber.substr(index+1);
        beforePointSize = realNumber.substr(0,index).size();
        afterPointSize = realNumber.substr(index+1).size();
    }
    cout << numSign << beforePoint << '.'<< afterPoint<< '\n';
}
BigReal :: BigReal (BigDecimalInt& bigInteger){
    afterPoint = "0";
    beforePoint = bigInteger.getNumber();
    beforePointSize = beforePoint.size();
    afterPointSize = afterPoint.size();
    if(bigInteger.sign()){
        numSign='+';
    }
    else {
        numSign = '-';
    }
    cout << numSign << beforePoint << '.'<< afterPoint<<'\n';

}
bool BigReal::operator<(const BigReal& anotherReal)
{
    if (this->numSign == '-' && anotherReal.numSign == '+')
    {
        return true;
    }
    else if(this->numSign == '+' && anotherReal.numSign == '-')
    {
        return false;
    }
    else if (this->numSign == anotherReal.numSign && anotherReal.numSign == '-')
    {
        if(this->beforePointSize < anotherReal.beforePointSize)
            {return false;}
        else if (this->beforePointSize > anotherReal.beforePointSize)
            {return true;}
        else
        {
            if(this->beforePoint > anotherReal.beforePoint)
            {
                return true;
            }
            else if (this->beforePoint < anotherReal.beforePoint)
            {
                return false;
            }
            else
            {
                if (this->afterPointSize > anotherReal.afterPointSize)
                {
                    return true;
                }
                else if (this->afterPointSize < anotherReal.afterPointSize)
                {
                    return false;
                }
                else
                {
                    if (this->afterPoint > anotherReal.afterPoint)
                    {
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }
    }
    else if(this->numSign == anotherReal.numSign && anotherReal.numSign == '+')
    {
        if(this->beforePointSize < anotherReal.beforePointSize)
            {return true;}
        else if (this->beforePointSize > anotherReal.beforePointSize)
            {return false;}
        else
        {
            if(this->beforePoint < anotherReal.beforePoint)
            {
                return true;
            }
            else if (this->beforePoint > anotherReal.beforePoint)
            {
                return false;
            }
            else
            {
                if (this->afterPointSize < anotherReal.afterPointSize)
                {
                    return true;
                }
                else if (this->afterPointSize > anotherReal.afterPointSize)
                {
                    return false;
                }
                else
                {
                    if (this->afterPoint < anotherReal.afterPoint)
                    {
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                }
        }
    }
}
}
bool BigReal::operator>(const BigReal& anotherReal)
{
    BigReal cpy = anotherReal;
    return (cpy < *this);
}

// 1.55 1.550

bool BigReal::operator==(const BigReal& anotherReal)
{
    if (this->beforePointSize == anotherReal.beforePointSize && this->afterPointSize == anotherReal.afterPointSize)
    {
        if(this->beforePoint == anotherReal.beforePoint && this->afterPoint == anotherReal.afterPoint && this->numSign == anotherReal.numSign)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }

}
BigReal BigReal::operator= (const BigReal& other)
{
    this->afterPoint = other.afterPoint;
    this->beforePoint = other.beforePoint;
    this->numSign = other.numSign;
    this->beforePointSize = other.beforePointSize;
    this->afterPointSize = other.afterPointSize;
    return *this;
}

ostream& operator << (ostream& out, const BigReal& num)
{
    if (num.numSign == '-')
    {
        out << num.numSign;
    }
    out << num.wholeNum;
    return out;
}
istream& operator >> (istream& in, BigReal& num)
{
    in >> num.wholeNum;
    BigReal(num.wholeNum);
    return in;
}

BigReal BigReal:: operator+ (const BigReal& other)
{
    return addTwoStrNums(other);
}

BigReal BigReal:: addTwoStrNums(const BigReal& other)
{
    BigReal result , firstNum = *this , secondNum = other;
    result.wholeNum="";
    int digit , carry = 0;
    if(firstNum.beforePointSize<secondNum.beforePointSize)
    {
        for(int i=0;i<secondNum.beforePointSize-firstNum.beforePointSize;i++)
        {
            firstNum.wholeNum.insert(0 , 1 , '0');
        }
    }
    else if(firstNum.beforePointSize>secondNum.beforePointSize)
    {
        for(int i=0;i<firstNum.beforePointSize-secondNum.beforePointSize;i++)
        {
            secondNum.wholeNum.insert(0 , 1 , '0');
        }
    }

    if(firstNum.afterPointSize<secondNum.afterPointSize)
    {
        for(int i=0;i<secondNum.afterPointSize-firstNum.afterPointSize;i++)
        {
            firstNum.wholeNum.push_back('0');
        }
    }
    else if(firstNum.afterPointSize>secondNum.afterPointSize)
    {
        for(int i=0;i<firstNum.afterPointSize-secondNum.afterPointSize;i++)
        {
            secondNum.wholeNum.push_back('0');
        }
    }
    cout<<firstNum.wholeNum.size()<<" "<<secondNum.wholeNum.size()<<endl;
    /////////////////////////////////////////////////////////////////

    if(firstNum.numSign==secondNum.numSign)
    {
        for(int i=secondNum.wholeNum.size()-1;i>=0;i--)
        {
          if(firstNum.wholeNum[i]=='.')
          {
              result.wholeNum.push_back('.');
              i--;
          }
          digit = (firstNum.wholeNum[i]-'0') + (secondNum.wholeNum[i]-'0')+carry;
          result.wholeNum.push_back(digit%10 + '0');
          carry = digit/10;
        }
        if(carry)
        {
            result.wholeNum.push_back(carry + '0');
        }
        result.numSign = firstNum.numSign;
    }
    else
    {
        if(firstNum.wholeNum>secondNum.wholeNum)
        {
          result.numSign = firstNum.numSign;
        }
        else if(firstNum.wholeNum == secondNum.wholeNum)
        {
            result.wholeNum = "0";
            return result;
        }
        else
        {
           swap(firstNum.wholeNum,secondNum.wholeNum);
           result.numSign = secondNum.numSign;
        }
        for(int i=secondNum.wholeNum.size()-1;i>=0;i--)
        {
            if(firstNum.wholeNum[i]=='.')
            {
              result.wholeNum.push_back('.');
              i--;
            }
          digit = (firstNum.wholeNum[i]-'0') - (secondNum.wholeNum[i]-'0')-carry;
          if(digit<0)
          {
              digit += 10;
              carry = 1;
          }
          else
          {
              carry = 0;
          }
          result.wholeNum.push_back(digit + '0');
        }
    }
    reverse(result.wholeNum.begin() , result.wholeNum.end());
    return result;
}

BigReal BigReal:: operator- (const BigReal& other)
{
    BigReal NNA = other;
    if(NNA.numSign == '-')
    {
        NNA.numSign = '+';
    }
    else
    {
        NNA.numSign = '-';
    }
    return addTwoStrNums(NNA);
}

