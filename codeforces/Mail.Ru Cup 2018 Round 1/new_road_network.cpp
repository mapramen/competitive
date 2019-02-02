#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 2000

vector< pii > edges[N + 1];
bitset<N> a[N];
int parent[N];
char s[N + 1];

int Find(int i){
  return (parent[i] == i) ? i : parent[i] = Find(parent[i]);
}

bool Union(int i, int j){
  i = Find(i), j = Find(j);
  if(i == j){
    return 0;
  }
  if(i > j){
    swap(i, j);
  }
  parent[j] = i;
  return 1;
}

void Reset(){
  for(int i = 0; i < N; ++i){
    parent[i] = i;
    a[i].reset();
  }
  for(int i = 0; i <= N; ++i){
    edges[i].clear();
  }
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    int n, m;

    scanf("%d%d", &n, &m);
    Reset();

    int targetMSTWeight = -m;
    for(int x = 0; x < m; ++x){
      scanf("%s", s);
      for(int i = 0; i < n; ++i){
        if(s[i] == '1'){
          a[i].set(x);
          ++targetMSTWeight;
        }
      }
    }

    for(int i = 0; i < n; ++i){
      for(int j = i + 1; j < n; ++j){
        int k = (a[i] & a[j]).count();
        edges[k].PB(MP(i, j));
      }
    }

    vector< pii > ans;
    int mstWeight = 0;
    for(int k = m; k > -1 && mstWeight <= targetMSTWeight; --k){
      for(auto edge : edges[k]){
        int i, j;
        tie(i, j) = edge;
        if(Union(i, j)){
          mstWeight += k;
          ans.PB(MP(i, j));
          if(mstWeight > targetMSTWeight){
            break;
          }
        }
      }
    }

    if(mstWeight != targetMSTWeight){
      printf("NO\n");
    }
    else{
      printf("YES\n");
      for(auto p : ans){
        int i, j;
        tie(i, j) = p;
        printf("%d %d\n", i + 1, j + 1);
      }
    }
  }

  return 0;
}
