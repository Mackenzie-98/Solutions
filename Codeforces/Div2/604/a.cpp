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
        int cur = 0;
        char abc[3] = {'a', 'b', 'c'};
        map<char, int> mp;
        int cnt = 0;
        bool ok = 1;
        forn(i, sz(s)) {
            bool mark[3] = {0, 0, 0};
            if (i > 0 && s[i - 1] != '?') {
                mark[s[i - 1] - 'a'] = 1;
            }
            if (i < sz(s) - 1 && s[i + 1] != '?') {
                mark[s[i + 1] - 'a'] = 1;
            }
            if (s[i] == '?') {
                forn(j, 3) {
                    if (!mark[j]) {
                        s[i] = abc[j];
                        ok = 1;
                        break;
                    }
                }
            }
            if (i < sz(s) - 1 && s[i] == s[i + 1]) {
                ok = 0;
                break;
            }
        }
        if (!ok)
            cout << -1 << endl;
        else
            cout << s << endl;
    }
    return 0;
}