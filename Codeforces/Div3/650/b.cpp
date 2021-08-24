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
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> v(n);
        int even=0,odd=0,ans=0;
        forn(i,n)cin>>v[i],even+=v[i]%2==0,odd+=v[i]%2==1;
        if(n/2==odd&&(n+1)/2==even){
            forn(i,n){
                if(v[i]%2!=i%2)ans++;
            }
            cout<<ans/2<<endl;
        }else cout<<-1<<endl;

    }
    return 0;
}
