#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;
#define INF 1000*1000*1000
int right,left;

priority_queue < int , vector<int> , less < int > > a;
void sift_down(int i)
{
 if(2*i+1<=a.size())
 {
  left=a[2*i+1];
 }
 else
 left=INF;
 if (2*i+2<=a.size())
  right = A[2*i+2]; // правый сын
 else
  right=INF;
 if (left==right  && right==INF) return;
 if (right <= left && right < a[i])
  swap(A[2 * i + 2], a[i])
  sift_down(2 * i + 2)
 if (left < a[i])
  swap(a[2 * i + 1], a[i])
  sift_down(2 * i + 1)
}
void sift_up(int i)
{
 if (i == 0) return; //Мы в корне
  if (a[i] < a[i/2])
    swap(a[i], a[i/2]);
    sift_up(i/2);
}
int extract_min()
{
 min = a[0]
 a[0] = a[a.size - 1]
 a.size = a.size - 1
 sift_down(0)
 return min;
}
void insert(int key)
{
 a.size = a.size + 1
 a[a.size - 1] = key
 sift_up(a.size - 1)
}
int main()
{
 int n;
 cin>>n;
 for(int i=0;i<n;i++)
 {
  cin>>a[i];
 }
 cout<<extract_min();
 return 0;
}
