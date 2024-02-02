
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
