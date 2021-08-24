#include <bits/stdc++.h>
using namespace std;
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'
#define ft first
#define sd second
#define pb push_back
#define pob pop_back()
#define pf push_front
#define pof pop_front()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<char, char> pcc;
typedef pair<double, double> pdd;
typedef pair<long long, long long> pll;
// scanf("%d %d %d %d", &w, &b, &d, &s); %lld
// printf("%d\n", points);
// const double PI = acos(-1);
int h, w;
const int MAX = 4e6 + 5;
vector<pii> g[MAX];
int dist[MAX];

void init() {
    for(int i = 0; i < MAX; i++) {
        dist[i] = -1;
        g[i].clear();
    }
}

void bfs(int u) {
    queue<int> q;
    q.push(u);
    dist[u] = 0;
    while(q.size()) {
        int v = q.front();
        q.pop();
        for(auto x : g[v]) {
            if(dist[x.ft] == -1) {
                q.push(x.ft);
                dist[x.ft] = dist[v] + x.sd;
            } else dist[x.ft] = min(dist[x.ft], dist[v] + x.sd);
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
    fastIO;
#endif
    int cur;
    pii ini, fin;
    cin >> h >> w >> ini.ft >> ini.sd >> fin.ft >> fin.sd;
    ini.ft--, ini.sd--, fin.ft--, fin.sd--;
    vector<string> v(h);
    init();
    for(int i = 0; i < h; i++)
        cin >> v[i];
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            if(v[i][j] == '#') continue;
            cur = j + i * w;
            if(j + 1 < w && v[i][j + 1] != '#')
                g[cur].pb({cur + 1, 0}), g[cur + 1].pb({cur, 0});
            if(i + 1 < h && v[i + 1][j] != '#')
                g[cur].pb({cur + w, 0}), g[cur + w].pb({cur, 0});
            if(j - 1 >= 0 && v[i][j - 1] != '#')
                g[cur].pb({cur - 1, 0}), g[cur - 1].pb({cur, 0});
            if(i - 1 >= 0 && v[i - 1][j] != '#')
                g[cur].pb({cur - w, 0}), g[cur - w].pb({cur, 0});
            for(int k = max(i - 2, 0);  k < min(i + 3, h); k++) {
                for(int l = max(j - 2, 0);  l < min(j + 3, w); l++) {
                    int cur2 = k * w + l;
                    if(cur != cur2 && v[k][l] != '#')g[cur].pb({cur2, 1}), g[cur2].pb({cur, 1});
                }
            }
        }
    }
    bfs(ini.ft * w + ini.sd);
    cout << dist[fin.ft * w + fin.sd] << endl;
    return 0;
}
