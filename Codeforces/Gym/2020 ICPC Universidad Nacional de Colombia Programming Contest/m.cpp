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
void debug_out() {cerr << endl;}
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {cerr << " " << to_string(H), debug_out(T...);}

int main() {
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
#define debug(...) 3
    fastIO;
#endif
    string s;
    cin>>s;
    int q;
    cin>>q;
    map<char,vector<int>> mp;
    forn(i,sz(s))mp[s[i]].pb(i);
    int last=-1;
    while(q--){
        string x;
        cin>>x;
        string ans="";
        last=-1;
        forn(i,sz(x)){
            if(sz(mp[x[i]])==0)break;
            int ind=lower_bound(all(mp[x[i]]),last)-mp[x[i]].begin();
            //debug(ind,mp[x[i]][ind]);
            if(ind<0||ind>=sz(mp[x[i]]))break;
            last=mp[x[i]][ind]+1;
            ans+=x[i];
        }
        if(ans!="")cout<<ans<<endl;
        else cout<<"IMPOSSIBLE"<<endl;

    }
    return 0;
}
