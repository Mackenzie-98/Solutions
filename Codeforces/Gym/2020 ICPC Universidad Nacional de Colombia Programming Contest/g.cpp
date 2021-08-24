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
const int MAX = 1e5 + 5, m = 1e9 + 7;
ll F[MAX];
int n, k;
ll mulmod(ll a, ll b, ll m) {
    ll r = a * b - (ll)((long double)a * b / m + .5) * m;
    return r < 0 ? r + m : r;
}
ll expmod(ll b, ll e, ll m) {
    int ans = 1;
    while (e) {
        if (e & 1) ans = mulmod(ans, b, m) % m;
        b = mulmod( b, b, m) % m;
        e /= 2;
    }
    return ans;
}
int invmod(int a, int m) {
    return expmod(a, m - 2, m);
}
void fact() {
    F[0] = 1;
    for(ll i = 1; i <= n + 1; i++)
        F[i] = mulmod(F[i - 1], i, m);
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
    n!/2^m
    cin >> n >> k;
    fact();
    ll P1 = mulmod(F[n], invmod(F[2 * k], m), m);
    ll P2 = 1;
    for(ll i = 2*k-1; i >0; i -=2) {
        P2 = mulmod(P2,mulmod(mulmod(i, (i + 1) % m, m), invmod(2, m), m),m);
    }
    cout << mulmod(P1, P2, m) << endl;
    return 0;
}
