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

int main() {
#ifdef LOCAL
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
    fastIO;
#endif
    int n;
    string s;
    cin >> n >> s;
    string p = "ABC";
    int ans = 0;
    for (int i = 0; i < n - 2; i++) {
        //cout << s.substr(i, 3) << endl;
        if (s.substr(i, 3) == p) ans++;
    }
    cout << ans << endl;
    return 0;
}