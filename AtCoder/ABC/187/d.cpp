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
const int MAX=2e5+5;

int n;
bool cmp(pair<ll,pll> a, pair<ll,pll> b){
    return 2*a.sd.ft+a.sd.sd<2*b.sd.ft+b.sd.sd;
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

    cin>>n;
    ll ao=0;
    vector<pair<ll,pll>> v(n);
    forn(i,n){
        cin>>v[i].sd.ft>>v[i].sd.sd;
        v[i].ft=v[i].sd.ft+v[i].sd.sd;
        ao+=v[i].sd.ft;
    }
    sort(all(v),cmp);
    int ans=0;
    ll cur=0;
    forn(i,n){
        if(ao>=cur){
            cur+=v[n-i-1].ft;
            ao-=v[n-i-1].sd.ft;
            ans++;
        }else break;
    }
    cout<<ans<<endl;
    return 0;
}
