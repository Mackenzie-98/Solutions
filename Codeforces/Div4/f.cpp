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
        int a, b, c;
        cin >> a >> b >> c;
        string sa, sb, sc;
        sa = sb = sc = "";
        forn(i, a) sa += "0";
        if (a > 0 && b == 0) sa += "0";
        forn(i, (b + 1) / 2) sb += "01";
        if (b > 0 && b % 2 == 0) sa = "1" + sa;
        if (b == 0 && a == 0)
            forn(i, c + 1) sc += "1";
        else
            forn(i, c) sc += "1";
        cout << sa + sb + sc << endl;
    }
    return 0;
}