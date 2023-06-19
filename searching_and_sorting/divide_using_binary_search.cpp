// dividend = quotient * divisor + remainder


#include<iostream>

using namespace std;





int main(int argc, char const *argv[])
{
    int dividend = 55;
    int divisor = 3;

    int start = 0;
    int end = dividend;
    int quotient = 0;
    int remainder = 0;

    while (start <= end)
    {
        int mid = (start + end)/2;

        if (mid * divisor == dividend)
        {
            quotient = mid;
            remainder = 0;
            break;
        }
        else if(mid * divisor < dividend)
        {
            start = mid + 1;
            quotient = mid;
        }
        else
        {
            end = mid - 1;
        }
        
    }
        remainder = dividend - (quotient * divisor);

    cout << "Quotient: " << quotient << endl;
    cout << "Remainder: " << remainder << endl;
    

    return 0;
}
