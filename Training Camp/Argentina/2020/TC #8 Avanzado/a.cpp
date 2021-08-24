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
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll x, y, m=1e9+7;

ll euclid(ll a, ll b) {
    if(b == 0) { x = 1; y = 0; return a; }
    ll d = euclid(b, a % b);
    ll aux = x;
    x = y;
    y = aux - (a/b)*y;
    return d;
}

ll mulmod(ll a, ll b, ll m) {
	ll r = a*b-(ll)((long double)a*b/m+.5)*m;
	return r < 0 ? r+m : r;
}
ll expmod(ll b, ll e, ll m) {
    if (e == 0) return 1;
    if (e&1) return mulmod(b, expmod(b, e-1, m), m);
    b = expmod(b, e>>1, m);
    return mulmod(b, b, m);
}

pair<ll,ll> f(ld a,ld b, ld c){
    return {(ll)round((-b+sqrt(b*b-4*a*c))/(2.0*a)),(ll)round((-b+sqrt(b*b-4*a*c))/(2.0*a))};
}

ll invmod(ll a, ll m) {
    ll d = euclid(a, m);
    if (d > 1) return -1;
    return (x % m + m) % m;
}


int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
    fastIO;
#endif
    int t;
    cin>>t;
    while(t--){
        ll a,n;
        cin>>a>>n;
        pll w=f(1,-a,1);
        ll b=0;
        for(ll p=-1000000;p<=1000000;p++){
            x=0,y=0;
            //if(p*p-a*p+1==0){
                ll num=(mulmod(expmod(p,n,m),expmod(p,n,m),m)+1)%m;
                ll den = expmod(p,n,m);
                if(num%den==0){
                    //cout<<b<<endl;
                    b = mulmod(num,invmod(den,m),m);
                    break;
                }

        }
        cout<<b<<endl;
        /*ll b=0;
        ll p=w.F,y=w.S;
        if(p*p-a*p+1==0)b=mulmod((mulmod(expmod(p,n,m),expmod(p,n,m),m)+1)%m,invmod(expmod(p,n,m),m),m);
        else b=mulmod((mulmod(expmod(y,n,m),expmod(y,n,m),m)+1)%m,invmod(expmod(y,n,m),m),m);
        cout<<b<<endl;*/
    }
    return 0;
}
