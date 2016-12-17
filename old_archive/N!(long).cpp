#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int a;
vector<int> mult;

vector<int> umn(vector<int> A,vector<int> B)
{
	vector<int> c(10000);
	int res;
	int k;
	reverse(A.begin(),A.end());
	reverse(B.begin(),B.end());
	
	for(int i=0;i<A.size();i++)
	{
		for(int j=0;j<B.size();j++)
		{
			k=i+j;
			res=A[i]*B[j];
			while(res)
			{
				res+=c[k];
				c[k]=res%10;
				res/=10;
				k++;
			}
		}
	}
	while(!c.back())
		c.pop_back();
	reverse(c.begin(),c.end());
	return c;
}

vector<int> vec(int a)
{
	vector<int> v;
	while(a)
	{
		v.push_back(a%10);
		a/=10;
	}	
	reverse(v.begin(),v.end());
	return v;
}
	
			
int main()
{
	cin >> a;
	mult.push_back(1);
	for(int i=2;i<=a;i++)
		mult=umn(vec(i),mult);
	for(int i=0;i<mult.size();i++)
		cout << mult[i];
	return 0;
}