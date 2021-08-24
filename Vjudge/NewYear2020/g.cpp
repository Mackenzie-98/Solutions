#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define F first
#define S second
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define pb push_back
#define fastIO ios::sync_with_stdio(0), cin.tie(0);
#define endl '\n'
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
int main() {
#ifdef LOCAL
    // freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#else
    fastIO;
#endif
    int t;
    cin >> t;
    while (t--) {
        int w, n;
        cin >> w >> n;
        vector<pii> v;
        ll prefix[n];
        memset(prefix, 0, sizeof prefix);
        forn(i, n) {
            int xi, wi;
            cin >> xi >> wi;
            v.pb({xi, wi});
        }
        prefix[0] = v[0].F;
        forn(i, n - 1) {
            prefix[i + 1] = (v[i + 1].F - v[i].F) + prefix[i];
        }
        // forn(i, n) cout << prefix[i] << " ";
        // cout << endl;
        ll ans = 0;
        ll acum = 0;
        int i = 0;
        bool ok = 0;
        while (i < sz(v)) {
            acum += v[i].S;
            ok = 0;
            if (acum > w) {
                ans += 2 * prefix[i];
                acum = 0;
                continue;
                //cout << acum << " " << ans << endl;
            }
            if (acum == w) {
                ok = 1;
                ans += (i == sz(v) - 1 ? prefix[i] : 2 * prefix[i]);
                acum = 0;
                //cout << acum << " " << ans << endl;
            }
            ans += v[i].F - (i == 0 ? 0 : v[i - 1].F);
            //cout << acum << " " << ans << endl;
            i++;
        }
        //cout << ans << endl;
        cout << ans + (ok ? 0 : prefix[n - 1]) << endl;
    }
    return 0;
}