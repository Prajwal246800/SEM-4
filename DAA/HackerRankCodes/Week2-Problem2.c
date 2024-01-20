/*
    Louise joined a social networking site to stay in touch with her friends.
    The signup page required her to input a name and a password.
    However, the password must be strong.
    The website considers a password to be strong if it satisfies the following criteria:
    Its length is at least 6.
        It contains at least one digit.
        It contains at least one lowercase English character.
        It contains at least one uppercase English character.
        It contains at least one special character. The special characters are: !@#$%^&*()-+
    She typed a random string of length  in the password field but wasn't sure if it was strong. Given the string she typed, can you find the minimum number of characters she must add to make her password strong?
    Note: Here's the set of types of characters in a form you can paste in your solution:
        numbers = "0123456789"
        lower_case = "abcdefghijklmnopqrstuvwxyz"
        upper_case = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        special_characters = "!@#$%^&*()-+"
    Example
        This password is 5 characters long and is missing an uppercase and a special character.
        The minimum number of characters to add is .
        This password is 5 characters long and has at least one of each character type.
        The minimum number of characters to add is .
    Function Description
        Complete the minimumNumber function in the editor below.
        minimumNumber has the following parameters:
            int n: the length of the password
            string password: the password to test
        Returns
            int: the minimum number of characters to add
        Input Format
            The first line contains an integer , the length of the password.
            The second line contains the password string. Each character is either a lowercase/uppercase English alphabet, a digit, or a special character.
        Constraints
            All characters in  are in [a-z], [A-Z], [0-9], or [!@#$%^&*()-+ ].
        Sample Input 0
            3
            Ab1
        Sample Output 0
            3
        Explanation 0
            She can make the password strong by adding  characters, for example, $hk, turning the password into Ab1$hk which is strong.
            characters aren't enough since the length must be at least .
        Sample Input 1
            11
        #HackerRank
        Sample Output 1
            1
        Explanation 1
            The password isn't strong, but she can make it strong by adding a single digit.
*/

//CODE
#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* readline();
char* ltrim(char*);
char* rtrim(char*);
int parse_int(char*);
/*
    * Complete the 'minimumNumber' function below.
    * The function is expected to return an INTEGER.
    * The function accepts following parameters:
    *  1. INTEGER n
    *  2. STRING password
*/
int minimumNumber(int n, char* password)
{
    // Return the minimum number of characters to make the password strong
    int addCount = 0;
    bool hasDigit = false, hasLower = false, hasUpper = false, hasSpecial = false;
    for (int i = 0; i < n; i++)
    {
        if (password[i] >= '0' && password[i] <= '9')
        {
            hasDigit = true;
        }
        else if (password[i] >= 'a' && password[i] <= 'z')
        {
            hasLower = true;
        }
        else if (password[i] >= 'A' && password[i] <= 'Z')
        {
            hasUpper = true;
        }
        else
        {
            hasSpecial = true;
        }
    }
    // Check for missing criteria and increment addCount accordingly
    if (!hasDigit)
    {
        addCount++;
    }
    if (!hasLower)
    {
        addCount++;
    }
    if (!hasUpper)
    {
        addCount++;
    }
    if (!hasSpecial)
    {
        addCount++;
    }
    // Check for minimum length criteria
    if (n + addCount < 6)
    {
        addCount += 6 - (n + addCount);
    }
    return addCount;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");
    int n = parse_int(ltrim(rtrim(readline())));
    char* password = readline();
    int answer = minimumNumber(n, password);
    fprintf(fptr, "%d\n", answer);
    fclose(fptr);
    return 0;
}
char* readline()
{
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);
    while (true)
    {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);
        if (!line)
        {
            break;
        }
        data_length += strlen(cursor);
        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n')
        {
            break;
        }
        alloc_length <<= 1;
        data = realloc(data, alloc_length);
        if (!data)
        {
            data = '\0';
            break;
        }
    }
    if (data[data_length - 1] == '\n')
    {
        data[data_length - 1] = '\0';
        data = realloc(data, data_length);
        if (!data)
        {
            data = '\0';
        }
    }
    else
    {
        data = realloc(data, data_length + 1);
        if (!data)
        {
            data = '\0';
        }
        else
        {
            data[data_length] = '\0';
        }
    }
    return data;
}
char* ltrim(char* str)
{
    if (!str)
    {
        return '\0';
    }
    if (!*str)
    {
        return str;
    }
    while (*str != '\0' && isspace(*str))
    {
        str++;
    }
    return str;
}
char* rtrim(char* str)
{
    if (!str)
    {
        return '\0';
    }
    if (!*str)
    {
        return str;
    }
    char* end = str + strlen(str) - 1;
    while (end >= str && isspace(*end))
    {
        end--;
    }
    *(end + 1) = '\0';
    return str;
}
int parse_int(char* str)
{
    char* endptr;
    int value = strtol(str, &endptr, 10);
    if (endptr == str || *endptr != '\0')
    {
        exit(EXIT_FAILURE);
    }
    return value;
}