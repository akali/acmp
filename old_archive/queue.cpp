#include <iostream>
#include <locale.h>
#include <string>
#include <queue>
using namespace std;
int main()

{
    freopen("input.txt", "r", stdin);
    int n;
    string str;
    queue <string> a;
    queue <string> b;
    queue <string> c;
    while(cin)
    {
        cin>>n;
        cin>>str;
        if(n==9)  a.push(str);
        else
        if(n==10) b.push(str);
        else
        if(n==11) c.push(str);
    }
    while(!a.empty())
    {
        cout<<"9 "<<a.front()<<"\n";
        a.pop();
    }
    while(!b.empty())
    {
        cout<<"10 "<<b.front()<<"\n";
        b.pop();
    }
    while(!c.empty())
    {
        cout<<"11 "<<c.front()<<"\n";
        c.pop();
    }
return 0;
}

