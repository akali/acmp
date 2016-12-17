#include <iostream>
#include <stack>
#include <string>
 
inline bool LeftBracket(char c)
{
    return ('(' == c || '{' == c || '[' == c);
}
 
inline bool Fit(char lb, char rb)
{
    return ('(' == lb && ')' == rb) || ('[' == lb && ']' == rb) || ('{' == lb && '}' == rb);
}
 
int main()
{
    std::string s;
    std::cin>>s;
    std::stack<char> stack;
    for(std::string::const_iterator it(s.begin()), itEnd(s.end()); it != itEnd; ++it)
    {
        if(LeftBracket(*it))
        {
            stack.push(*it);
        }
        else if(Fit(stack.top(), *it))
        {
            stack.pop();
        }
        else
        {
            stack.push(*it);
            break;
        }
    }
    std::cout << (stack.empty() ? "right" : "wrong") << std::endl;
    return 0;
}