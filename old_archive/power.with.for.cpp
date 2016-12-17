#include <iostream>
using namespace std;
int main()
{
    int n,m,i,c=1;
    cin>>n>>m;
    for(i=1;i<=m;i++)
    {
        c*=n;
    }
    cout<<c;
}
