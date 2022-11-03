#include "BigReal.h"
#include "BigDecimalIntClass.h"

//string beforePoint, afterPoint;
//int beforePointSize, afterPointSize;
//char numSign;

BigReal :: BigReal (double realNumber){
    string strReal = to_string(realNumber);
    int index = strReal.find('.');
    if (strReal[0]== '+' || strReal[0] =='-'){
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
    if (realNumber[0]== '+' || realNumber[0] =='-'){
        numSign = realNumber[0];
        beforePoint = realNumber.substr(1,index-1);
        afterPoint = realNumber.substr(index+1);
        beforePointSize = realNumber.substr(1,index-1).size();
        afterPointSize = realNumber.substr(index+1).size();
    }
    else{
        numSign ='+';
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
