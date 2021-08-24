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
void debug_out() {
    cerr << endl;
}
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H), debug_out(T...);
}
ll m = 1e9 + 7;
ll x, y;
ll euclid(ll a, ll b) {
    if(b == 0) {
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

ll mul(ll a, ll b) {
    ll r = a * b - (ll)((long double)a * b / m + .5) * m;
    return r < 0 ? r + m : r;
}

ll invmod(ll a) {
    ll d = euclid(a, m);
    if (d > 1) return -1;
    return (x % m + m) % m;
}

ll solve(ll n, ll mid) {
    ll p1 = mul(mul(n, mul((n + 1) % m, (mul(2, n) + 1) % m)), invmod(12)) % m;
    ll p2 = mul(mul(n, (n + 1) % m), invmod(4)) % m;
    ll ans = mul(mid, (p1 % m + p2 % m) % m) % m;
    ans %= m;
    return ans;
}
int main() {
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
#define debug(...) 3
    fastIO;
#endif
    int t;
    cin >> t;
    while(t--) {
        x = 0, y = 0;
        ll n;
        cin >> n;
        ll k = mul(n, invmod(2));
        ll ans = (solve(n, n / 2 + 1) - solve(n / 2, n / 2 + 1) + m) % m;
        if(n % 2) {
            ans = (ans - mul(mul(mul(k, (k + 1) % m), invmod(2)), (k + 1) % m) + m) % m;
        } else {
            ans = (ans - mul(mul(mul(k, (k + 1) % m), invmod(2)), k ) + m) % m;
        }
        cout << ans%m << endl;
    }
    return 0;
}
