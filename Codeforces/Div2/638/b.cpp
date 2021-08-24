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
        int n, k;
        cin >> n >> k;
        vector<int> v(n);
        map<int, int> mp;
        vector<int> ans;
        forn(i, n) {
            cin >> v[i];
            if (!mp[v[i]]) ans.pb(v[i]);
            mp[v[i]]++;
        }
        int aux = sz(ans);
        if (sz(ans) < k) {
            forn(i, k - aux) ans.pb(ans[i % aux]);
        }
        if (mp.size() > k)
            cout << -1 << endl;
        else {
            int cnt = 0;
            int ind = 0;
            vector<int> printed;
            while (ind < n) {
                // cout << v[ind] << " " << ans[cnt % sz(ans)] << endl;
                if (v[ind] == ans[cnt % k])
                    printed.pb(v[ind]), cnt++, ind++;
                else
                    printed.pb(ans[cnt % k]), cnt++;
            }
            cout << sz(printed) << endl;
            forn(i, sz(printed)) cout << printed[i] << " ";
            cout << endl;
        }
    }
    return 0;
}