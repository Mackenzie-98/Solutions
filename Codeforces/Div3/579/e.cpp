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
bool mark[1000000];
int main() {
#ifdef LOCAL
    // freopen("h.txt", "r", stdin);
    // freopen("main.out", "w", stdout);
#else
    ios::sync_with_stdio(0), cin.tie(0);
#define endl '\n'
#endif
    int n;
    cin >> n;
    int arr[n];
    forn(i, n) cin >> arr[i];
    sort(arr, arr + n);
    int cnt = 0;
    forn(i, n) {
        if (arr[i] == 1 && !mark[1]) {
            // cout << "1" << endl;
            mark[1] = 1;
            cnt++;
            continue;
        }
        if (arr[i] != 1 && !mark[arr[i] - 1]) {
            // cout << "2" << endl;
            mark[arr[i] - 1] = 1;
            cnt++;
            continue;
        }
        if (!mark[arr[i]]) {
            // cout << "3" << endl;
            cnt++;
            mark[arr[i]] = 1;
            continue;
        }
        if (mark[arr[i]] && !mark[arr[i] + 1]) {
            // cout << "4" << endl;
            mark[arr[i] + 1] = 1;
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}