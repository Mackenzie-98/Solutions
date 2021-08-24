#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define F first
#define S second
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define pb push_back
#define fastIO ios::sync_with_stdio(0), cin.tie(0);
#define endl '\n'
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
int main() {
#ifdef LOCAL
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
    fastIO;
#endif
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int x = 0, y = 0;
        int u = 0, d = 0, r = 0, l = 0;
        int cnt = 0;
        forn(i, sz(s)) {
            if (x == 0 && y == 0) {
                cnt++;
            }
            if (s[i] == 'U') y++, u++;
            if (s[i] == 'D') y--, d++;
            if (s[i] == 'R') x++, r++;
            if (s[i] == 'L') x--, l++;
        }
        // if (x == 0 && y == 0) {
        //     cout << 2 << endl;
        //     cout << "RL" << endl;
        // } else {
        if (x > 0) {
            r -= x;
        }
        if (x < 0) {
            l -= -x;
        }
        if (y > 0) {
            u -= y;
        }
        if (y < 0) {
            d -= -y;
        }
        if (u == 0 || d == 0) {
            r = min(1, r);
            l = min(1, l);
        }
        if (r == 0 || l == 0) {
            u = min(1, u);
            d = min(1, d);
        }
        cout << r + l + d + u << endl;
        forn(i, l) cout << "L";
        forn(i, u) cout << "U";
        forn(i, r) cout << "R";
        forn(i, d) cout << "D";
        cout << endl;
        // }
    }
    return 0;
}