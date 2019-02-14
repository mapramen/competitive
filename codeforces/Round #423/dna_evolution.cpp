#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define B 4
#define M 11
#define N 100001

int n, T[B][M][M][N];
char s[N], t[M];

int GetMappedInt(char c){
  int ans;
  if(c == 'A')
    ans = 0;
  else if(c == 'C')
    ans = 1;
  else if(c == 'G')
    ans = 2;
  else
    ans = 3;
  return ans;
}

void BITUpdate(int T[], int i, int x){
  for( ; i <= n; i += (i & -i))
    T[i] += x;
}

int BITQuery(int T[], int i){
  int ans = 0;
  for( ; i > 0; i -= (i & -i))
    ans += T[i];
  return ans;
}

void UpdateX(int i, int c, int val){
  int x = GetMappedInt(c);
  for(int d = 1; d < M; d++)
    BITUpdate(T[x][d][i % d], i, val);
}

void Update(int i, char c){
  UpdateX(i, s[i - 1], -1);
  UpdateX(i, c, 1);
  s[i - 1] = c;
}

int Query(int i, int mod){
  int d = strlen(t), ans = 0;
  for(int j = 0; j < d; j++, mod++){
    int x = GetMappedInt(t[j]);
    mod %= d;
    ans += BITQuery(T[x][d][mod], i);
  }
  return ans;
}

void PreProcess(){
  for(int i = 1; i <= n; i++)
    UpdateX(i, s[i - 1], 1);
}

int main(){
  int q;

  scanf("%s", s);
  n = strlen(s);
  PreProcess();

  scanf("%d", &q);
  while(q--){
    int k;
    scanf("%d", &k);
    if(k == 1){
      int i;
      scanf("%d%s", &i, t);
      Update(i, t[0]);
    }
    else{
      int l, r;
      scanf("%d%d%s", &l, &r, t);
      int ans = Query(r, l) - Query(l - 1, l);
      printf("%d\n", ans);
    }
  }

  return 0;
}
