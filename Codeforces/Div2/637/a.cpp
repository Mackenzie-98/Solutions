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

int n, a, b, c, d, x, y, p, q;
bool ans = 0;
// bool f(int i, int sum) {
//     cout << i << " " << sum << endl;
//     if (i == n && sum >= p && sum <= q) {
//         ans = 1;
//         return 1;
//     }
//     if (i > n) return 0;
//     for (int xi = x; xi <= y; xi++) {
//         f(i + 1, sum + xi);
//     }
// }
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
        cin >> n >> a >> b >> c >> d;
        x = a - b, y = a + b, p = c - d, q = c + d;
        vector<int> v(n, y);
        int total = n * y;
        bool ok = 1;
        if (total < p) ok = 0;
        if (total > q) {
            int dif = total - q;
            if (dif > n * (y - x)) ok = 0;
        }
        if (ok)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}