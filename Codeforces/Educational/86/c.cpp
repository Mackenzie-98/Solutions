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
ll _lcm(ll a, ll b) { return (a / __gcd(a, b)) * b; }
int main() {
#ifdef LOCAL
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
    fastIO;
#endif
    // cout << lcm(10, 70) << endl;
    // int a, b;
    // cin >> a >> b;
    // int l, r;
    // cin >> l >> r;
    // for (int i = l; i <= r; i++) {
    //     cout << i << " " << (i % a) % b << " " << (i % b) % a << endl;
    // }
    int t;
    cin >> t;
    while (t--) {
        int a, b, q;
        cin >> a >> b >> q;
        ll lcm = _lcm(a, b);
        ll cnt = 0;
        for (ll j = 0; j < max(a, b); j++) {
            // cout << j << " " << (j % a) % b << " " << (j % b) % a << endl;
            // if (j < l) continue;
            if ((j % a) % b == (j % b) % a)
                cnt++;
            else
                break;
        }
        forn(i, q) {
            ll l, r;
            cin >> l >> r;
            // if (max(a, b) % min(a, b) == 0)
            //     cout << r - l + 1 << " ";
            // else {
            ll x = (l + lcm - 1) / lcm;

            // cout << x * lcm << " " << r << endl;

            // cout << cnt << endl;
            ll total = 0;
            if (r <= lcm) {
                for (ll j = l; j <= r; j++) {
                    if ((j % a) % b != (j % b) % a) total++;
                }
                cout << total << " ";
            } else {
                total = r - l + 1;
                ll bads = (r + 1) / lcm - ((l) / lcm);
                // cout << total << " " << bads << endl;
                cout << total - cnt * bads << " ";
            }
        }
        cout << endl;
    }

    return 0;
}