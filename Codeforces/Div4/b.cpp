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
        ll n, k;
        cin >> n >> k;
        if (n % 2 == 1 && k % 2 == 0)
            cout << "NO" << endl;
        else {
            ll a = k - 1, b = 2 * (k - 1);
            if ((n - a) >= 1 && (n - a) % 2 == 1) {
                cout << "YES" << endl;
                forn(i, k - 1) cout << 1 << " ";
                cout << n - a << endl;
            } else if ((n - b) >= 2 && (n - b) % 2 == 0) {
                cout << "YES" << endl;
                forn(i, k - 1) cout << 2 << " ";
                cout << n - b << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}