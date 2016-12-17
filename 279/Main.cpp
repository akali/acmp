#include <iostream>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <string>
#include <climits>
 
using namespace std;
 
bool calced[111][111];
string d[111][111], s;
int n;
 
string getFor (char g) {
    if (g == '(' || g == ')')
        return "()";
    else
        if (g == '[' || g == ']')
            return "[]";
        else
            return "{}";
}
 
string f (int l, int r) {
    if (l == r)
        return getFor (s[l]);
    if (r < l)
        return "";
    if ((s[l] == '(' && s[r] == ')') || (s[l] == '[' && s[r] == ']') || (s[l] == '{' && s[r] == '}'))
        return s[l] + f (l + 1, r - 1) + s[r];
    if (calced[l][r])
        return d[l][r];
    calced[l][r] = true;
    string res = "";
    int size = INT_MAX;
    for (int i = l; i < r; i++) {   
        string This = f (l, i) + f (i + 1, r);
        if (This.size() < size)
            res = This, size = res.size();
    }
    return d[l][r] = res;
}
 
bool check ()
{
    vector <char> st;
    st.push_back(s[0]);
    int ans = 0;
    for (int i = 1; i < n; i++) {
        if ((st.back() == '(' && s[i] == ']') || (st.back () == '[' && s[i] == ')')) {
            ans++;
            st.pop_back ();
        } else {
            if (st.back() == '(' && s[i] == ')')
                st.pop_back();
            else
                if (st.back() == '[' && s[i] == ']')
                    st.pop_back();
                else
                    st.push_back (s[i]);
        }
    }
    if (!st.empty ())
        cout << -1;
    else
        cout << ans;
    return true; // st.empty();
}
 
int main () {
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    cin >> s;
    n = s.size();
    if (check ()) {
        // cout << 0;
        return 0;
    }
    string res = f (0, n - 1);
    cerr << res << endl;
    int ans = res.size() - s.size();
    cout << ans;
    return 0;
}
