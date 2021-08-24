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

const int MAX=1e3+5;
ll m = 1e9+7;
ll F[MAX+5];

ll expmod(ll b, ll e) {
    ll ans = 1;
    while (e) {
        if (e&1) ans = (1ll*ans*b) % m;
        b = (1ll*b*b) % m;
        e /= 2;
    }
    return ans;
}

ll mulmod(ll a, ll b) {
    ll r = a*b-(ll)((long double)a*b/m+.5)*m;
    return r < 0 ? r+m : r;
}
ll invmod(ll a) {
    return expmod(a, m-2);
}

void fact() {
    F[0]=F[1]=1;
    for(ll i=2; i<=MAX; i++) {
        F[i]=mulmod(F[i-1],i);
    }
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
    fact();
    int t;
    cin>>t;
    while(t--) {
        int n,k;
        cin>>n>>k;
        vector<int> v(n);
        map<ll,ll> mp;
        forn(i,n)cin>>v[i],mp[v[i]]++;
        sort(rall(v));
        int pos=0;
        for(int i=0; i<n; i++) {
            if(v[i]==v[k-1]) {
                pos=i;
                break;
            }
        }
        ll x=mp[v[k-1]];
        ll y=((k-1)-pos)+1;
        ll ans=mulmod(F[x],invmod(mulmod(F[y],F[x-y])));
        cout<<ans<<endl;
    }
    return 0;
}
