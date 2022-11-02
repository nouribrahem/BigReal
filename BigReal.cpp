#include "BigReal.h"
#include "BigDecimalIntClass.h"

//string beforePoint, afterPoint;
//int beforePointSize, afterPointSize;
//char numSign;

using namespace std;
BigReal :: BigReal (double realNumber){
    string strReal = to_string(realNumber);
    int index = strReal.find('.');
    if (strReal[0]== '+' || strReal[0] =='-'){
        numSign = strReal[0];
        beforePoint = strReal.substr(1,index);
        afterPoint = strReal.substr(index+1);
    }
    else{
        numSign ='+';
        beforePoint = strReal.substr(0,index);
        afterPoint = strReal.substr(index+1);
    }
    cout << numSign << beforePoint << '.'<< afterPoint<<'\n';

}
BigReal :: BigReal (const string& realNumber){
    int index = realNumber.find('.');

    if (realNumber[0]== '+' || realNumber[0] =='-'){
        numSign = realNumber[0];
        beforePoint = realNumber.substr(1,index-1);
        afterPoint = realNumber.substr(index+1);
    }
    else{
        numSign ='+';
        beforePoint = realNumber.substr(0,index-1);
        afterPoint = realNumber.substr(index+1);
    }
    cout << numSign << beforePoint << '.'<< afterPoint<<'\n';
}
BigReal :: BigReal (BigDecimalInt& bigInteger){
    afterPoint = "0";
    beforePoint = bigInteger.getNumber();
    if(bigInteger.sign()){
        numSign='+';
    }
    else {
        numSign = '-';
    }
    cout << numSign << beforePoint << '.'<< afterPoint<<'\n';

}