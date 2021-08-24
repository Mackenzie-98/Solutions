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
const int MAX = 8005;
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
        int n;
        cin >> n;
        vector<int> v(n);
        forn(i, n) cin >> v[i];
        memset(arr, 0, sizeof arr);
        vector<int> pre(n);
        pre[0] = v[0];
        for (int i = 1; i < n; i++) {
            pre[i] = v[i] + pre[i - 1];
        }
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                int sum = pre[j] - (i == 0 ? 0 : pre[i - 1]);
                if (sum <= 8000)
                    arr[sum] = 1;
            }
        }
        int ans = 0;
        forn(i, n) ans += arr[v[i]] > 0;
        cout << ans << endl;
    }
    return 0;
}