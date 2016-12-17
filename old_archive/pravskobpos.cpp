#include <iostream>
#include <stack>
#include <string>
using namespace std;
bool is_correct( const std::string& );

int main()
{   //freopen("input.txt",  "r", stdin);
    //freopen("output.txt", "w", stdout);
    std::string str;
    //for ( char ch; std::cin >> ch && ch != ' '; str.push_back(ch) );
    char ch;
    cin>>str;

    std::cout << ( is_correct(str) ? "yes" : "no" ) << std::endl;
}

bool is_correct( const std::string& str)
{
    std::stack< char > stack;

    for (int i = 0; i < (int) str.length(); ++i)
    {
        if ( str[i] == '(' || str[i] == '{' || str[i] == '[' )
        {
            stack.push( str[i] );
        }
        else
        {

            if ( stack.empty() ||
            (str[i] == ')' ^ stack.top() == '(' ) ||
            (str[i] == '}' ^ stack.top() == '{' ) ||
            (str[i] == ']' ^ stack.top() == '[' )   )
            {
                return false;
            }

            stack.pop();
        }
    }

    return stack.empty();
}
