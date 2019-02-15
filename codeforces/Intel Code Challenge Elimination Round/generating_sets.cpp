#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

int main(){
	int n, a;
	priority_queue<int> q;
	set<int> s;

	scanf("%d", &n);

	while(n--){
		scanf("%d", &a);
		q.push(a);
		s.insert(a);
	}
	
	while(a){
		for(a = q.top(); a > 0; a /= 2){
			if(s.find(a) == s.end()){
				s.erase(q.top());
				q.pop();

				s.insert(a);
				q.push(a);
				break;
			}
		}
	}

	for(auto it = s.begin(); it != s.end(); it++)
		printf("%d ", (*it));
	printf("\n");

	return 0;
}
