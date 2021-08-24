#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define F first
#define S second
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define pb push_back
#define fastIO ios::sync_with_stdio(0), cin.tie(0);
#define endl '\n'
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
int n, k;
bool check(int m, vector<int> p) {
    int cnt = 0;
    for (int i = 0; i < sz(p) - 1; i++) {
        if (p[i + 1] - p[i] <= m) {
            cnt++;
            i++;
        }
        if (cnt == n || 2 * cnt * k <= i) {
            break;
        }
    }
    return cnt == n ? 1 : 0;
}
int main() {
#ifdef LOCAL
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
    fastIO;
#endif
    while (cin >> n >> k) {
        vector<int> p;
        forn(i, 2 * n * k) {
            int pi;
            cin >> pi;
            p.pb(pi);
        }
        sort(all(p));
        int lo = 0, hi = 2e9;
        for (int it = 0; it < 70; it++) {
            int mid = (lo + hi) / 2;
            //cout << mid << endl;
            if (check(mid, p)) {
                hi = mid;
            } else {
                lo = mid;
            }
        }
        cout << hi << endl;
    }
    return 0;
}