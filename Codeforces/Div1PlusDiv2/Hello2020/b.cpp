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
// bool cmp(pair<bool, pair<int, int>> a, pair<bool, pair<int, int>> b) {
//     if (a.S.F != b.S.F) return a.S.F < b.S.F;
// }
int main() {
#ifdef LOCAL
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
    fastIO;
#endif
    int n;
    cin >> n;
    vector<pair<bool, pair<int, int>>> v;
    vector<int> vmx;
    forn(i, n) {
        int l;
        cin >> l;
        int arr[l];
        int mx = 0, mn = 1e9;
        forn(j, l) {
            cin >> arr[j];
            mx = max(mx, arr[j]);
            mn = min(mn, arr[j]);
        }
        int pre[l];
        pre[l - 1] = arr[l - 1];
        for (int j = l - 2; j >= 0; j--) {
            pre[j] = max(arr[j], pre[j + 1]);
        }
        bool ok = 0;
        forn(j, l) {
            if (pre[j] > arr[j]) {
                ok = 1;
                break;
            }
        }
        v.pb({ok, {mn, mx}});
        if (!ok) vmx.pb(mx);
    }
    // for (auto x : v) {
    //     cout << x.F << " " << x.S.F << " " << x.S.S << endl;
    // }
    sort(all(vmx));
    ll ans = 0;
    forn(i, n) {
        //cout << v[i].F << " " << v[i].S.F << " " << v[i].S.S << endl;
        if (v[i].F) {
            ans += n;
        } else {
            int ind = upper_bound(all(vmx), v[i].S.F) - vmx.begin();
            ans += n - ind;
        }
        //cout << n - ind << endl;
    }
    cout << ans << endl;
    return 0;
}