#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 256

char s[N];

int main(){
	int n, m, i, j, k, l, a = 0, b = 0, x;

	scanf("%d", &n);
	scanf("%s", s);

	for(i = x = l = 0; i < n; i++){
		if(s[i] == '_' || s[i] == '(' || s[i] == ')'){
			if(l != 0){
				if(x == 1)
					b++;
				else
					a = max(a, l);

				// cout << i << ' ' << l << ' ' << x << ' ' << a << ' ' << b << '\n';

				l = 0;
			}

			if(s[i] == '(')
					x++;
				else if(s[i] == ')')
					x--;
		}
		else
			l++;
	}

	a = max(a, l);

	cout << a << ' ' << b << '\n';

	return 0;
}
