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
bool mark[1000005];
void sieve(){
    mark[0]=mark[1]=1;
    for(ll i=2;i<1000001;i++){
        if(!mark[i]){
            for(ll j=i*i;j<1000001;j+=i){
                mark[j]=1;
            }
        }
    }
}
ll mulmod(ll a, ll b, ll m) {
	ll r = a*b-(ll)((long double)a*b/m+.5)*m;
	return r < 0 ? r+m : r;
}
pair<ll,ll> solve(ll n){
    pair<ll,ll> ans={1e18,-1e18};
    for(ll i=1;i*i<=n;i++){
        if(i*i==n){
            if(!mark[i]){
                ans.F=min(ans.F,i);
                ans.S=max(ans.S,i);
            }
        }else if(n%i==0){
            if(!mark[i]){
            ans.F=min(ans.F,i);
             ans.S=max(ans.S,i);
            }
            if(!mark[n/i]){
            ans.S=max(ans.S,n/i);
            ans.F=min(ans.F,n/i);
            }
            
        }
    }
    return ans;
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
    sieve();
    while(t--){
        ll n;
        cin>>n;
        pll ans=solve(n);
        cout<<ans.F<<" "<<ans.S<<endl;

    }
  return 0;
}