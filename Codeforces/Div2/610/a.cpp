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
        ll a, b, c, r;
        cin >> a >> b >> c >> r;
        if (a > b) swap(a, b);
        ll mind = 0;
        if (c < a) {
            a = max(a, c + r);
            mind = max(0ll, b - a);
        } else if (c > b) {
            b = min(b, c - r);
            mind = max(0ll, b - a);
        } else {
            mind = max(0ll, max(0ll, b - a) - (((min(c + r, b) - c) + (c - max(c - r, a)))));
        }
        cout << mind << endl;
    }
    return 0;
}