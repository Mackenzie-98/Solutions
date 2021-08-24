/**
 * @author: Mackenzie
**/
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
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
bool isPal(string s){
    for(int i=0;i<(sz(s)+1)/2;i++){
        //cout<<s[i]<<" "<<s[sz(s)-i-1]<<endl;
        if(s[i]!=s[sz(s)-i-1])return false;
    }
    return true;
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
    fastIO;
#endif
    int n,m;
    cin>>n>>m;
    vector<ll> v(n);
    forn(i,n){
        int x,y;
        cin>>x>>y;
        v[i]=x*y;
    }
    vector<ll> pre(n);
    pre[0]=v[0];
    for(int i=1;i<n;i++){
        pre[i]=v[i]+pre[i-1];
    }
    forn(i,m){
        int q;
        cin>>q;
        int ans=lower_bound(all(pre),q)-pre.begin();
        cout<<ans+1<<endl;
    }
    return 0;
}
