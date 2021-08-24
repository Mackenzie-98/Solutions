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
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void debug_out() {
    cerr << endl;
}
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H), debug_out(T...);
}



ll f(int i, int j, int k) {
    //cout << i << k << k << endl;
    if(NO SE CUANDO PARAR)return 0;
    //cout << i << " " << j << " " << k << endl;
    ll &ans = dp[i][j][k];
    if(ans != -1)return ans;
    ans = 0;
    ans = max(ans, f(i + 1, j + 1, k) + r[i] * g[j]);
    ans = max(ans, f(i + 1, j, k + 1) + r[i] * b[k]);
    ans = max(ans, f(i, j + 1, k + 1) + g[j] * b[k]);
    return ans;
}

int R, G, B;
const int MAX = 201;
ll dp[MAX][MAX][MAX];

int main() {
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
#define debug(...) 3
    fastIO;
#endif
    cin >> R >> G >> B;
    vector<ll> r(R), g(G), b(B);
    forn(i, R)cin >> r[i];
    forn(i, G)cin >> g[i];
    forn(i, B)cin >> b[i];
    sort(all(r));
    sort(all(b));
    sort(all(g));
    for(int i = 0; i <= R; i++) {
        for(int j = 0; j <= G; j++) {
            for(int k = 0; k <= B; k++) {
                if(i&&j)dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][k] + r[i - 1] * g[j - 1]);
                if(i&&k)dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k - 1] + r[i - 1] * b[k - 1]);
                if(j&&k)dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k - 1] + g[j - 1] * b[k - 1]);
            }
        }
    }
    cout << dp[R][G][B] << endl;
    return 0;
}
