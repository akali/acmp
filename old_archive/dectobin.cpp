#include <iostream>
using namespace std;
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt","w",stdout);
    long long bin,dec,w=0;
    cin>>dec;
    while(dec>0)
    {
        w+=dec%2;
        dec/=2;
    }
    cout<<w;
    return 0;
}
