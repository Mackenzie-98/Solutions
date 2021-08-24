#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " = " << x << endl;
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
typedef pair<ll, ll> pll;
const int MAX = 2e5 + 5;
struct dsu {
    vector<int> par, sz;
    int size;
    dsu(int n) {
        size = n;
        par = sz = vector<int>(n);
        for (int i = 0; i < n; i++) {
            par[i] = i;
            sz[i] = 1;
        }
    }
    // Busca el nodo representativo del conjunto de u
    int find(int u) { return par[u] == u ? u : (par[u] = find(par[u])); }
    // Une los conjuntos de u y v
    void unite(int u, int v) {
        if ((u = find(u)) == (v = find(v))) return;
        if (sz[u] > sz[v]) swap(u, v);
        par[u] = v;
        sz[v] += sz[u];
        size--;
    }
    // Retorna la cantidad de elementos del conjunto de u
    int count(int u) { return sz[find(u)]; }
};
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
        dsu ds(n);
        int arr[n];
        forn(i, n) {
            cin >> arr[i], arr[i]--;
            ds.unite(i, arr[i]);
        }
        forn(i, n) cout << ds.count(i) << " ";
        cout << endl;
    }
    return 0;
}