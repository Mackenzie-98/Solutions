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
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int dig = 0, u = 0, l = 0;
        forn(i, sz(s)) {
            if (s[i] >= '0' && s[i] <= '9') dig++;
            if (s[i] >= 'a' && s[i] <= 'z') l++;
            if (s[i] >= 'A' && s[i] <= 'Z') u++;
        }
        if (!dig) {
            if (u > 1) {
                forn(i, sz(s)) {
                    if (s[i] >= 'A' && s[i] <= 'Z') {
                        u--;
                        s[i] = '1';
                        break;
                    }
                }
            } else {
                forn(i, sz(s)) {
                    if (s[i] >= 'a' && s[i] <= 'z') {
                        l--;
                        s[i] = '1';
                        break;
                    }
                }
            }
        }
        if (!u) {
            if (dig > 1) {
                forn(i, sz(s)) {
                    if (s[i] >= '0' && s[i] <= '9') {
                        dig--;
                        s[i] = 'A';
                        break;
                    }
                }
            } else {
                forn(i, sz(s)) {
                    if (s[i] >= 'a' && s[i] <= 'z') {
                        l--;
                        s[i] = 'A';
                        break;
                    }
                }
            }
        }
        if (!l) {
            if (dig > 1) {
                forn(i, sz(s)) {
                    if (s[i] >= '0' && s[i] <= '9') {
                        dig--;
                        s[i] = 'a';
                        break;
                    }
                }
            } else {
                forn(i, sz(s)) {
                    if (s[i] >= 'A' && s[i] <= 'Z') {
                        u--;    
                        s[i] = 'a';
                        break;
                    }
                }
            }
        }
        cout << s << endl;
    }
    return 0;
}