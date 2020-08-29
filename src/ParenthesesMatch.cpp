#include <Stack.h>
#include "ParenthesesMatch.h"

bool parenthesesMatch(const char* str){

    int strLength = charstrCount(str);                             //gets the length of the character string str
    Stack<char> parenthesestStack;                                 //create the stack that holds the parentheses


    for (int i = 0; i < strLength; i++)                            //loop that will itterate through the c-string
    {
        char tempChar = str[i];

        if (tempChar == '(')                                      //checks if the character is an opening
        {
            parenthesestStack.push(tempChar);                     //pushes to the stack
        }
        if (tempChar == ')')                                      //checks if the character is a closing parentheses
        {
            if (parenthesestStack.empty() == true)
            {
                return false;                                     //breaks algorithm, checks if there is an opening to pop off
            }
            else                                                 //handles if there is an opening parentheses to pop off
                {
                    parenthesestStack.pop();                     //pops the opening parenthesis
                }
        }
    }

    if (parenthesestStack.size() > 0)                  //final check, if the stack size is greater than zero, it is uneven
    {
        return false;
    }
    else                                             //else, if it is 0, return true, stack is even
    {
        return true;
    }


}

int charstrCount(const char* str)
{
    int count = 0;
    while (str[count] != '\0')               //gets the length of the str string
    {
        count++;
    }
    return count;

}
