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
ll lcm(ll a, ll b) {
    return (a) * (b / __gcd(a, b));
}
int main() {
#ifdef LOCAL
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
    fastIO;
#endif
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    ll L = 1;
    ll G = 0;
    ll INF = 1e10;
    forn(i, n) cin >> a[i], L = lcm(L, a[i]), G = __gcd(G, a[i]);
    //cout << L << " " << G << endl;
    ll x = L / 2;
    cout << max(0ll, m - x) / L + (m >= x ? 1 : 0) << endl;
    return 0;
}
