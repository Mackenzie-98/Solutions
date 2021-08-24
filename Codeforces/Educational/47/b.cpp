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
    string s;
    cin >> s;
    int n = sz(s);
    map<char, int> mp;
    forn(i, sz(s)) {
        mp[s[i]]++;
    }
    int ind = 0;
    bool ok = 0;
    forn(i, sz(s)) {
        if (s[i] == '2') {
            ind = i;
            ok = 1;
            break;
        }
        if (s[i] == '0') cout << s[i];
    }
    forn(i, mp['1']) cout << 1;
    if (ok) {
        for (int i = ind; i < sz(s); i++) {
            if (s[i] != '1') cout << s[i];
        }
    }
    cout << endl;
    return 0;
}