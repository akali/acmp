#include <iostream>
#include <string>
#include <sstream>
using namespace std;
struct lib_n
{
    string name;
    string type;
    int year;
} lib1,lib2;
//-----------------------------
void print (lib_n book)
{
    cout<<"name - "<<book.name<<endl;
    cout<<"type - "<<book.type<<endl;
    cout<<"year - "<<book.year<<endl;
}
int main()
{
    string str;
    lib1.name="The programming art";
    lib1.type="Informatics";
    lib1.year=2012;
    cout<<"Enter name of your libriary book";
    getline(cin,lib2.name);
    cout<<"Enter type of your libriary book";
    getline(cin,lib2.type);
    cout<<"Enter year of your libriary book";
    cin>>str;
    stringstream(str) >> lib2.year;

    cout<<"Mine ";
    print(lib1);
    cout<<"Your libriary book";
    print(lib2);
    return 0;
}
