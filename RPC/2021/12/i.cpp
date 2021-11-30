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

const int MAX=1e5+5;
int t[MAX], s[MAX];

int n;

bool check(ll ans, vector<pll> arr){
    int computers=0;
    forn(i,sz(arr)){
        computers+= (arr[i].sd+ans-1)/ans;
    }
    cout<<"ans: "<<ans<<endl;
    cout<<"Computadoras: "<<computers<<endl;

    return ans > 0;
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
    forn(i,n)cin>>t[i];
    forn(i,n)cin>>s[i];
    vector<pll> arr;

    forn(i,n){
        if(s[i]!=-1){
            arr.pb({s[i],t[i]});
        }
    }
    sort(all(arr));

    ll lo=1, hi = 1e18, ans=0;

    forn(it,70){
        ans = (lo+hi)/2;
        if(check(ans, arr)) hi = ans;
        else lo = ans;
    }
    cout<<ans<<endl;
    return 0;
}
