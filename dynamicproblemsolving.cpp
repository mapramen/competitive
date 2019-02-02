#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 120
#define B 5
#define C 6

int a[N][B], s[B], c[B], inf = INT_MAX;

int GetCategory(int x, int n){
  int ans;
  if(32 * x <= n)
    ans = 0;
  else if(16 * x <= n)
    ans = 1;
  else if(8 * x <= n)
    ans = 2;
  else if(4 * x <= n)
    ans = 3;
  else if(2 * x <= n)
    ans = 4;
  else
    ans = 5;
  return ans;
}

int GetMaxScore(int category){
  return 500 * (6 - category);
}

int GetScore(int i){
  int ans = 0;
  for(int j = 0; j < B; j++){
    if(a[i][j] != -1)
      ans += (GetMaxScore(c[j]) / 250) * (250 - a[i][j]);
  }
  return ans;
}

int main(){
  int n, ans = inf;

  cin >> n;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < B; j++){
      cin >> a[i][j];
      if(a[i][j] != -1)
        s[j]++;
    }
  }

  for(int x = 0; x <= 31 * n && ans == inf; x++){
    for(int i = 0; i < B; i++){
      if(a[0][i] == -1 || a[1][i] == -1 || a[0][i] < a[1][i])
        c[i] = GetCategory(s[i], n + x);
      else
        c[i] = GetCategory(s[i] + x, n + x);
    }

    int scoreV = GetScore(0), scoreP = GetScore(1);

    if(scoreV > scoreP)
      ans = x;
  }

  if(ans == inf)
    ans = -1;

  cout << ans << '\n';

  return 0;
}
