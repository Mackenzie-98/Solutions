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
        string s;
        cin >> s;
        bool ok1 = 0, ok2 = 0, ok3 = 0;
        ll pos = s.find("A");
        if (pos != s.npos) ok1 = 1;
        pos = s.find("AB");
        if (pos != s.npos) ok2 = 1;
        pos = s.find("BA");
        if (pos != s.npos) ok3 = 1;

        if (ok1 && !ok2 && !ok3 || (ok2 && ok3))
            cout << "SIMPLE" << endl;
        else if (ok2 && !ok3)
            cout << "FULLY-GROWN" << endl;
        else if (ok3)
            cout << "MUTAGENIC" << endl;
        else
            cout << "MUTANT" << endl;
    }
    return 0;
}