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
void debug_out() {
    cerr << endl;
}
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H), debug_out(T...);
}

int n,m;
const int MAX=1005;
int a[MAX],b[MAX];
int dp[MAX][MAX];
int f(int i,int j){
    if(i>=n)return m-j;
    if(j>=m)return n-i;
    int &ans=dp[i][j];
    if(ans!=-1)return ans;
    ans=1e9;
    ans=min(f(i+1,j)+1,f(i,j+1)+1);
    ans=min(ans,f(i+1,j+1)+(a[i]!=b[j]));
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
    cin>>n>>m;
    forn(i,n)cin>>a[i];
    forn(i,m)cin>>b[i];
    cout<<f(0,0)<<endl;
    return 0;
}
