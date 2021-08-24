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

const int MAX=2e5+5;
bool cats[MAX];
int n,m;
vector<int> g[MAX];
int g2[MAX];
bitset<MAX> vis;

void dfs(int u,int k) {
    if(k+cats[u]>m)return;
    vis[u] = true;
    for (auto v : g[u]) {
        if (!vis[v]){
                if(cats[u])dfs(v,k+cats[u]);
                else dfs(v,0);
        }
    }
}

void init() {
    for(int i = 0; i <= n; i++) {
        g2[i]=0;
        g[i].clear();
        vis[i] = false;
    }
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
    fastIO;
#endif
    cin>>n>>m;
    init();
    forn(i,n)cin>>cats[i];
    forn(i,n-1){
        int x,y;
        cin>>x>>y;x--,y--;
        g[x].pb(y);
        g[y].pb(x);
    }
    dfs(0,0);
    int ans=0;
    for(int i=1;i<n;i++){
        if(sz(g[i])==1&&vis[i])ans++;
    }
    cout<<ans<<endl;
    return 0;
}

