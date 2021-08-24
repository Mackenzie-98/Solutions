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
void debug_out() {
    cerr << endl;
}
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H), debug_out(T...);
}
bool check(string s) {
}

int main() {
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
#define debug(...) 3
    fastIO;
#endif
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<string> v(n);
        forn(i, n)cin >> v[i];
        string ans = "";
        bool ok = false;
        for(int i = 0; i < n ; i++) {
            string ans = v[i];
            for(int j = 0; j < m ; j++) {
                for(int k = 0; k < 26 ; k++) {
                    string cur = ans;
                    cur[j] = (char)('a' + k);
                    bool ok = true;
                    forn(w, n) {
                        int dif = 0;
                        if(w != i) {
                            //cout << ans << " " << cur << " " << v[w] << endl;
                            forn(p, m)if(cur[p] != v[w][p])dif++;
                            if(dif > 1) {
                                ok = false;
                                break;
                            }
                        }
                    }
                    if(ok) {
                        cout << cur<< endl;
                        goto done;
                    }
                }
            }
        }
        cout << -1 << endl;
done:
        ;
    }
    return 0;
}
