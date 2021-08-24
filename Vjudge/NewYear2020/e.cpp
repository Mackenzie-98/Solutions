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
#define INF (1 << 27)
const int MAX = 105;
int old[MAX][MAX];
int newp[MAX][MAX];
int N, M;
void floydWarshall1() {
    for (int k = 0; k < N; k++)
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                old[i][j] = min(old[i][j], old[i][k] + old[k][j]);
}
void floydWarshall2() {
    for (int k = 0; k < N; k++)
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                newp[i][j] = min(newp[i][j], newp[i][k] + newp[k][j]);
}
vector<string> split(string &s) {
    vector<string> v;
    istringstream iss(s);
    string sub;
    while (iss >> sub) {
        v.push_back(sub);
    }
    return v;
}
void init() {
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            old[i][j] = (i == j ? 0 : INF);
            newp[i][j] = (i == j ? 0 : INF);
        }
    }
}
int main() {
#ifdef LOCAL
// freopen("in.txt", "r", stdin);
// freopen("out.txt", "w", stdout);
#else
    fastIO;
#endif
    string aux = "";
    while (cin >> N && N != 0) {
        getline(cin, aux);
        init();
        forn(i, N) {
            string line;
            getline(cin, line);
            //cout << line << endl;
            vector<string> nodos = split(line);
            for (int j = 1; j < sz(nodos); j++) {
                //cout << stoi(nodos[j]) - 1 << " ";
                old[i][stoi(nodos[j]) - 1] = 1;
            }
            //cout << endl;
        }

        forn(i, N) {
            string line;
            getline(cin, line);
            vector<string> nodos = split(line);
            for (int j = 1; j < sz(nodos); j++) {
                newp[i][stoi(nodos[j]) - 1] = 1;
            }
        }
        int a, b;
        cin >> a >> b;
        floydWarshall1();
        floydWarshall2();
        bool ok = 1;
        forn(i, N) {
            forn(j, N) {
                //cout << i + 1 << " " << j + 1 << " = [" << old[i][j] << ", " << newp[i][j] << "]" << endl;
                if (newp[i][j] > a * old[i][j] + b) {
                    ok = 0;
                    break;
                }
            }
        }
        if (ok)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}