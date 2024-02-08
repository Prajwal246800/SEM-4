/*
    Find the number of ways that a given integer, can be expressed as the sum of the  powers of unique, natural numbers.
    For example, if  and , we have to find all combinations of unique squares adding up to .
    The only solution is .
    Function Description
        Complete the powerSum function in the editor below. It should return an integer that represents the number of possible combinations.
        powerSum has the following parameter(s):
        X: the integer to sum to
        N: the integer power to raise numbers to
    Input Format
        The first line contains an integer .
        The second line contains an integer .
    Constraints
        Output Format
            Output a single integer, the number of possible combinations caclulated.
        Sample Input 0
            10
            2
        Sample Output 0
            1
        Explanation 0
            If  and , we need to find the number of ways that  can be represented as the sum of squares of unique numbers.
            This is the only way in which  can be expressed as the sum of unique squares.
        Sample Input 1
            100
            2
        Sample Output 1
            3
        Explanation 1
        Sample Input 2
            100
            3
        Sample Output 2
            1
        Explanation 2
            can be expressed as the sum of the cubes of .
            . There is no other way to express  as the sum of cubes.
*/

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
char *readline();
char *ltrim(char *);
char *rtrim(char *);
int parse_int(char *);
/*
 * Complete the 'powerSum' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER X
 *  2. INTEGER N
 */

int powerSumHelper(int X, int N, int current)
{
    // Base case: if X becomes 0, we've found a valid combination
    if (X == 0)
    {
        return 1;
    }
    // If X becomes negative or if current exceeds X, no valid combination possible
    if (X < 0 || current > X)
    {
        return 0;
    }
    // Recursive case: two possibilities - either include current number raised to N or not
    // If we include current number, reduce X by current^N and move to the next number
    // If we exclude current number, just move to the next number
    return powerSumHelper(X - pow(current, N), N, current + 1) + powerSumHelper(X, N, current + 1);
}
int powerSum(int X, int N)
{
    // Start recursion from 1st natural number
    return powerSumHelper(X, N, 1);
}

int main()
{
    FILE *fptr = fopen(getenv("OUTPUT_PATH"), "w");
    int X = parse_int(ltrim(rtrim(readline())));
    int N = parse_int(ltrim(rtrim(readline())));
    int result = powerSum(X, N);
    fprintf(fptr, "%d\n", result);
    fclose(fptr);
    return 0;
}

char *readline()
{
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char *data = malloc(alloc_length);
    while (true)
    {
        char *cursor = data + data_length;
        char *line = fgets(cursor, alloc_length - data_length, stdin);
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
char *ltrim(char *str)
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
char *rtrim(char *str)
{
    if (!str)
    {
        return '\0';
    }
    if (!*str)
    {
        return str;
    }
    char *end = str + strlen(str) - 1;
    while (end >= str && isspace(*end))
    {
        end--;
    }
    *(end + 1) = '\0';
    return str;
}
int parse_int(char *str)
{
    char *endptr;
    int value = strtol(str, &endptr, 10);
    if (endptr == str || *endptr != '\0')
    {
        exit(EXIT_FAILURE);
    }
    return value;
}