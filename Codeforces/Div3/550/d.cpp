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
    int a[n];
    map<int, int> mp;
    int mx = 0;
    int x = 0;
    forn(i, n) {
        cin >> a[i];
        mp[a[i]]++;
        if (mp[a[i]] > mx) {
            mx = mp[a[i]];
            x = a[i];
        }
    }
    int cnt = 0;
    int ini = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] != x) {
            cnt++;
        } else {
            ini = i;
        }
    }
    cout << cnt << endl;
    for (int i = ini - 1; i >= 0; i--) {
        if (a[i] == a[i + 1]) continue;
        if (a[i] < a[i + 1]) {
            a[i] = a[i] + abs(a[i] - a[i + 1]);
            cout << 1 << " " << i + 1 << " " << i + 2 << endl;
        } else {
            a[i] = a[i] - abs(a[i] - a[i + 1]);
            cout << 2 << " " << i + 1 << " " << i + 2 << endl;
        }
    }
    for (int i = ini + 1; i <= n - 1; i++) {
        if (a[i] == a[i - 1]) continue;
        if (a[i] < a[i - 1]) {
            a[i] = a[i] + abs(a[i] - a[i - 1]);
            cout << 1 << " " << i + 1 << " " << i << endl;
        } else {
            a[i] = a[i] - abs(a[i] - a[i - 1]);
            cout << 2 << " " << i + 1 << " " << i << endl;
        }
    }
    return 0;
}