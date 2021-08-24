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
typedef pair<ll, ll> pll;
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
        ll arr[n];
        forn(i, n) cin >> arr[i];
        ll pre1[n], pre2[n];
        memset(pre1, 0, sizeof pre1);
        memset(pre2, 0, sizeof pre2);
        ll cur = 1;
        pre1[0] = 1;
        for (int i = 1; i < n; i++) {
            if (arr[i] >= arr[i - 1]) {
                pre1[i] = pre1[i - 1] + 1;
            } else {
                pre1[i] = 1;
            }
        }
        pre2[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] >= arr[i + 1]) {
                pre2[i] = pre2[i + 1] + 1;
            } else {
                pre2[i] = 1;
            }
        }
        ll best = 1;
        for (int i = 0; i < n; i++) {
            ll cnt = 1;
            if (i > 0 && arr[i] >= arr[i - 1]) cnt += pre1[i - 1];
            if (i < n - 1 && arr[i] >= arr[i + 1]) cnt += pre2[i + 1];
            best = max(cnt, best);
        }
        cout << best << endl;
    }
    return 0;
}