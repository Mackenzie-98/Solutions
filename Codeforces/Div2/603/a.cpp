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
        int arr[3];
        cin >> arr[0] >> arr[1] >> arr[2];
        sort(arr, arr + 3);
        int ans = 0;
        ans += min(arr[0], arr[2] - arr[1]);
        arr[0] -= min(arr[0], arr[2] - arr[1]);
        arr[2] -= min(arr[0], arr[2] - arr[1]);
        int d = arr[0] / 2;
        arr[1] -= d;
        arr[2] -= d;
        ans += 2 * d;
        ans += min(arr[1], arr[2]);

        // int ans = 0;
        // do {
        //     int cur = 0;
        //     int d = min(arr[0] / 2, min(arr[1], arr[2]));
        //     if (arr[0] % 2) {
        //         arr[2] -= d + 1;
        //         arr[1] -= d;
        //         cur += d + 1;
        //     } else {
        //         arr[1] -= d;
        //         arr[2] -= d;
        //         cur += d;
        //     }
        //     cur += min(arr[1], arr[2]);
        //     ans = max(ans, cur);
        // } while (next_permutation(arr, arr + 3));
        cout << ans << endl;
    }

    return 0;
}