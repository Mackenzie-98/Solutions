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
    vector<ull> pot;
    for (int i = 0; i <= 10; i++) {
        pot.pb(pow(3, i));
    }
    vector<ull> ans;
    for (int mask = 0; mask < (1 << 10); mask++) {
        ull sum = 0;
        for (int bit = 0; bit < 10; bit++) {
            if (mask & (1 << bit)) {
                sum += pot[bit];
            }
        }
        ans.pb(sum);
    }
    sort(all(ans));
    while (t--) {
        ull n;
        cin >> n;
        cout << ans[lower_bound(all(ans),n)-ans.begin()] << endl;
    }
    return 0;
}