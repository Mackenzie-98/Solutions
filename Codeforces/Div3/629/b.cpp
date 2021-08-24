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
typedef long double ld;
ld cuadratic(ld a, ld b, ld c) {
    return (-b + sqrt(b * b - 4 * a * c)) / (2.0 * a);
}
int main() {
#ifdef LOCAL
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
    fastIO;
#endif
    int t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        vector<bool> ans(n, 0);
        ll x = ceil(cuadratic(1, -1, -2.0 * k)) - 2;
        ll y = k - (((x + 1) * x) / 2) - 1;
        ans[n - x - 2] = 1;
        ans[n - y - 1] = 1;
        forn(i, sz(ans)) {
            if (!ans[i])
                cout << "a";
            else
                cout << "b";
        }
        cout << endl;
    }
    return 0;
}