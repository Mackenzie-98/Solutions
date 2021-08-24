#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;
typedef long long ld;


const int MX = 1e6;
bool marked[MX+1];
int primes=0;


/// O(MX log(log(MX)))
void sieve(int n) {
    marked[0] = marked[1] = true;
    for (int i = 2; i <= n; i++) {
        if (marked[i]) continue;
        primes++;
        for (ll j = 1ll*i; j <= n; j += i) marked[j] = true;
    }
}


int main() {
    // violinista forever xd
    ios::sync_with_stdio(0),cin.tie(0);
    int n,t,s1,s2,p1,p2,c1,c2;
    int v,m,cp,cc;
    cin>>n>>t;
    cin>>s2>>p2>>c2;
    v=t/n;
    m=t%n;

    s1=s2-m;
    if(s1<1)s1=n+s1;
    sieve(n);
    cp=primes*v;
    cc=(n-primes)*v;
    if(s1>s2) {
        int aux=0;
        for(int i=2; i<s2; i++) {
            if(!marked[i])aux++;
        }
        cp+=primes-aux;
    } else if(s1<s2) {
        int aux=0;
        for(int i=2; i<s1; i++) {
            if(!marked[i])aux++;
        }
        cp+=primes-aux;
    }
    v=cp/n;
    m=cp%n;
    p1=p2-m;

//cout<<cp<<" v"<<endl;
//cout<<cc<<" v"<<endl;
    if(s1>s2) {
        int aux=0;
        for(int i=1; i<s1; i++) {
            if(marked[i])aux++;
        }
        //cout<<aux<<" v "<<s2<<endl;
        cc+=(n-primes)-aux;

    } else if(s1<s2) {
        int aux=0;
        for(int i=1; i<s2; i++) {
            if(marked[i])aux++;
        }
        cc+=(n-primes)-aux;
    }
//cout<<cc<<" v"<<endl;
    m=cc%n;
    c1=c2+m;
    c1=c1%n;
    if(c1==0)c1=n;



    cout<<s1<<" "<<p1<<" "<<c1<<endl;
    return 0;
}
