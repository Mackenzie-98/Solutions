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
    return (a * b) / (__gcd(a, b));
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
    vector<ll> div;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            if (i * i == n)
                div.pb(i);
            else {
                div.pb(i);
                div.pb(n / i);
            }
        }
    }
    sort(all(div));
    ll mn = 1e18;
    ll aa = n, bb = n;
    forn(i, sz(div)) {
        ll a, b;
        a = div[i];
        b = n / a;
        if (lcm(a, b) == n && max(a, b) < mn) {
            mn = max(a, b);
            aa = a;
            bb = b;
        }
    }
    cout << aa << " " << bb << endl;
    return 0;
}