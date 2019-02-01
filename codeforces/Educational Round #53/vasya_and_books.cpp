#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200001

bool visited[N];

int main(){
  int n;
  queue<int> Q;

  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    int x;
    scanf("%d", &x);
    Q.push(x);
  }

  for(int i = 1; i <= n; ++i){
    int x, k = 0;
    scanf("%d", &x);
    while(visited[x] == 0 && !Q.empty()){
      visited[Q.front()] = 1;
      Q.pop();
      ++k;
    }
    printf("%d ", k);
  }
  printf("\n");

  return 0;
}
