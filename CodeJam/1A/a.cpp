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

vector<string> split(string &s, char c) {
    vector<string> v;
    istringstream iss(s);
    string sub;
    while (iss >> sub) {
        while (getline(iss, sub, c)) {
            v.push_back(sub);
        }
        return v;
    }
}

int main() {
#ifdef LOCAL
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
    fastIO;
#endif
    int t;
    cin >> t;
    int casos = 0;
    while (t--) {
        casos++;
        int n;
        cin >> n;
        string best = "";
        vector<string> v(n);
        string l = "", r = "";
        forn(i, n) {
            cin >> v[i];
            int pos1 = v[i].find("*");
            int pos2 = v[i].find_last_of("*");
            string curl = v[i].substr(0, pos1);
            string curr = v[i].substr(pos2 + 1, sz(v[i]));
            if (sz(curl) > sz(l)) {
                l = curl;
            }
            if (sz(curr) > sz(r)) {
                r = curr;
            }
        }
        string mid = "";
        bool ok = 1;
        forn(i, n) {
            int pos1 = v[i].find("*");
            int pos2 = v[i].find_last_of("*");
            string curl = v[i].substr(0, pos1);
            string curr = v[i].substr(pos2 + 1, sz(v[i]));
            int last = pos1;
            for (int j = last + 1; j < sz(v[i]); j++) {
                if (v[i][j] == '*') {
                    // cout << v[i].substr(last + 1, j - last - 1) << endl;
                    mid += v[i].substr(last + 1, j - last - 1);
                    last = j;
                }
            }
            //cout << curl << " " << curr << endl;
            //cout << r.substr(sz(r) - sz(curr) + 1, sz(r)) << endl;
            if (curl != l.substr(0, sz(curl)) || curr != r.substr(sz(r) - sz(curr), sz(r))) {
                ok = 0;
                break;
            }
        }
        cout << "Case #" << casos << ": ";
        if (ok)
            cout << l + mid + r << endl;
        else
            cout << "*" << endl;
    }
    return 0;
}