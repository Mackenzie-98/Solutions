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
bool cmp1(pair<pii, int> a, pair<pii, int> b) {
    if (a.F.F != b.F.F)
        return a.F.F < b.F.F;
    else
        return a.F.S < b.F.S;
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
    int casos = 0;
    while (t--) {
        casos++;
        int n;
        cin >> n;
        vector<pair<pii, int>> v(n);
        forn(i, n) cin >> v[i].F.F >> v[i].F.S, v[i].S = i;
        sort(all(v), cmp1);
        string op[] = {"C", "J"};
        int cur = 0;
        string ans = op[cur];
        bool ok = 1;
        for (int i = 1; i < n && ok; i++) {
            //cout << v[i].F.F << " " << v[i].F.S << endl;
            int cnt = 0;
            for (int j = 0; j < i; j++) {
                if (v[i].F.F < v[j].F.S) cnt++;
            }
            if (cnt >= 2) ok = 0;
            if (v[i].F.F < v[i - 1].F.S) {
                cur ^= 1;
                ans += op[cur];
            } else {
                ans += op[cur];
            }
        }
        cout << "Case #" << casos << ": ";
        if (!ok)
            cout << "IMPOSSIBLE" << endl;
        else {
            vector<string> ans2(n, "");
            forn(i, n) {
                ans2[v[i].S] = ans[i];
            }
            forn(i, n) cout << ans2[i];
            cout << endl;
        }
    }
    return 0;
}