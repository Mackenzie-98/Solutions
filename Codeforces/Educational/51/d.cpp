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
const int MAX = 2e3 + 5;
bool vis[MAX];
vector<int> G[MAX];
void dfs(int u) {
    vis[u] = 1;
    for (auto v : G[u]) {
        if (!vis[v]) dfs(v);
    }
}
void init() {
    forn(i, MAX) {
        G[i].clear();
        vis[i] = 0;
    }
}
int main() {
#ifdef LOCAL
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
    fastIO;
#endif
    int n, k;
    cin >> n >> k;
    ll ans = 0;
    for (int mask = 0; mask < (1 << (2 * n)); mask++) {
        init();
        for (int bit = 0; bit < 2 * n; bit++) {
            if (mask & (1 << bit)) {
                if (bit < n && mask && (1 << (bit + n))) {
                    G[bit][bit + n] = 1;
                }
                if (bit < 2 * n && mask && (1 << (bit + 1))) {
                    G[bit][bit + 1] = 1;
                }
            } else {
                if (bit < n && !(mask && (1 << (bit + n)))) {
                    G[bit][bit + n] = 0;
                }
                if (bit < 2 * n && !(mask && (1 << (bit + 1)))) {
                    G[bit][bit + 1] = 0;
                }
            }
        }
        int c = 0;
        for (int i = 0; i < 2 * n; i++) {
            if (!vis[i]) {
                dfs(i);
                c++;
            }
        }
        if (c == k) {
            forn(i, 2 * n) cout << ((mask & (1 << i)) != 0 ? 1 : 0);
            cout << endl;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}