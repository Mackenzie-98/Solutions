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
    int casos = 0;
    while (t--) {
        casos++;
        string s;
        cin >> s;
        s = "0" + s;
        s = s + "0";
        vector<pii> v(sz(s) - 2, {0, 0});
        forn(i, sz(v)) {
            v[i].F = max(0, (s[i + 1] - '0') - (s[i] - '0'));
            v[i].S = max(0, (s[i + 1] - '0') - (s[i + 2] - '0'));
        }
        string ans = "";
        forn(i, sz(v)) {
            forn(j, v[i].F) ans += "(";
            ans += s[i + 1];
            forn(j, v[i].S) ans += ")";
        }
        cout << "Case #" << casos << ": " << ans << endl;
    }
    return 0;
}