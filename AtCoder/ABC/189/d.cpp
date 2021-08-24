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

int main() {
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
#define debug(...) 3
    fastIO;
#endif
    int n;
    cin>>n;
    vector<string> v(n);
    forn(i,n)cin>>v[i];
    ll dp[n+2];
    memset(dp,0,sizeof dp);
    dp[n]=1;
    for(int i=n-1;i>=0;i--){
        if(v[i]=="AND"){
            dp[i]=dp[i+1];
        }else{
            dp[i]=dp[i+1]+(1ll<<(i+1));
        }
    }
    cout<<dp[0]<<endl;
    return 0;
}
