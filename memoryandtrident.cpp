#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001

char s[N];

int main(){
	int i, a, b, ans;

	scanf("%s", s);

	for(i = a = b = 0; s[i] != '\0'; i++)
		if(s[i] == 'U')
			a++;
		else
			if(s[i] == 'R')
				b++;
			else
				if(s[i] == 'D')
					a--;
				else
					b--;

	a = abs(a);
	b = abs(b);

	if(a % 2 != b % 2)
		ans = -1;
	else
		ans = (a + b) / 2;

	printf("%d\n", ans);

	return 0;
}
