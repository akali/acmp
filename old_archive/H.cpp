#include <iostream>
using namespace std;

int n,i,a[100],j,s;
bool used[1000000];

int main()
{
	cin >> n >> s;
	
	for(i=1;i<=n;i++)
		cin >> a[i] ;

	used[0]=true;

	for(i=1;i<=n;i++){
		for(j=s;j>=0;j--){
			if(used[j])used[j+a[i]]=true;
		}
	}

	if(used[s])cout<<"YES";
	else cout<<"NO";	                        
	             
	return 0;
}