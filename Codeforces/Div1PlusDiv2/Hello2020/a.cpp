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
    int n, m;
    cin >> n >> m;
    string s[n], t[m];
    forn(i, n) {
        cin >> s[i];
    }
    forn(i, m) {
        cin >> t[i];
    }
    int q;
    cin >> q;
    forn(i, q) {
        int x;
        cin >> x;
        cout << s[(x - 1) % n] << t[(x - 1) % m] << endl;
    }
    return 0;
}