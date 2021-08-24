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

const int MAX = 2e5 + 5;
int n, m;
struct dsu {
    vector<int> par, sz;
    int size;

    dsu(int n) {
        size = n;
        par = sz = vector<int>(n);
        for (int i = 0; i < n; i++) {
            par[i] = i;
            sz[i] = 1;
        }
    }
    int find(int u) {
        return par[u] == u ? u : (par[u] = find(par[u]));
    }
    void unite(int u, int v) {
        if ((u = find(u)) == (v = find(v))) return;
        if (sz[u] > sz[v]) swap(u, v);
        par[u] = v;
        sz[v] += sz[u];
        size--;
    }
    int count(int u) {
        return sz[find(u)];
    }
};
int main() {
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
#define debug(...) 3
    fastIO;
#endif
    cin >> n >> m;
    dsu ds(n);
    forn(i, m) {
        int x, y;
        cin>>x>>y;
        x--, y--;
        ds.unite(x, y);
    }
    int ans = 0;
    forn(i, n) {
        ans = max(ans, ds.count(i));
    }
    cout << ans << endl;
    return 0;
}
