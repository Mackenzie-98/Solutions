#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;
typedef long long ld;


int main() {
	// violinista forever xd
	ios::sync_with_stdio(0),cin.tie(0);
	int t,q,tipo,tmp;
	cin>>t;
	while(t--){
	multiset<int> orden;
	multiset <int, greater <int> > orden2;
    stack<int> pila;

		cin>>q;

		while(q--){
			cin>>tipo;
			switch(tipo){
				case 1: cin>>tmp;
				pila.push(tmp);
				orden.insert(tmp);
				orden2.insert(tmp);
				break;

				case 2: if(pila.empty()==false){
				tmp=pila.top();
				pila.pop();
				orden.erase(orden.find(tmp));
				orden2.erase(orden2.find(tmp));
				}
				break;
				case 3: if(pila.empty())cout<<"Empty!"<<endl;
				else{
					multiset<int>::iterator a,b;
					a=orden.begin();
					b=orden2.begin();
					next(b,1);
					next(a,1);
					//for(auto f:orden)cout<<" - "<<f;

					//cout<<*a<<" ab "<<*b<<endl;
					tmp=*b-*a;
					cout<<tmp<<endl;
				}
			}

		}
	}
	return 0;
}
