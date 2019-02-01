#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 1001

int v[N][2 * N], p[N][2 * N], n, k, base;

void FillWin(int i){
  for(int j = base - k + 2; j <= base + k; j++)
    if(v[i - 1][j - 1])
      v[i][j] = 1, p[i][j] = -1;
}

void FillLose(int i){
  for(int j = base - k; j <= base + k - 2; j++)
    if(v[i - 1][j + 1])
      v[i][j] = 1, p[i][j] = 1;
}

void FillDraw(int i){
  for(int j = base - k + 1; j <= base + k - 1; j++)
    if(v[i - 1][j])
      v[i][j] = 1, p[i][j] = 0;
}

void Print(int i, int j){
  if(i == 0)
    return ;
  Print(i - 1, j + p[i][j]);
  if(p[i][j] == -1)
    putchar('W');
  else if(p[i][j] == 1)
    putchar('L');
  else
    putchar('D');
}

int main(){
  string s;

  cin >> n >> k >> s;
  base = k;

  v[0][base] = 1;

  for(int i = 1; i <= n; i++){
    char c = s[i - 1];
    if(c == 'W' || c == '?')
      FillWin(i);
    if(c == 'L' || c == '?')
      FillLose(i);
    if(c == 'D' || c == '?')
      FillDraw(i);
  }

  if(v[n][base - k] == 0 && v[n][base + k] == 0)
    printf("NO");
  else{
    if(v[n][base + k] == 1)
      Print(n, base + k);
    else
      Print(n, base - k);
  }
  printf("\n");

  return 0;
}
