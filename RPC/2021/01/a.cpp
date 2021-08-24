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
        ll a,s;
        cin>>a>>s;
        vector<ll> eval(a);
        ll y=0;
        forn(i,a)cin>>eval[i],y+=eval[i];
        forn(i,s) {
            ll sum=0;
            forn(j,a) {
                ll x;
                cin>>x;
                sum+=x*eval[j];
            }
            int x=(sum/(1.0*y))/5;
            double diff=(sum/(1.0*y))-x*5.0;
            if(abs(diff)<1e-10) {
                cout<<x*5<<" SAME"<<endl;
            } else if(diff>2.5&&abs(diff-2.5)>1e-10) {
                x++;
                cout<<x*5<<" UP"<<endl;
            } else cout<<x*5<<" DOWN"<<endl;
        }
        cout<<endl;
    }
    return 0;
}
