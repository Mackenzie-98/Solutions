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

int main() {
#ifdef LOCAL
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
    fastIO;
#endif
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string ans = "3 1 4 2";
        if (n < 4)
            cout << -1 << endl;
        else {
            bool flag = 0;
            forn(i, n - 4) {
                if (!flag) {
                    ans = ans + " " + to_string(i + 5);
                    flag = 1;
                } else {
                    ans = to_string(i + 5) + " " + ans;
                    flag = 0;
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}