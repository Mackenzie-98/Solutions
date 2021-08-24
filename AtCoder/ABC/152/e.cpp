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
ll m = 1e9 + 7;

ll mulmod(ll a, ll b) {
    ll r = a * b - (ll)((long double)a * b / m + .5) * m;
    return r < 0 ? r + m : r;
}
ll expmod(ll b, ll e) {
    if (e == 0) return 1;
    if (e & 1) return mulmod(b, expmod(b, e - 1));
    b = expmod(b, e >> 1);
    return mulmod(b, b);
}
ll invmod(ll a) {
    return expmod(a, m - 2);
}
ll add(ll a, ll b) {
    a += b;
    if (a >= m) a -= m;
    return a;
}
ll lcm(ll a, ll b) {
    return (a * b) / __gcd(a, b);
}
int main() {
#ifdef LOCAL
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
    fastIO;
#endif
    int n;
    cin >> n;
    vector<ll> A(n), B(n);
    //ll L = 1;
    forn(i, n) cin >> A[i];
    map<ll, ll> Fmax;
    forn(i, n) {
        map<ll, ll> F;
        ll cur = A[i];
        for (ll j = 2; j * j <= cur; j++) {
            while (cur % j == 0) F[j]++, cur /= j;
            Fmax[j] = max(Fmax[j], F[j]);
        }
        if (cur > 1) F[cur]++, Fmax[cur] = max(F[cur], Fmax[cur]);
    }
    ll L = 1;
    for (auto x : Fmax) {
        if (x.S != 0) {
            L = mulmod(L, expmod(x.F, x.S));
        }
    }
    ll ans = 0;
    forn(i, n) {
        ans = add(ans, mulmod(L, invmod(A[i])));
    }
    cout << ans << endl;
    return 0;
}