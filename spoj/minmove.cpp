#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 200001

int f[N];

// Booth's algorithm
int MinimalRotationIndex(string s){
	s += s;
	int n = s.size(), k = 0;

	for(int i = 0; i < n; ++i){
		f[i] = -1;
	}

	for(int j = 1; j < n; ++j){
		char sj = s[j];
		int i = f[j - k - 1];

		while(i != -1 && s[k + i + 1] != sj){
			if(sj < s[k + i + 1]){
				k = j - i - 1;
			}
			i = f[i];
		}

		if(sj != s[k + i + 1]){
			if(sj < s[k]){
				k = j;
			}
			f[j - k] = -1;
		}
		else{
			f[j - k] = i + 1;
		}
	}

	return k;
}

int main(){
  string s;
  cin >> s;

  printf("%d\n", MinimalRotationIndex(s));

  return 0;
}