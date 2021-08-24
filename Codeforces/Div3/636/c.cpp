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

int n;
const int MAX = 2e5 + 5;
ll arr[MAX];
// int dp[MAX][4];
// int f(int i, int flag) {
//     if (i >= n) return 0;
//     int &ans = dp[i][flag];
//     if (ans != -1) return ans;
//     ans = 0;
//     int x = arr[i] >= 0;
//     if (x != flag) ans = max(ans, f(i + 1, flag ^ 1) + 1);
//     ans = max(ans, f(i + 1, flag));
//     return ans;
// }
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
        cin >> n;
        forn(i, n) cin >> arr[i];
        vector<ll> pre(n + 1);
        pre[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] < 0) {
                if (pre[i + 1] < 0)
                    pre[i] = max(arr[i], pre[i + 1]);
                else
                    pre[i] = arr[i];
            } else
                pre[i] = max(arr[i], pre[i + 1]);
        }
        // forn(i, n) cout << pre[i] << " ";
        // cout << endl;
        ll cnt1 = 0, cnt2 = 0, sum1 = 0, sum2 = 0;

        int flag = 0;
        forn(i, n) {
            if (pre[i] >= 0 && !flag) {
                flag ^= 1;
                sum1 += pre[i];
                cnt1++;
            }
            if (pre[i] < 0 && flag) {
                flag ^= 1;
                sum1 += pre[i];
                cnt1++;
            }
            // cout << sum1 << endl;
        }
        flag = 1;
        forn(i, n) {
            if (pre[i] >= 0 && !flag) {
                flag ^= 1;
                sum2 += pre[i];
                cnt2++;
            }
            if (pre[i] < 0 && flag) {
                flag ^= 1;
                sum2 += pre[i];
                cnt2++;
            }
        }
        if (cnt1 == cnt2)
            cout << max(sum1, sum2) << endl;
        else if (cnt1 > cnt2)
            cout << sum1 << endl;
        else
            cout << sum2 << endl;
    }
    return 0;
}