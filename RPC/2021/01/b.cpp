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
const int MAXN = 1e4 + 1, MAXK = 1e2 + 1;
int n, k;
pair<int, pii> a[MAXN];
int dp[MAXN][MAXK];
int oo = 1e9;
int f(int i, int ki) {
    if(i == n) {
        if(ki == 0)
            return 0;
        else return -oo;
    }
    int &ans = dp[i][ki];
    if(ans != -1)return ans;
    else ans = max(f(i + 1, max(0,ki - a[i].ft)), f(i + 1, ki) + max(a[i].sd.ft, a[i].sd.sd));
    return ans;
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
    int t;
    cin >> t;
    while(t--) {
        memset(dp, -1, sizeof dp);
        cin >> n >> k;
        ll sum = 0;
        forn(i, n) {
            cin >> a[i].ft >> a[i].sd.ft >> a[i].sd.sd;
            sum += a[i].ft;
        }
        if(sum < k)cout << "NO SOLUTION" << endl;
        else cout << f(0, k) << endl;
    }
    return 0;
}
