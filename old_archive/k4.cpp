#include <iostream>
#include <deque>
using namespace std;

int fact(int x){
	int sum=1;
	for(int i=2; i<=x; i++){
		sum*=i;
	}
	return sum;
}

int main(){
	int k4[13];
	int n;
	int k;
	cin>>n>>k;
	k--;
	for(int i=0; i<n; i++){
		k4[i]=k/fact(n-i-1);
		k%=fact(n-i-1);
		cout<<k4[i]<<" ";
	}
	cout<<endl;
	deque<int> ar;
	for(int i=0; i<n; i++){
		ar.push_back(i+1);
	}
	for(int i=0; i<n; i++){
			cout<<ar[k4[i]]<<" ";
			ar.erase(ar.begin()+k4[i]);
	}
	return 0;
}