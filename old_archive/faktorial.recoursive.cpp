#include <iostream>
using namespace std;
double Factorial(int N)
  {
    double F;
    if (N<=1) F=1.; else F=Factorial(N-1)*N;
    return F;
  }
int main()
{
 int a;
 cin>>a;
 cout<<Factorial(a);
 return 0;
}
