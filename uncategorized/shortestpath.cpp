#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define piii pair< pii, int >
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 3001

vector< vector<int> > adj(N);
int d[N][N], parent[N][N], w;

void PrintPath(int i, int p){
  if(i == 0)
    return ;

  PrintPath(p, parent[i][p]);
  printf("%d ", i);
}

int main(){
  int n, m, k, i, j, a, b, c, p;
  set< piii > s;

  scanf("%d%d%d", &n, &m, &k);

  while(m--){
    scanf("%d%d", &i, &j);
    adj[i].PB(j);
    adj[j].PB(i);
  }

  while(k--){
    scanf("%d%d%d", &a, &b, &c);
    s.insert(MP(MP(a, b), c));
  }

  queue< pii > q;
  q.push(MP(1, 0));

  while(!q.empty()){
    i = q.front().first;
    p = q.front().second;

    if(i == n)
      break;

    q.pop();

    for(j = 0; j < adj[i].size(); j++){
      k = adj[i][j];

      if(s.find(MP(MP(p, i), k)) != s.end() || d[k][i] != 0)
        continue;

      d[k][i] = d[i][p] + 1;
      parent[k][i] = p;

      q.push(MP(k, i));
    }
  }

  if(i != n)
    printf("-1\n");
  else{
    printf("%d\n", d[i][p]);
    PrintPath(i, p);
    printf("\n");
  }

  return 0;
}
