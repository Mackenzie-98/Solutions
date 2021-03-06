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
void debug_out() {cerr << endl;}
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {cerr << " " << to_string(H), debug_out(T...);}

int n;
const int MAX=300;
vector<int> g[MAX];
int mat[MAX][MAX];
ll mem[MAX];
bool vis[MAX][MAX];
void init(){
    memset(mat,0,sizeof mat);
    for(int i=0;i<=n*n+1;i++){
        g[i].clear();
    }
}

bool check(pii cur,pii dest){
    for(int i=-1;i<=1;i++){
        for(int j=-1;j<=1;j++){
            if(i==0&&j==0)continue;
            if(cur.ft+i==dest.ft&&cur.sd+j==dest.sd)return true;
        }
    }
    return false;
}
ll dp(int i,map<int,bool> mark){
    cout<<"Nodo: "<<i+1<<endl;
    for(auto xx:mark)cout<<xx.ft+1<<" ";
    cout<<endl;
    int jj=i%n,ii=(i-jj)/n;
    if(mark.count(i))return 0;
    ll &ans=mem[i];
    //if(ans!=-1)return ans;
    mark[i]=true;
    ll rta=mat[ii][jj];
    for(auto x:g[i]){
        rta=max(rta,dp(x,mark)+mat[ii][jj]);
    }
    return rta;
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
    int t;
    cin>>t;
    while(t--){
        init();
        cin>>n;
        forn(i,n){
            forn(j,n)cin>>mat[i][j];
        }
        map<pii,bool> mark;
        forn(p,n*n){
            int y=p%n,x=(p-y)/n;
            forn(i,n){
                forn(j,n){
                    if(x==i&&y==j)continue;
                    if(!check({x,y},{i,j})){
                        int cur=x*n+y;
                        int dest=i*n+j;
                        if(!mark.count({cur,dest}))g[cur].pb(dest);
                        mark[{cur,dest}]=true;
                    }
                }
            }
        }
        /*forn(i,n*n){
            cout<<"Nodo: "<<i+1<<endl;
            for( auto x:g[i])cout<<x+1<<" ";
            cout<<endl;
        }*/
        ll ans=0;
        forn(i,n*n){
            memset(mem,-1,sizeof mem);
            int jj=i%n,ii=(i-jj)/n;
            map<int,bool> mp;
            ans=max(ans,dp(i,mp));
        }
        cout<<ans<<endl;
    }
    return 0;
}
