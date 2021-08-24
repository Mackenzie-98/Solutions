#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " = " << x << endl;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define F first
#define S second
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define pb push_back
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll x, y;

ll euclid(ll a, ll b) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll d = euclid(b, a % b);
    ll aux = x;
    x = y;
    y = aux - (a / b) * y;
    return d;
}

ll invmod(ll a, ll m) {
    ll d = euclid(a, m);
    if (d > 1) return -1;
    return (x % m + m) % m;
}

ll mulmod(ll a, ll b, ll m) {
    ll r = a * b - (ll)((long double)a * b / m + .5) * m;
    return r < 0 ? r + m : r;
}
/// O(log(e)), 0 <= b < m
ll expmod(ll b, ll e, ll m) {
    if (e == 0) return 1;
    if (e & 1) return mulmod(b, expmod(b, e - 1, m), m);
    b = expmod(b, e >> 1, m);
    return mulmod(b, b, m);
}

ll mod = 1e9 + 7;

int main() {
#ifdef LOCAL
    freopen("a.txt", "r", stdin);
    // freopen("main.out", "w", stdout);
#else
    ios::sync_with_stdio(0), cin.tie(0);
#define endl '\n'
#endif
    ll a, b, k, c;
    cin >> a >> b >> k >> c;
    if ((a != c && b != c) || k == 0) {
        cout << 0 << endl;
        return 0;
    }
    ll _k = expmod(2, k, mod);
    ll kk = mulmod(_k, k, mod);
    // cout << _k << ' ' << kk << ' ';
    if (a == b) {
        cout << k << endl;
    } else {
        cout << mulmod(kk, invmod(2, mod), mod) << endl;
    }
    return 0;
}