/*
  Hanoi towers recoursive solution
  Kali Aisultan
*/

#include <iostream>
using namespace std;
void Towers (int n, int from, int to, int free)
{
  if (n != 0)
  {
    Towers (n-1, from, free, to);
    cout<<from<<" "<<to<<"\n";
    Towers (n-1, free, to, from);
  }
}

int main()
{
    int n;
    cin>>n;
    Towers(n,1,2,3);
    return 0;
}
