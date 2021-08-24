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
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> v(n);
        ll sum = 0, best3 = -1e18;
        forn(i, n) cin >> v[i], sum += v[i], best3 = max(best3, v[i]);
        ll best1 = -1e18, best2 = -1e18;
        ll cursum = 0;
        for (int i = 0; i < n - 1; i++) {
            cursum += v[i];
            if (cursum > best1) {
                best1 = cursum;
            }
            if (cursum < 0) {
                cursum = 0;
            }
        }
        cursum = 0;
        for (int i = 1; i < n; i++) {
            cursum += v[i];
            if (cursum > best2) {
                best2 = cursum;
            }
            if (cursum < 0) {
                cursum = 0;
            }
        }
        //cout << best1 << " " << best2 << " " << best3 << endl;
        if (sum > best1 && sum > best2 && sum > best3)
            cout
                << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}