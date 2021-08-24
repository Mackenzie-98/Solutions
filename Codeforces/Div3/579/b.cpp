#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define F first
#define S second
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define pb push_back
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
int main() {
#ifdef LOCAL
    // freopen("h.txt", "r", stdin);
    // freopen("main.out", "w", stdout);
#else
    ios::sync_with_stdio(0), cin.tie(0);
#define endl '\n'
#endif
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[4 * n];
        forn(i, 4 * n) cin >> arr[i];
        sort(arr, arr + 4 * n);
        if (n == 1 && arr[0] == arr[1] && arr[2] == arr[3]) {
            cout << "YES" << endl;
        } else {
            bool ok = 1;
            int area = arr[0] * arr[4 * n - 1];
            for (int i = 0; i < 2 * n; i += 2) {
                // cout << arr[i] << " " << arr[4 * n - i - 1] << " ";
                if (arr[i] * arr[4 * n - i - 1] != area ||
                    (arr[i] != arr[i + 1]) ||
                    (arr[4 * n - i - 1] != arr[4 * n - i - 2])) {
                    ok = 0;
                    break;
                }
            }
            if (ok && n != 1)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
    return 0;
}