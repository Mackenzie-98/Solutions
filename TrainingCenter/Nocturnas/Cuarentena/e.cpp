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
    int n;
    cin >> n;
    vector<int> v(n);
    forn(i, n) cin >> v[i], v[i] = v[i] % 2;
    while (true) {
        bool ok = 0;
        int ind = 0;
        while (ind < sz(v) - 1) {
            if (v[ind] == v[ind + 1]) {
                v.erase(v.begin() + ind);
                v.erase(v.begin() + ind);
                ok = 1;
            }
            ind++;
        }
        if (!ok) break;
    }
    cout << sz(v) << endl;
    return 0;
}