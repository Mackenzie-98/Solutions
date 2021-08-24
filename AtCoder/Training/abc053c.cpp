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
    ll x;
    cin >> x;
    ll y = ((x + 10) / 11);
    int ok = 0;
    if ((6 * y + 5 * (y - 1)) >= x || (6 * (y - 1) + 5 * y >= x)) ok = 1;
    cout << 2 * y - ok << endl;

    return 0;
}