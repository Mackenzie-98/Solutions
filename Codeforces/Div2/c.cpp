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
vector<int> g[MAX];
int p[MAX], h[MAX];
ll cnt[MAX];
ll happy[MAX];
bool ans = true;
int n, m;

void dfs(int u, int r) {
    cnt[u] = p[u];
    ll sum = 0;
    for(auto v : g[u]) {
        if(v == r)continue;
        dfs(v, u);
        cnt[u] += cnt[v];
        sum += happy[v];
    }
    happy[u] = (cnt[u] + h[u]) / 2;
    bool c1 = (cnt[u] + h[u]) % 2 != 0;
    bool c2 = happy[u] > cnt[u] || happy[u] < 0;
    bool c3 = sum > happy[u];
    if(c1 || c2 || c3)ans = 0;
}

void init() {
    ans = 1;
    forn(i, n + 1) {
        g[i].clear();
        p[i] = 0, h[i] = 0, happy[i] = 0;
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
    fastIO;
#endif
    int t;
    cin >> t;
    while(t--) {
        init();
        cin >> n >> m;
        forn(i, n)cin >> p[i];
        forn(i, n)cin >> h[i];
        forn(i, n - 1) {
            int x, y;
            cin >> x >> y;
            x--, y--;
            g[x].pb(y);
            g[y].pb(x);
        }
        dfs(0, 0);
        if(ans)cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
