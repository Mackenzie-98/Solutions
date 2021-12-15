#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
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

struct dsu {
    vector<int> par, sz;
    int size; //Cantidad de conjuntos

    dsu(int n) : par(n), sz(n,1) {
        size = n;
        iota(par.begin(), par.end(), 0);
    }
    //Busca el nodo representativo del conjunto de u
    int find(int u) {
        return par[u] == u ? u : (par[u] = find(par[u]));
    }
    //Une los conjuntos de u y v
    void unite(int u, int v) {
        u = find(u), v = find(v);
        if (u == v) return;
        if (sz[u] > sz[v]) swap(u,v);
        par[u] = v;
        sz[v] += sz[u];
        size--;
    }
    //Retorna la cantidad de elementos del conjunto de u
    int count(int u) { return sz[find(u)]; }
};

int main() {

#ifdef LOCAL
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
#define debug(x...) 03
    fastIO;
#endif
    int t;
    cin>>t;
    int cases=0;
    while(t--){
        cases++;
        int w,h;
        cin>>w>>h;
        dsu ds(w*h);
        char mat[h+1][w+1];
        forn(i,h){
            string cad;
            cin>>cad;
            forn(j,cad.size()){
                mat[i][j]=cad[j];
            }
        }
        forn(i,h){
            forn(j,w){
                if(mat[i][j]=='.'){
                    int cur = i*w+j;
                    if(j+1<w&&mat[i][j+1]=='.'){
                        int node = i*w+j+1;
                        ds.unite(cur,node);
                    }
                    if(j-1>=0&&mat[i][j-1]=='.'){
                        int node = i*w+j-1;
                        ds.unite(cur,node);
                    }
                    if(i+1<h&&mat[i+1][j]=='.'){
                        int node = (i+1)*w+j;
                        ds.unite(cur,node);
                    }
                    if(i-1>=0&&mat[i-1][j]=='.'){
                        int node = (i-1)*w+j;
                        ds.unite(cur,node);
                    }
                }
            }
        }
        cout<<"Case "<<cases<<":"<<endl;
        int q;
        cin>>q;
        while(q--){
            int x,y;
            cin>>x>>y;
            x--,y--;
            int cur = x*w+y;
            cout<<ds.count(cur)<<endl;
        }
    }

    return 0;
}
