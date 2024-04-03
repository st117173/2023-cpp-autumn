#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>

std::string findMostFrequentWord(const std::string& text)
{
    std::string mostFrequentWord;
    int maxCount = 0;
    char* textCopy = strdup(text.c_str());
    char* token = strtok(textCopy, " ,.-");

    while (token != NULL)
    {
        std::string word = token;
        int count = 0;
        char* searchPos = textCopy;
        while ((searchPos = strstr(searchPos, token)) != NULL)
        {
            count++;
            searchPos += strlen(token);
        }

        if (count > maxCount)
        {
            maxCount = count;
            mostFrequentWord = word;
        }

        token = strtok(nullptr, " ,.-");
    }

    free(textCopy);
    return mostFrequentWord;
}

bool isPalindrome(const std::string& str)
{
    int i = 0, j = str.length() - 1;
    while (i < j)
    {
        if (str[i] != str[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int main(int argc, char* argv[])
{
    std::string input;
    char c;
    std::cout << "Enter the text: ";

    while ((c = std::cin.get()) != EOF && c != '\n')
    {
        input += c;
    }

    std::string mostFrequentWord = findMostFrequentWord(input);
    std::cout << "Most frequent word: " << mostFrequentWord << std::endl;

    if (isPalindrome(input))
    {
        std::cout << "It's a palindrome" << std::endl;
    }
    else
    {
        std::cout << "It's not a palindrome" << std::endl;
    }

    std::cin.get();

    return EXIT_SUCCESS;
}
