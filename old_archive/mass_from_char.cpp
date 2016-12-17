#include <iostream>
using namespace std;
int main()
{
    char c[100][100];
    int n,m,i,j;
    cin>>n>>m;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            cin>>c[i][j];
        }
    cout<<c[i][1];
    }
    return 0;
}
