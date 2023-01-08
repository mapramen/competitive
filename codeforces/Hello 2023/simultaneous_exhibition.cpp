#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 251

int out_degrees[N];

int Query(int n, int i, set<int>& S){
  printf("? %d ", i);

  for(int j = 1; j <= n; ++j){
    printf("%c", '0' + (j != i && S.count(j) != 0));
  }
  printf("\n");
  fflush(stdout);

  int x;
  scanf("%d", &x);
  return x;
}

void PrintAns(int n, set<int>& S){
  printf("! ");
  for(int i = 1; i <= n; ++i){
    printf("%c", '0' + (S.count(i) != 0));
  }
  printf("\n");
  fflush(stdout);
}

int main(){
  int n;
  scanf("%d", &n);

  set<int> S;
  for(int i = 1; i <= n; ++i){
    S.insert(i);
  }  

  for(int i = 1; i <= n; ++i){
    out_degrees[i] = Query(n, i, S);
  }

  vector<int> v(n);
  iota(v.begin(), v.end(), 1);
  sort(v.begin(), v.end(), [](int i, int j) { return out_degrees[i] > out_degrees[j]; });

  S.clear();
  S.insert(v.front());
  for(int k = 1; k < n; ++k){
    int i = v[k];
    if(Query(n, i, S) == 0){
      continue;
    }

    for(int j = k; j > - 1; --j){
      S.insert(v[j]);
    }
  }

  PrintAns(n, S);

  return 0;
}