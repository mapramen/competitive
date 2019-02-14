#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001

int f[N + 1], c[N + 1];

int main(){
  int n, m, free_time = 0, jobs_completed = 0, ans = -1;

  scanf("%d", &n);
  for(int x = 1; x <= n; x++){
    int i;
    scanf("%d", &i);
    f[i]++;
  }

  scanf("%d", &m);
  for(int x = 1; x <= m; x++){
    int l, r;
    scanf("%d%d", &l, &r);
    c[l]++;
    c[r + 1]--;
  }

  for(int i = 1, j = 1; jobs_completed < n && j < N; j++){
    c[j] += c[j - 1];
    free_time++;

    if(c[j] == 0)
      continue;

    while(i < N){
      if(f[i] == 0){
        i++;
      }
      else{
        if(i <= free_time){
          free_time -= i;
          f[i]--;
          jobs_completed++;
        }
        else
          break;
      }
    }

    if(jobs_completed == n)
      ans = j;
  }

  printf("%d\n", ans);

  return 0;
}
