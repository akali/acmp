#include <iostream>
using namespace std;
int main()
{
    char c[20000];
    char x[20000];
    int i=0;
    int j=0;
    while(!cin.eof())
    {
        cin>>c[i];
        cin>>x[j];
        i++;
        j++;
    cout<<c[i]<<"\n"<<x[j];
    }
    return 0;
}
