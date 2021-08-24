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
void debug_out() {
    cerr << endl;
}
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H), debug_out(T...);
}

int n, k;
const int MAX = 5005;
int a[MAX], c[MAX];
vector<ll> pre;
bitset < MAX + 2 > vis;
ll best = -1e18;
void score(int i, ll sum) {
    vis[i] = true;
    if(!vis[a[i]]) {
        pre.pb(pre[sz(pre) - 1] + c[a[i]]);
        best = max(best, pre[sz(pre) - 1]);
        score(a[i], sum + c[a[i]]);
    }
}
void init() {
    best = -1e18;
    pre.clear();
    pre.pb(0);
    for(int i = 0; i < n + 2; i++) {
        vis[i] = false;
    }
}
int main() {
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
#define debug(...) 3
    fastIO;
#endif
    cin >> n >> k;
    forn(i, n)cin >> a[i + 1];
    forn(i, n)cin >> c[i + 1];
    ll mx = -1e18;
    for(int i = 1; i <= n; i++) {
        init();
        score(i, 0);
        ll y = pre[sz(pre) - 1] + c[i];
        /*for(auto x : pre)cout << x << " ";
        ll ans = pre[(k % sz(pre))] + y * (k / sz(pre));
        debug(ans);
        cout << endl;*/
        mx = max(mx, best+ (y >= 1 ? y * (k / sz(pre)) : 0));
    }
    cout << mx << endl;
    return 0;
}
