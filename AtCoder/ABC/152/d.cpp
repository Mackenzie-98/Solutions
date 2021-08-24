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
int main() {
#ifdef LOCAL
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
    fastIO;
#endif
    map<pair<int, int>, int> F;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int cur = i;
        while (cur > 9) {
            cur /= 10;
        }
        F[{cur, i % 10}]++;
    }
    //clfor (auto x : F) cout << x.F << " " << x.S << endl;
    ll ans = 0;
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            ans += F[{i, j}] * F[{j, i}];
        }
    }
    cout << ans << endl;
    return 0;
}