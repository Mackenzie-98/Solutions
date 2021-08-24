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
// int ft[MAXN + 1];
// void upd(int i0, int v) {
//     for (int i = i0 + 1; i <= MAXN; i += i & -i) ft[i] += v;
// }
// int get(int i0) {
//     int r = 0;
//     for (int i = i0; i; i -= i & -i) r += ft[i];
//     return r;
// }
// int get_sum(int i0, int i1) {
//     return get(i1) - get(i0);
// }
const int MAX = 1e5 + 5;
int pre[MAX];
int arr[MAX];
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
        int n, s;
        cin >> n >> s;
        memset(pre, 0, sizeof pre);
        memset(arr, 0, sizeof arr);
        forn(i, n) {
            int v;
            cin >> v;
            if (i == 0) {
                pre[i] = v;
            } else {
                pre[i] = v + pre[i - 1];
            }
            arr[i] = v;
            //upd(i, v);
        }

        if (pre[n - 1] <= s)
            cout << 0 << endl;
        else {
            int ans = 0;
            int mx = 0;
            forn(i, n) {
                int ind = upper_bound(pre, pre + n, s + arr[i]) - pre;
                if (ind > i && mx < (ind - 1)) {
                    mx = ind - 1;
                    ans = i + 1;
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}