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
const double eps = 1e-12;
bool check(ll r, vector<pii> z, vector<pii> m) {
    int cnt = 0;
    map<pii, bool> mp;
    for (auto x : m) {
        for (auto y : z) {
            ll dis = ((x.F - y.F) * (x.F - y.F) + (x.S - y.S) * (x.S - y.S));
            //cout << dis << " ";
            if (dis <= r) {
                mp[{y.F, y.S}] = 1;
            }
        }
    }
    for (auto x : z) {
        if (mp[{x.F, x.S}]) cnt++;
    }
    return cnt == sz(z);
}
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
        int n, m;
        cin >> m >> n;
        vector<pii> mines;
        vector<pii> zombies;
        forn(i, n) {
            string s;
            cin >> s;
            forn(j, m) {
                if (s[j] == 'Z') {
                    zombies.pb({i, j});
                }
                if (s[j] == 'M') {
                    mines.pb({i, j});
                }
            }
        }
        ll l = 0, h = 1e9;
        ll mid = 0;
        for (int it = 0; it < 70; it++) {
            mid = (l + h) / 2;
            //cout << mid << endl;
            if (check(mid, zombies, mines)) {
                h = mid;
            } else {
                l = mid;
            }
        }
        cout << fixed << setprecision(9) << sqrt(h) << endl;
    }
    return 0;
}