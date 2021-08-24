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

/*const int oo = 1e9;
const int MAX = 1e5 + 1;

int dp[1001][MAX];
int n, x;

int maxPages(int i, int w) {
    if(w < 0)return -oo;
    if(w == 0 || i >= n)return 0;
    int &ans = dp[i][w];
    if(ans != -1)return ans;
    return ans = max(maxPages(i + 1, w), maxPages(i + 1, w - price[i]) + pages[i]);
}*/
const int oo = 1e9;
const int MAX = 1e5 + 1;
int price[MAX], pages[MAX];
int main() {

#ifdef LOCAL
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
#define debug(x...) 03
    fastIO;
#endif
    int n, x;
    cin >> n >> x;
    forn(i, n)cin >> price[i + 1];
    forn(i, n)cin >> pages[i + 1];
    int dp[n + 1][x + 1];
    memset(dp, 0, sizeof dp);
    for(int i = 1; i <= n; i++) {
        for(int money = 0; money <= x; money++) {
            dp[i][money] = dp[i - 1][money];
            if(money - price[i] >= 0) {
                dp[i][money] = max(dp[i][money], pages[i] + dp[i - 1][money - price[i]]);
            }
        }
    }
    cout << dp[n][x] << endl;
    return 0;
}
