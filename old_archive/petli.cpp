#include <iostream>
using namespace std;
long long a[101][101],n,m,l,i,j;
int c=0;
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            cin>>a[i][j];
        }
    }
    for(i=1;i<=n;i++)
    {
            if(a[i][i]==1){cout<<"YES";return 0;}
            else
            {
            cout<<"NO";
            return 0;
            }
    }
    if(c==n) cout<<"NO";
    else
    cout<<"YES";
    cout<<endl<<c;
    return 0;
}
