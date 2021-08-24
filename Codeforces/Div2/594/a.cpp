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
      int n;
      cin>>n;
      ll odd1=0,even1=0,odd2=0,even2=0;
      forn(i,n){
          ll x;
          cin>>x;
          if(x&1)odd1++;
          else even1++;
      }
      int m;
      cin>>m;
      forn(i,m){
          ll x;
          cin>>x;
          if(x&1)odd2++;
          else even2++;
      }
    cout<<odd1*odd2+even1*even2<<endl;
  }
  return 0;
}