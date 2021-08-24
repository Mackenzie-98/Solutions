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
    map<char, char> mp;
    mp['@'] = 'a';
    mp['&'] = 'e';
    mp['!'] = 'i';
    mp['*'] = 'o';
    mp['#'] = 'u';
    string s;
    while (getline(cin, s)) {
        forn(i, sz(s)) {
            if (mp[s[i]]) {
                cout << mp[s[i]];
            } else {
                cout << s[i];
            }
        }
        cout << endl;
    }
    return 0;
}