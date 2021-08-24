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
typedef double lf;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll INF = 1e18;

const int MAX = 305;
ll g[MAX][MAX];
ll g2[MAX][MAX];
int N, M, L;

void floydWarshall() {
    for (int k = 0; k < N; k++)
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
}
void floydWarshall2() {
    for (int k = 0; k < N; k++)
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                g2[i][j] = min(g2[i][j], g2[i][k] + g2[k][j]);
}

void init(){
    forn(i,N+1){
        forn(j,N+1){
            g[i][j]=(i==j?0:INF);
            g2[i][j]=0;
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
    cin>>N>>M>>L;
    init();
    forn(i,M){
        int x,y,c;
        cin>>x>>y>>c;
        x--,y--;
        g[x][y]=c,g[y][x]=c;
    }
    floydWarshall();
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(g[i][j]<=L)g2[i][j]=1;
            else g2[i][j]=INF;
        }
    }
    floydWarshall2();
    int q;
    cin>>q;
    while(q--){
        int x,y;
        cin>>x>>y;
        x--,y--;
        if(g2[x][y]==INF)cout<<-1<<endl;
        else cout<<g2[x][y]-1<<endl;
    }
    return 0;
}
