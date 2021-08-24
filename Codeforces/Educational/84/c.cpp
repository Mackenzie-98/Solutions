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
    int n, m, k;
    cin >> n >> m >> k;
    forn(i, 2 * k) {
        int x, y;
        cin >> x >> y;
    }
    string ans = "";
    forn(i, n - 1) ans += "U";
    forn(i, m - 1) ans += "L";
    forn(i, n) {
        forn(j, m - 1) {
            if (i % 2 == 0) {
                ans += "R";
            } else {
                ans += "L";
            }
        }
        if (i != n - 1)
            ans += "D";
    }
    cout << sz(ans) << endl;
    cout << ans << endl;
    return 0;
}