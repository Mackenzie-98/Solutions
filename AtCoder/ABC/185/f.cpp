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
    cerr << " " << to_string(H);
    debug_out(T...);
}


int n, q;

struct SegmentTree {
    int size;
    vector<ll> xors;

    void init(int n) {
        size = 1;
        while(size < n)size *= 2;
        xors.assign(2 * size, 0);
    }

    void update(int i, int v, int x, int lx, int rx) {
        if(rx - lx == 1) {
            xors[x] = v;
            return;
        }
        int l = 2 * x + 1;
        int r = 2 * x + 2;
        int m = (lx + rx) / 2;
        if(i < m) {
            update(i, v, l, lx, m);
        } else {
            update(i, v, r, m, rx);
        }
        xors[x] = (xors[l] ^ xors[r]);
    }
    //Actualiza v en la posición i.
    void update(int i, int v) {
        update(i, v, 0, 0, size);
    }

    ll sum(int l, int r, int x, int lx, int rx) {
        //debug(l, r, x, lx, rx);
        if(lx >= r || rx <= l)return 0;
        else if(lx >= l && rx <= r) {
            return xors[x];
        } else {
            int m = (lx + rx) / 2;
            int left = 2 * x + 1;
            int rigth = 2 * x + 2;
            return (sum(l, r, left, lx, m) ^ sum(l, r, rigth, m, rx));
        }
    }
    ll sum(int l, int r) {
        return sum(l, r, 0, 0, size);
    }
};

int main() {
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#else
#define debug(...) 3
    fastIO;
#endif
    cin >> n >> q;
    SegmentTree st;
    st.init(n);
    vector<ll> a(n);
    forn(i, n) {
        int v;
        cin >> v;
        a[i]=v;
        st.update(i, v);
    }
    while(q--) {
        int op;
        cin >> op;
        if(op == 1) {
            int i, v;
            cin >> i >> v;
            st.update(i-1, (a[i-1]^v));
            a[i-1]=(a[i-1]^v);
        } else {
            int l, r;
            cin >> l >> r;
            l--;
            cout << st.sum(l, r) << endl;
        }
    }
    return 0;
}
