#include <iostream>
#include <set>
#include <cstdio>
#include <cmath>

using namespace std;

long long n;

int take(int l, int r)
{
    return (r * (r + 1) - l * (l - 1)) / 2;
}

int main()
{
    freopen("input.txt" ,"r",stdin);
    freopen("output.txt","w",stdout);
    long long ans = 0;
    cin>>n;
    int S = sqrt (double(n));
    for(int i = 1; i <= S; i++)
        if(take(i - ans, i) < n) ans++;

    //cout<<(n == 1) ? 1 : ans;
    if(n == 1) cout << 1;
    else
    cout<<ans;
    return 0;
}

