#include <iostream>
#include <vector>
using namespace std;

int n,i,a[100],j,s,k;
bool used[1000];
vector < int > v[1000];

int main()
{
	cin >> n >> s;
	
	for(i=1;i<=n;i++)
		cin >> a[i] ;

	used[0]=true;

	for(i=1;i<=n;i++){
		for(j=s;j>=0;j--){
			if(used[j]){
				if(used[j+a[i]]){
					if(v[j].size()+1<v[j+a[i]].size()){
						while(v[j+a[i]].size()>0)v[j+a[i]].pop_back();
						for(k=0;k<v[j].size();k++){
							v[j+a[i]].push_back(v[j][k]);
						}
						v[j+a[i]].push_back(a[i]);
					}	
				}
				else {
					for(k=0;k<v[j].size();k++){
						v[j+a[i]].push_back(v[j][k]);
					}
					v[j+a[i]].push_back(a[i]);

				}
				
				used[j+a[i]]=true;
			}
		}
	}

	if(used[s]){	
		//cout<<"Yes"<<endl;
		for(i=0;i<v[s].size();i++)
			cout<<v[s][i]<<" ";
	}
	else cout<<"0";	                        
	             
	return 0;
}