#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " = " << x << endl;
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
        int mp[n + 1];
        int arr[n];
        forn(i, n) {
            int v;
            cin >> v;
            arr[i] = v;
            mp[v] = i;
        }
        int swaps = 0;
        int low = 1;
        bool mark[n + 1];
        memset(mark, 0, sizeof mark);
        while (swaps <= n - 1 && low <= n) {
            for (int j = mp[low]; j >= low; j--) {
                if (!mark[j - 1] && arr[j] < arr[j - 1]) {
                    swaps++;
                    mark[j - 1] = 1;
                    swap(arr[j], arr[j - 1]);
                } else {
                    break;
                }
            }
            low++;
        }
        forn(i, n) cout << arr[i] << " ";
        cout << endl;
    }
    return 0;
}