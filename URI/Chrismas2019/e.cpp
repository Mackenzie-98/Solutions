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
const int MAX = 1e4 + 10;
const ll INF = 1e18;
int m;
ll mem[MAX][3];
ll rec[MAX][3];
ll go(int i, int c, int d) {
    if (c < 0 || c > 2) return INF;
    if (i > m) return 0;
    if (rec[i][c] == 1 && d) return INF;
    ll &ans = mem[i][c];
    if (ans != -1) return ans;
    ans = INF;
    ans = go(i + 1, c, 1);
    ans = min(ans, go(i, c + 1, 0) + 1);
    ans = min(ans, go(i, c - 1, 0) + 1);
    ans = min(ans, go(i, c + 2, 0) + 2);
    ans = min(ans, go(i, c - 2, 0) + 2);
    return ans;
}
int main() {
#ifdef LOCAL
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
    fastIO;
#endif
    while (cin >> m && m != 0) {
        forn(i, MAX) {
            forn(j, 3) {
                mem[i][j] = -1;
                rec[i][j] = 0;
            }
        }
        forn(i, m) {
            forn(j, 3) {
                cin >> rec[i + 1][j];
            }
        }
        cout << go(0, 1, 0) << endl;
    }
    return 0;
}