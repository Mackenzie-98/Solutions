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
    set<int> v;
    map<int, int> mp;
    bool ok2 = 0, ok1 = 0;
    vector<int> v2;
    forn(i, n) {
        int x;
        cin >> x;
        v.insert(x);
        mp[x]++;
        if (mp[x] >= 3) {
            ok2 = 1;
        }
        if (mp[x] == 2) {
            v2.pb(x);
            ok1 = 1;
        }
    }
    sort(all(v2));
    if (ok2)
        cout << "NO" << endl;
    else {
        cout << "YES" << endl;
        if (ok1) {
            cout << sz(v2) << endl;
            for (auto x : v2) cout << x << " ";
            cout << endl;
            cout << sz(v) << endl;
            for (auto it = v.rbegin(); it != v.rend(); it++) cout << *it << " ";
            cout << endl;
        } else {
            cout << 0 << endl;
            cout << endl;
            cout << sz(v) << endl;
            for (auto it = v.rbegin(); it != v.rend(); it++) cout << *it << " ";
            cout << endl;
        }
    }

    return 0;
}