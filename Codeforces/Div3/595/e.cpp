#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " = " << x << endl;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define F first
#define S second
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define pb push_back
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAX = 2e5 + 5;
int n, c;
ll a[MAX];
ll b[MAX];
ll dp[MAX][2];

int main() {
#ifdef LOCAL
    // freopen("h.txt", "r", stdin);
    // freopen("main.out", "w", stdout);
#else
    ios::sync_with_stdio(0), cin.tie(0);
#define endl '\n'
#endif

    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < 2; j++) {
            dp[i][j] = 1e9;
        }
    }
    cin >> n >> c;
    forn(i, n - 1) cin >> a[i];
    forn(i, n - 1) cin >> b[i];
    dp[0][0] = 0;
    dp[0][1] = c;
    for (int i = 1; i < n; i++) {
        dp[i][0] = dp[i - 1][0] + a[i - 1];
        dp[i][0] = min(dp[i][0], dp[i - 1][1] + a[i - 1]);
        dp[i][1] = min(dp[i][1], dp[i - 1][0] + c + b[i - 1]);
        dp[i][1] = min(dp[i][1], dp[i - 1][1] + b[i - 1]);
    }
    forn(i, n) cout << min(dp[i][0], dp[i][1]) << " ";
    cout << endl;
    return 0;
}