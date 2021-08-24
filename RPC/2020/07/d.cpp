#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;
typedef long long ld;


int main() {
	// your code goes here
	ios::sync_with_stdio(0),cin.tie(0);
	int n;
	ll t,s,tmp,ant,aux=0,rta=0;
	cin>>n;
	while(n--){
		cin>>t>>s;
		cin>>ant;
		rta=0;
		for(ll i=0;i<s-1;i++){
			cin>>tmp;
			if(ant<tmp){
				aux = t+ant-tmp+1;
                rta+= min(tmp-ant-1,aux);
            }
            else if(ant>tmp){
            	aux = t+tmp-ant-1;
            	rta+= min(ant-tmp+1,aux);
            }else rta++;

            ant=tmp;
		}
		cout<<rta<<endl;
	}

	return 0;
}
