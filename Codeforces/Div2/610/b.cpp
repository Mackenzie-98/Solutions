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
ll n, p, k;
const int MAX = 2e5 + 10;
ll pre[MAX];
ll arr[MAX];
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
        cin >> n >> p >> k;
        forn(i, n) cin >> arr[i];
        sort(arr, arr + n);
        pre[0] = arr[0];
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (i == 0)
                pre[i] = arr[i];
            else if (i < k - 1) {
                pre[i] = arr[i] + pre[i - 1];
            } else {
                pre[i] = arr[i] + pre[i - k];
            }
            if (pre[i] <= p) {
                ans = i + 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}