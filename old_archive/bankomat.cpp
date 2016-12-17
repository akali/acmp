#include <fstream>
#include <algorithm>
using namespace std;
int dp[1000001];

int main(){
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	int w[101];
	int n,k;
	cin>>n;
	for(int i=0; i<n; i++)
		cin>>w[i];
	cin>>k;
	for(int i=0; i<=k; i++)
		dp[i]=-1;
	dp[0]=0;
	for(int j=0; j<=k; j++){
		for(int i=0; i<n; i++){
			if(dp[j]>-1&&(j+w[i])<=k){
				if(dp[j+w[i]]==-1)
					dp[j+w[i]]=dp[j]+1;
				else
					dp[j+w[i]]=min(dp[j+w[i]],dp[j]+1);
			}
		}
	}
	if(dp[k]==-1) cout<<"No solution";
	else{
		for (int j=k; j>=0; j--)
		{
			for(int i=n-1; i>=0; i--){
				if(j>=w[i]){
				if(dp[j-w[i]]==dp[j]-1){
					cout<<w[i]<<" ";
					j-=w[i];
				}
				}
			}
		}
	}
	cout<<endl;
	/*for (int i=0; i<=k; i++)
	{
		cout<<i<<" "<<dp[i]<<endl;
	}*/
	return 0;
}