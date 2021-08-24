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
        int k;
        string s;
        cin >> k >> s;
        vector<map<char, int>> v;
        map<char, int> mp;
        ll ans = 0;
        forn(i, sz(s) / k) {
            for (int j = i * k; j < (i + 1) * k; j++) {
                mp[s[j]]++;
            }
            ans += mp.size();
            v.pb(mp);
            mp.clear();
        }
        bool carry = 0;
        forn(i, sz(s) / k - 1) {
            for (auto x : v[i]) {
                if (v[i + 1][x.F]) {
                    ans--;
                    v[i + 1].erase(x.F);
                    break;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}