#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " = " << x << endl;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define F first
#define S second
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define pb push_back
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll mod=1000000007;
ll mulmod(ll a, ll b, ll m) {
	ll r = a*b-(ll)((long double)a*b/m+.5)*m;
	return r < 0 ? r+m : r;
}
ll solve(ll n,ll m,ll k){
    ll ans=1;
    for(ll i=1;i*i<=k;i++){
        if(i*i==k){
            ans=mulmod(ans,i,mod);
        }else if(k%i==0){
             ans=mulmod(ans,i,mod);
             ans=mulmod(ans,n/i,mod);
        }
    }
    return ans;
}
ll lcm(ll a,ll b){
    return (a*b)/__gcd(a,b);
}
int main() {
#ifdef LOCAL
  // freopen("h.txt", "r", stdin);
  // freopen("main.out", "w", stdout);
#else
  ios::sync_with_stdio(0), cin.tie(0);
#define endl '\n'
#endif
    int t;
    cin>>t;
    while(t--){
        ll n,m,k;
        cin>>n>>m>>k;
        ll a=max(n,m),b=min(n,m);
        cout<<(k-1)/lcm(a,b)+1<<endl;

    }
  return 0;
}