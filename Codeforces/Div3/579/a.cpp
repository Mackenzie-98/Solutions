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
        int arr[n];
        int start = 0;
        forn(i, n) {
            cin >> arr[i];
            if (arr[i] == 1) {
                start = i;
            }
        }
        bool ok1 = 1, ok2 = 1;
        int cur = start;
        for (int i = 0; i < n; i++) {
            if (arr[cur % n] != i + 1) {
                ok1 = 0;
                break;
            }
            cur++;
        }
        cur = start;
        for (int i = 0; i < n; i++) {
            if (arr[cur] != i + 1) {
                ok2 = 0;
                break;
            }
            cur--;
            if (cur < 0) cur += n;
        }
        if (ok1 || ok2)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}