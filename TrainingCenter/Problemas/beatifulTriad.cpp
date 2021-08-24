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
    // for (int n = 0; n <= 10; n++) {
    //     for (int k = 0; k <= 10; k++) {
    //         ll cnt = 0;
    //         for (int a = 0; a <= n; a++) {
    //             for (int b = 0; b <= n; b++) {
    //                 for (int c = 0; c <= n; c++) {
    //                     if (abs(a - b) <= k && abs(b - c) <= k && abs(a - c) <= k) cnt++;
    //                 }
    //             }
    //         }
    //         cout << "n = " << n << " k = " << k << " ans = " << cnt << endl;
    //     }
    // }
    int t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        ll x = k - 1;
        k = min(k, n);
        cout << (n + 1 - k) * (1 + 3 * k * k + 3 * k) + (k == 0 ? 0 : (x * x * x + 3 * x * x + 3 * x + 1)) << endl;
    }
    return 0;
}