class Solution {
public:
    // Function to find the largest number that can be made with given sum of digits.
    string findLargest(int N, int S) {
        string ans = "";

        // If the sum of digits is 0 and the number of digits is more than 1,
        // return -1 since it is not possible to form a number with only 0 digits.
        if (S == 0 && N > 1)
            return "-1";

        // Iterating over each digit in the number.
        for (int i = 0; i < N; i++) {
            // If the sum is greater than or equal to 9,
            // we add '9' to the number and subtract 9 from the sum.
            if (S >= 9) {
                ans += '9';
                S -= 9;
            }
            // If the sum is less than 9, we add the corresponding digit
            // to the number and set the sum to 0.
            else {
                ans += char(48 + S);
                S = 0;
            }
        }

        // If there is any remaining sum, it means we were not able to
        // use up the entire sum, so we return -1.
        if (S > 0)
            return "-1";

        // Returning the largest number that can be formed.
        return ans;
    }
};
