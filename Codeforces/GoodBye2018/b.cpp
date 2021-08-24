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
    while (t--) {
        int n;
        cin >> n;
        vector<int> v;
        forn(i, n) {
            int x;
            cin >> x;
            v.pb(x);
        }
        forn(i, n - 1) {
            if (abs(v[i] - v[i + 1]) >= 2) {
                cout << "YES" << endl;
                cout << i + 1 << " " << i + 2 << endl;
                goto done;
            }
        }
        cout << "NO" << endl;
    done:;
    }
    return 0;
}