#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define tiii tuple< int, int, int >
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define N 2001

int a[N], pairedIndex[N];
bool taken[N];
priority_queue< tiii > Q;

void Print(int i){
  cout << i << '\n';
  fflush(stdout);
  taken[i] = 1;
}

void ClearTakenItems(){
  while(!Q.empty()){
    int t, p, i;
    tie(t, p, i) = Q.top();
    if(taken[i]){
      Q.pop();
    }
    else{
      break;
    }
  }
}

int main(){
  int n, m;

  cin >> n >> m;

  for(int i = 1; i <= n + n; ++i){
    cin >> a[i];
  }

  while(m--){
    int i, j;
    cin >> i >> j;
    pairedIndex[i] = j;
    pairedIndex[j] = i;
  }

  for(int i = 1; i <= n + n; ++i){
    Q.push(MT(pairedIndex[i] > 0, a[i], i));
  }

  int t;
  cin >> t;
  --t;

  for(int forcedIndex = 0; !Q.empty(); t = 1 - t, ClearTakenItems()){
    if(t){
      int i;
      scanf("%d", &i);
      taken[i] = 1;
      forcedIndex = pairedIndex[i];
    }
    else{
      if(forcedIndex && taken[forcedIndex] == 0){
        Print(forcedIndex);
      }
      else{
        int t, p, i;
        tie(t, p, i) = Q.top();
        Print(i);
      }
      forcedIndex = 0;
    }
  }

  return 0;
}
