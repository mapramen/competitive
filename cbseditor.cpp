#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 500001

int n, m, p, match[N];
char s[N], op[N];
set<int> lft;
set<int>::iterator it;

void build_match_lft(){
	stack<int> a;

	for(int i = 0; i < n; i++){
		if(s[i] == '(')
			a.push(i);
		else{
			match[i] = a.top();
			match[a.top()] = i;
			a.pop();
		}

		lft.insert(i);
	}
}

int main(){
	int i,j,k,l,r;
	scanf("%d%d%d", &n, &m, &p);

	scanf("%s", s);
	scanf("%s", op);

	build_match_lft();

	p--;

	for(k = 0; k < m; k++){
		if(op[k] == 'L'){
			it = lft.find(p);
			it--;
			p = *it;
			continue;
		}

		if(op[k] == 'R'){
			it = lft.find(p);
			it++;
			p = *it;
			continue;
		}

		i = p;
		j = match[i];
		l = min(i,j);
		r = max(i,j);

		set<int> del;

		for(it = lft.find(l); it != lft.end() && *it <= r; it++)
			del.insert(*it);

		for(it = del.begin(); it != del.end(); it++)
			lft.erase(*it);

		it = lft.upper_bound(p);

		if(it == lft.end())
			it--;

		p = *it;
	}

	for(it = lft.begin(); it != lft.end(); it++)
		putchar(s[*it]);

	putchar('\n');

	return 0;
}
