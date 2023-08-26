class Solution{
  public:
    int longestKSubstr(string s, int k) {
        int n = s.length();
        
        if (n == 0 || k == 0) {
            return -1;
        }

        int start = 0, end = 0;
        int max_len = -1;

        // A map to keep track of the frequency of characters in the current window
        unordered_map<char, int> char_count;

        while (end < n) {
            // Increase the count of the character at the 'end' pointer in the map
            char_count[s[end]]++;

            // Slide the 'end' pointer to the right
            end++;

            // If the number of unique characters in the current window exceeds K
            while (char_count.size() > k) {
                // Decrease the count of the character at the 'start' pointer
                char_count[s[start]]--;

                if (char_count[s[start]] == 0) {
                    char_count.erase(s[start]);
                }

                // Slide the 'start' pointer to the right
                start++;
            }

            // If the number of unique characters is K, update the max length
            if (char_count.size() == k) {
                max_len = max(max_len, end - start);
            }
        }

        return max_len == -1 ? -1 : max_len;
    }
};