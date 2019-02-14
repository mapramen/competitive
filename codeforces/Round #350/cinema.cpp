#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define M 200000

int b[M], c[M];

int main(){
	int n,m,i,j,k,x,y,z;

	scanf("%d", &n);

	map<int,int> s;
	map<int,int>::iterator it;

	while(n--){
		scanf("%d", &i);

		it = s.find(i);

		if(it != s.end())
			it->second++;
		else
			s.insert(MP(i,1));
	}

	scanf("%d", &m);

	for(i = 0; i < m; i++){
		scanf("%d", &b[i]);

		it = s.find(b[i]);

		if(it == s.end())
			s.insert(MP(b[i],0));
	}


	for(i = 0; i < m; i++){
		scanf("%d", &c[i]);

		it = s.find(c[i]);

		if(it == s.end())
			s.insert(MP(c[i],0));
	}

	x = -1;

	for(i = 0; i < m; i++){
		it = s.find(b[i]);

		if(it->second > x){
			x = it->second;
			y = s.find(c[i])->second;
			z = i;
		}

		if(it->second == x){
			it = s.find(c[i]);
			if(it->second > y){
				y = it->second;
				z = i;
			}
		}
	}

	printf("%d\n", z + 1);

	return 0;
}
