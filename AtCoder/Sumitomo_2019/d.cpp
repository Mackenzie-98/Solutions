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
int n;
string s;
bool isSubsequence(string &t, int i, int j) {
    if (j == 3) return true;
    if (i == n) return false;
    if (s[i] == t[j]) {
        return isSubsequence(t, i + 1, j + 1);
    } else {
        return isSubsequence(t, i + 1, j);
    }
}
int main() {
#ifdef LOCAL
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
    fastIO;
#endif
    cin >> n >> s;
    ll ans = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < 10; k++) {
                string t = "";
                t += i + '0';
                t += j + '0';
                t += k + '0';
                //cout << t << endl;
                if (isSubsequence(t, 0, 0)) ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}