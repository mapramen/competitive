#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100001

vector<vector<int>> adj(N);
int a[N];
ll dp_down_buy[N], dp_down_sell[N], dp_up_buy[N], dp_up_sell[N], ans[N];

void DownDFS(int i, int p){
  dp_down_buy[i] = 0, dp_down_sell[i] = a[i];
  for(int j: adj[i]){
    if(j == p){
      continue;
    }
    DownDFS(j, i);
    dp_down_buy[i] = max(dp_down_buy[i], max(dp_down_buy[j], -a[i] + dp_down_sell[j]));
    dp_down_sell[i] = max(dp_down_sell[i], max(dp_down_sell[j], a[i] + dp_down_buy[j]));
  }
}

void UpdateChildrenInUpDFS(int i, int p, ll buy, ll sell){
  for(int j: adj[i]){
    if(j == p){
      continue;
    }

    dp_up_buy[j] = max(dp_up_buy[j], max(buy, -a[i] + sell));
    dp_up_sell[j] = max(dp_up_sell[j], max(sell, a[i] + buy));

    buy = max(buy, dp_down_buy[j]);
    sell = max(sell, dp_down_sell[j]);
  }
}

void UpDFS(int i, int p, ll buy, ll sell){
  dp_up_buy[i] = max(buy, -a[i] + sell);
  dp_up_sell[i] = max(sell, a[i] + buy);

  UpdateChildrenInUpDFS(i, p, buy, sell);
  reverse(adj[i].begin(), adj[i].end());
  UpdateChildrenInUpDFS(i, p, buy, sell);

  for(int j: adj[i]){
    if(j == p){
      continue;
    }
    UpDFS(j, i, dp_up_buy[j], dp_up_sell[j]);
  }
}

void PreProcess(int n){
  DownDFS(1, 0);
  UpDFS(1, 0, 0ll, 0ll);

  for(int i = 1; i <= n; ++i){
    ans[i] = max(dp_down_buy[i], dp_up_buy[i]);
  }
}

int main(){
  int n, q;
  scanf("%d%d", &n, &q);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  for(int x = 1; x < n; ++x){
    int i, j;
    scanf("%d%d", &i, &j);
    ++i, ++j;
    adj[i].push_back(j);
    adj[j].push_back(i);
  }

  PreProcess(n);

  while(q--){
    int i;
    scanf("%d", &i);
    ++i;
    printf("%lld\n", ans[i]);
  }

  return 0;
}