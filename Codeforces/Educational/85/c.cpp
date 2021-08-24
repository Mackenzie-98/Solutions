/**
 * @author: Mackenzie
**/
#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define F first
#define S second
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define pb push_back
#define fastIO ios::sync_with_stdio(0), cin.tie(0)
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
bool cmp(pair<pll, int> a, pair<pll, int> b) {
    if (a.F != b.F) return a.F < b.F;
    return a.S > b.S;
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
        int n;
        cin >> n;
        vector<pair<pll, int>> v(n), sorted(n);
        forn(i, n) cin >> v[i].F.F >> v[i].F.S, v[i].S = i, sorted[i] = {{v[i].F.F, v[i].F.S}, v[i].S};
        sort(all(sorted));
        ll ans = 0;
        bool mark[n];
        memset(mark, 0, sizeof mark);
        forn(i, n) {
            pair<pll, int> cur = sorted[i];
            if (!mark[cur.S]) {
                mark[cur.S] = 1;
                ans += v[cur.S].F.F;
                v[cur.S].F.F = 0;
                int next = (cur.S + 1) % n;
                while (!mark[next] && v[next].F.F < v[(next - 1 + n) % n].F.S) {
                    v[next].F.F -= v[(next - 1 + n) % n].F.S;
                    mark[next] = 1;
                    next = (next + 1) % n;
                }
                v[next].F.F -= v[(next - 1 + n) % n].F.S;
                if (v[next].F.F <= 0) mark[next] = 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}