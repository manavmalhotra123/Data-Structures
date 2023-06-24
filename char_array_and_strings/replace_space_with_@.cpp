#include <iostream>
#include <cstring>
#include <string>

std::string replaceNullWith(const char sentence[], char replacement) {
    std::string modifiedSentence = sentence;
    int length = modifiedSentence.length();
    
    for (int i = 0; i < length; i++) {
        if (modifiedSentence[i] == '\0') {
            modifiedSentence[i] = replacement;
        }
    }
    
    return modifiedSentence;
}

int main() {
    char sentence[100];
    
    std::cout << "Enter a sentence: ";
    std::cin.getline(sentence, sizeof(sentence));
    
    std::string replacedSentence = replaceNullWith(sentence,'d');
    
    std::cout << "Replaced sentence: " << replacedSentence << std::endl;
    
    return 0;
}
