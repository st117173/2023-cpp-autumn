#include <stdio.h>
#include <stdlib.h>

int countWords(const char*);
char* findLongestSentence(const char*);
char* my_strcat(char*, const char*);
char* my_strstr(const char*, const char*);
char* my_substr(const char*, int, int);
int my_strcmp(const char*, const char*);
size_t my_strlen(const char*);
char* my_strcpy(char*, const char*);
char* my_strmult(const char*, int);
char* my_strncpy(char* , const char* , size_t );
char* readFromFile(const char*);
void writeWordCountToFile(int, const char*);
void writeLongestSentenceToFile(const char*, const char*);
void processOperations();
void performOperation(int);

int main()
{
    char* text = readFromFile("in.txt");
    if (text != NULL)
    {
        int wordCount = countWords(text);
        char* longestSentence = findLongestSentence(text);

        if (longestSentence != NULL)
        {
            printf("Number of words: %d\n", wordCount);
            printf("Longest sentence: %s\n", longestSentence);
            writeWordCountToFile(wordCount, "out.txt");
            writeLongestSentenceToFile(longestSentence, "out.txt");
            free(longestSentence);
        }

        free(text);
    }
    else
    {
        printf("Failed to read file 'in.txt'.\n");
    }

    processOperations();

    return 0;
}

int countWords(const char* text)
{
    int words = 0;
    int isInsideWord = 0;

    for (const char* ptr = text; *ptr; ptr++)
    {
        if (*ptr == ' ' || *ptr == '\t' || *ptr == '\n')
        {
            isInsideWord = 0;
        }
        else if (!isInsideWord)
        {
            words++;
            isInsideWord = 1;
        }
    }

    return words;
}

char* findLongestSentence(const char* text)
{
    const char* start = text;
    const char* end = text;
    const char* longestStart = text;
    int maxWordCount = 0;
    int curWordCount = 0;

    char* longest = NULL;
    int maxLength = 0;

    while (*end != '\0')
    {
        if (*end == '.' || *end == '!' || *end == '?' || *(end + 1) == '\0' || *end == '\n')
        {
            int length = end - start + 1;
            if (length > maxLength)
            {
                maxLength = length;
                if (longest)
                {
                    free(longest);
                }
                longest = (char*)malloc(length + 1);
                if (!longest)
                {
                    return NULL;
                }
                my_strncpy(longest, start, length);
                longest[length] = '\0';
            }
            start = end + 1;
        }
        end++;
    }

    return longest;
}

void performOperation(int choice)
{
    char str1[1000];
    char str2[500];
    char *substr;
    switch (choice)
    {
        case 1:
    {
            printf("Enter the first string: ");
            char str1[1000];
            scanf("%s", str1);
            printf("Enter the second string: ");
            char str2[500];
            scanf("%s", str2);
            printf("Concatenated string: %s\n", my_strcat(str1, str2));
            break;
        }
        case 2:
        {
            printf("Enter the main string: ");
            scanf("%s", str1);
            printf("Enter the substring to search for: ");
            scanf("%s", str2);
            char *ptr = my_strstr(str1, str2);
            if (ptr != NULL)
            {
            printf("'%s' is found in '%s' at position %ld\n", str2, str1, ptr - str1);
            }
            else
            {
            printf("'%s' is not found in '%s'\n", str2, str1);
            }
            break;
        }
        case 3:
        {
            printf("Enter the string: ");
            scanf("%s", str1);
            int start_index = 0;
            printf("Enter the starting index: ");
            scanf("%d", &start_index);
            int length = 0;
            printf("Enter the length of the substring: ");
            scanf("%d", &length);
            substr = my_substr(str1, start_index, length);
            printf("Substring: %s\n", substr);
            free(substr);
            break;
        }
        case 4:
        {
            printf("Enter the first string: ");
            scanf("%s", str1);
            printf("Enter the second string: ");
            scanf("%s", str2);
            int result = my_strcmp(str1, str2);
            if (result == 0)
            {
            printf("The strings are equal.\n");
            }
            else if (result < 0)
            {
            printf("String 1 is less than string 2.\n");
            }
            else
            {
            printf("String 1 is greater than string 2.\n");
            }
            break;
        }
        case 5:
        {
            printf("Enter the string: ");
            scanf("%s", str1);
            int multiplier = 0;
            printf("Enter the multiplier: ");
            scanf("%d", &multiplier);
            for (int i = 0; i < multiplier; i++)
            {
            printf("%s", str1);
            }
            printf("\n");
            break;
        }
        case 6:
        {
            printf("Exiting program...\n");
            break;
        }
        default:
        {
            printf("Invalid choice\n");
            break;
        }
    }
}

