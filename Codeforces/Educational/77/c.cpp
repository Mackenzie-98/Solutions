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
        ll r, b, k;
        cin >> r >> b >> k;
        if (r > b) swap(r, b);
        ll g = __gcd(r, b);
        r = r / g;
        b = b / g;
        if (b > r * (k - 1) + 1)
            cout << "REBEL" << endl;
        else
            cout << "OBEY" << endl;
    }
    return 0;
}