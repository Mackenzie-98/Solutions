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
    int t, casos = 0;
    cin >> t;
    while (t--) {
        casos++;
        int n, d;
        cin >> n >> d;
        map<ll, int> mp;
        vector<ll> v(n);
        forn(i, n) cin >> v[i], mp[v[i]]++;
        cout << "Case #" << casos << ": ";
        if (d == 2) {
            if (mp.size() < n)
                cout << 0 << endl;
            else
                cout << 1 << endl;
        } else {
            if (n - mp.size() + 1 >= 3)
                cout << 0 << endl;
            else if (n - mp.size() + 1 == 2) {
                bool ok = 0;
                forn(i, n) {
                    forn(j, n) {
                        if (i != j && v[i] != v[j] && v[i] % v[j] == 0) {
                            ok = 1;
                        }
                    }
                }
                if (n == 2) {
                    if (ok)
                        cout << 1 << endl;
                    else
                        cout << 2 << endl;
                } else {
                    cout << 1 << endl;
                }
            } else {
                bool ok = 0;
                forn(i, n) {
                    forn(j, n) {
                        if (i != j && v[i] % v[j] == 0) {
                            ok = 1;
                        }
                    }
                }
                if (n == 1)
                    cout << 2 << endl;
                else {
                    if (ok)
                        cout << 1 << endl;
                    else
                        cout << 2 << endl;
                }
            }
        }
    }
    return 0;
}