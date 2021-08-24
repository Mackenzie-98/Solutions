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
const int MAX = 1e5 + 5;
ll arr[MAX];
int n;
ll f(ll m) {
    ll mx = 0;
    for (int i = 0; i < n - 1; i++) {
        mx = max(mx, abs((arr[i + 1] == -1 ? m : arr[i + 1]) - (arr[i] == -1 ? m : arr[i])));
    }
    return mx;
}

pair<ll, ll> ternary_search(ll l, ll r) {
    for (int it = 0; it <= 200; it++) {
        ll m1 = round(l + (double)(r - l) / 3.0);
        ll m2 = round(r - (double)(r - l) / 3.0);
        ll f1 = f(m1);
        ll f2 = f(m2);
        if (f1 > f2)
            l = m1;
        else
            r = m2;
    }
    if (f(l) <= f(r))
        return {f(l), l};
    else
        return {f(r), r};
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
        cin >> n;
        memset(arr, 0, sizeof arr);
        forn(i, n) cin >> arr[i];
        pair<ll, ll> ans = ternary_search(0, 1000000000);
        cout << ans.F << " " << ans.S << endl;
    }
    return 0;
}