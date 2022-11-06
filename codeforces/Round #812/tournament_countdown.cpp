#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int Query(int a, int b){
  printf("? %d %d\n", a, b);
  fflush(stdout);
  
  int x;
  scanf("%d", &x);
  return x;
}

int ExtractFront(queue<int>& Q){
  int i = Q.front();
  Q.pop();
  return i;
}

int GetWinner(int a, int b){
  int qans = Query(a, b);
  if(qans == 0){
    return -1;
  }

  return qans == 1 ? a : b;
}

int GetWinnerOfWinners(queue<int>& Q){
  vector<int> v;
  for(int k = 0; k < 4; ++k){
    v.push_back(ExtractFront(Q));
  }

  int a = Query(v[0], v[2]);
  if(a == 0){
    return GetWinner(v[1], v[3]);
  }

  if(a == 1){
    swap(v[0], v[2]);
    swap(v[1], v[3]);
  }

  return Query(v[1], v[2]) == 1 ? v[1] : v[2];
}

void Solve(){
  int n;
  scanf("%d", &n);

  queue<int> Q;
  for(int i = 1; i <= (1 << n); ++i){
    Q.push(i);
  }

  while(Q.size() > 2){
    queue<int> nQ;

    while(!Q.empty()){
      nQ.push(GetWinnerOfWinners(Q));
    }

    Q.swap(nQ);
  }

  printf("! %d\n", Q.size() == 1 ? Q.front() : GetWinner(ExtractFront(Q), ExtractFront(Q)));
  fflush(stdout);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}