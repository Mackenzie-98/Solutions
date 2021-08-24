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
int n;
bool check(int u, int d, int r, int l) {
    if(u == n) {
        if(d == n) {
            if(!(r >= 2 && l >= 2))
                return false;
        } else if(d == n - 1) {
            if(!((r >= 1 && l >= 2) || (r >= 2 && l >= 1)))
                return false;
        } else {
            if(!(r >= 1 && l >= 1))
                return false;
        }
    } else if(u == n - 1) {
        if(d == n) {
            if(!((r >= 1 && l >= 2) || (r >= 2 && l >= 1)))
                return false;
        } else if(d == n - 1) {
            if(!((r >= 1 && l >= 1) || (r >= 2) || (l >= 2)))
                return false;
        } else {
            if(!(r >= 1 || l >= 1))
                return false;
        }
    }
    return true;
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
    int t;
    cin >> t;
    while(t--) {
        int u, r, d, l;
        cin >> n >> u >> r >> d >> l;
        //debug(check(u, d, r, l), check(d, u, r, l), check(r, l, u, d), check(l, r, u, d));
        bool ok = !check(u, d, r, l) || !check(d, u, r, l) || !check(r, l, u, d) || !check(l, r, u, d);
        if(ok)cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    return 0;
}
