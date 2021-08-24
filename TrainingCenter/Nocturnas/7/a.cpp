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
const int MAX = 2e3 + 5;
ll mem[MAX][MAX];
ll dp(int i, int j) {
    // cout << i << " " << j << endl;
    if (i >= sz(s1) || j >= sz(s2)) {
        return 0;
    }
    ll &ans = mem[i][j];
    // if (ans != -1) return ans;
    ans = 0;
    if (s1[i] == s2[j]) {
        ans = max(ans, dp(i + 1, j + 1) + 2);
    } else if ((s1[i] == tolower(s2[j])) || (s2[j] == tolower(s1[i]))) {
        ans = max(ans, max(dp(i + 1, j) + 1, dp(i, j + 1) + 1));
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
        memset(mem, -1, sizeof mem);
        cout << dp(0, 0) << endl;
        // forn(i, sz(s1)) {
        //     forn(j, sz(s2)) { cout << mem[i][j] << " "; }
        //     cout << endl;
        // }
    }
    return 0;
}