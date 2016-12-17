#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;
 
int x,Q1[1001],Q2[1001],y;
 
int x1,y1,x2,y2,n;
int dis[1001][1001];
bool u[1001][1001];

void push(int i){Q1[++x]=i;}
void push2(int i){Q2[++y]=i;}

int main() {
	freopen ("input.txt","r",stdin);
	freopen ("output.txt","w",stdout);
 
	cin>>n;
	cin>>x1>>y1;
	cin>>x2>>y2;
  
	push(x1);
	push2(y1);
 
	int c=1;
	while(u[x2][y2] == 0) {
		x1 = Q1[c];
		y1 = Q2[c];
 
		if(x1 - 2 > 0  && y1 - 1 > 0  && !u[x1 - 2][y1 - 1]){u[x1 - 2][y1 - 1] = true;push(x1-2); push2(y1-1); dis[x1-2][y1-1] = dis[x1][y1]+1;}
		if(x1 - 2 > 0  && y1 + 1 <= n && !u[x1 - 2][y1 + 1]){u[x1 - 2][y1 + 1] = true;push(x1-2); push2(y1+1); dis[x1-2][y1+1] = dis[x1][y1]+1;}
		if(x1 - 1 > 0  && y1 - 2 > 0  && !u[x1 - 1][y1 - 2]){u[x1 - 1][y1 - 2] = true;push(x1-1); push2(y1-2); dis[x1-1][y1-2] = dis[x1][y1]+1;}
		if(x1 - 1 > 0  && y1 + 2 <= n && !u[x1 - 1][y1 + 2]){u[x1 - 1][y1 + 2] = true;push(x1-1); push2(y1+2); dis[x1-1][y1+2] = dis[x1][y1]+1;}
		if(x1 + 1 <= n && y1 + 2 <= n && !u[x1 + 1][y1 + 2]){u[x1 + 1][y1 + 2] = true;push(x1+1); push2(y1+2); dis[x1+1][y1+2] = dis[x1][y1]+1;}
		if(x1 + 1 <= n && y1 - 2 > 0  && !u[x1 + 1][y1 - 2]){u[x1 + 1][y1 - 2] = true;push(x1+1); push2(y1-2); dis[x1+1][y1-2] = dis[x1][y1]+1;}
		if(x1 + 2 <= n && y1 - 1 > 0  && !u[x1 + 2][y1 - 1]){u[x1 + 2][y1 - 1] = true;push(x1+2); push2(y1-1); dis[x1+2][y1-1] = dis[x1][y1]+1;}
		if(x1 + 2 <= n && y1 + 1 <= n && !u[x1 + 2][y1 + 1]){u[x1 + 2][y1 + 1] = true;push(x1+2); push2(y1+1); dis[x1+2][y1+1] = dis[x1][y1]+1;}
		
		c++;
	}
	cout<<dis[x2][y2];
	return 0;
}