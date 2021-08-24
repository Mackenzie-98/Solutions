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
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll cuadratic(ll a, ll b, ll c) {
    return (ll)(ceil(((ld)(-b) - sqrt((ld)b * b - 4 * a * c)) / (2.0 * (ld)a)));
}
int main() {
#ifdef LOCAL
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
    fastIO;
#endif
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    forn(i, n) cin >> v[i];
    sort(all(v));
    int a = 0, b = 0;
    a = cuadratic(1, -2 * n + 1, 2 * k);
    b = a + (k - ((a - 1) * n - ((a - 1) * (a) / 2)));
    cout << a << " " << b << endl;
    cout << v[a - 1] * v[b - 1] << endl;
    return 0;
}