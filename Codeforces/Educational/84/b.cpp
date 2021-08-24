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
const int MAX = 1e5 + 5;
int n;
vector<int> g[MAX];
void init() {
    forn(i, n + 1) {
        g[i].clear();
    }
}
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
        cin >> n;
        init();
        forn(i, n) {
            int k;
            cin >> k;
            forn(j, k) {
                int ki;
                cin >> ki;
                g[i].pb(ki - 1);
            }
        }
        vector<bool> prince(n + 1, 0);
        pair<int, int> ans;
        forn(i, n) {
            bool ok = 0;
            for (auto x : g[i]) {
                if (!prince[x]) {
                    prince[x] = 1;
                    ok = 1;
                    break;
                }
            }
            if (!ok) {
                ans.F = i + 1;
            }
        }
        bool ok = 0;
        forn(i, n) {
            if (!prince[i]) {
                ans.S = i + 1;
                ok = 1;
                break;
            }
        }
        if (ok) {
            cout << "IMPROVE" << endl;
            cout << ans.F << " " << ans.S << endl;
        } else {
            cout << "OPTIMAL" << endl;
        }
    }
    return 0;
}