/**
 * @author: Mackenzie
**/
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
const int MAX = 1e5 + 5;
ll m = 1000000007;
ll dp[MAX];
void pre() {
    dp[1] = 0;
    dp[2] = 0;
    dp[3] = 1;
    for (int i = 4; i <= MAX - 1; i++) {
        dp[i] = (dp[i - 1] % m + dp[i - 2] % m + dp[i - 3] % m) % m;
    }
}
int main() {
#ifdef LOCAL
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
    fastIO;
#endif
    pre();
    int n;
    while (cin >> n) {
        cout << dp[n] << endl;
    }
    return 0;
}