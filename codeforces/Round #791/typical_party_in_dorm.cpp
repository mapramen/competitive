#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1001
#define B 17
#define M (1 << B)
#define MOD 998244353

char s[N];
vector<vector<int>> V(N);
int total_question_mark, c[N], p[B + 1][N], cnt[M], dp[M];

void Update(int i, int j, int& mask, int& cnt){
  if(s[i - 1] == s[j - 1]){
    cnt += (s[i - 1] == '?');
  }
  else{
    if(s[i - 1] != '?'){
      mask |= (1 << (s[i - 1] - 'a'));
    }
    else{
      mask |= (1 << (s[j - 1] - 'a'));
    }
  }

  V[total_question_mark - (c[j] - c[i - 1]) + cnt].push_back(mask);
}

int main(){
  int n;
  scanf("%d%s", &n, s);

  for(int i = 1; i <= n; ++i){
    c[i] = c[i - 1] + (s[i - 1] == '?');
  }
  total_question_mark = c[n];

  for(int k = 1; k <= n; ++k){
    int mask = 0, cnt = 0;
    for(int i = k, j = k; 1 <= i && j <= n; --i, ++j){
      if(s[i - 1] != '?' && s[j - 1] != '?' && s[i - 1] != s[j - 1]){
        break;
      }
      Update(i, j, mask, cnt);
    }
  }

  for(int k = 1; k < n; ++k){
    int mask = 0, cnt = 0;
    for(int i = k, j = k + 1; 1 <= i && j <= n; --i, ++j){
      if(s[i - 1] != '?' && s[j - 1] != '?' && s[i - 1] != s[j - 1]){
        break;
      }
      Update(i, j, mask, cnt);
    }
  }

  for(int k = 0; k <= B; ++k){
    p[k][0] = 1;
    for(int i = 1; i < N; ++i){
      p[k][i] = (1ll * k * p[k][i - 1]) % MOD;
    }
  }

  for(int i = 0; i < N; ++i){
    if(V[i].empty()){
      continue;
    }

    for(int mask: V[i]){
      ++cnt[mask];
    }

    for(int k = 0; k < B; ++k){
      for(int mask = 0; mask < M; ++mask){
        if((mask & (1 << k)) == 0){
          continue;
        }
        cnt[mask] += cnt[mask ^ (1 << k)];
      }
    }

    for(int mask = 0; mask != M; ++mask){
      dp[mask] = (dp[mask] + 1ll * cnt[mask] * p[__builtin_popcount(mask)][i]) % MOD;
      cnt[mask] = 0;
    }
  }

  int q;
  scanf("%d", &q);

  while(q--){
    scanf("%s", s);

    int mask = 0;
    for(int i = 0; s[i] != '\0'; ++i){
      mask |= (1 << (s[i] - 'a'));
    }

    printf("%d\n", dp[mask]);
  }

  return 0;
}