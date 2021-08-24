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
    int n, szs, szt;
    string s, t;
    cin >> n >> s >> t;
    szs = szt = n;

    map<char, int> mps, mpt;
    map<char, vector<int>> poss, post;
    forn(i, szs) {
        mps[s[i]]++;
        mpt[t[i]]++;
        poss[s[i]].pb(i + 1);
        post[t[i]].pb(i + 1);
    }
    vector<pii> ans;
    for (int i = 'a'; i <= 'z'; i++) {
        while (mps[i] && mpt[i]) {
            szs--, szt--;
            mps[i]--;
            mpt[i]--;
            int x, y;
            x = poss[i][sz(poss[i]) - 1];
            y = post[i][sz(post[i]) - 1];
            poss[i].pop_back();
            post[i].pop_back();
            ans.pb({x, y});
        }
    }
    if (mpt['?'] && szs) {
        for (int i = 'a'; i <= 'z'; i++) {
            while (mps[i] && mpt['?']) {
                szs--, szt--;
                mps[i]--;
                mpt['?']--;
                int x, y;
                x = poss[i][sz(poss[i]) - 1];
                y = post['?'][sz(post['?']) - 1];
                poss[i].pop_back();
                post['?'].pop_back();
                ans.pb({x, y});
            }
        }
    }
    if (mps['?'] && szt) {
        for (int i = 'a'; i <= 'z'; i++) {
            while (mpt[i] && mps['?']) {
                szs--, szt--;
                mpt[i]--;
                mps['?']--;
                int x, y;
                x = poss['?'][sz(poss['?']) - 1];
                y = post[i][sz(post[i]) - 1];
                poss['?'].pop_back();
                post[i].pop_back();
                ans.pb({x, y});
            }
        }
    }
    while (mps['?'] && mpt['?']) {
        szs--, szt--;
        mps['?']--, mpt['?']--;
        int x = poss['?'][sz(poss['?']) - 1];
        int y = post['?'][sz(post['?']) - 1];
        poss['?'].pop_back();
        post['?'].pop_back();
        ans.pb({x, y});
    }
    cout << sz(ans) << endl;
    for (auto x : ans) cout << x.F << " " << x.S << endl;
    return 0;
}