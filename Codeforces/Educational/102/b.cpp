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

int _lcm(int a,int b) {
    return (a*b)    /(__gcd(a,b));
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
        string a,b;
        cin>>a>>b;
        if(sz(a)>sz(b))swap(a,b);
        int lcm=_lcm(sz(a),sz(b));
        int x=lcm/sz(b);
        string ans="";
        forn(i,x)ans+=b;
        bool ok=true;
        for(int i=0; i<sz(ans); i+=sz(a)) {
            if(ans.substr(i,sz(a))!=a) {
                ok=false;
                break;
            }
        }
        if(ok)cout<<ans<<endl;
        else cout<<-1<<endl;

    }
    return 0;
}
