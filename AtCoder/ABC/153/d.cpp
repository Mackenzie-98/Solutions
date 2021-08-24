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
ll atacks(ll x) {
    if (x == 1) return 1;
    ll ans = 0;
    ans += atacks(x / 2) + atacks(x / 2) + 1;
    return ans;
}
int main() {
#ifdef LOCAL
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
    fastIO;
#endif
    ll h;
    cin >> h;
    ll x = 0;
    while (h - (1ll << x) >= 0) {
        x++;
    }
    cout << (1ll << (x)) - 1 << endl;
    return 0;
}