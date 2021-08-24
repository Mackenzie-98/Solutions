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
    // freopen("out.txt", "w", stdout);
#else
    fastIO;
#endif
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> p;
        forn(i, n) {
            int v;
            cin >> v;
            p.pb(v);
        }
        vector<int> l, r;
        int mn = 1e9;
        pii dir[n];
        forn(i, n) {
            mn = min(mn, p[i]);
            l.pb(mn);
            dir[i].F = mn;
        }
        mn = 1e9;
        for (int i = n - 1; i >= 0; i--) {
            mn = min(mn, p[i]);
            r.pb(mn);
            dir[i].S = mn;
        }
        reverse(all(l));
        reverse(all(r));
        // for (auto x : l) cout
        //                      << x << " ";
        // cout << endl;
        // for (int x : r) cout
        //                     << x << " ";
        // cout << endl;
        bool mark[n];
        memset(mark, 0, sizeof mark);
        forn(i, n) {
            //cout << dir[i].F << " " << dir[i].S << " ";
            int left = n - ((upper_bound(all(l), p[i] - 1) - l.begin()));
            int right = upper_bound(all(r), p[i] - 1) - r.begin() - 1;
            left = min(left, i);
            right = max(i, right);
            //cout << left << " " << right << endl;
            if (right - left + 1 == p[i]) {
                mark[p[i] - 1] = 1;
            }
            // if (right - left + 1 == p[i]) {
            //     cout << 1;
            // } else {
            //     cout << 0;
            // }
        }
        for (auto x : mark) cout << x;
        cout << endl;
    }
    return 0;
}