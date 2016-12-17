#include <iostream>
#define W stream
int Q(int m,int n)
{
 return (n ? Q(n,m%n) : m);
}
int main()
{
 int n,m;
 std:: ifW ("input.txt") >>n>>m;
 std:: ofW ("output.txt") <<n/Q(n,m);
}