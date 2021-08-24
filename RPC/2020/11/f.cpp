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
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void debug_out() {
    cerr << endl;
}
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H), debug_out(T...);
}

struct edge {
    int v;
    ll w;
    edge(int _v,ll _w) {
        v=_v;
        w=_w;
    };
    bool operator < (const edge &o) const {
        return o.w < w; //invertidos para que la pq ordene de < a >
    }
};

const ll INF = 1e18;
const int MX = 2505;
vector<edge> g[MX];
vector<bool> vis;
vector<ll> dist;
int pre[MX];
int n,k;
void dijkstra(int u) {
    priority_queue<edge> pq;
    pq.push({u, 0});
    dist[u] = 0;

    while (pq.size()) {
        u = pq.top().v;
        pq.pop();
        if (!vis[u]) {
            vis[u] = true;
            for (auto &ed : g[u]) {
                int v = ed.v;
                if (!vis[v] && dist[v] > dist[u] + ed.w) {
                    dist[v] = dist[u] + ed.w;
                    pre[v] = u;
                    pq.push({v, dist[v]});
                }
            }
        }
    }
}

void init() {
    vis.assign(n*n+1, false);
    dist.assign(n*n+1, INF);
    for (int i = 0; i <= n*n+1; i++) {
        g[i].clear();
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
    init();

    cin>>n>>k;
    vector<int> v[k+1];
    forn(i,n) {
        forn(j,n) {
            int x;
            cin>>x;
            v[x].pb(i*n+j);
        }
    }
    bool ok=true;
    for(int i=1; i<=k-1; i++) {
        if(sz(v[i])==0||sz(v[i+1])==0) {
            ok=false;
            break;
        }
        for(auto x:v[i]) {
            for(auto y:v[i+1]) {
                int i1=x/n,i2=y/n;
                int j1=x%n,j2=y%n;
                g[x].pb(edge(y,abs(i1-i2)+abs(j1-j2)));
            }
        }
    }

    if(!ok)cout<<-1<<endl;
    else {
        ll mn=INF;
        for(auto x:v[1]) {
            vis.assign(n*n+1, false);
            dist.assign(n*n+1, INF);
            dijkstra(x);
            for(auto y:v[k]) {
                if(dist[y]!=-1)mn=min(mn,dist[y]);
        }
    }
    cout<<mn<<endl;
}
return 0;
}
