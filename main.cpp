#include "BigReal.h"
#include "BigDecimalIntClass.h"

int main()
{
    BigReal num1("12.234");
    BigReal num2("12.4523");

//    cout << (num1 > num2) << " " << (num1 < num2) << " " << (num1 == num2);
    BigReal num3 = BigReal("9.0");
    BigReal b(BigReal("0.9"));
    //BigReal NUM4 = num1;
    cout  << endl <<num3 <<  endl << b;
    return 0;
}
