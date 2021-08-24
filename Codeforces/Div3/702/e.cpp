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
    while(t--){
        int n;
        cin>>n;
        vector<pii> v(n);
        vector<ll> pre(n),ans;
        forn(i,n)cin>>v[i].ft,v[i].sd=i+1;
        sort(all(v));
        pre[0]=v[0].ft;
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]+v[i].ft;
        }
        ans.pb(v[n-1].sd);
        bool mark[n+1];
        memset(mark,0,sizeof mark);
        mark[n-1]=true;
        for(int i=n-2;i>=0;i--){
            if(pre[i]>=v[i+1].ft&&mark[i+1])ans.pb(v[i].sd),mark[i]=true;
            else break;
        }
        sort(all(ans));
        cout<<sz(ans)<<endl;
        for(auto x:ans)cout<<x<<" ";
        cout<<endl;
    }
    return 0;
}
