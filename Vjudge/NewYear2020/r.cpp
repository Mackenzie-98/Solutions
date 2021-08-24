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
ll pre[1100][1100];
ll rect[1100][1100];
ll arr[1100][1100];
int main() {
#ifdef LOCAL
    // freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#else
    fastIO;
#endif
    int t;
    cin >> t;
    while (t--) {
        memset(arr, 0, sizeof arr);
        memset(pre, 0, sizeof pre);
        memset(rect, 0, sizeof rect);
        int d, n;
        cin >> d >> n;
        forn(i, n) {
            int x, y, p;
            cin >> x >> y >> p;
            arr[x][y] = p;
        }
        forn(i, 1025) {
            forn(j, 1025) {
                //cout << arr[i][j] << " " << (j == 0 ? 0 : pre[i][j - 1]) << endl;
                pre[i][j] = arr[i][j] + (j == 0 ? 0 : pre[i][j - 1]);
            }
        }
        // forn(i, 4) {
        //     forn(j, 4) {
        //         cout << pre[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        forn(i, 1025) {
            forn(j, 1025) {
                //cout << pre[j][i] << " " << (j == 0 ? 0 : rect[j - 1][i]) << endl;
                rect[j][i] = pre[j][i] + (j == 0 ? 0 : rect[j - 1][i]);
            }
        }
        ll mx = 0;
        int xi = 0, yi = 0;
        forn(i, 1025) {
            forn(j, 1025) {
                ll pop = rect[i + d][j + d] - (i - d - 1 < 0 ? 0 : rect[i - d - 1][j + d]) - (j - d - 1 < 0 ? 0 : rect[i + d][j - d - 1]) + ((i - d - 1 < 0) || (j - d - 1 < 0) ? 0 : rect[i - d - 1][j - d - 1]);
                //cout << pop << " " << i << " " << j << " " << rect[i + d][j + d] << " " << (i - d - 1 < 0 ? 0 : rect[i - d - 1][j + d]) << " " << (j - d - 1 < 0 ? 0 : rect[i + d][j - d - 1]) << " " << ((i - d - 1 < 0) || (j - d - 1 < 0) ? 0 : rect[i - d - 1][j - d - 1]) << endl;
                if (pop > mx && rect[i + d][j + d] != 0) {
                    mx = pop;
                    xi = i;
                    yi = j;
                }
            }
        }
        //cout << rect[i + d][j + d] << " " << (i - d - 1 < 0 ? 0 : rect[i - d - 1][1024]) << " " << (j - d - 1 < 0 ? 0 : rect[1024][j - d - 1]) << " " << ((i - d - 1 < 0) || (j - d - 1 < 0) ? 0 : rect[i - 1][j - d - 1]) << endl;
        cout << xi << " " << yi << " " << mx << endl;
    }
    return 0;
}