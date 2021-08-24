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
        map<int,vector<int>> g;
        map<int,int> mp;
        int n;
        cin>>n;
        bool mark[n];
        memset(mark,0,sizeof mark);
        forn(i,n) {
            int x;
            cin>>x;
            g[x].pb(i);
            mp[i]=x;
        }
        vector<int> v;
        for(auto x:g) {
            v.pb(x.ft);
        }
        if(sz(g)==1)cout<<"NO"<<endl;
        else {
            cout<<"YES"<<endl;
            int target1=g[v[0]][0];
            int target2=g[v[1]][0];
            for(int i=0; i<sz(v)-1; i++) {
                cout<<to_string(g[v[i]][0]+1)<<" "<<to_string(g[v[i+1]][0]+1)<<endl;
                mark[g[v[i]][0]]=true;
                mark[g[v[i+1]][0]]=true;
            }
            for(int i=0; i<n; i++) {
                if(!mark[i]) {
                    if(mp[i]!=mp[target1]) {
                        cout<<i+1<<" "<<target1+1<<endl;
                        mark[i]=true;
                    } else {
                        cout<<i+1<<" "<<target2+1<<endl;
                        mark[i]=true;
                    }
                }
            }
        }
    }
    return 0;
}
