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
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void debug_out() {cerr << endl;}
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {cerr << " " << to_string(H), debug_out(T...);}
ll n,X,V;
const ld pi = acos(-1);
double time(vector<pair<pair<ll,ll>,ld>> v, ld teta,ld &tt){
    ld ans=v[0].ft.ft*tan(teta);
    ld h = sqrt(v[0].ft.ft*v[0].ft.ft+ans*ans);
    tt+=h/(1.0*V);
    forn(i,n){
        ll xi=v[i].ft.sd-v[i].ft.ft;
        h = sqrt(xi*xi+ans*ans);
        tt+=h/abs(v[i].sd);
        if(v[i].sd<=0)
            ans-=xi*tan(teta);
        else ans+=xi*tan(teta);
    }
    ll xx=(X-v[n-1].ft.sd);
    h = sqrt(xx*xx+ans*ans);
    tt+=h/(1.0*V);
    return v[n-1].ft.sd+abs(ans)*tan(teta);
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
    cin>>n>>X>>V;
    vector<pair<pair<ll,ll>,ld>> v(n);
    forn(i,n)cin>>v[i].ft.ft>>v[i].ft.sd>>v[i].sd;
    ld hi=90,lo=-90;
    forn(it,70){
        ld angle=(lo+hi)/2;
        ld tt=0;
        ld cur=time(v,(angle*pi)/180.0,tt);
        debug(angle,cur,tt);
        if(cur>X){
            hi=angle;
        }else{
            lo=angle;
        }
    }
    double v2=V*cos((hi*pi)/(180.0));
    double ans=X/v2;
    cout<<ans<<endl;

    return 0;
}
