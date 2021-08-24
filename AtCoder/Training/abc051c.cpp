/**
 * @author: Mackenzie
**/
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

int main() {
#ifdef LOCAL
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
    fastIO;
#endif
    int sx,sy,tx,ty;
    cin>>sx>>sy>>tx>>ty;
    int h=tx-sx;
    int v=ty-sy;
    forn(i,h)cout<<"R";
    forn(i,v)cout<<"U";
    forn(i,h)cout<<"L";
    forn(i,v)cout<<"D";
    cout<<"D";
    forn(i,h+1)cout<<"R";
    forn(i,v+1)cout<<"U";
    cout<<"LU";
    forn(i,h+1)cout<<"L";
    forn(i,v+1)cout<<"D";
    cout<<"R"<<endl;
    return 0;
}