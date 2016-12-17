#include <iostream>
using namespace std;
void t(int n, int from, int to, int free)
{
    if(n!=0)
    {
        t(n-1,from,free,to);
        cout<<"Disk="<<n<<" "<<from<<" "<<to<<"\n";
        t(n-1,free , to,from);
    }
}
int main()
{
//2    freopen("o.txt", "w",stdout);
    int n;
    cin>>n;
    t(n,1,3,2);
    return 0;
}
