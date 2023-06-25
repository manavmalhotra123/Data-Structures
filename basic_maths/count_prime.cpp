// count the prime numbers that are strictly less than n

#include <iostream> // header files
#include <vector> // vector header files

using namespace std; // namespace

// function to check whether the given number is prime or not
bool isPrime(int n)
{
    // returning false as 1 is not prime number
    if (n < 2)
    {
        return false;
    }

    // starting the loop from 2 as prime number always have 1 and n as it's factrors.
    for (int i = 2; i < n; i++)
    {
        // if the number is having any other factor than 1 or n then it will return false as it's not prime
        if (n % i == 0)
        {
            return false;
        }
    }
    // if the number passes all the tests then the number is prime
    return true;
}

// function to count the prime numbers that are strictly less than n along with their list
void list_prime(int n)
{
    vector<int> prime;
    for (int i = 0; i < n; i++)
    {
        if (isPrime(i) == true)
        {
            prime.push_back(i);
        }
    }
    cout << "Prime number lies till " << n << " are " << prime.size() << endl;
    cout << "They are " << endl;
    for (int i = 0; i < prime.size(); i++)
    {
        cout << prime[i] << " ";
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    // decalaration of n 
    int n;
    // taking n as input
    cin >> n;
    // using n as parameter to list_prime function
    list_prime(n);
    return 0;
}
