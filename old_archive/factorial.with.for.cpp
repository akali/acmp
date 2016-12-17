#include <iostream>
using namespace std;
int fact(int f)
    {
    return f+fact(f-1);
    }
int main()
{
    /*freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);*/
    int n,i,c=0;
    cin>>n;
    cout<<fact(n);
    return 0;
}
