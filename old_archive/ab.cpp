/*
Using structures
Kali Aisultan
*/
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
struct PersonRec
{
string lastName;
string firstName;
int age;
};
typedef PersonRec PeopleArrayType[4]; //an array of 10 structs
void LoadArray(PeopleArrayType peop);
int main()
{
PeopleArrayType people; //a variable of the array type
LoadArray(people);
// output the array
for (int i = 0; i < 3; i++)
{
cout<<people[i].firstName<<" "<<people[i].lastName
    <<setw(3) << people[i].age;
}
}
void LoadArray(PeopleArrayType peop)
{
for (int i = 0; i < 3; i++)
{
cout << "Enter first name: ";
cin >> peop[i].firstName;
cout << "Enter last name: ";
cin >> peop[i].lastName;
cout << "Enter age: \n";
cin >> peop[i].age;
}
}
