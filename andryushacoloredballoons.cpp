#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200001

vector< vector<int> > adj(N);
int color[N], totalColor;

void DFS(int i, int p){
  int colorNo = 1;
  for(auto k : adj[i]){
    if(k != p){
      colorNo += (colorNo == color[p]);
      colorNo += (colorNo == color[i]);
      colorNo += (colorNo == color[p]);
      color[k] = colorNo;
      DFS(k, i);
      ++colorNo;
    }
  }
}

int main(){
  int n;

  scanf("%d", &n);

  for(int x = 1; x < n; x++){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].PB(j);
    adj[j].PB(i);
  }

  for(int i = 1; i <= n; i++)
    totalColor = max(totalColor, (int)adj[i].size() + 1);

  color[1] = 1;
  DFS(1, 0);

  printf("%d\n", totalColor);
  for(int i = 1; i <= n; i++)
    printf("%d ", color[i]);
  printf("\n");

  return 0;
}
