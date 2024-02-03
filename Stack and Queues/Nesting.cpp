/*
Nesting: Determine whether a given string of parentheses (single type) is properly nested.
**************************************************************************************************************************
A string S consisting of N characters is called properly nested if:
    *    S is empty;
    *    S has the form "(U)" where U is a properly nested string;
    *    S has the form "VW" where V and W are properly nested strings.
    
For example, string "(()(())())" is properly nested but string "())" isn't.

Write a function:
    int solution(string &S);

that, given a string S consisting of N characters, returns 1 if string S is properly nested and 0 otherwise.
For example, given S = "(()(())())", the function should return 1 and given S = "())", 
the function should return 0, as explained above.

Write an efficient algorithm for the following assumptions:
    *    N is an integer within the range [0..1,000,000];
    *    string S is made only of the characters '(' and/or ')'.
*/
#include <stack>
int solution(string &S) {
    if (S.empty())
    {
        return 1;
    }
    else if (S.size() % 2 != 0)
    {
        return 0;
    }
    std::stack<char> st;
    for (char c: S)
    {
        switch(c)
        {
            case '(':
                st.push(c);
                break;
            case ')':
                if (st.top() != '(')
                {
                    return 0;
                }
                st.pop();
                break;
            default:
               return 0;
        }
    }
    return st.empty();
}
