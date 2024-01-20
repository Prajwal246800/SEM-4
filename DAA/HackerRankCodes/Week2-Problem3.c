/*
    We say that a string contains the word hackerrank if a subsequence of its characters spell the word hackerrank.
    Remember that a subsequence maintains the order of characters selected from a sequence.
    More formally, let  be the respective indices of h, a, c, k, e, r, r, a, n, k in string .
    If  is true, then  contains hackerrank.
    For each query, print YES on a new line if the string contains hackerrank, otherwise, print NO.
    Example
        This contains a subsequence of all of the characters in the proper order. Answer YES
        This is missing the second 'r'. Answer NO.
        There is no 'c' after the first occurrence of an 'a', so answer NO.
    Function Description
        Complete the hackerrankInString function in the editor below.
        hackerrankInString has the following parameter(s):
            string s: a string
            Returns
                string: YES or NO
            Input Format
                The first line contains an integer , the number of queries.
                Each of the next  lines contains a single query string .
            Constraints
                Sample Input 0
                    2
                    hereiamstackerrank
                    hackerworld
                Sample Output 0
                    YES
                    NO
                Explanation 0
                    We perform the following  queries:
                    The characters of hackerrank are bolded in the string above.
                    Because the string contains all the characters in hackerrank in the same exact order as they appear in hackerrank,
                        we return YES.
                    does not contain the last three characters of hackerrank, so we return NO.
                Sample Input 1
                    2
                    hhaacckkekraraannk
                    rhbaasdndfsdskgbfefdbrsdfhuyatrjtcrtyytktjjt
                Sample Output 1
                    YES
                    NO
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
    * Complete the 'hackerrankInString' function below.
    *
    * The function is expected to return a STRING.
    * The function accepts STRING s as parameter.
*/
/*
    * To return the string from the function, you should either do static allocation or dynamic allocation
    * For example,
    * char* return_string_using_static_allocation() {
    *     static char s[] = "static allocation of string";
    *     return s;
    * }
    * char* return_string_using_dynamic_allocation() {
    *     char* s = malloc(100 * sizeof(char));
    *     s = "dynamic allocation of string";
    *     return s;
    * }
*/
char* hackerrankInString(char* s)
{
    char* hackerrank = "hackerrank";
    int hackerrankIndex = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == hackerrank[hackerrankIndex])
        {
            hackerrankIndex++;
        }
        if (hackerrank[hackerrankIndex] == '\0')
        {
            return "YES";
        }
    }
    return "NO";
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");
    int q = parse_int(ltrim(rtrim(readline())));
    for (int q_itr = 0; q_itr < q; q_itr++)
    {
        char* s = readline();
        char* result = hackerrankInString(s);
        fprintf(fptr, "%s\n", result);
    }
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