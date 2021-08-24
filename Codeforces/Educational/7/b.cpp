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
string addmin(int h,int m,int addm){
    int rh=h,rm=m;
    if(m+addm>=60){
        rh+=(m+addm)/60;
        rh=rh%24;
        rm=(m+addm)%60;
    }else{
        rm+=addm;
    }
return (sz(to_string(rh))==1?"0":"")+to_string(rh)+":"+(sz(to_string(rm))==1?"0":"")+to_string(rm);
}
int main() {
#ifdef LOCAL
  // freopen("h.txt", "r", stdin);
  // freopen("main.out", "w", stdout);
#else
  ios::sync_with_stdio(0), cin.tie(0);
#define endl '\n'
#endif
    string s;
    cin>>s;
    int m;
    cin>>m;
    cout<<addmin(stoi(s.substr(0,2)),stoi(s.substr(3,2)),m)<<endl;
  return 0;
}