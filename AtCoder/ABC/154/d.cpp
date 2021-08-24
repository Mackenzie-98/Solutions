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

int main() {
#ifdef LOCAL
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
    fastIO;
#endif
    int n, k;
    cin >> n >> k;
    vector<ll> pi(n);
    forn(i, n) cin >> pi[i];
    vector<ll> pre(n);
    pre[0] = pi[0];
    for (int i = 1; i < n; i++) {
        pre[i] = pi[i] + pre[i - 1];
    }
    int ini = -1, last = -1;
    ll best = -1e18;
    for (int i = 0; i <= n - k; i++) {
        ll cur = pre[i + k - 1] - (i == 0 ? 0 : pre[i - 1]);
        // cout << cur << endl;
        if (cur > best) ini = i, last = i + k - 1, best = cur;
    }
    long double ans = 0;
    for (int i = ini; i <= last; i++) {
        ans += (pi[i] + 1) * 0.5;
    }
    cout << fixed << setprecision(12) << ans << endl;
    return 0;
}