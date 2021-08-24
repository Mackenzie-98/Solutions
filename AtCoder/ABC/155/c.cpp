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
bool cmp(pair<string, int> a, pair<string, int> b) {
    if (a.S != b.S) return a.S > b.S;
    return a.F < b.F;
}
int main() {
#ifdef LOCAL
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
    fastIO;
#endif
    int n;
    cin >> n;
    set<string> st;
    map<string, int> mp;
    vector<pair<string, int>> arr;
    int mx = 0;
    forn(i, n) {
        string s;
        cin >> s;
        mp[s]++;
        mx = max(mx, mp[s]);
    }
    for (auto x : mp) {
        if (x.S == mx) {
            cout << x.F << endl;
        }
    }
    return 0;
}