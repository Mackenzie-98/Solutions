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
        string s;
        cin >> n >> s;
        bool flag = 0;
        vector<int> a(n), b(n);
        forn(i, n) {
            if (s[i] == '2') {
                if (!flag) {
                    a[i] = 1;
                    b[i] = 1;
                } else {
                    a[i] = 2;
                    b[i] = 0;
                }
            }
            if (s[i] == '1') {
                if (!flag) {
                    flag = 1;
                    a[i] = 0;
                    b[i] = 1;
                } else {
                    a[i] = 1;
                    b[i] = 0;
                }
            }
            if (s[i] == '0') {
                a[i] = 0;
                b[i] = 0;
            }
        }
        forn(i, n) cout << a[i];
        cout << endl;
        forn(i, n) cout << b[i];
        cout << endl;
    }

    return 0;
}