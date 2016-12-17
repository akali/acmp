#include <iostream>
#include <cmath>
#include <math.h>
using namespace std;
int main()
{
    int a,h,m,s;
    cin>>a;
    h=a/3600;
    //a-=h;
    if(a>3600)
    {
        h=h%24;
    }
    m=a/60;
    m%=60;
    /*a-=m;
    s=a;*/
    s=a%60;
    cout<<h<<":";
    if(m<10) cout<<"0"<<m%10;
    else
    cout<<m;
    cout<<":"<<s/10<<s%10;
    return 0;
}
