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
int n, x;
ll memo[25][155];
ll dp(int left, int points) {
    if (left == 0 && points >= x) return 1;
    if (left == 0 && points < x) return 0;
    ll &ans = memo[left][points];
    if (ans != -1) return ans;
    ans = 0;
    forn(i, 6) {
        ans += dp(left - 1, points + i + 1);
    }
    return ans;
}
int main() {
#ifdef LOCAL
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
    fastIO;
#endif
    while (cin >> n >> x && !(n == 0 && x == 0)) {
        memset(memo, -1, sizeof memo);
        ll events = dp(n, 0);
        ll total = pow(6, n);
        ll g = __gcd(events, total);
        events /= g, total /= g;
        if (events == 0)
            cout << 0 << endl;
        else if (events == 1 && total == 1)
            cout << 1 << endl;
        else
            cout << events << "/" << total << endl;
    }
    return 0;
}