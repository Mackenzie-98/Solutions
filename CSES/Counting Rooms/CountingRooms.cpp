#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define ft first
#define sd second
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define pb push_back
#define fastIO ios::sync_with_stdio(0), cin.tie(0)
#define endl '\n'
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

void __print( int x ) {cerr << x;}
void __print( long long x ) {cerr << x;}
void __print( double x ) {cerr << x;}
void __print( long double x ) {cerr << x;}
void __print( char x ) {cerr << '\'' << x << '\'';}
void __print( const string &x ) {cerr << '\"' << x << '\"';}
void __print( bool x ) {cerr << ( x ? "true" : "false" );}
template<typename T, typename V>
void __print( const pair<T, V> &x ) {cerr << '{'; __print( x.first ); cerr << ','; __print( x.second ); cerr << '}';}
template<typename T>
void __print( const T &x ) {int f = 0; cerr << '{'; for( auto &i : x ) cerr << ( f++ ? "," : "" ), __print( i ); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print( T t, V... v ) {__print( t ); if( sizeof...( v ) ) cerr << ", "; _print( v... );}

int n, m;
const int MAX = 1e3 + 5;
const int MAX_NODES = 1e6 + 5;
char mat[MAX][MAX];
bool vis[MAX_NODES];
vector<int> g[MAX_NODES];

void dfs( int u ) {
    vis[u] = true;

    for( auto v : g[u] ) {
        if( !vis[v] ) dfs( v );
    }
}
void init() {
    for( int i = 0; i < n * m; i++ ) {
        g[i].clear();
        vis[i] = false;
    }
}


int main() {
#ifdef DLOCAL
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
    freopen( "in.txt", "r", stdin );
    // freopen("out.txt", "w", stdout);
#else
#define debug(x...) 03
    fastIO;
#endif
    cin >> n >> m;
    init();
    forn( i, n ) {
        forn( j, m ) {
            cin >> mat[i][j];
        }
    }
    forn( i, n ) {
        forn( j, m ) {
            if( mat[i][j] == '.' ) {
                int curNode = i * m + j;

                if( j + 1 < m && mat[i][j + 1] == '.' ) {
                    int node = i * m + j + 1;
                    g[curNode].pb( node );
                    g[node].pb( curNode );
                }

                if( i + 1 < n && mat[i + 1][j] == '.' ) {
                    int node = ( i + 1 ) * m + j;
                    g[curNode].pb( node );
                    g[node].pb( curNode );
                }
            }
        }
    }
    int components = 0;
    forn( i, n ) {
        forn( j, m ) {
            int curNode = i * m + j;
            if( !vis[curNode] && mat[i][j] == '.' ) {
                dfs( curNode );
                components++;
            }
        }
    }
    cout << components << endl;
    return 0;
}
