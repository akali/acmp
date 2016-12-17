#include <iostream>
using namespace std;

int x,i,Q1[1111],Q2[1111] ,j,y;

void push(int i)
{
x++;Q1[x]=i;
}
void push2(int i)
{
y++;Q2[y]=i;
}
int main()
{
freopen ("input.txt","r",stdin);
freopen ("output.txt","w",stdout);

int x1,y1,x2,y2,N;
int used[111][111],dis[111][111];
cin>>N;
cin>>x1>>y1;
cin>>x2>>y2;
for(i=1;i<=N;i++){for(j=1;j<=N;j++){used[i][j]=0;}}
used[x1][y1]=1;
push(x1);
push2(y1);
int d=0 ,uk=1;
dis[x1][y1]=0;
while(used[x2][y2]!=1)
{x1=Q1[uk];
 y1=Q2[uk];

    if(x1-2>0 && y1-1>0 && used[x1-2][y1-1]==0){used[x1-2][y1-1]=1;push(x1-2);push2(y1-1);dis[x1-2][y1-1]=dis[x1][y1]+1;}
    if(x1-2>0 && y1+1<=N && used[x1-2][y1+1]==0){used[x1-2][y1+1]=1;push(x1-2);push2(y1+1);dis[x1-2][y1+1]=dis[x1][y1]+1;}
    if(x1-1>0 && y1-2>0 && used[x1-1][y1-2]==0){used[x1-1][y1-2]=1;push(x1-1);push2(y1-2);dis[x1-1][y1-2]=dis[x1][y1]+1;}
    if(x1-1>0 && y1+2<=N && used[x1-1][y1+2]==0){used[x1-1][y1+2]=1;push(x1-1);push2(y1+2);dis[x1-1][y1+2]=dis[x1][y1]+1;}
    if(x1+1<=N && y1+2<=N && used[x1+1][y1+2]==0){used[x1+1][y1+2]=1;push(x1+1);push2(y1+2);dis[x1+1][y1+2]=dis[x1][y1]+1;}
    if(x1+1<=N && y1-2>0 && used[x1+1][y1-2]==0){used[x1+1][y1-2]=1;push(x1+1);push2(y1-2);dis[x1+1][y1-2]=dis[x1][y1]+1;}
    if(x1+2<=N && y1-1>0 && used[x1+2][y1-1]==0){used[x1+2][y1-1]=1;push(x1+2);push2(y1-1);dis[x1+2][y1-1]=dis[x1][y1]+1;}
    if(x1+2<=N && y1+1<=N && used[x1+2][y1+1]==0){used[x1+2][y1+1]=1;push(x1+2);push2(y1+1);dis[x1+2][y1+1]=dis[x1][y1]+1;}
    d++;uk++;


}
cout<<dis[x2][y2];


return 0;
}