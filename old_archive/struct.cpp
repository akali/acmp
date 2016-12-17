#include <iostream>
#include <string>
using namespace std;
struct com
{
    string company;
    string core;
    int year;
} comp;

int main()
{
    cout<<"What is your computers company - ";
    getline(cin,comp.company);
    cout<<"What is your computers core - ";
    getline(cin,comp.core);
    cout<<"Year - ";
    cin>>comp.year;

    cout<<"Your computers company is "<<comp.company<<"\n";
    cout<<"Your computers core    is "<<comp.core<<"\n";
    cout<<"Your computers year    is "<<comp.year<<"\n";
    return 0;
}
