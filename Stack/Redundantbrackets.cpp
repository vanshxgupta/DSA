#include <iostream>
#include <stack>
using namespace std;

bool findRedundantBrackets(string &s)
{
    stack<char> st;

    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            st.push(ch);
        }
        else if (ch == ')')
        {
            bool isredundant = true;
            while (st.top() != '(')
            {
                char top = st.top();
                if (top == '+' || top == '-' || top == '*' || top == '/')
                {
                    isredundant = false;
                }
                st.pop();
            }
            st.pop(); // Remove '(' from stack
            if (isredundant)
            {
                return true;
            }
        }
    }
    return false;
}


