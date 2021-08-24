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
    ll n,c;
    cin>>n>>c;
    vector<pair<pll,ll>> v(n);
    ll cost=0,sum=0,mn=1e15;
    forn(i,n) {
        cin>>v[i].ft.ft>>v[i].ft.sd>>v[i].sd;
        mn=min(mn,(v[i].ft.sd-v[i].ft.ft+1));
        sum+=v[i].sd;
    }
    if(sum>c)cost-=(sum*mn-c*mn);
    int curdays=0;
    forn(i,n) {
        cin>>v[i].ft.ft>>v[i].ft.sd>>v[i].sd;
        cost+=(v[i].ft.sd-(v[i].ft.ft+curdays)+1)*v[i].sd;
        if(v[i].sd>=c) {
            cost+=max(0ll,(c-v[i].sd)*(v[i].ft.sd-(v[i].ft.ft+curdays)+1));
            curdays=abs(curdays-((v[i].ft.sd-(v[i].ft.ft+curdays)+1)));
        }
    }
    cout<<cost<<endl;
    return 0;
}
