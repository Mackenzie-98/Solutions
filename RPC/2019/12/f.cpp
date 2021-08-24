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

ll n, k;
vector<ll> v;

ll f(ll x) {
    ll ans = 0;
    for (ll i = 0, r = x; i < n; i++, r += k) {
        ans += abs(v[i] - r);
    }
    return ans;
}

ll ternary_search(ll l, ll r, ll it = 100) {
    ll a = (2 * l + r) / 3;
    ll b = (l + 2 * r) / 3;
    if (it == 0) return min(f(a), f(b));
    if (f(a) < f(b)) return ternary_search(l, b, it - 1);
    return ternary_search(a, r, it - 1);
}

int main() {
#ifdef LOCAL
    //freopen("f.txt", "r", stdin);
    // freopen("main.out", "w", stdout);
#else
    ios::sync_with_stdio(0), cin.tie(0);
#define endl '\n'
#endif
    cin >> n >> k;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    cout << ternary_search(-1e12, 1e12) << endl;
    return 0;
}
