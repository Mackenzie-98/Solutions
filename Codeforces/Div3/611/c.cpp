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
    int n;
    cin >> n;
    int mark[n + 1];
    memset(mark, 0, sizeof mark);
    pii arr[n + 1];
    forn(i, n) {
        int v;
        cin >> v;
        arr[i] = {v, i + 1};
        mark[arr[i].F] = 1;
    }
    vector<int> zeros;
    forn(i, n + 1) {
        if (!mark[i + 1] || arr[min(i, n - 1)].F == 0) {
            zeros.pb(i);
        }
    }
    int cnt = sz(zeros) - 1;
    // forn(i, sz(zeros)) cout << zeros[i] << " ";
    // cout << endl;
    forn(i, n) {
        //cout << arr[i].F << " " << mark[i + 1] << endl;
        if (!mark[i + 1] || arr[i].F == 0) {
            if (arr[i].F == 0)
                cout << zeros[cnt] << " ", cnt--;
            else {
                arr[zeros[cnt]].F = i + 1;
                cout << arr[i].F << " ";
            }
        } else {
            cout << arr[i].F << " ";
        }
    }
    cout << endl;

    return 0;
}