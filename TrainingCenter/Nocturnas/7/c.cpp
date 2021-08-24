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
const int MAX = 4e3 + 5;
ll dp[MAX];
int main() {
#ifdef LOCAL
    // freopen("h.txt", "r", stdin);
    // freopen("main.out", "w", stdout);
#else
    ios::sync_with_stdio(0), cin.tie(0);
#define endl '\n'
#endif
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        pii player[n];
        forn(i, n) {
            int x, y;
            cin >> x >> y;
            player[i] = {x, y};
        }
        memset(dp, 0, sizeof dp);
        ll best = 1;
        for (int i = 0; i < n; i++) {
            dp[i] = player[i].S;
            for (int j = 0; j < i; j++) {
                if (player[i].F >= player[j].F) {
                    dp[i] = max(dp[i], dp[j] + player[i].S);
                }
            }
            best = max(best, dp[i]);
        }
        cout << best << endl;
    }
    return 0;
}