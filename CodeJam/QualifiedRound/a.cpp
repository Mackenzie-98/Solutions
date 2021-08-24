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
    int casos = 0;
    while (t--) {
        casos++;
        int n;
        cin >> n;
        int mat[n][n];
        forn(i, n) {
            forn(j, n) {
                cin >> mat[i][j];
            }
        }
        int k = 0, r = 0, c = 0;
        forn(i, n) {
            k += mat[i][i];
        }
        set<int> s1, s2;

        forn(i, n) {
            forn(j, n) {
                s1.insert(mat[i][j]);
                s2.insert(mat[j][i]);
            }
            if (sz(s1) != n) r++;
            if (sz(s2) != n) c++;
            s1.clear();
            s2.clear();
        }

        cout << "Case #" << casos << ": " << k << " " << r << " " << c << endl;
    }
    return 0;
}