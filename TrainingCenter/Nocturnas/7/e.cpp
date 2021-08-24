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
pii mem[1e4 + 5];
pii dp(int t) {
    if (t <= 0) {
        return {0, 0};
    }
    pii &ans = mem[t];
    if (ans != -1) return ans;
    ans = max(ans, {dp(t - 1).F - 1, dp(t - 1).S});
    ans = max(ans, {dp(t - n).F - n, dp(t - n).S + 1});
    ans = max(ans, {dp(t - m).F - m, dp(t - m).S + 1});
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
    int m, n, t;
    while (cin >> m >> n >> t) {
        for (int i = 0; i <= t + 5; i++) mem[i] = {-1, 1e9};
        pii ans = dp(0);
        cout << ans.F << " " << ans.S << endl;
    }
    return 0;
}