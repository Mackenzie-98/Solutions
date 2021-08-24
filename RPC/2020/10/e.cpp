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
typedef double lf ;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
void debug_out() {
    cerr << endl;
}
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H), debug_out(T...);
}

const lf eps = 1e-9;
typedef double T;
struct pt {
    T x, y;
    pt(double a=0,double b=0) {
        x=a,y=b;
    }
    pt operator + (pt p) {
        return {x+p.x, y+p.y};
    }
    pt operator - (pt p) {
        return {x-p.x, y-p.y};
    }
    pt operator * (pt p) {
        return {x*p.x-y*p.y, x*p.y+y*p.x};
    }
    pt operator * (T d) {
        return {x*d, y*d};
    }
    pt operator / (lf d) {
        return {x/d, y/d};
    }
    bool operator == (pt b) {
        return x == b.x && y == b.y;
    }
    bool operator != (pt b) {
        return !(*this == b);
    }
    bool operator < (const pt &o) const {
        return y < o.y || (y == o.y && x < o.x);
    }
    bool operator > (const pt &o) const {
        return y > o.y || (y == o.y && x > o.x);
    }
};
T dot(pt a, pt b) {
    return a.x*b.x + a.y*b.y;
}
T cross(pt a, pt b) {
    return a.x*b.y - a.y*b.x;
}
T orient(pt a, pt b, pt c) {
    return cross(b-a,c-a);
}

bool in_disk(pt a, pt b, pt p) {
    return dot(a-p, b-p) <= 0;
}

bool on_segment(pt a, pt b, pt p) {
    return orient(a,b,p) == 0 && in_disk(a,b,p);
}
bool proper_inter(pt a, pt b, pt c, pt d, pt &out) {
    T oa = orient(c,d,a),
      ob = orient(c,d,b),
      oc = orient(a,b,c),
      od = orient(a,b,d);
    if (oa*ob < 0 && oc*od < 0) {
        out = (a*ob - b*oa) / (ob-oa);
        return true;
    }
    return false;
}
set<pt> inter_ss(pt a, pt b, pt c, pt d) {
    pt out;
    if (proper_inter(a,b,c,d,out)) return {out};
    set<pt> s;
    if (on_segment(c,d,a)) s.insert(a);
    if (on_segment(c,d,b)) s.insert(b);
    if (on_segment(a,b,c)) s.insert(c);
    if (on_segment(a,b,d)) s.insert(d);
    return s;
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

    int x1,y1,x2,y2, xx1,yy1,xx2,yy2;
    cin>>x1>>y1>>x2>>y2>>xx1>>yy1>>xx2>>yy2;
    pt a(x1,y1),b(x2,y2),c(xx1,yy1),d(xx2,yy2);
    set<pt> ans=inter_ss(a,b,c,d);
    if(sz(ans)==0)cout<<0<<endl;
    else {
        pt p=*ans.begin();
        if(b.y<d.y) {
            long double m=(yy2-yy1)/(1.0*(xx2-xx1));
            long double xx=(m*xx1+b.y-yy1)/m;
            pt v(b.x,b.y),w(xx,b.y);
            debug(v.x,v.y);
            debug(w.x,w.y);
            cout<<fixed<<setprecision(5)<<(v.x*w.y-v.y*w.x)*0.5<<endl;
        } else {
            long double m=(y2-y1)/(1.0*(x2-x1));
            long double xx=(m*x1+d.y-y1)/m;
            pt v(p.x+d.x,d.y),w(xx,d.y);
            debug(v.x,v.y);
            debug(w.x,w.y);
            cout<<fixed<<setprecision(5)<<(v.x*w.y-v.y*w.x)*0.5<<endl;
        }
    }
    return 0;
}
