#include <iostream>

using namespace std;

int main()
{
        char ** strArr;
        const int size=2;
        strArr = new char*[size];

        for(int i=0; i<size; i++)
        {
                cout<<"Input string:"<<endl;
                strArr[i] = new char[255];
                cin.getline(strArr[i], 255);
        }

        // Print string array and free memory
        for(int i=0; i<size; i++)
        {
                cout<<strArr[i]<<endl;
                delete [] strArr[i];
        }
        delete [] strArr;

}
