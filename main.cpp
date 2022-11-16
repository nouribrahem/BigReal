// FCAI –CS213: Object Oriented Programming – 2022 - Assignment 2 - task 1
// Program Name: A2_task1_S23_20210059_20210424_20210436_main.cpp
// Last Modification Date: 15/11/2022
// Author1 and ID and Section: Nahla Hesham Moustafa           20210424        S23
// Author2 and ID and Section: Arwa Elsaadawy Abdellatif       20210059        S23
// Author3 and ID and Section: Nourhan Elsayed Hassan          20210436        S23
// Purpose: develop a new C++ type (class) that can hold unlimited Real numbers values and performs arithmetic operations on them.
#include "BigReal.h"
#include "BigDecimalIntClass.h"

int main()
{
    BigReal num1("12.234");
    BigReal num2("12.4523");
    BigReal num7("-12.234");
    BigReal num8("-12.4523");
    BigReal num3 = BigReal("9.0");
    BigReal b(BigReal("0.9"));
    BigReal NUM4 = num1;
    cout << endl << "num1 = " << num1 << endl << "num2 = " << num2 << endl <<"num7 = " << num7 << endl << "num8 = " << num8 << "\n";
    BigReal num5 = num1+num2;
    cout << "num1 > num2  " << (num1 > num2) << "\nnum1 < num2  " << (num1 < num2) << "\nnum1 == num2 " << (num1 == num2) << "\n";
    cout << "num7 > num8  " << (num7 > num8) << "\nnum7 < num8  " << (num7 < num8) << "\nnum7 == num8 " << (num7 == num8) ;
    cout  << endl << "num5 = num1+num2 = " << num5;
    BigReal num6 = num1-num2;
    cout  << endl << "num6 = num1-num2 = " << num6;
    BigReal num9 = num7-num8;
    cout  << endl << "num9 = num7-num8 = " << num9;
    BigReal num10 = num7+num8;
    cout  << endl << "num10 = num7+num8 = " << num10;
    BigReal num11 = num7+num1;
    cout  << endl << "num11 = num7+num1 = " << num11;
    cout  << endl << "NUM4 = " << NUM4 << endl << "num3 = " <<num3 <<  endl << "b = " << b << endl;
    BigReal n1 ("11.9000000000000000000000000000000001");
    BigReal n2 ("2333333333339.1134322222222292");
    BigReal n3 = n1 + n2;
    cout << "n1 = " << n1 << endl << "n2 = " << n2 << endl;
    cout << "n3 = n1 + n2 = "<< n3 << endl ;
    return 0;
}
