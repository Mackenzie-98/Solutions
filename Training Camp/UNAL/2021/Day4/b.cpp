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

void __print(int x) {cerr << x;}
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

const int MAX = 1e3 + 5;
const int T = 1e6 + 5;
int gas[MAX], sup[MAX];
int tt[T];
int p, r, c;

int main() {

#ifdef LOCAL
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
#define debug(x...) 03
    fastIO;
#endif
    cin >> p >> r >> c;
    ll sum = 0;
    forn(i, p)cin >> gas[i], sum += gas[i];
    forn(i, r)cin >> sup[i];
    vector<ll> time[MAX];
    int mx = 0;
    map<int, int> mp;
    forn(i, c) {
        int x, y, t;
        cin >> x >> y >> t;
        x--, y--;
        mx = max(mx, t);
        debug(mp);
        forn(i, 6)cout << tt[i] << " ";
        cout << endl;
        if(mp.count(y) && t < mp[y]) {
            tt[mp[y]] -= sup[y];
            tt[t] += sup[y];
            mp[y ] = t;
        }
        else {
            tt[t] += sup[y ];
            mp[y ] = t;
        }
    }
    forn(i, 6)cout << tt[i] << " ";
    cout << endl;
    vector<ll> pre;
    pre.pb(tt[0]);
    for(int i = 1; i <= mx; i++) {
        if(pre[i - 1] + tt[i] >= 1e6 + 5)break;
        pre.pb(pre[i - 1] + tt[i]);
    }
    forn(i, mx + 1) {
        cout << i << " " << tt[i] << endl;
        if(pre[i] >= sum) {
            cout << i << endl;
            break;
        }
    }

    return 0;
}
