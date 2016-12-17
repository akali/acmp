#include <iostream>
#include <string>
#include <functional>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
 
int n;
string a;
vector<string> v;
void input()
{
    cin>>a;
    n = a.size();
}
bool prev_permutation(string &a) {
 
    int j = n - 2;
    while (j != -1 && a[j] <= a[j+1]) j--;
    if (j == -1) return false;
    int k = n - 1;
    while (a[j] <= a[k]) k--;
 
    swap(a[j], a[k]);
 
    int l = j+1, r = n-1;
    while (l<r)
        swap(a[l++],a[r--]);
    return true;
}

void solve() {
    //sort(a.begin(),a.end(), greater<char>() );
    do
    {
        for(int i=0;i<n;i++)
        cout<<a[i];
        cout<<endl;
        //v.push_back(a.c_str());
        //printf("%s\n",a.c_str());
    }
    while (next_permutation(a.begin() , a.end()));
    //reverse(v.begin(),v.end());
    //for(int i=0;i<v.size();i++) cout<<v[i]<<endl;
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    input();
    solve();
    return 0;
}