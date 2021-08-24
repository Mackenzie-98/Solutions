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

int main() {

#ifdef LOCAL
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
#define debug(x...) 03
    fastIO;
#endif
    ll a, x, y;
    cin >> a >> x >> y;
    ll ans = -1;
    if(y < 2 * a) {
        if(!(y == 0 || y == a) && ((x > -a / 2 && x < a / 2) || ((a % 2 == 1) && x >= -a / 2 && x <= a / 2)))
            ans = (y + a - 1) / a;
    }
    else {
        y -= 2 * a;
        ll level = 3;
        ll cur = 0;
        while(y - a >= 0) {
            if(cur % 2 == 0)level += 2;
            else level++;
            cur++;
            y -= a;
            debug(level, y, cur);
        }
        if(y != 0) {
            if(cur % 2 == 0) {
                if(x < 0 && x > -a)
                    ans = level;
                else if(x > 0 && x < a)
                    ans = level + 1;
            }
            else {
                if((x > -a / 2 && x < a / 2) || (((a % 2 == 1) && x >= -a / 2 && x <= a / 2)))
                    ans = level;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
