#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define ft first
#define sd second
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define pb push_back
#define fastIO ios::sync_with_stdio(0), cin.tie(0)
#define endl '\n'
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

void __print(int x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for(auto &i : x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if(sizeof...(v)) cerr << ", "; _print(v...);}
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
struct edge {
    int v; ll w, k;

    bool operator < (const edge &o) const {
        return o.w < w;
    }
};
const int MAX = 1e5 + 1;
int n, m, x, y;
const ll inf = 1e18;
vector<edge> g[MAX];
vector<bool> vis;
vector<ll> dist;
int pre[MAX];
void dijkstra(int u,int time) {
    priority_queue<edge> pq;
    pq.push({u, 0});
    dist[u] = 0;
    while(pq.size()) {
        u = pq.top().v; pq.pop();
        if(!vis[u]) {
            vis[u] = true;
            for(auto &ed : g[u]) {
                int v = ed.v;
                debug(u, v, g[u][v].k);
                int k = ed.k;
                if(!vis[v] && dist[v]  > dist[u] + ed.w + k * ((dist[u] + k - 1) / k)) {
                    dist[v] = dist[u] + ed.w + k * ((dist[u] + k - 1) / k);
                    pre[v] = u;
                    pq.push({v, dist[v]});
                }
            }
        }
    }
}

void init() {
    vis.assign(n, false);
    dist.assign(n, inf);
    for(int i = 0; i <= n; i++) {
        g[i].clear();
    }
}

int main() {

#ifdef LOCAL

    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
#define debug(x...) 03
    fastIO;
#endif
    cin >> n >> m >> x >> y;
    x--, y--;
    init();
    forn(i, m) {
        int a, b, t, k;
        cin >> a >> b >> t >> k;
        a--, b--;
        g[a].pb({b, t, k});
        g[b].pb({a, t, k});
    }
    dijkstra(x,0);
    if(dist[y] == inf)cout << -1 << endl;
    else cout << dist[y]  << endl;
    return 0;
}
