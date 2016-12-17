#include <iostream>
using namespace std;
int main()
{
    int max=0,i,n,a;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a;
        if(max<a) max=a;
    }
    cout<<max;
}
