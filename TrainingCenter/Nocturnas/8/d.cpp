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
const ll mod = 1000000007;
ll mulmod(ll a, ll b, ll m) {
    ll r = a * b - (ll)((long double)a * b / m + .5) * m;
    return r < 0 ? r + m : r;
}
ll expmod(ll b, ll e, ll m) {
    if (e == 0) return 1;
    if (e & 1) return mulmod(b, expmod(b, e - 1, m), m);
    b = expmod(b, e >> 1, m);
    return mulmod(b, b, m);
}
bool test(ll n, int a) {
    if (n == a) return true;
    ll s = 0, d = n - 1;
    while (d % 2 == 0) s++, d /= 2;
    ll x = expmod(a, d, n);
    if (x == 1 || x + 1 == n) return true;
    for (int i = 0; i < s - 1; i++) {
        x = mulmod(x, x, n);
        if (x == 1) return false;
        if (x + 1 == n) return true;
    }
    return false;
}
ll rho(ll n) {
    if (!(n & 1)) return 2;
    ll i = 0, k = 2, x = 3, y = 3, d;
    while (true) {
        x = (mulmod(x, x, n) + n - 1) % n;
        d = __gcd(abs(y - x), n);
        if (d != 1 && d != n) return d;
        if (++i == k) y = x, k <<= 1;
    }
}
bool isPrime(ll n) {
    if (n == 1) return false;
    vector<int> ar = {2, 3, 5, 7, 11, 13, 17, 19, 23};
    for (auto& a : ar)
        if (!test(n, a)) return false;
    return true;
}
void fact(ll n, map<ll, int>& f) {
    if (n == 1) return;
    if (isPrime(n)) {
        f[n]++;
        return;
    }
    ll q = rho(n);
    fact(q, f);
    fact(n / q, f);
}
ll cantDiv(ll n) {
    map<ll, int> f;
    fact(n, f);
    ll ans = 1;
    for (auto p : f) ans *= (p.second + 1);
    return ans;
}
int main() {
#ifdef LOCAL
    // freopen("h.txt", "r", stdin);
    // freopen("main.out", "w", stdout);
#else
    ios::sync_with_stdio(0), cin.tie(0);
#define endl '\n'
#endif
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        ll div = cantDiv(n);
        cout << mulmod(expmod(n, div / 2, mod),
                       (div % 2 ? (ll)round(sqrt(n)) : 1), mod)
             << endl;
    }
    return 0;
}