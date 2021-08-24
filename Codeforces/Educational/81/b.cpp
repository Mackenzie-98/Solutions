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
        ll n, x;
        cin >> n >> x;

        string s;
        cin >> s;
        int ans = 0;
        map<int, int> mp;
        forn(i, n) {
            mp[s[i] - '0']++;
        }
        ll d = mp[0] - mp[1];
        ll cur = 0;
        bool ok = 1;
        mp.clear();
        forn(i, n) {
            mp[s[i] - '0']++;
            if (d == 0) {
                if (cur == x) ok = 0;
            } else {
                if (abs(x - cur) % abs(d) == 0 && (x - cur) / d >= 0) ans++;
            }
            cur = mp[0] - mp[1];
        }
        if (!ok)
            cout << -1 << endl;
        else
            cout << ans << endl;
    }
    return 0;
}