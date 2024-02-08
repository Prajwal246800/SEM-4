/*
    We define super digit of an integer  using the following rules:
    Given an integer, we need to find the super digit of the integer.
    If  has only  digit, then its super digit is .
    Otherwise, the super digit of  is equal to the super digit of the sum of the digits of .
    For example, the super digit of  will be calculated as:
        super_digit(9875)   	9+8+7+5 = 29 
        super_digit(29) 	2 + 9 = 11
        super_digit(11)		1 + 1 = 2
        super_digit(2)		= 2  
    Example
    The number  is created by concatenating the string   times so the initial .
        superDigit(p) = superDigit(9875987598759875)
                    9+8+7+5+9+8+7+5+9+8+7+5+9+8+7+5 = 116
        superDigit(p) = superDigit(116)
                    1+1+6 = 8
        superDigit(p) = superDigit(8)
    All of the digits of  sum to . The digits of  sum to .  is only one digit, so it is the super digit.
    Function Description
        Complete the function superDigit in the editor below. It must return the calculated super digit as an integer.
        superDigit has the following parameter(s):
        string n: a string representation of an integer
        int k: the times to concatenate  to make 
    Returns
        int: the super digit of  repeated  times
    Input Format
        The first line contains two space separated integers,  and .
    Constraints
    Sample Input 0
        148 3
    Sample Output 0
        3
    Explanation 0
        Here  and , so .
    super_digit(P) = super_digit(148148148) 
                = super_digit(1+4+8+1+4+8+1+4+8)
                = super_digit(39)
                = super_digit(3+9)
                = super_digit(12)
                = super_digit(1+2)
                = super_digit(3)
                = 3
    Sample Input 1
        9875 4
    Sample Output 1
        8
    Sample Input 2
        123 3
    Sample Output 2
        9
    Explanation 2
        Here  and , so .
    super_digit(P) = super_digit(123123123) 
                = super_digit(1+2+3+1+2+3+1+2+3)
                = super_digit(18)
                = super_digit(1+8)
                = super_digit(9)
                = 9
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
char* readline();
char* ltrim(char*);
char* rtrim(char*);
char** split_string(char*);
int parse_int(char*);
int sumDigits(char* str)
{
    int sum = 0;
    while (*str != '\0')
    {
        sum += (*str - '0');
        str++;
    }
    return sum;
}
int recursiveSuperDigit(char* str)
{
    int sum = sumDigits(str);
    if (sum < 10)
    {
        return sum;
    }
    else
    {
        char sum_str[20];
        sprintf(sum_str, "%d", sum);
        return recursiveSuperDigit(sum_str);
    }
}
int superDigit(char* n, int k)
{
    long long initialSum = (long long)sumDigits(n) * k;
    char initialSumStr[20];
    sprintf(initialSumStr, "%lld", initialSum);
    return recursiveSuperDigit(initialSumStr);
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");
    char** first_multiple_input = split_string(rtrim(readline()));
    char* n = *(first_multiple_input + 0);
    int k = parse_int(*(first_multiple_input + 1));
    int result = superDigit(n, k);
    fprintf(fptr, "%d\n", result);
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
char** split_string(char* str)
{
    char** splits = NULL;
    char* token = strtok(str, " ");
    int spaces = 0;
    while (token)
    {
        splits = realloc(splits, sizeof(char*) * ++spaces);
        if (!splits)
        {
            return splits;
        }
        splits[spaces - 1] = token;
        token = strtok(NULL, " ");
    }
    return splits;
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