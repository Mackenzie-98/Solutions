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
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
bool isPal(string s){
    for(int i=0;i<(sz(s)+1)/2;i++){
        //cout<<s[i]<<" "<<s[sz(s)-i-1]<<endl;
        if(s[i]!=s[sz(s)-i-1])return false;
    }
    return true;
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
    fastIO;
#endif
    string s;
    cin>>s;
    int mx=0;
    for(int i=0;i<sz(s)-1;i++){
        for(int j=i+1;j<sz(s);j++){
            //cout<<s.substr(i,j-i+1)<<isPal(s.substr(i,j-i+1))<<endl;
            if(!isPal(s.substr(i,j-i+1))){
                    mx=max(mx,j-i+1);
            }
        }
    }
    cout<<mx<<endl;
    return 0;
}
