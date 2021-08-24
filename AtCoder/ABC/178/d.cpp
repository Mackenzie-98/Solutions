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
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void debug_out() {
    cerr << endl;
}
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H), debug_out(T...);
}

const int MAX=2e3+5,m=1e9+7;
ll dp[MAX];
int n;

ll f(int sum) {
    if(sum==0)return 1;
    if(sum<0)return 0;
    ll &ans=dp[sum];
    if(ans!=-1)return ans;
    ans=0;
    for(int i=3;i<=n;i++)ans=(ans%m+f(sum-i)%m)%m;
    return ans;
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
    memset(dp,-1,sizeof dp);
    cin>>n;
    ll ans=0;
    cout<<f(n)<<endl;
    return 0;
}
