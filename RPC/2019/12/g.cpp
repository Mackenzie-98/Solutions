#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define F first
#define S second
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define pb push_back
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
int main() {
#ifdef LOCAL
    // freopen("h.txt", "r", stdin);
    // freopen("main.out", "w", stdout);
#else
    ios::sync_with_stdio(0), cin.tie(0);
#define endl '\n'
#endif
    int n;
    string s;
    cin >> n >> s;
    int best = 0;
    int cnt[20];
    memset(cnt, 0, sizeof cnt);
    for (int i = 0; i < n; i++) {
        int sum = 0;
        cnt[s[i] - 'a']++;
        int impar = 0;
        for (int j = 0; j < 20; j++) {
            if (cnt[j] % 2) {
                sum += cnt[j];
                impar++;
            } else {
                sum += cnt[j];
            }
        }
        if (impar <= 1) best = max(best, sum);
    }
    memset(cnt, 0, sizeof cnt);
    for (int i = n - 1; i >= 0; i--) {
        int sum = 0;
        cnt[s[i] - 'a']++;
        int impar = 0;
        for (int j = 0; j < 20; j++) {
            if (cnt[j] % 2) {
                sum += cnt[j];
                impar++;
            } else {
                sum += cnt[j];
            }
        }
        if (impar <= 1) best = max(best, sum);
    }
    cout << best << endl;
    return 0;
}