#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
    vector <int> a;
    vector <int> b;
    vector <int> c;
    string s3,s1,s2;
    cin>>s1>>s2>>s3;
    for (int i=(int)s1.length(); i>0; i-=9)
	if (i < 9)
		a.push_back (atoi (s1.substr (0, i).c_str()));
	else
		a.push_back (atoi (s1.substr (i-9, 9).c_str()));
    //-------------------------------------------------
        for (int i=(int)s2.length(); i>0; i-=9)
	if (i < 9)
		b.push_back (atoi (s2.substr (0, i).c_str()));
	else
		b.push_back (atoi (s2.substr (i-9, 9).c_str()));
    //-------------------------------------------------
        for (int i=(int)s3.length(); i>0; i-=9)
	if (i < 9)
		c.push_back (atoi (s3.substr (0, i).c_str()));
	else
		c.push_back (atoi (s3.substr (i-9, 9).c_str()));
    //-------------------------------------------------
    //-------------------------------------------------
    while (a.size() > 1 && a.back() == 0)
	a.pop_back();
	//--
	while (b.size() > 1 && b.back() == 0)
	b.pop_back();
	//--
	while (c.size() > 1 && c.back() == 0)
    c.pop_back();
    //-------------------------------------------------
    int massOne[4] = {0,1,2,2};
    int massTwo[5] = {2,4,0,1,0};

    int i,j;

    for(i=0; i<4; i++)
    {
        for(j=0; j<5; j++)
        {
            if( massOne[i] == massTwo[j])
            {
                cout << "massOne[" << i << "]= " << massOne[i] << "  == massTwo[" << j << "]=" << massTwo[j] << endl;
            }
        }
    }
}
