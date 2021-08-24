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
typedef double lf;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

map<int,pair<bool,bool>> mp;
const int MAX = 55;
vector<int> g[MAX];
bitset<MAX> vis;
int n;

void dfs(int u) {
    vis[u] = true;
    for (auto v : g[u]) {
        if (!vis[v]&&(abs(u-v)==1&&mp[u].S&&mp[v].F)) dfs(v);
    }
}

void init() {
    for(int i = 0; i <= n; i++) {
        g[i].clear();
        vis[i] = false;
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
     freopen("out.txt", "w", stdout);
#else
    fastIO;
#endif
    int t;
    cin>>t;
    int casos=0;
    while(t--){
        mp.clear();
        init();
        casos++;
        int n;
        cin>>n;
        string s1,s2;
        cin>>s1>>s2;
        forn(i,n){
            if(i<n-1)g[i].pb(i+1);
            if(i>0)g[i].pb(i-1);
            if(s1[i]=='Y')mp[i].F=1;
            else mp[i].F=0;
            if(s2[i]=='Y')mp[i].S=1;
            else mp[i].S=0;
        }
        cout<<"Case #"<<casos<<":"<<endl;
        forn(i,n){
            vis.reset();
            dfs(i);
            forn(j,n){
                if(vis[j])cout<<"Y";
                else cout<<"N";
            }
            cout<<endl;
        }
    }
    return 0;
}
