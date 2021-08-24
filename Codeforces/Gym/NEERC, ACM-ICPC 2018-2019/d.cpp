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
ll mp[1000005];
int main() {
    fastIO;
    freopen("deposits.in", "r", stdin);
    freopen("deposits.out", "w", stdout);
    int n;
    cin>>n;
    vector<int> a(n);
    forn(i,n)cin>>a[i];
    int m;
    cin>>m;
    vector<int> b(m);
    memset(mp,0,sizeof mp);
    forn(i,m)cin>>b[i],mp[b[i]]++;
    ll ans=0;
    forn(i,n) {
        for(ll j=1; j*j<=a[i]; j++) {
            if(a[i]%j==0) {
                if(j*j==a[i])ans+=mp[j];
                else {
                    ans+=mp[j];
                    ans+=mp[a[i]/j];
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
