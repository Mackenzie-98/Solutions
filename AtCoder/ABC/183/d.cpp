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


struct STree {
    vector<ll> st,lazy;
    int n;
    STree(int n): st(4*n+5,0), lazy(4*n+5,0), n(n) {}
    void init(int k, int s, int e,ll *a) {
        lazy[k]=0;
        if(s+1==e) {
            st[k]=a[s];
            return;
        }
        int m=(s+e)/2;
        init(2*k,s,m,a);
        init(2*k+1,m,e,a);
        st[k]=st[2*k]+st[2*k+1];
    }
    void push(int k, ll s, ll e) {
        if(!lazy[k])return;
        st[k]+=(e-s)*lazy[k];
        if(s+1<e) {
            lazy[2*k]+=lazy[k];
            lazy[2*k+1]+=lazy[k];
        }
        lazy[k]=0;
    }
    void upd(int k, ll s, ll e, int a, int b, ll v) {
        push(k,s,e);
        if(s>=b||e<=a)return;
        if(s>=a&&e<=b) {
            lazy[k]+=v;
            push(k,s,e);
            return;
        }
        int m=(s+e)/2;
        upd(2*k,s,m,a,b,v);
        upd(2*k+1,m,e,a,b,v);
        st[k]=st[2*k]+st[2*k+1];
    }
    ll query(int k, ll s, ll e, int a, int b) {
        if(s>=b||e<=a)return 0;
        push(k,s,e);
        if(s>=a&&e<=b)return st[k];
        int m=(s+e)/2;
        return query(2*k,s,m,a,b)+query(2*k+1,m,e,a,b);
    }
    void init(ll *a) {
        init(1,0,n,a);
    }
    void upd(int a, int b, ll v) {
        upd(1,0,n,a,b,v);
    }
    ll query(int a, int b) {
        return query(1,0,n,a,b);
    }
};
const int MAX=2e5+5;
int main() {
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
#define debug(...) 3
    fastIO;
#endif
    int n,w;
    cin>>n>>w;
    STree st(MAX);
    ll mx=0;
    forn(i,n) {
        ll x,y,p;
        cin>>x>>y>>p;
        st.upd(x,y,p);
        mx=max(mx,y);
    }
    bool ok=true;
    for(int i=0; i<=mx&&ok; i++) {
        debug(i,st.query(i,i+1));
        if(st.query(i,i+1)>w) {
            ok=false;
        }
    }
    if(ok)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}

