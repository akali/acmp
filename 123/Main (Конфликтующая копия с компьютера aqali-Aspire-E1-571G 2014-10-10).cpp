#include <cstring>
#include <cstdio>

using namespace std;

long long d[2009][2009];
char s[100];

int main() {
    freopen("input.txt", "r", stdin);
    gets(s);


    int n = strlen(s);

    d[0][0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (s[i] == '?' || s[i] == '(')
                d[i + 1][j + 1] += d[i][j];
            if (j > 0 && (s[i] == '?' || s[i] == ')'))
                d[i + 1][j - 1] += d[i][j];
        }
    }
    freopen("output.txt", "w", stdout);
    printf("%I64d", d[n][0]);
}
