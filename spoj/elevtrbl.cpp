#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1000001

int d[N];
queue<int> Q;

void CheckAndPush(int n, int i, int di){
  if(i > 0 && i <= n && di < d[i]){
    d[i] = di;
    Q.push(i);
  }
}

int main(){
  int n, s, t, x, y;
  scanf("%d%d%d%d%d", &n, &s, &t, &x, &y);

  for(int i = 1; i <= n; ++i){
    d[i] = INT_MAX;
  }

  CheckAndPush(n, s, 0);

  while(d[t] == INT_MAX && !Q.empty()){
    int i = Q.front();
    Q.pop();
    CheckAndPush(n, i + x, d[i] + 1);
    CheckAndPush(n, i - y, d[i] + 1);
  }

  if(d[t] == INT_MAX){
    printf("use the stairs\n");
  }
  else{
    printf("%d\n", d[t]);
  }

  return 0;
}