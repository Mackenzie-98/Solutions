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

map<int, int> mp;
vector<int> z_function(string &s) {
    int n = s.size();
    vector<int> z(n);
    for(int i = 1, x = 0, y = 0; i < n; i++) {
        z[i] = max(0, min(z[i - x], y - i + 1));
        mp[z[i]]++;
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            x = i, y = i + z[i], z[i]++;
            mp[z[i]]++;
        }
    }
    return z;
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
    string s, p;
    int n;
    getline(cin,s),getline(cin,p);
    cin>>n;
    int cnt=0;
    forn(i, sz(s)) {
        if(s[i] == p[0])cnt++;
    }
    string t = p + "$" + s;
    vector<int> z = z_function(t);
    forn(i, sz(p)+1)mp[z[i]]--, z[i] = 0;
    debug(z);
    debug(mp);
    bool ok=false;
    for(auto it=mp.rbegin();it!=mp.rend();it++){
        if(it->ft<2)break;
        if(it->sd>=n){
            cout<<p.substr(0,it->ft)<<endl;
            ok=true;
            break;
        }
    }
    if(!ok&&cnt>=n&&p[0]!=' ')cout<<p[0]<<endl;
    else if(!ok)cout<<"IMPOSSIBLE"<<endl;
    return 0;
}
