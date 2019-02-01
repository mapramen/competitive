#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001
#define B 26

int dp[N], temp[N], inf = INT_MAX, T[N][B];
string s, t;

//-------------------- Aho-Corasick Automation --------------------//
int tr[N][B], au[N][B], f[N], nx = 1;

void AddString(string s){
  int i = 0;
  for(auto c : s){
    int j = c - 'a';
    if(tr[i][j] == 0)
      tr[i][j] = nx++;
    i = tr[i][j];
  }
}

void ComputeFailure(){
	queue<int> q;
	q.push(0);
	while(!q.empty()){
		int v = q.front();
		q.pop();

		for(int i = 0; i < B; i++){
			int u = tr[v][i];
			if(u){
				au[v][i] = u;
				if(v)
					f[u] = au[f[v]][i];
				q.push(u);
			}
			else
				au[v][i] = au[f[v]][i];
		}
	}
}
//-------------------- Aho-Corasick Automation Ends --------------------//

int main(){
  int n, m, ans = 0;

  cin >> s >> t;

  n = s.size(), m = t.size();

  AddString(t);
  ComputeFailure();

  for(int i = 1; i < m; i++)
    dp[i] = -inf;

  for(int j = 0; j < m; j++)
    for(int a = 0; a < B; a++)
      T[j][a] = -1;

  for(int i = 0; i < n; i++){
    char cmin, cmax;

    if(s[i] == '?')
      cmin = 'a', cmax = 'z';
    else
      cmin = cmax = s[i];

    for(int j = 0; j < m; j++)
      temp[j] = -inf;

    for(int j = 0; j < m; j++){
      for(char c = cmin; c <= cmax; c++){
        int a = c - 'a';
        int k = au[j][a];
        if(k != m)
          temp[k] = max(temp[k], dp[j]);
        else{
          k = f[k];
          temp[k] = max(temp[k], dp[j] + 1);
        }
      }
    }

    for(int j = 0; j < m; j++)
      dp[j] = temp[j];
  }

  for(int i = 0; i < m; i++)
    ans = max(ans, dp[i]);

  printf("%d\n", ans);

  return 0;
}
