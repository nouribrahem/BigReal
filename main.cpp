#include "BigReal.h"
#include "BigDecimalIntClass.h"

int main()
{
    BigReal num1("12.234");
    BigReal num2("12.2345");
    cout << (num1 > num2) << " " << (num1 < num2) << " " << (num1 == num2);
    return 0;
}
