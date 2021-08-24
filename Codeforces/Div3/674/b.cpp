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
        int n,m;
        cin>>n>>m;
        bool ok1=false,ok2=false;
        vector<int> a[n+1];
        forn(i,n) {
            int x,b,c,d;
            vector<int> v;
            cin>>x>>b>>c>>d;
            v.pb(x),v.pb(b),v.pb(c),v.pb(d);
            a[i]=v;
            if(c==b)ok1=true;
        }
        for(int i=0; i<n; i++) {
            for(int j=i; j<n; j++) {
                if(a[i][0]==a[j][0]&&a[i][1]==a[j][2]&&a[i][2]==a[j][1]&&a[i][3]==a[j][3]) {
                    ok2=true;
                    break;
                }
            }
        }
       // cout<<m<<" "<<ok1<<" "<<ok2<<endl;
        if(m%2==0&&ok1&&ok2)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
