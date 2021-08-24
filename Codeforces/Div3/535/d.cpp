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
    int n;
    string s;
    cin >> n >> s;
    string aux = s;
    int cur = 1;
    int ans = 0;
    vector<int> blocks;
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i - 1]) {
            cur++;
        } else {
            blocks.pb(cur);
            //ans += cur / 2;
            cur = 1;
        }
    }
    blocks.pb(cur);
    //ans += cur / 2;
    char op[3] = {'R', 'G', 'B'};
    int pos = 0;
    int last = 0;
    forn(i, sz(blocks)) {
        if (blocks[i] & 1) {
            pos++;
        }
        //cout << pos << " " << blocks[i] << endl;
        for (; pos - last < blocks[i]; pos += 2) {
            //cout << s[pos] << " ";
            if ((pos - 1 >= 0 && s[pos - 1] == s[pos]) || (pos + 1 < n && s[pos] == s[pos + 1])) {
                ans++;
                forn(j, 3) {
                    if (op[j] != s[pos - 1] && op[j] != s[pos + 1]) {
                        s[pos] = op[j];
                        break;
                    }
                }
            }
        }
        last += blocks[i];
    }
    cout << ans << endl;
    cout << s << endl;
    return 0;
}