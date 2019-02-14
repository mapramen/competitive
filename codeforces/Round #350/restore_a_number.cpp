#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 1000100
#define B 11

int a[N], c[N], b[B];
char s[N], t[N];

void fill(string& d, int n, int m){
	for(int i = n; i <= m; i++){
		for(int j = 0; j < b[i]; j++)
			d.PB('0' + i);
	}
}

int main(){
	int n,m,i,j,k,x,y,z,d;
	string s1, s2, s3, ans;

	scanf("%s", s);
	scanf("%s", t);
	
	n = strlen(s);

	if(n == 2){
		m = atoi(s);
		
		if(m == 1 || m == 10){
			printf("0\n");
			return 0;
		}
	}

	i = j = 1;
	k = 0;

	while(1){
		for(; i < j && (i + k) != n; i++);

		if(i != j){
			m = i;
			break;
		}

		j *= 10;
		k++;
	}

	for(i = 0; s[i] != '\0'; i++)
		b[s[i] - '0']++;

	for(i = 0; t[i] != '\0'; i++)
		b[t[i] - '0']--;

	n = m;

	for(; m > 0; m /= 10)
		b[(m%10)]--;

	if(t[0] == '0'){
		for(i = 0; i < n; i++)
			s1.PB('9');
	}
	else{
		for(i = 0; t[i] != '\0'; i++)
			s1.PB(t[i]);

		fill(s1,0,9);
	}

	k = t[0] - '0';

	for(i = 1; i < 10 && b[i] == 0; i++);

	m = i;

	if(k == 0 || (k != 0 && m <= k)){
		s2.PB('0' + m);
		s3.PB('0' + m);
		b[m]--;

		fill(s2,0,k-1);
		fill(s3,0,k);

		for(i = 0; t[i] != '\0'; i++){
			s2.PB(t[i]);
			s3.PB(t[i]);
		}

		fill(s2,k,9);
		fill(s3,k+1,9);

		b[m]++;
	}
	else{
		for(i = 0; i < n; i++){
			s2.PB('9');
			s3.PB('9');
		}
	}

	// cout << s1 << ' ' << s2 << ' ' << s3 << '\n';

	if(s1 < s2)
		if(s1 < s3)
			ans = s1;
		else
			ans = s3;
	else
		if(s2 < s3)
			ans = s2;
		else
			ans = s3;

	cout << ans << '\n';

	return 0;
}