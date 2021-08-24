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

int main() {
#ifdef LOCAL
  // freopen("h.txt", "r", stdin);
  // freopen("main.out", "w", stdout);
#else
  ios::sync_with_stdio(0), cin.tie(0);
#define endl '\n'
#endif
    int r,c;
    cin>>r>>c;
    int A[r];
    int B[c];
    forn(i,r)cin>>A[i];
    forn(i,c)cin>>B[i];
    int mat[r][c];
    int AM[r];
    int BM[c];
    memset(AM,0,sizeof AM);
    memset(BM,0,sizeof BM);
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            mat[i][j]=min(A[i],B[j]);
            AM[i]=max(AM[i],mat[i][j]);
            BM[j]=max(BM[j],mat[i][j]);
        }

    }
    bool ok=1;
    forn(i,r){
//        cout<<AM[i]<<" ";
        if(A[i]!=AM[i]){
            ok=0;
            break;
        }
    }
//    cout<<endl;
    forn(i,c){
//        cout<<AM[i]<<" ";
        if(B[i]!=BM[i]){
            ok=0;
            break;
        }
    }
//    cout<<endl;
    if(ok)cout<<"possible"<<endl;
    else cout<<"impossible"<<endl;
  return 0;
}
