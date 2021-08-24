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

const int MAX=1e3+5;
vector<int> g[MAX];
map<int,int> mp;
vector<bool> vis;
deque<int> order;
int n;

void toposort(int u) {
    vis[u] = true;
    for (auto &v : g[u]) {
        if (!vis[v]) toposort(v);
    }
    order.push_front(u);
}
void dfs(int u) {
    vis[u] = true;
    int x=-1,mn=1e9;
    for (auto &v : g[u]) {
        if (!vis[v]&&mp[v]<mn){
                mn=mp[v];
                x=v;
        }
    }
    if(x!=-1)dfs(x);
}

void init() {
    order.clear();
    vis.assign(n, false);
    for (int i = 0; i <= n; i++) {
        g[i].clear();
    }
}

int main() {

#ifdef LOCAL
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
#define debug(x...) 03
    fastIO;
#endif
    cin>>n;
    init();
    forn(i,n){
        int x;
        cin>>x;
        forn(j,x){
            int p;
            cin>>p;
            g[i].pb(p);
            mp[p]++;
        }
    }
    forn(i,n){
        if(!vis[i])toposort(i);
    }
    int ans=0;
    vis.assign(n, false);
    forn(i,n){
        if(!vis[order[i]])dfs(order[ i]),ans++;
    }
    debug(order);
    cout<<ans<<endl;
    return 0;
}
