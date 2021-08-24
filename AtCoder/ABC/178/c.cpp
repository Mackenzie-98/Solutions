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
void debug_out() {
    cerr << endl;
}
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H), debug_out(T...);
}
const ll m=1e9+7;
ll mulmod(ll a, ll b) {
    ll r = a*b-(ll)((long double)a*b/m+.5)*m;
    return r < 0 ? r+m : r;
}
ll binpow(ll a,ll n) {
    if(n==0)return 1;
    else if(n&1)return mulmod(a,binpow(mulmod(a,a),n/2));
    else return binpow(mulmod(a,a),n/2);
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
    ll n;
    cin>>n;
    cout<<(binpow(10ll,n)%m-mulmod(2,binpow(9ll,n))%m+binpow(8ll,n)%m+m)%m<<endl;
    return 0;
}