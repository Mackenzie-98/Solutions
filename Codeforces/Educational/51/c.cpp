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

int main() {
#ifdef LOCAL
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
    fastIO;
#endif
    int n;
    cin >> n;
    map<int, int> freq;
    vector<int> s(n);
    forn(i, n) cin >> s[i], freq[s[i]]++;
    int nice = 0;
    bool ok = 0;
    int value = 0;
    for (auto x : freq) {
        if (x.S >= 3 && !ok) ok = 1, value = x.F;
        if (x.S == 1) nice++;
    }
    if ((nice & 1) && !ok)
        cout << "NO" << endl;
    else {
        int cur = 0;
        cout << "YES" << endl;
        string ab = "AB";
        map<int, char> ans;
        for (auto x : freq) {
            if (x.S == 1) {
                ans[x.F] = ab[cur];
                cur ^= 1;
                continue;
            }
            ans[x.F] = 'A';
        }
        forn(i, n) {
            if ((nice & 1) && ok && s[i] == value) {
                cout << 'B';
                ok = 0;
            } else {
                cout << ans[s[i]];
            }
        }
        cout << endl;
    }
    return 0;
}