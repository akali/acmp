/*
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
~~~Programm about structs;~~~
~~Structures can be pointed~~
~~by &,* and other pointers~~
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
struct film
{
    string name;
    int year;
};

int main()
{
    string str;
    film a_film;
    film * b_film;
    b_film=&a_film;

    cout<<"Enter name - \n";
    getline (cin,b_film->name);
    cout<<"Enter year of the film - \n";
    getline(cin,str);
    (stringstream) str>>b_film->year;

    cout<<"Your favorite is:\n"<<b_film->name<<"("<<b_film->year <<")";
    return 0;
}
