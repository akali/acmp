#include <iostream>
using namespace std;
void hanoy(int n,int from, int to, int free)
{
    if(n!=0)
    {
        hanoy(n-1,from,free,to);
        cout<<"DiskNumber "<<n<<" "<<from<<" "<<to<<endl;
        hanoy(n-1,free,to,from);
    }
}
int main()
{
    int a;
    cin>>a;
    hanoy(a,1,3,2);
    return 0;
}
