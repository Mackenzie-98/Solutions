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

int main() {
#ifdef LOCAL
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
    fastIO;
#endif
    int n, r;
    cin >> n >> r;
    vector<int> a(n);
    forn(i, n) cin >> a[i];
    vector<int> v(n, 0);
    int ans = 0;
    forn(i, n) {
        if (a[i]) {
            ans++;
            for (int x = max(0, i - r + 1); x <= min(n - 1, i + r - 1); x++) {
                v[x]++;
            }
        }
    }
    forn(i, n) {
        if (a[i]) {
            bool ok = 1;
            for (int x = max(0, i - r + 1); x <= min(n - 1, i + r - 1) && ok; x++) {
                if (v[x] == 1) ok = 0;
            }
            if (ok) {
                ans--;
                for (int x = max(0, i - r + 1); x <= min(n - 1, i + r - 1) && ok; x++) {
                    v[x]--;
                }
            }
        }
    }
    bool ok = 1;
    forn(i, n) if (!v[i]) ok = 0;
    // forn(i, n) cout << v[i] << " ";
    // cout << endl;
    if (ok)
        cout << ans << endl;
    else
        cout << -1 << endl;
    return 0;
}