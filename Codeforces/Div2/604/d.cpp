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
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int it = min(a, b);
    vector<int> ans;
    a -= it;
    b -= it;
    forn(i, it) {
        ans.pb(0);
        ans.pb(1);
    }

    it = min(b, c);
    b -= it;
    c -= it;
    if (it != 0 && c >= 1) {
        ans.pb(2);
        c--;
    }
    forn(i, it) {
        ans.pb(1);
        ans.pb(2);
    }
    if (a == 1 && c == 0 && d == 0) {
        ans.pb(0);
        a--;
    }
    it = min(c, d);
    c -= it;
    d -= it;
    for (auto x : ans) cout << x << " ";
    cout << endl;
    if (d > 0 && ans[sz(ans) - 1] == '2') {
        ans.pb(3);
        d--;
    }
    for (auto x : ans) cout << x << " ";
    cout << endl;
    forn(i, it) {
        ans.pb(2);
        ans.pb(3);
    }
    for (auto x : ans) cout << x << " ";
    cout << endl;
    if (c == 1 && (ans[sz(ans) - 1] == 1 || ans[sz(ans) - 1] == 3)) {
        ans.pb(2);
        c--;
    }
    if (d == 1 && ans[sz(ans) - 1] == 2) {
        ans.pb(3);
        d--;
    }
    if (b == 1 && ans[0] == 0) {
        ans.insert(ans.begin(), 1);
        b--;
    }
    cout << a << " " << b << " " << c << " " << d << endl;
    for (auto x : ans) cout << x << " ";
    cout << endl;
    if (a == 0 && b == 0 && c == 0 && d == 0) {
        cout << "YES" << endl;
        for (auto x : ans) cout << x << " ";
        cout << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}