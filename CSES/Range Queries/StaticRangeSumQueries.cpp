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

const int MAX = 2e5 + 10;
int arr[MAX];

int main() {
#ifdef DLOCAL
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
    freopen( "in.txt", "r", stdin );
    // freopen("out.txt", "w", stdout);
#else
#define debug(x...) 03
    fastIO;
#endif
    int n, q;
    cin >> n >> q;
    forn( i, n )cin>>arr[i];
    vector<ll> prefix_sum( n, 0 );
    prefix_sum[0] = arr[0];

    for( int i = 1; i < n; i++ ) {
        prefix_sum[i] = arr[i] + prefix_sum[i - 1];
    }

    while( q-- ) {
        int a, b;
        cin >> a >> b;
        a--,b--;
        cout << prefix_sum[b] - ( a == 0 ? 0 : prefix_sum[a - 1] )<<endl;
    }

    return 0;
}
