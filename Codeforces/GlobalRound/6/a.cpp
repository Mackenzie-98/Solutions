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
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int sum = 0;
        int mark[10];
        memset(mark, 0, sizeof mark);
        forn(i, sz(s)) {
            sum += s[i] - '0';
            int x = s[i] - '0';
            mark[x]++;
        }
        bool ok = (mark[0] >= 2) || (mark[6] && mark[0]) || (mark[2] && mark[0]) || (mark[8] && mark[0]) || (mark[4] && mark[0]);
        if (sum % 3 == 0 && ok) {
            cout << "red" << endl;
        } else {
            cout << "cyan" << endl;
        }
    }

    return 0;
}