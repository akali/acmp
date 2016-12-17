#include <iostream>
#include <string>
#include <sstream>
using namespace std;
struct notebook
{
    string com;
    int year;
    string core;
} book[5];

void print(notebook c)
{
    cout<<"Company name"<<c.com<<"\n";
    cout<<"Year"<<c.year<<"\n";
    cout<<"Core type"<<c.core<<"\n";
}

int main()
{
    string str;
    int i;
    for(i=0;i<3;i++)
    {
        cout<<"Your notebook company - ";
        getline(cin,book[i].com);
        cout<<"Your notebook year - ";
        getline(cin,str);
        cout<<"Your notebook core - ";
        getline(cin,book[i].core);
        stringstream(str) >> book[i].year;
    }

    cout<<"Your notebooks";
    for(i=0;i<3;i++)
    {
        print(book[i]);
    }
    return 0;
}
