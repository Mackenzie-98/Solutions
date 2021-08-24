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

string a, b;
const int MAX = 5000;
const int oo=1e9;
int dp[MAX + 1][MAX + 1];

int edit_distance(int i, int j) {
    if(i == sz(a) && j == sz(b))return 0;
    int &ans = dp[i][j];
    if(ans != -1)return ans;
    ans = oo;
    if(i < sz(a) && j < sz(b) && a[i] == b[j])
        ans = min(ans, edit_distance(i + 1, j + 1));
    else {
        if(i < sz(a) && j < sz(b))
            ans = min(ans, edit_distance(i + 1, j + 1) + 1);
        if(i < sz(a))
            ans = min(ans, edit_distance(i + 1, j) + 1);
        if(j < sz(b))
            ans = min(ans, edit_distance(i, j + 1) + 1);
    }
    return ans;
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
    memset(dp, -1, sizeof dp);
    cin >> a >> b;
    if(sz(a) > sz(b))swap(a, b);
    cout << edit_distance(0, 0) << endl;
    return 0;
}
