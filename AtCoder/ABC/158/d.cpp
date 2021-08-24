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
void debug_out() {
    cerr << endl;
}
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H), debug_out(T...);
}

int main() {
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
#define debug(...) 3
    fastIO;
#endif
    string s;
    cin>>s;
    int q;
    cin>>q;
    int cur=0;
    while(q--) {
        int op;
        cin>>op;
        if(op==1)cur++;
        else {
            int f;
            char c;
            cin>>f>>c;
            if(f==1) {
                if(cur%2==0) {
                    s=c+s;
                } else {
                    s+=c;
                }
            } else {
                if(cur%2==0) {
                    s+=c;
                } else {
                    s=c+s;
                }
            }
        }
    }
    if(cur&1) {
        reverse(all(s));
        cout<<s<<endl;
    }else cout<<s<<endl;
    return 0;
}
