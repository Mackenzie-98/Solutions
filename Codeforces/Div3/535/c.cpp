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
    int n;
    string s;
    cin >> n >> s;
    map<char, int> mp;
    mp['R'] = 0;
    mp['G'] = 1;
    mp['B'] = 2;
    int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0;
    int ini = 0;
    forn(i, sz(s)) {
        if (mp[s[i]] != ini) {
            a++;
        }
        ini = (ini + 1) % 3;
    }
    ini = 1;
    forn(i, sz(s)) {
        if (mp[s[i]] != ini) {
            b++;
        }
        ini = (ini + 1) % 3;
    }
    ini = 2;
    forn(i, sz(s)) {
        if (mp[s[i]] != ini) {
            c++;
        }
        ini = (ini + 1) % 3;
    }
    string pat = "RBG";
    ini = 0;
    forn(i, n) {
        if (s[i] != pat[ini]) {
            d++;
        }
        ini = (ini + 1) % 3;
    }
    pat = "BGR";
    ini = 0;
    forn(i, n) {
        if (s[i] != pat[ini]) {
            e++;
        }
        ini = (ini + 1) % 3;
    }
    pat = "GRB";
    ini = 0;
    forn(i, n) {
        if (s[i] != pat[ini]) {
            f++;
        }
        ini = (ini + 1) % 3;
    }

    if (a <= b && a <= c && a <= d && a <= e && a <= f) {
        pat = "RGB";
        cout << a << endl;
        ini = 0;
        forn(i, n) {
            cout << pat[ini];
            ini = (ini + 1) % 3;
        }
    } else if (b <= a && b <= c && b <= d && b <= e && b <= f) {
        cout << b << endl;
        pat = "RGB";
        ini = 1;
        forn(i, n) {
            cout << pat[ini];
            ini = (ini + 1) % 3;
        }
    } else if (c <= a && c <= b && c <= d && c <= e && c <= f) {
        cout << c << endl;
        pat = "RGB";
        ini = 2;
        forn(i, n) {
            cout << pat[ini];
            ini = (ini + 1) % 3;
        }
    } else if (d <= a && d <= b && d <= c && d <= e && d <= f) {
        cout << d << endl;
        pat = "RBG";
        ini = 0;
        forn(i, n) {
            cout << pat[ini];
            ini = (ini + 1) % 3;
        }
    } else if (e <= a && e <= b && e <= c && e <= d && e <= f) {
        cout << e << endl;
        pat = "BGR";
        ini = 0;
        forn(i, n) {
            cout << pat[ini];
            ini = (ini + 1) % 3;
        }
    } else {
        cout << f << endl;
        pat = "GRB";
        ini = 0;
        forn(i, n) {
            cout << pat[ini];
            ini = (ini + 1) % 3;
        }
    }
    cout << endl;
    return 0;
}