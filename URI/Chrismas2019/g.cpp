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
int main() {
#ifdef LOCAL
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
    fastIO;
#endif
    int t;
    cin >> t;
    string ans[2] = {"JOAO", "MARIA"};
    while (t--) {
        int j = 0, m = 0;
        forn(i, 3) {
            int x, d;
            cin >> x >> d;
            j += x * d;
        }
        forn(i, 3) {
            int x, d;
            cin >> x >> d;
            m += x * d;
        }
        if (j > m) {
            cout << ans[0] << endl;
        } else {
            cout << ans[1] << endl;
        }
    }
    return 0;
}