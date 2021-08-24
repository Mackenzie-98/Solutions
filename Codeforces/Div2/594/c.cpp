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
const ll mod=1e9+7;
ll mulmod(ll a, ll b, ll m) {
	ll r = a*b-(ll)((long double)a*b/m+.5)*m;
	return r < 0 ? r+m : r;
}
const int MAX=1e5+5;
ll F[MAX];
void fib(){
  F[0]=F[1]=1;
  for(int i=2;i<MAX;i++){
    F[i]=(F[i-1]%mod+F[i-2]%mod)%mod;
  }
}
int main() {
#ifdef LOCAL
  // freopen("h.txt", "r", stdin);
  // freopen("main.out", "w", stdout);
#else
  ios::sync_with_stdio(0), cin.tie(0);
#define endl '\n'
#endif
  fib();
  int n,m;
  cin>>n>>m;
  cout<<mulmod(2ll,(F[n]%mod+F[m]%mod-1+mod)%mod,mod)<<endl;
  return 0;
}