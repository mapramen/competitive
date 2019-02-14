#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200001

set<int> adj[N];
bool visited[N];

int main(){
  int n;
  queue<int> Q1, Q2;

  scanf("%d", &n);

  for(int x = 1; x < n; ++x){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].insert(j);
    adj[j].insert(i);
  }

  for(int x = 1; x <= n; ++x){
    int i;
    scanf("%d", &i);
    Q1.push(i);
  }

  if(Q1.front() != 1){
    printf("No\n");
    return 0;
  }

  Q2.push(1);
  Q1.pop();
  visited[1] = 1;

  while(!Q2.empty()){
    int i = Q2.front();
    Q2.pop();

    while(!Q1.empty()){
      int j = Q1.front();

      if(adj[i].find(j) == adj[i].end()){
        break;
      }

      Q1.pop();

      visited[j] = 1;
      Q2.push(j);
      adj[i].erase(j);
      adj[j].erase(i);
    }
  }

  printf("%s\n", Q1.empty() ? "Yes" : "No");

  return 0;
}
