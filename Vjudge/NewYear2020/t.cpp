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
map<char, int> priority;
struct Player {
    int number;
    string name;
    char role;
    int exp;
    Player() {
    }
    Player(int _number, string _name, char _role, int _exp) {
        number = _number;
        name = _name;
        role = _role;
        exp = _exp;
    }
    string toString() {
        string s = to_string(number) + " " + name + " " + role;
        return s;
    }
};
vector<string> split1(string &s) {
    vector<string> v;
    istringstream iss(s);
    string sub;
    while (iss >> sub) {
        v.push_back(sub);
    }
    return v;
}
bool cmp(Player a, Player b) {
    return a.number < b.number;
}
int main() {
#ifdef LOCAL
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
    fastIO;
#endif
    string number;
    while (cin >> number && number != "0") {
        map<char, int> freq;
        int g = 1, d = 0, m = 0, s = 0;
        int sum = 0;
        vector<Player> players;
        string name;
        char role;
        vector<string> years;
        vector<Player> gk, defenders, mid, strickers;
        forn(i, 22) {
            int num = 0;
            if (i != 0) {
                cin >> num;
            } else {
                num = stoi(number);
            }
            cin >> name >> role;
            string line;
            getline(cin, line);
            years = split1(line);
            int xp = 0;
            for (auto x : years) {
                xp += stoi(x.substr(5, 4)) - stoi(x.substr(0, 4)) + 1;
            }
            Player p(num, name, role, xp);
            if (role == 'G') {
                gk.pb(p);
            }
            if (role == 'D') {
                defenders.pb(p);
            }
            if (role == 'M') {
                mid.pb(p);
            }
            if (role == 'S') {
                strickers.pb(p);
            }
        }
        char aux;
        cin >> d >> aux >> m >> aux >> s;
        if (sz(defenders) < d || sz(mid) < m || sz(strickers) < s || sz(gk) < 1) {
            cout << "IMPOSSIBLE TO ARRANGE" << endl;
            cout << endl;
        } else {
            sort(all(gk), cmp);
            sort(all(defenders), cmp);
            sort(all(mid), cmp);
            sort(all(strickers), cmp);
            vector<Player> ans;
            ans.pb(gk[0]);
            forn(i, d) {
                ans.pb(defenders[i]);
            }
            forn(i, m) {
                ans.pb(mid[i]);
            }
            forn(i, s) {
                ans.pb(strickers[i]);
            }
            int mx = 0;
            Player capitan;
            for (int i = 0; i < 11; i++) {
                if (ans[i].exp > mx) {
                    mx = ans[i].exp;
                    capitan = ans[i];
                } else if (ans[i].exp == mx) {
                    if (ans[i].number > capitan.number) capitan = ans[i];
                }
            }
            //cout << sz(ans) << " " << d << endl;
            cout << capitan.toString() << endl;
            forn(i, 11) {
                if (ans[i].number != capitan.number) cout << ans[i].toString() << endl;
            }
            cout << endl;
        }
    }
    return 0;
}