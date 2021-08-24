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
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int n,k, OS=0;
int b[5];
string v[5];
ll ans=0;
vector<pair<char,pii>> possibles[5];
bool mat[5][5];
vector<int> op;
pair<char,pii> x;

void f(int y) {
    if(y==k) {
        memset(mat,0,sizeof mat);
        int os=0;
        for(int p=0; p<sz(op); p++) {
            x=possibles[p][op[p]];
            if(x.ft=='H') {
                forn(i,b[p]) {
                    if(mat[x.sd.ft][x.sd.sd+i])return;
                    mat[x.sd.ft][x.sd.sd+i]=1;
                    if(v[x.sd.ft][x.sd.sd+i]=='O')os++;
                }

            } else {
                forn(i,b[p]) {
                    if(mat[x.sd.ft+i][x.sd.sd])return;
                    mat[x.sd.ft+i][x.sd.sd]=1;
                    if(v[x.sd.ft+i][x.sd.sd]=='O')os++;
                }
            }
        }
        if(os==OS)ans++;
        return;
    }
    for(int i=0;i<sz(possibles[y]);i++) {
        op.pb(i);
        f(y+1);
        op.pop_back();
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
    fastIO;
#endif
    cin>>n>>k;
    forn(i,n)cin>>v[i];
    forn(i,k)cin>>b[i];
    forn(i,n){
        forn(j,n){
            if(v[i][j]=='O')OS++;
        }
    }
    forn(i,k) {
        forn(x,n) {
            forn(y,n) {
                bool ok=true;
                if(y+b[i]>n)ok=false;
                for(int p=y; p < min(y+b[i],n)&&ok; p++) {
                    if(v[x][p]=='X') {
                        ok=false;
                        break;
                    }
                }
                if(ok)possibles[i].pb({'H',{x,y}});
                if(b[i]!=1) {
                    ok=true;
                    if(x+b[i]>n)ok=false;
                    for(int p=x; p<min(x+b[i],n)&&ok; p++) {
                        if(v[p][y]=='X') {
                            ok=false;
                            break;
                        }
                    }
                    if(ok)possibles[i].pb({'V',{x, y}});
                }
            }
        }
    }
    f(0);
    cout<<ans<<endl;
    return 0;
}
