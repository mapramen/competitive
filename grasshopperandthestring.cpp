#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 101

char s[N];

int main(){
	int n, ans = 0;
	vector<int> v;

	scanf("%s", s);
	n = strlen(s);

	v.PB(0);

	for(int i = 0; s[i] != '\0'; i++)
		if(s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' || s[i] == 'Y')
			v.PB(i + 1);

	v.PB(n + 1);

	for(int i = 0; i < v.size() - 1; i++)
		ans = max(ans, v[i + 1] - v[i]);

	printf("%d\n", ans);

	return 0;
}
