#include <iostream>
#include <string>
#include <algorithm>

void remove_duplicates(const std::string& input) {
    std::string string_without_duplicates;

    for (char current : input) {
        bool duplicate_found = false;

        for (char c : string_without_duplicates) {
            if (current == c) {
                duplicate_found = true;
                break;
            }
        }

        if (!duplicate_found) {
            string_without_duplicates += current;
        }
    }

    std::cout << string_without_duplicates << std::endl;
}

int main() {
    std::string input = "manav malhotra";
    std::cout << input << std::endl;

    remove_duplicates(input);

    return 0;
}
