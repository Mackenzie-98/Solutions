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
int main() {
#ifdef LOCAL
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
    fastIO;
#endif
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> v(n);
    forn(i, n) {
        cin >> v[i].S >> v[i].F;
    }
    sort(all(v));
    vector<ll> pre(n);
    pre[0] = v[0].S;
    for (int i = 1; i < n; i++) {
        pre[i] = pre[i - 1] + v[i].S;
    }
    ll mx = 0;
    for (int i = n - k; i < n; i++) {
        ll cur = v[i].F * (pre[n - 1] - (i == 0 ? 0 : pre[i - 1]));
        mx = max(mx, cur);
    }
    cout << mx << endl;
    return 0;
}