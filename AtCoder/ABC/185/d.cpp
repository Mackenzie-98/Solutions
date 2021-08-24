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
void debug_out() {
    cerr << endl;
}
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H), debug_out(T...);
}

int main() {
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
#define debug(...) 3
    fastIO;
#endif
    ll n,m;
    cin>>n>>m;
    if(m==0)cout<<1<<endl;
    else {
        vector<ll> v(m);
        forn(i,m)cin>>v[i];
        sort(all(v));
        ll mn=1e15;
        if(sz(v)) {
            if(v[0]!=1)
                mn=min(mn,v[0]-1);
            if(v[m-1]!=n)
                mn=min(mn,n-v[m-1]);
        }
        forn(i,m-1) {
            if(v[i+1]-v[i]-1!=0)
                mn=min(mn,v[i+1]-v[i]-1);
        }
        ll ans=0;
        if(sz(v))ans+=(v[0]+mn-2)/mn,ans+=(n-v[m-1]+mn-1)/mn;
        forn(i,m-1) {
            ans+=(v[i+1]-v[i]+mn-2) /mn;
        }
        cout<<ans<<endl;
    }
    return 0;
}
