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
        string s, h;
        cin >> s >> h;
        int sc[26];
        memset(sc, 0, sizeof sc);
        forn(i, sz(s)) {
            sc[s[i] - 'a']++;
        }
        bool ok = 0;
        for (int i = 0; i < sz(h); i++) {
            for (int j = i; j < sz(h); j++) {
                int hc[26];
                memset(hc, 0, sizeof hc);
                for (int k = i; k <= j; k++) {
                    hc[h[k] - 'a']++;
                }
                if (j - i + 1 == sz(s)) {
                    ok = 1;
                    for (auto x : s) {
                        if (sc[x - 'a'] != hc[x - 'a']) {
                            ok = 0;
                            break;
                        }
                    }
                }
                if (ok) {
                    goto done;
                }
            }
        }
    done:;
        if (ok)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}