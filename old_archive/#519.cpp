#include <string>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <functional>
#include <cstring>
// #include <>

using namespace std;

template <typename Iter> bool next_permutation(Iter first, Iter last)
{
    if (first == last)
        return false;
    Iter i = first;
    ++i;
    if (i == last)
        return false;
    i = last;
    --i;
        
    for(;;)
    {
        Iter ii = i;
        --i;
        if (*i < *ii)
        {
            Iter j = last;
            while (!(*i < *--j))
            {}
            std::iter_swap(i, j);
            std::reverse(ii, last);
            return true;
        }
        if (i == first)
        {
            std::reverse(first, last);
            return false;
        }
    }
}

int main () {

	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
	
	string s; cin >> s;
	sort (s.begin(), s.end());
	do {
		if (s[0] != '0')
			break;
	} while (::next_permutation (s.begin(), s.end()));
	cout << s << " ";
	sort (s.begin(), s.end());
	reverse (s.begin(), s.end());
	cout << s;
	return 0;
}
