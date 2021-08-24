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
    int n, c, k;
    while (cin >> n >> c >> k && !(n == 0 && c == 0 && k == 0)) {
        map<int, int> mp;
        forn(i, n) {
            forn(j, c) {
                int v;
                cin >> v;
                mp[v]++;
            }
        }
        int mn = 1e9;
        forn(i, k) {
            mn = min(mp[i + 1], mn);
        }
        vector<int> ans;
        for (auto x : mp) {
            if (x.S == mn) {
                ans.pb(x.F);
            }
        }
        sort(all(ans));
        forn(i, sz(ans)) {
            cout << ans[i] << (i == sz(ans) - 1 ? "" : " ");
        }
        cout << endl;
    }
    return 0;
}