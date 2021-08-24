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
    //freopen("out.txt", "w", stdout);
#else
#define debug(...) 3
    fastIO;
#endif
    vector<int> v= {1,2,3,4,5};

    do {
        for(auto x:v)cout<<x<<" ";
        //cout<<endl;
        vector<int> cur;
        forn(i,4)cur.pb(v[i]);
        cur.pb(v[4]);
        forn(i,4)cur.pb(i+2);
        int cnt=0;
        //for(auto x:cur)cout<<x<<" ";
        //cout<<endl;
        forn(i,sz(cur)) {
            for(int j=i+1; j<sz(cur); j++) {
                if(cur[i]>cur[j])cnt++;
            }
        }
        cout<<"---->"<<cnt<<endl;
    } while(next_permutation(all(v)));
    return 0;
}
