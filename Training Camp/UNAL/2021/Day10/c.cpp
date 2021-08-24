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
typedef pair<double, double> pdd;
typedef unsigned long long ull;
struct fraction {
    ll x, y;
    fraction(ll _x, ll _y) {x = _x, y = _y;}

};

void __print(int x) {cerr << x;}
void __print(fraction f) {cerr << f.x << "/" << f.y;}
void __print(long long x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for(auto &i : x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if(sizeof...(v)) cerr << ", "; _print(v...);}
const ld eps = 1e-12;

bool check(fraction a, fraction b) {
    return a.x * b.y == a.y * b.x;
}
ull gcd(ull a, ull b) {
    return b == 0 ? a : gcd(b, a%b);
}
int main() {

#ifdef LOCAL
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
#define debug(x...) 03
    fastIO;
#endif
    int n;
    cin >> n;
    set<pair< pair<pair<ull, ull>, pair<ull, ull>>, pair<ull, ull>>> v;
    ull xi, yi, zi;
    cin >> xi >> yi >> zi;
    forn(i, n - 1) {
        ull x, y, z;
        cin >> x >> y >> z;
        ull u = (ull)((x - xi) * (x - xi)) + (ull)((y - yi) * (y - yi)) + (ull)((z - zi) * (z - zi));
        ull aa=gcd((x - xi) * (x - xi), u);
        ull bb=gcd((y - yi) * (y - yi), u);
        ull cc=gcd((z - zi) * (z - zi), u);
        pair<ull, ull> a(((x - xi) * (x - xi))/aa, u/aa);
        pair<ull, ull> b(((y - yi) * (y - yi))/bb, u/bb);
        pair<ull, ull> c(((z - zi) * (z - zi))/cc, u/cc);
        /*cout<<a.ft<<" "<<a.sd<<endl;
        cout<<b.ft<<" "<<b.sd<<endl;
        cout<<c.ft<<" "<<c.sd<<endl;
        cout<<u<<endl;*/
        v.insert({{a, b}, c});
    }
    cout << sz(v) << endl;
    /*vector<pair<pair<fraction, fraction>, fraction>> ans;
    for(int i = 0; i < sz(v); i++) {
        bool ok = true;
        forn(j, sz(ans)) {
            if(check(v[i].ft.ft, ans[j].ft.ft) && check(v[i].ft.sd, ans[j].ft.sd) && check(v[i].sd, ans[j].sd)) {
                ok = false;
                break;
            }
        }
        if(ok)
            ans.pb(v[i]);
    }
    cout << sz(ans) << endl;*/
    return 0;
}
