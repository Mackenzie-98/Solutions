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
ll mulmod(ll a, ll b, ll m) {
    ll r = a*b-(ll)((long double)a*b/m+.5)*m;
    return r < 0 ? r+m : r;
}
const int m = 1e9+7;
int main() {
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
#define debug(...) 3
    fastIO;
#endif
    vector<string> v(3);
    string s;
    cin>>v[0]>>v[1]>>v[2]>>s;
    vector<int> cnt(3,0);
    ll ans=1;
    forn(i,sz(s)) {
        ll cur=0,pos=0,mx=0;
        forn(j,3) {
            if(cnt[j]<sz(v[j])&&v[j][cnt[j]]==s[i]) {
                cur++;
                bool ok=true;
                int cnt=1;
                for(int k=i+1; k<sz(s); k++) {
                    if(s[k]==v[j][cnt[j]+cnt])cnt++;
                }
                if(cnt)
            }
            ans=mulmod(cur,ans,m);
            cnt[pos]++;
        }
        cout<<ans<<endl;
        return 0;
    }
