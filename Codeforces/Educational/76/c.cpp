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
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        map<int, int> mp1;
        map<int, int> mp2;
        int arr[n];
        forn(i, n) cin >> arr[i];
        int mn = 1e9;
        forn(i, n) {
            if (mp1[arr[i]] != 0) {
                mn = min(mn, i - mp2[arr[i]] + 1);
                mp1[arr[i]] = 1;
                mp2[arr[i]] = i;
            }
            mp1[arr[i]]++;
            mp2[arr[i]] = i;
        }
        cout << (mn == 1e9 ? -1 : mn) << endl;
    }
    return 0;
}