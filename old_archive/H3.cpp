#include <iostream>                  
#include <math.h>       	
using namespace std;

int n,i,j,s,m[111],c[111],st[1000999],maxi=-1;
bool used[1000999];

int main()
{
	cin >> n >> s;
	
	for(i=1;i<=n;i++)
		cin >> m[i] ;

	for(i=1;i<=n;i++)
		cin >> c[i] ;

	for(i=0;i<=1000111;i++)st[i]=-1;
	used[0]=true;
	st[0]=0;

	for(i=1;i<=n;i++){
		for(j=s;j>=0;j--){
			if(used[j]){
				used[j+m[i]]=true;
				if(st[j]+c[i]>st[j+m[i]])st[j+m[i]]=st[j]+c[i];
			}
		}
	}
                                                        
	for(i=0;i<=s;i++){
		maxi=max(maxi,st[i]);
	}	
	cout<<maxi;             
	return 0;
}