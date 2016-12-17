#include <fstream>
#include <queue>
#include <string>
using namespace std;

int main(){
	ifstream  cin("input.txt");
	ofstream cout("output.txt");
	string str;
	int n;
	queue <string> st9;
	queue <string> st10;
	queue <string> st11;
	while(cin>>n){
		cin>>str;
		if(n==9)
			st9.push(str);
		else if(n==10)
			st10.push(str);
		else if(n==11)
			st11.push(str);
	}
	while(!st9.empty()){
		cout<<9<<" "<<st9.front();
		cout<<endl;
		st9.pop();
	}
	while(!st10.empty()){
		cout<<10<<" "<<st10.front();
		cout<<endl;
		st10.pop();
	}
	while(!st11.empty()){
		cout<<11<<" "<<st11.front();
		cout<<endl;	
		st11.pop();
	}
	return 0;
}