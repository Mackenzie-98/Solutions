#include <bits/stdc++.h>
using namespace std;
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
int main() {
#ifdef LOCAL
    // freopen("h.txt", "r", stdin);
    // freopen("main.out", "w", stdout);
#else
    ios::sync_with_stdio(0), cin.tie(0);
#define endl '\n'
#endif
    string s, t;
    cin >> s >> t;
    int ans = 0;
    for (int i = 0; i <= sz(s) - 1; i++) {
        for (int j = i + 1; j <= sz(s); j++) {
            string cur = s.substr(0, i) + s.substr(j, sz(s) - j);
            int ind = 0;
            for (int k = 0; k < sz(cur) && ind < sz(t); k++) {
                if (cur[k] == t[ind]) {
                    ind++;
                }
            }
            if (ind == sz(t)) {
                ans = max(ans, j - i);
            }
            // cout << i << " " << j << " " << cur << endl;
        }
    }
    cout << ans << endl;
    // int ans = 0;
    // for (int i = 0; i < sz(s) - sz(t) + 1; i++) {
    //     cout << s.substr(i, sz(t)) << " " << i << " " << sz(s) - (i + sz(t))
    //          << endl;
    //     if (s.substr(i, sz(t)) == t) {
    //         ans = max(ans, max(i, sz(s) - (i + sz(t))));
    //     }
    // }
    // cout << ans << endl;
    // int r[sz(s)];
    // int l[sz(s)];
    // memset(r, 0, sizeof r);
    // memset(l, 0, sizeof l);
    // for (int i = 0; i < sz(s); i++) {
    //     char cur = t[0];
    //     int ind = 0;
    //     int cnt = 0;
    //     for (int j = 0; j <= i && ind < sz(t); j++) {
    //         // cout << s[j] << " " << cur << endl;
    //         if (s[j] == cur) {
    //             ind++;
    //             cur = t[ind];
    //             cnt++;
    //         }
    //     }
    //     r[i] = cnt;
    // }
    // for (int i = sz(s) - 1; i >= 0; i--) {
    //     char cur = t[sz(t) - 1];
    //     int ind = sz(t) - 1;
    //     int cnt = 0;
    //     for (int j = sz(s) - 1; j >= i && ind >= 0; j--) {
    //         // cout << s[j] << " " << cur << endl;
    //         if (s[j] == cur) {
    //             ind--;
    //             cur = t[ind];
    //             cnt++;
    //         }
    //     }
    //     l[i] = cnt;
    // }
    // for (auto x : r)
    //     cout << x << " "
    //          << " ";
    // cout << endl;
    // for (auto x : l)
    //     cout << x << " "
    //          << " ";
    // cout << endl;
    return 0;
}