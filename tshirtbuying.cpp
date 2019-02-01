#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200001

int p[N], a[N], b[N];
bool sold[N];
priority_queue<  pii , vector< pii >, greater< pii > > Q[4];

int main(){
  int n, m;

  scanf("%d", &n);

  for(int i = 1; i <= n; i++)
    scanf("%d", &p[i]);

  for(int i = 1; i <= n; i++)
    scanf("%d", &a[i]);

  for(int i = 1; i <= n; i++)
    scanf("%d", &b[i]);

  for(int i = 1; i <= n; i++){
    Q[a[i]].push(MP(p[i], i));
    Q[b[i]].push(MP(p[i], i));
  }

  scanf("%d", &m);
  while(m--){
    int c;
    scanf("%d", &c);

    while(!Q[c].empty() && sold[Q[c].top().second] == 1)
      Q[c].pop();

    if(Q[c].empty())
      printf("-1 ");
    else{
      int p, i;
      tie(p, i) = Q[c].top();
      Q[c].pop();
      printf("%d ", p);
      sold[i] = 1;
    }
  }
  printf("\n");

  return 0;
}
