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

vector<string> split(const string &s, char c) {
    vector<string> v;
    stringstream ss(s);
    string sub;
    while (getline(ss, sub, c)) v.pb(sub);
    return v;
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
    string a,b;
    cin>>a>>b;
    vector<string> v1 = split(a,'/');
    vector<string> v2 = split(b,'/');
    int pre=0,suc=0;
    while(v1[pre] == v2[pre]){
        pre++;
    }

    int i= v1.size()-1,j = v2.size()-1;
    while(v1[i]==v2[j]){
        i--,j--;
        suc++;
    }

    string ans="";
    forn(i,pre){
        ans+=v1[i]+"/";
    }
    ans+="{";
    for(int x = pre; x <= i ;x++){
        ans+= v1[x]+(x!=i?"/":"");
    }

    ans+=" => ";
    for(int x = pre; x <= j ;x++){
        ans+= v2[x]+(x!=j?"/":"");
    }

    ans+="}";
    for(int x = j+1; x < v2.size() ;x++){
        ans+= "/"+v2[x];
    }
    cout<<ans<<endl;
    return 0;
}
