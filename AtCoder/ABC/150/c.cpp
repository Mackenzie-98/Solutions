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
    int n;
    cin >> n;
    vector<int> a(n), b(n), x, y;
    forn(i, n) cin >> a[i];
    forn(i, n) cin >> b[i];
    x = a, y = b;
    sort(all(a)), sort(all(b));
    int p = 0, q = 0;
    int cur = 0;
    do {
        bool ok1 = 1, ok2 = 1;
        forn(i, n) {
            if (x[i] != a[i]) {
                ok1 = 0;
                break;
            }
        }
        forn(i, n) {
            if (y[i] != a[i]) {
                ok2 = 0;
                break;
            }
        }
        if (ok1) {
            p = cur;
        }
        if (ok2) {
            q = cur;
        }
        cur++;
    } while (next_permutation(all(a)));
    cout << abs(p - q) << endl;
    return 0;
}