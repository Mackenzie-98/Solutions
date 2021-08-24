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

bool isPrime(ll n) {
    if (n == 1) return false;
    vector<int> ar = {2, 3, 5, 7, 11, 13, 17, 19, 23};
    for (auto& a : ar)
        if (!test(n, a)) return false;
    return true;
}
int main() {
#ifdef LOCAL
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
    fastIO;
#endif
    ll a, b;
    cin >> a >> b;
    ll d = __gcd(a, b);
    vector<ll> div;
    for (ll i = 1; i * i <= d; i++) {
        if (d % i == 0) {
            if (i * i == d)
                div.pb(i);
            else
                div.pb(i), div.pb(d / i);
        }
    }
    int ans = 0;
    for (auto x : div) {
        if (isPrime(x)) ans++;
    }
    cout << ans + 1 << endl;
    return 0;
}