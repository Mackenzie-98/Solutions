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
        string s;
        cin >> s;
        vector<string> ans;
        forn(i, sz(s)) {
            if (s[i] != '0') {
                string c(sz(s) - i - 1, '0');
                c = s[i] + c;
                ans.pb(c);
            }
        }
        cout << sz(ans) << endl;
        forn(i, sz(ans)) cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}