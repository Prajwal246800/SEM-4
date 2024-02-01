/*
    Find the sum of atoms in the given chemical formula
    If the element is simply given, it is one atom,
    else the number following it gives the number of atoms a single string of chemical formula
    Molecules can be enclosed in parentheses, which have to be counted with the number given outside the parentheses eg (SO3)2
    The element name always starts with a capital letter and is followed by a small letter
    Input Format
        A single string of chemical formula.
    Constraints
        The formula should be of size <=20.
        The digit denoting the number of atoms should be a single digit (2 to 9).
        Assume the string is always valid.
    Output Format
        A single integer denoting the sum of atoms.
    Sample Input 0
        H2O
    Sample Output 0
        3
    Explanation 0
        2 atoms of Hydrogen + 1 atom of Oxygen
    Sample Input 1
        (SO3)2
    Sample Output 1
        8
    Explanation 1
        2 molecules of SO3, having 3 atoms of Oxygen and 1 atom of Sulphur
*/


#include <stdio.h>
#include <stdlib.h>

typedef struct stackelement
{
    int num;
    char parentheses;
} SE;

int atoms_sum(char formula[])
{
    SE stack[20];
    int stkptr=-1;
    int res=0;
    for (int i=0;formula[i]!='\0';i++)
    {
        if (formula[i]>='A' && formula[i]<='Z')
        {
            int atom_no = 1; 
            if (formula[i+1]>='2' && formula[i+1]<='9')
            {
                atom_no=formula[i+1] - '0';
                i++;
            }
            if (formula[i+1]>='a' && formula[i+1]<='z')
            {
                i++;
                if (formula[i+1]>='2' && formula[i+1]<='9')
                {
                    atom_no=formula[i+1] - '0';
                    i++;
                }
            }
            res+=atom_no;
        }
        else if(formula[i] == '(')
        {
            stkptr++;
            stack[stkptr].num=res;
            stack[stkptr].parentheses='(';
            res=0;
        }
        else if(formula[i]==')')
        {
            int atom_no=res;
            if (formula[i + 1] >= '2' && formula[i + 1] <= '9')
            {
                atom_no*=(formula[i + 1] - '0');
                i++;
            }
            res=stack[stkptr].num+atom_no; 
            stkptr--;
        }
    }
    return res;
}

int main()
{
    char formula[21];
    scanf("%s", formula);
    printf("%d", atoms_sum(formula));
    return 0;
}