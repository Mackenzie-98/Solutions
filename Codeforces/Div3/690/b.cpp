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
void debug_out() {cerr << endl;}
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {cerr << " " << to_string(H), debug_out(T...);}

int main() {
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
#define debug(...) 3
    fastIO;
#endif
    int t;
    cin>>t;
    while(t--){
        int n;
        string s;
        cin>>n>>s;
        bool ok1=s.substr(0,1)=="2"&&s.substr(n-3,3)=="020";
        bool ok2=s.substr(0,2)=="20"&&s.substr(n-2,2)=="20";
        bool ok3=s.substr(0,3)=="202"&&s.substr(n-1,1)=="0";
        bool ok4=s.substr(0,4)=="2020";
        bool ok5=s.substr(n-4,4)=="2020";
        if(ok1||ok2||ok3||ok4||ok5)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
