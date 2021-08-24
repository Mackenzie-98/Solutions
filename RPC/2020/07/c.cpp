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
typedef double lf;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

pii x1,x2,x3,x4,c1,c2,c3,c4;

bool inPolygon(vector<pii> c,pii p1,pii p2){
    for(auto x:c){
        if(x.F>p1.F&&x.F<p2.F&&x.S>p1.S&&x.S<p2.S)return true;
    }
    bool cond1=c[0].S==x1.S&&c[0].F>=x1.F&&c[0].F<=x3.F;
    bool cond2=c[1].S==x2.S&&c[1].F>=x2.F&&c[1].F<=x2.F;
    bool cond3=c[2].F==x1.F&&c[2].S>=x1.S&&c[2].S<=x2.S;
    bool cond4=c[3].F==x3.F&&c[3].S>=x3.S&&c[3].S<=x4.S;
    if(cond1||cond2||cond3||cond4)return true;
    return false;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
    fastIO;
#endif
    int x,y,r,tx,ty,s;
    cin>>x>>y>>r>>tx>>ty>>s;


    x1={tx,ty};
    x2={tx,ty+s};
    x3={tx+s,ty};
    x4={tx+s,ty+s};

    c1={x,y-r};
    c2={x,y+r};
    c3={x-r,y};
    c4={x+r,y};

    vector<pii> points={x1,x2,x3,x4};
    vector<pii> centros={c1,c2,c3,c4};
    bool ok=0;
    for(auto p:points){
        if((x-p.F)*(x-p.F)+(y-p.S)*(y-p.S)<r*r){
            ok=1;
            break;
        }
    }
    ok|=inPolygon(centros,x1,x4);
    if(ok)cout<<2<<endl;
    else{
        bool cond1=c1.S==x2.S&&c1.F>=x2.F&&c1.F<=x4.F;
        bool cond2=c2.S==x1.S&&c2.F>=x1.F&&c2.F<=x3.F;
        bool cond3=c3.F==x3.F&&c3.S>=x3.S&&c3.S<=x4.S;
        bool cond4=c4.F==x1.F&&c4.S>=x1.S&&c4.S<=x2.S;
        bool cond5=0;
        for(auto p:points){
            if((p.F-x)*(p.F-x)+(p.S-y)*(p.S-y)==r*r){
                cond5=1;
                break;
            }
        }
        //cout<<cond1<<" "<<cond2<<" "<<cond3<<" "<<cond4<<" "<<cond5<<endl;
        if(cond1||cond2||cond3||cond4||cond5)cout<<1<<endl;
        else cout<<0<<endl;
    }
    return 0;
}
