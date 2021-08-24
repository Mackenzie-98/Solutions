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
        int n;
        cin >> n;
        int arr[n];
        map<int, int> mp;
        forn(i, n) {
            cin >> arr[i];
            mp[arr[i]]++;
        }
        int cnt = 0;
        vector<int> ans;
        for (int i = n - 1; i >= 0; i--) {
            if (mp[arr[i]] > 1) {
                int cur = arr[i];
                int curd = cur % 10;
                while (mp[cur] >= 1) {
                    cur /= 10;
                    curd = (curd + 1) % 10;
                    cur = 10 * cur + curd;
                }
                mp[cur]++;
                mp[arr[i]]--;
                ans.pb(cur);
                cnt++;
            } else {
                ans.pb(arr[i]);
            }
        }
        string add[] = {"0", "00", "000", "0000"};
        cout << cnt << endl;
        for (int i = sz(ans) - 1; i >= 0; i--) {
            string s = to_string(ans[i]);
            if (sz(s) == 4) {
                cout << s << endl;
            } else {
                cout << add[3 - sz(s)] + s << endl;
            }
        }
    }
    return 0;
}