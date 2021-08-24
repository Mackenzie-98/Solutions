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
typedef pair<ll, ll> pll;
bool cmp(pair<ll, char> a, pair<ll, char> b) { return a.F < b.F; }
int main() {
#ifdef LOCAL
    // freopen("h.txt", "r", stdin);
    // freopen("main.out", "w", stdout);
#else
    ios::sync_with_stdio(0), cin.tie(0);
#define endl '\n'
#endif
    int t;
    cin >> t;
    while (t--) {
        int n, b, m, e;
        cin >> n >> b >> m >> e;
        vector<pair<ll, char>> time;
        forn(i, n) {
            ll x, y;
            char c;
            cin >> x >> y >> c;
            ll dis = x * x + y * y;
            ll v = 0;
            if (c == 'Z') v = 16;
            if (c == 'F') v = 4;
            if (c == 'V') v = 1;
            time.pb({dis * v, c});
        }
        sort(all(time), cmp);
        // for (auto x : time) cout << x.F << " " << x.S << endl;
        bool ok = 1;
        ll cnt = 0;
        forn(i, n) {
            if (time[i].S == 'Z') b--;
            if (time[i].S == 'F') m--;
            if (time[i].S == 'V') e--;
            if (b < 0 || m < 0 || e < 0) {
                ok = 0;
                break;
            }
            cnt++;
        }
        if (ok)
            cout << "Sobrevivi" << endl;
        else
            cout << cnt << endl;
    }
    return 0;
}
