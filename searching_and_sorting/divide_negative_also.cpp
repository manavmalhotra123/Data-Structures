#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int dividend = -55;
    int divisor = 3;

    int start = 0;
    int end = abs(dividend);
    int quotient = 0;
    int remainder = 0;

    bool isNegative = false;

    if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0))
    {
        isNegative = true;
    }

    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (mid * abs(divisor) == abs(dividend))
        {
            quotient = mid;
            remainder = 0;
            break;
        }
        else if (mid * abs(divisor) < abs(dividend))
        {
            start = mid + 1;
            quotient = mid;
        }
        else
        {
            end = mid - 1;
        }
    }

    remainder = abs(dividend) - (quotient * abs(divisor));

    if (isNegative)
    {
        quotient = -quotient;
        remainder = -remainder;
    }

    cout << "Quotient: " << quotient << endl;
    cout << "Remainder: " << remainder << endl;

    return 0;
}
