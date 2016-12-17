#include <iostream>
#include <time.h>
using namespace std;
double time()
{
 return double(clock())/double(CLOCKS_PER_SEC);
}
int n,a[111][111],s[111];
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout); 
    cin>>n;
    for(int i=0;i<n;i++){
            cin>>a[i][0]>>a[i][1]>>a[i][2];
            s[i]=3600*a[i][0]+60*a[i][1]+a[i][2];
            }
    for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                    if(s[i]>s[j]){
                                  swap(s[i],s[j]);
                                  swap(a[i][0],a[j][0]);
                                  swap(a[i][1],a[j][1]);
                                  swap(a[i][2],a[j][2]); 
                    }
             }
     }

            for(int i=0;i<n;i++){
                    cout<<a[i][0]<<" "<<a[i][1]<<" "<<a[i][2]<<"\n";
                    }
              
   
   return 0;
}