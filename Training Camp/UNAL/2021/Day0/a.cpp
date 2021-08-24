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
const double pi = acos(-1);
int main() {
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
#define debug(...) 3
    fastIO;
#endif
    int n;
    cin>>n;
    vector<pair<pii,int>> v(n);
    forn(i,n)cin>>v[i].ft.sd>>v[i].ft.ft,v[i].sd=i+1;
    sort(all(v));
    bool ok=true;
    forn(i,n-2) {
        double x1=v[i].ft.ft,y1=v[i].ft.sd;
        double x2=v[i+1].ft.ft,y2=v[i+1].ft.sd;
        double x3=v[i+2].ft.ft,y3=v[i+2].ft.sd;
        double a=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
        double b=sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
        double c=sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1));
        double teta= (((c*c-a*a-b*b)/(-2*a*b))*pi)/180.0;
        double angle= abs(acos(teta))-1e-10;
        if(angle>pi/2.0){
            ok=false;
            break;
        }
    }
    ok=true;
    if(ok){
        forn(i,n){
            if(i!=n-1)
            cout<<v[i].sd<<" ";
            else cout<<v[i].sd<<endl;
        }
    }else{

    }

    return 0;
}
