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
	int i, j;

	scanf("%s", s);

	for(i = j = 0; s[i] != '\0'; i++){
		if(j == 0)
			if(s[i] != 'a'){
				s[i]--;
				j = 1;
			}
			else
				if(s[i + 1] == '\0')
					s[i] = 'z';
				else;
		else
			if(s[i] != 'a')
				s[i]--;
			else
				break;
	}

	printf("%s\n", s);

	return 0;
}
