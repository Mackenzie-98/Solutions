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
        if ((n / 2) % 2 != 0)
            cout << "NO" << endl;
        else {
            cout << "YES" << endl;
            int x = 2;
            ll sum = 0;
            forn(i, n / 2) {
                cout << (i + 1) * x << " ";
                sum += (i + 1) * x;
            }
            ll odd = 0;
            forn(i, n / 2 - 1) {
                cout << x * i + 1 << " ";
                odd += x * i + 1;
            }
            cout << sum - odd << endl;
        }
    }
    return 0;
}