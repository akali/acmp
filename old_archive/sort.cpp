#include <fstream>
#include <vector>
#include <deque>
using namespace std;
int main()
{
    ifstream cin("sort . in");
    ofstream cout("sort . out");
    deque <int> a;
    int n,i;
    cin>>n;
    for(i=0;i<n;i++)
    {
        int s;
        cin>>s;
        a.push_back(s);
    }
    sort(a.begin(),a.end());
    for(i=0;i<n;i++)
    {
    cout<<a.front()<<" ";
    a.pop_front();
    }
    return 0;
}
