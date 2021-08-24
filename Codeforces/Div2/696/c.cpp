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
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        map<int,bool> mp;
        vector<int> v(2*n);
        forn(i,2*n)cin>>v[i],mp[v[i]]=i;
        vector<pair<int,pii>> sums;
        for(int i=0; i<2*n; i++) {
            for(int j=i+1; j<2*n; j++) {
                if(mp.count(v[i]+v[j])&&mp[v[i]+v[j]]!=i&&mp[v[i]+v[j]]!=j) {
                    sums.pb({v[i]+v[j],{i,j}});
                }
            }
        }
        sort(all(sums));
        string ans="";
        bool ok=true;
        for(int i=1; i<sz(sums); i++) {
            if(sums[i-1].ft!=max(v[sums[i].sd.ft],v[sums[i].sd.sd])) {
                ok=false;
                break;
            }
        }
        if(!ok)cout<<"NO"<<endl;
        else {
            cout<<"YES"<<endl;
            cout<<v[sums[sz(sums)-1].sd.ft]+v[sums[sz(sums)-1].sd.sd]<<endl;
            for(auto x:sums)cout<<x.sd.ft<<" "<<x.sd.sd<<endl;
        }

    }
    return 0;
}
