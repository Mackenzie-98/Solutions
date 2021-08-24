#include <bits/stdc++.h>
using namespace std;
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
void fact(ll n, map<ll, int>& f) {
    for (ll p = 2; p * p <= n; p++)
        while (n % p == 0) f[p]++, n /= p;
    if (n > 1) f[n]++;
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
    int n;
    cin >> n;
    ll arr[n];
    ll g = 0;
    forn(i, n) cin >> arr[i], g = __gcd(g, arr[i]);
    cout << cantDiv(g) << endl;
    return 0;
}