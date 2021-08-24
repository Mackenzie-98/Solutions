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
const int MAX = 105;
int a[MAX];
int depth[MAX];
int n;
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
void f(int l, int r,int level) {
    if(r<l)return;
    int mx=0,ind=-1;
    for(int i = l; i <= r; i++){
        if(a[i] > mx) {
            ind = i;
            mx = a[i];
        }
    }
    depth[ind]=level++;
    f(l,ind-1,level);
    f(ind+1,r,level);
}
int main() {

#ifdef LOCAL

    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
#define debug(x...) 03
    fastIO;
#endif
    int t;
    cin >> t;
    while(t--) {
        memset(depth, 0, sizeof depth);
        cin >> n;
        int ind = -1, mx = 0;
        forn(i, n) {
            cin >> a[i];
            if(a[i] > mx) {
                ind = i;
                mx = a[i];
            }
        }
        f(0, ind - 1,1);
        f(ind + 1, n - 1,1);
        forn(i,n)cout<<depth[i]<<" ";
        cout<<endl;
    }
    return 0;
}
