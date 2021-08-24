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
    int n,m,k;
    cin>>n>>m>>k;
    vector<pii> s(k),f(k);
    pii ini= {0,0};
    forn(i,k)cin>>s[i].ft>>s[i].sd,ini.ft=max(ini.ft,s[i].ft),ini.sd=max(ini.sd,s[i].sd);
    forn(i,k)cin>>f[i].ft>>f[i].sd;
    string ans="";
    forn(i,ini.sd)ans+="L";
    forn(i,ini.ft)ans+="U";
    forn(i,n) {
        forn(j,m-1) {
            if(i%2==0)
                ans+="R";
            else ans+="L";
        }
        if(i!=n-1)
            ans+="D";
    }
    if(sz(ans)>2*n*m)cout<<-1<<endl;
    else {
        cout<<sz(ans)<<endl;
        cout<<ans<<endl;
    }

    return 0;
}
