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
    int cases = 0;
    while (t--) {
        cases++;
        int n, k;
        cin >> n >> k;
        vector<int> p;
        forn(i, n) {
            forn(j, n) {
                p.pb(i + 1);
            }
        }
        bool ok = 0;
        int cnt = 0;
        do {
            // int ki = 0;
            // ll sum = 0;
            // do {
            //     sum += p[ki];
            //     ki += n + 1;
            // } while (ki <= n * n - 1);
            set<int> s1, s2;
            bool ok1 = 1, ok2 = 1;
            forn(i, n) {
                forn(j, n) {
                    s1.insert(p[n * i + j]);
                    s2.insert(p[n * j + i]);
                }
                ok1 &= sz(s1) == n;
                ok2 &= sz(s2) == n;
                s1.clear();
                s2.clear();
            }
            if (ok1 && ok2) {
                cnt++;
                cout << endl;
                forn(i, n * n) {
                    if ((i + 1) % n == 0)
                        cout << p[i] << endl;
                    else
                        cout << p[i] << " ";
                }
                cout << endl;
            }
        } while (next_permutation(all(p)));
        cout << cnt << endl;
        // if (ok) {
        //     cout << "Case #" << cases << ": POSSIBLE" << endl;
        //     forn(i, n * n) {
        //         if ((i + 1) % n == 0)
        //             cout << p[i] << endl;
        //         else
        //             cout << p[i] << " ";
        //     }
        // } else {
        //     cout << "Case #" << cases << ": IMPOSSIBLE" << endl;
        // }
    }
    return 0;
}