void processOperations()
{
    int choice = 0;
    do
    {
        printf("\nChoose a function\n");
        printf("1 – strcat()\n");
        printf("2 – strstr()\n");
        printf("3 – substr()\n");
        printf("4 – strcmp()\n");
        printf("5 – strmult()\n");
        printf("6 – Exit\n");
        scanf("%d", &choice);
        performOperation(choice);
    } while (choice != 6);
}

char* readFromFile(const char* filename)
{
    FILE* file = fopen(filename, "r");
    if (file == NULL)
    {
        return NULL;
    }
    fseek(file, 0, SEEK_END);
    long length = ftell(file);
    fseek(file, 0, SEEK_SET);

    char* buffer = (char*)malloc(length + 1);
    if (buffer == NULL)
    {
        fclose(file);
        return NULL;
    }
    fread(buffer, 1, length, file);
    buffer[length] = '\0';

    fclose(file);
    return buffer;
}

void writeWordCountToFile(int wordCount, const char* filename)
{
    FILE* file = fopen(filename, "w");
    if (file != NULL)
    {
        fprintf(file, "Number of words: %d\n", wordCount);
        fclose(file);
    }
}

void writeLongestSentenceToFile(const char* longestSentence, const char* filename)
{
    FILE* file = fopen(filename, "a");
    if (file != NULL)
    {
        fprintf(file, "Longest sentence: %s\n", longestSentence);
        fclose(file);
    }
}

char* my_strcat(char* dest, const char* src)
{
    char* ptr = dest;

    while (*ptr != '\0')
    {
        ptr++;
    }

    while (*src != '\0')
    {
        *ptr = *src;
        ptr++;
        src++;
    }

    *ptr = '\0';

    return dest;
}

char* my_strstr(const char* haystack, const char* needle)
{
    if (*needle == '\0')
    {
        return (char*)haystack;
    }

    const char* p1 = haystack;
    while (*p1 != '\0')
    {
        const char* p1_begin = p1;
        const char* p2 = needle;

        while ((*p1 != '\0') && (*p2 != '\0') && (*p1 == *p2))
        {
            p1++;
            p2++;
        }

        if (*p2 == '\0')
        {
            return (char*)p1_begin;
        }

        p1 = p1_begin + 1;
    }

    return NULL;
}

char* my_substr(const char* str, int start, int length)
{
    char* substr = (char*)malloc((length + 1) * sizeof(char));

    if (substr == NULL)
    {
        return NULL;
    }

    int i;
    for (i = 0; i < length && str[start + i] != '\0'; i++)
    {
        substr[i] = str[start + i];
    }

    substr[i] = '\0';

    return substr;
}

int my_strcmp(const char* s1, const char* s2)
{
    const unsigned char* us1 = (const unsigned char*)s1;
    const unsigned char* us2 = (const unsigned char*)s2;

    while (*us1 == *us2 && *us1 != '\0')
    {
        us1++;
        us2++;
    }

    return (*us1 > *us2) - (*us1 < *us2);
}

size_t my_strlen(const char* str)
{
    const char* ptr = str;
    while (*ptr)
    {
        ptr++;
    }
    return (size_t)(ptr - str);
}

char* my_strcpy(char* dest, const char* src)
{
    char* ptr = dest;

    while (*src != '\0')
    {
        *ptr = *src;
        ptr++;
        src++;
    }

    *ptr = '\0';

    return dest;
}

char* my_strmult(const char* str, int multiplier)
{
    int length = my_strlen(str);
    char* result = (char*)malloc((length * multiplier + 1) * sizeof(char));

    if (result == NULL)
    {
        return NULL;
    }

    int j = 0;
    for (int i = 0; i < multiplier; i++)
    {
        my_strcpy(result + j, str);
        j += length;
    }

    result[j] = '\0';

    return result;
}

char* my_strncpy(char* dest, const char* src, size_t n) {
    char* destStart = dest;

    while (n && (*dest++ = *src++)) {
        n--;
    }

    while (n--) {
        *dest++ = '\0';
    }

    return destStart;
}
