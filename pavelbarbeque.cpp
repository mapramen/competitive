#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200001

int p[N];
bool visited[N];

int main(){
  int n, ans = 1, nloops = 0;

  scanf("%d", &n);

  for(int i = 1; i <= n; i++)
    scanf("%d", &p[i]);

  for(int i = 1; i <= n; i++){
    int j;
    scanf("%d", &j);
    ans ^= j;
  }

  for(int i = 1; i <= n; i++){
    if(visited[i])
      continue;

    for(int j = i; visited[j] == 0; j = p[j])
      visited[j] = 1;

    nloops++;
  }

  ans += (nloops > 1) ? nloops : 0;
  printf("%d\n", ans);

  return 0;
}
