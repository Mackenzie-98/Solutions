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
typedef double lf;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
    fastIO;
#endif
    int n;
    cin>>n;
    vector<int> v(n);
    forn(i,n)cin>>v[i];
    sort(all(v));
    ll ans=0;
    for(int i=n-1;i>1;i--){
        for(int j=i-1;j>0;j--){
            int c=upper_bound(all(v),v[i]-v[j])-v.begin();
            //cout<<v[i]<<" "<<v[j]<<" "<<v[c]<<" "<<max(0,j-c)<<endl;
            ans+=max(0,j-c);
        }
    }
    cout<<ans<<endl;
    return 0;
}
