#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <string.h>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <stdlib.h> // for exit(0)
#include <stack>
#include <list>
#include <ctime>
#include <set>
 
using namespace std;
 
typedef unsigned long long UINT;
int n;
struct volume {
    int value;
    string unit;
    double sort_value;
    volume(){}
    void input() {
        char buf[10];
        scanf("%d %s\n", &value, &buf);
        unit = string(buf);
        int pos = 0;
        double mul = 1;
        switch(buf[pos]) {
            case 'm': mul = 1e-3 ; pos++; break;
            case 'k': mul = 1e3;  pos++; break;
            case 'M': mul = 1e6;  pos++; break;
            case 'G': mul = 1e9;  pos++; break;
        }
        switch(buf[pos]) {
            case 'g': mul *= 1; break;
            case 'p': mul *= 16380; break;
            case 't': mul *= 1e6; break;
        }
        sort_value = value * mul;
    }
    void output() {
        printf("%d %s\n",value,unit.c_str());
    }
};
string units[] = {"mg", "g", ""};
bool operator < (const volume &a, const volume &b) {
    return a.sort_value < b.sort_value;
}
vector<volume> mas;
void input(){
    scanf("%d", &n);
    mas.resize(n);
    for (int i=0;i<n;++i)
        mas[i].input();
}
void output() {
    for (int i=0;i<mas.size();++i)
        mas[i].output();
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
 
    input();
    sort(mas.begin(), mas.end());
    output();
 
    return 0;
}
