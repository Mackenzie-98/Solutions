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
        int n;
        cin >> n;
        int sum = 0;
        int zeros = 0;
        vector<int> a;
        forn(i, n) {
            int v;
            cin >> v;
            a.pb(v);
            sum += v;
            if (v == 0) zeros++;
        }
        int ans = 0;
        forn(i, n) {
            if (a[i] == 0) sum++, ans++;
        }
        if (sum == 0) ans++;
        cout << ans << endl;
    }
    return 0;
}