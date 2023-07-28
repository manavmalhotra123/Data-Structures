// Selection Sort - minimum dhundo and usko utha ke aage aage rkhdo arram se

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print_vector(const std::vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}

void selection_sort(std::vector<int> &v)
{
    int mini = 0;
    int rounds = 0;
    for (int i = 0; i < v.size(); i++)
    {
        mini = i;
        for (int j = i + 1; j < v.size(); j++)
        {
            if (v[j] < v[mini])
            {
                mini = j;
            }
        }
        rounds++;
        std::cout << "Round: " << rounds << std::endl;

        if (v[mini] == v[i])
        {
            std::cout << "No swapping needed" << std::endl;
        }
        else
        {
            cout << "Swapping between " << v[i] << " and " << v[mini] << endl;
        }

        std::swap(v[i], v[mini]);
        cout << "Round " << rounds << " Result: " << endl;
        ;
        print_vector(v);
        cout << endl;
        cout << "-----------------------------------------------------------------------" << endl;
    }
}

int main()
{
    std::vector<int> v = {1, 2, 3, 5, 9, 10, 13, 14, 11};
    print_vector(v);
    selection_sort(v);

    return 0;
}

void Sort(vector<int> &v)
{
    int mini = 0;

    for (int i = 0; i < v.size(); i++)
    {
        mini = i;
        for (int j = i + 1; j < v.size(); j++)
        {
            if (v[mini] < v[j])
            {
                mini = j;
            }
        }
        if (mini != i)
        {
            swap(v[mini], v[i]);
        }
    }
}