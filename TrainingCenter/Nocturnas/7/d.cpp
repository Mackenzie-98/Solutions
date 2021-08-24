#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " = " << x << endl;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define F first
#define S second
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define pb push_back
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
string s1, s2;
const int MAX = 2e3 + 1;
int mem[MAX][MAX];
int dp(int i, int j) {
    // cout << i << " " << j << endl;
    if (i >= sz(s1) || j >= sz(s2)) {
        return 0;
    }
    int &ans = mem[i][j];
    if (ans != -1) return ans;
    ans = 0;
    if (s1[i] == s2[j]) {
        ans = max(ans, dp(i + 1, j + 1) + 2);
    } else if ((s1[i] == tolower(s2[j])) || (s2[j] == tolower(s1[i]))) {
        ans = max(ans, dp(i + 1, j + 1) + 1);
    } else {
        ans = max(ans, max(dp(i + 1, j), dp(i, j + 1)));
    }
    return ans;
}
int main() {
#ifdef LOCAL
    // freopen("h.txt", "r", stdin);
    // freopen("main.out", "w", stdout);
#else
    ios::sync_with_stdio(0), cin.tie(0);
#define endl '\n'
#endif
    while (cin >> s1 >> s2) {
        memset(mem, 0, sizeof mem);
        mem[0][0] = 0;
        for (int i = 1; i <= sz(s1); i++) {
            for (int j = 1; j <= sz(s2); j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    mem[i][j] = mem[i - 1][j - 1] + 2;
                } else if ((s1[i - 1] == tolower(s2[j - 1])) ||
                           (s2[j - 1] == tolower(s1[i - 1]))) {
                    mem[i][j] = max(mem[i][j], mem[i - 1][j - 1] + 1);
                } else {
                    mem[i][j] = max(mem[i - 1][j], mem[i][j - 1]);
                }
            }
        }
        cout << mem[sz(s1)][sz(s2)] << endl;
    }
    return 0;
}