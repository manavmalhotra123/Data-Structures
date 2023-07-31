/*
You are planning to go on a treasure hunt, and you have a knapsack with a maximum capacity of W units.
Along your journey, you encounter N valuable items, each with a weight and a corresponding value.
Your goal is to determine the maximum total value you can carry in your knapsack by selecting 
a subset of the items to fit into it without exceeding its capacity.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item {
    int value;
    int weight;

    Item(int v, int w) : value(v), weight(w) {}
};

int knapsackGreedy(int weight[], int value[], int n, int capacity) {
    vector<Item> items;
    for (int i = 0; i < n; ++i) {
        items.push_back(Item(value[i], weight[i]));
    }

    // Sort items based on their value-to-weight ratio in descending order
    sort(items.begin(), items.end(), [](const Item& a, const Item& b) {
        return static_cast<double>(a.value) / a.weight > static_cast<double>(b.value) / b.weight;
    });

    int totalValue = 0;
    int remainingCapacity = capacity;

    for (const Item& item : items) {
        if (item.weight <= remainingCapacity) {
            totalValue += item.value;
            remainingCapacity -= item.weight;
        } else {
            // Fractional part of item
            double fraction = static_cast<double>(remainingCapacity) / item.weight;
            totalValue += static_cast<int>(item.value * fraction);
            break; // Knapsack is full, no need to consider other items
        }
    }

    return totalValue;
}

int main() {
    int weight[] = {4, 5, 1};
    int value[] = {1, 2, 3};
    int n = 3;
    int capacity = 4;

    int ans = knapsackGreedy(weight, value, n, capacity);
    cout << "Ans: " << ans << endl;

    return 0;
}
