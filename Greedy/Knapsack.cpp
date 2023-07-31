/*
You are planning to go on a treasure hunt, and you have a knapsack with a maximum capacity of W units.
Along your journey, you encounter N valuable items, each with a weight and a corresponding value.
Your goal is to determine the maximum total value you can carry in your knapsack by selecting 
a subset of the items to fit into it without exceeding its capacity.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Item {
    int value;
    int weight;
    double valuePerWeight; // Store value-to-weight ratio

    Item(int v, int w) : value(v), weight(w), valuePerWeight(static_cast<double>(v) / w) {}
};

// Comparator to create a max heap based on item value-to-weight ratio
struct CompareItem {
    bool operator()(const Item& a, const Item& b) {
        return a.valuePerWeight < b.valuePerWeight;
    }
};

// Function to solve the knapsack problem using a greedy approach with max heap
int knapsackGreedy(int weight[], int value[], int n, int capacity) {
    // Create a max heap to store items based on their value-to-weight ratio
    priority_queue<Item, vector<Item>, CompareItem> maxHeap;
    for (int i = 0; i < n; ++i) {
        maxHeap.push(Item(value[i], weight[i]));
    }

    int totalValue = 0;
    int remainingCapacity = capacity;

    // Process items one by one until the knapsack is full or no more items
    while (!maxHeap.empty() && remainingCapacity > 0) {
        // Get the item with the highest value-to-weight ratio from the max heap
        Item item = maxHeap.top();
        maxHeap.pop();

        // If the item's weight fits in the remaining capacity, add it completely
        if (item.weight <= remainingCapacity) {
            totalValue += item.value;
            remainingCapacity -= item.weight;
        } else {
            // If the item's weight exceeds the remaining capacity,
            // add a fraction of it to maximize the total value
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
