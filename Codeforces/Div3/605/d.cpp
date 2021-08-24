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
    int arr[n];
    forn(i, n) cin >> arr[i];
    int l[n], r[n];
    memset(l, 0, sizeof l);
    memset(r, 0, sizeof r);
    l[0] = 1, r[n - 1] = 1;
    int cnt = 1;
    int best = 0;
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] < arr[i + 1]) {
            cnt++;
        } else {
            cnt = 1;
        }
        best = max(best, cnt);
    }
    best = max(best, cnt);
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[i - 1])
            l[i] = l[i - 1] + 1;
        else
            l[i] = 1;
    }
    for (int i = n - 2; i >= 0; i--) {
        if (arr[i + 1] > arr[i])
            r[i] = r[i + 1] + 1;
        else
            r[i] = 1;
    }
    for (int i = 1; i < n - 1; i++) {
        if (arr[i - 1] < arr[i + 1]) best = max(best, l[i - 1] + r[i + 1]);
    }
    cout << best << endl;
    return 0;
}