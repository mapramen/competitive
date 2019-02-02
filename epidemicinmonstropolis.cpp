#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define piii pair< pii, int >
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

void Process(vector<int>& a, int base){
	while(a.size() != 1){
		piii ans = MP(MP(0,0), 0);

		for(int i = 0; i < a.size() - 1; i++){
			if(a[i] != a[i + 1]){
				ans = max(ans, MP(MP(a[i], i), 1));
				ans = max(ans, MP(MP(a[i + 1], i + 1), 0));
			}
		}

		cout << base + ans.first.second << ' ' << "LR"[ans.second] << '\n';

		int i = ans.first.second;

		if(ans.second == 1)
			a[i + 1] += a[i];
		else
			a[i - 1] += a[i];

		queue<int> q;

		for(int j = 0; j < a.size(); j++){
			if(i != j)
				q.push(a[j]);
		}

		a.clear();

		while(!q.empty()){
			int j = q.front();
			q.pop();
			a.PB(j);
		}
	}
}

int main(){
	int n, i, j, k;
	vector<int> a, b;

	scanf("%d", &n);

	while(n--){
		scanf("%d", &i);
		a.PB(i);
	}

	scanf("%d", &n);

	while(n--){
		scanf("%d", &i);
		b.PB(i);
	}

	for(j = 0, i = 0; j < b.size(); j++){
		map<int, int> m;
		int s = 0;

		for( ; i < a.size() && s != b[j]; i++){
			s += a[i];
			m[a[i]]++;
		}

		if(s != b[j] || (m.size() == 1 && m.begin()->second != 1)){
			printf("NO\n");
			return 0;
		}
	}

	if(i < a.size()){
		printf("NO\n");
		return 0;
	}

	printf("YES\n");

	for(j = 0, i = 0; j < b.size(); j++){
		int s = 0;
		vector<int> c;

		for( ; i < a.size() && s != b[j]; i++){
			s += a[i];
			c.PB(a[i]);
		}

		Process(c, j + 1);
	}

	return 0;
}
