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
    while (n--) {
        ll c, s;
        cin >> c >> s;
        if (c >= s)
            cout << s << endl;
        else {
            ll x = (s - c) / c;
            ll cost = 0;
            ll res = (s - c) % c;
            cost += (x + 1) * (x + 1) * (c - res);
            if ((s - c) % c) cost += res * (x + 2) * (x + 2);
            cout << cost << endl;
        }
    }
    return 0;
}