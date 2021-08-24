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
  int n;
  cin>>n;
  int arr[n];
  forn(i,n)cin>>arr[i];
  sort(arr,arr+n);
  ll x=0;ll y=0;
  forn(i,n/2)x+=arr[i];
  for(int i=n/2;i<n;i++)y+=arr[i];
  cout<<x*x+y*y<<endl;
  return 0;
}