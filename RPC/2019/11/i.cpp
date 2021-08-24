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
    ll arr[n];
    ll sum=0;
    forn(i,n){
        cin>>arr[i];
        sum+=arr[i]*arr[i];
    }
    ll sum2=arr[n-1];
    sum-=arr[n-1]*arr[n-1];
    ll ans=0;
    for(int i=n-2;i>=0;i--){
        //cout<<ans<<" "<<sum<<" "<<sum2<<endl;
        ans=max(ans,sum*sum2);
        sum2+=arr[i];
        sum-=arr[i]*arr[i];
    }
    cout<<ans<<endl;

  return 0;
}
