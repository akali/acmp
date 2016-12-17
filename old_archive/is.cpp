#include <iostream>
using namespace std;
int main()
{
    /*freopen("isprime.in","r",stdin);
    freopen("isprime.out","w",stdout);*/
    int o,n;
    cin>>n;
    if(n==1 || n==2) cout<<"True";
    else
    for(int i=2;i<n;i++)
    {
        if(n%i==0)
        cout<<"False";
        else
        cout<<"True";
        break;
    }

    return 0;
}
