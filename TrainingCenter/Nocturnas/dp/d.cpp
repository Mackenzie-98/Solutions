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
int n;
string s;
const int MAX = 1e5 + 5;
ll mem[MAX];
ll dp(ll pos) {
    if (pos >= n) return 0;
    ll &ans = mem[pos];
    if (ans != -1) return ans;
    ans = max(ans, dp(pos + 1));
    ans = max(ans, dp(pos + (s[pos] - 'a' + 1)) + (s[pos] - 'a' + 1));
    return ans;
}
int main() {
#ifdef LOCAL
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
    fastIO;
#endif
    while (cin >> n >> s) {
        memset(mem, -1, sizeof mem);
        cout << dp(0) << endl;
    }
    return 0;
}