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
const int MAX = 1000005;
int s, c, t;
int dp[MAX];
int INF = 1e9;
int f(int time) {
    if (time - s < 0 && time - c >= 0) return min(time, f(time - c));
    if (time - c < 0 && time - s >= 0) return min(time, f(time - s));
    if (time - s < 0 && time - c < 0) return time;
    int &ans = dp[time];
    if (ans != INF) return ans;
    ans = min(ans, f(time - s));
    ans = min(ans, f(time - c));
    return ans;
}
int main() {
#ifdef LOCAL
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
    fastIO;
#endif
    while (cin >> t >> c >> s) {
        forn(i, t + 10) dp[i] = INF;
        cout << f(t) << endl;
    }
    return 0;
}