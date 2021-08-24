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
const int MAX = 1e5 + 5;
ll m = 1e9 + 7;
ll A[MAX];
ll mul(ll a, ll b, ll m) {
    return (ll)((__uint128_t)a * b % m);
}

int main() {
#ifdef LOCAL
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
    fastIO;
#endif
    ll n;
    cin >> n;
    map<ll, ll> mp;
    forn(i, n) cin >> A[i], mp[A[i]]++;
    bool ok = 1;
    ll ans = 1;
    for (auto x : mp) {
        if ((x.S > 2) || (x.F == 0 && x.S >= 2)) {
            ok = 0;
            break;
        }
        ans = mul(ans, x.S, m);
    }
    if (!ok)
        cout << 0 << endl;
    else
        cout << ans << endl;

    return 0;
}