#include <iostream>
#include <cmath>
#include <math.h>
using namespace std;
int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    float delta=b*b-(4*a*c);
    if(delta==0)
    {
        int x=b*(-1)/(2*a);
        cout<<x;//<<" "<<x;
    }
    else
    if(delta>0)
    {
        int x1=(b*(-1)+sqrt(delta))/(2*a);
        int x2=(b*(-1)-sqrt(delta))/(2*a);
        cout<<x1;//<<" "<<x2;
    }
    else
    cout<<"";
    system("PAUSE");
    return 0;
}
