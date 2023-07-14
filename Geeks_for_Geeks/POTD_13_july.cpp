class Solution {
public:
    bool isFrequencyUnique(int n, int arr[]) {
        std::vector<int> elements(arr, arr + n);
        std::sort(elements.begin(), elements.end());

        int currentElement = elements[0];
        int count = 1;

        for (int i = 1; i < elements.size(); ++i) {
            if (elements[i] == currentElement) {
                count++;
            } else {
                if (count > 1) {
                    return false;
                }
                currentElement = elements[i];
                count = 1;
            }
        }

        return count == 1;
    }
};