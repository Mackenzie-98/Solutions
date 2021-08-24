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
        int arr[20];
        forn(i, 20) {
            cin >> arr[i];
        }
        int cur = arr[19] % 2;
        int acum = arr[19] / 2;
        vector<int> ans;
        ans.pb(cur);
        for (int i = 20 - 2; i > 0; i--) {
            cur = (acum + arr[i]) % 2;
            acum = (acum + arr[i]) / 2;
            ans.pb(cur);
        }
        ans.pb(acum + arr[0]);
        reverse(all(ans));
        forn(i, 20) {
            cout << ans[i] << (i == 19 ? "" : " ");
        }
        cout << endl;
    }
    return 0;
}