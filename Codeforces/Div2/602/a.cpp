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
ll INF = 1e9 + 5;
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
        pii seg[n];
        int mn = INF, mx = -INF;
        forn(i, n) {
            int x, y;
            cin >> x >> y;
            seg[i] = {x, y};
            mn = min(mn, y);
            mx = max(mx, x);
        }
        sort(seg, seg + n);
        int left = 1e9, right = -1e9;
        for (int i = 0; i < n; i++) {
            if (left >= seg[i].F) {
                left = seg[i].S;
            }
            if (right <= seg[n - i - 1].S) {
                right = seg[n - i - 1].F;
            }
        }
        left = min(mn, left);
        right = max(mx, right);
        cout << max(0, right - left) << endl;
    }
    return 0;
}