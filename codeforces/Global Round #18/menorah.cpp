#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100001

char S[N], T[N];
set<vector<int>> visited;
queue<pair<vector<int>,int>> Q;

void CheckAndPush(vector<int>& v, int d){
  if(visited.count(v) == 0){
    visited.insert(v);
    Q.push({v, d});
  }
}

void Initialise(int n){
  visited.clear();
  while(!Q.empty()){
    Q.pop();
  }

  vector<int> v(4);
  for(int i = 0; i < n; ++i){
    int x = 2 * (T[i] == '1') + (S[i] == '1');
    ++v[x];
  }

  CheckAndPush(v, 0);
}

void Flip(vector<int>& v, int x){
  if(v[x] == 0){
    return;
  }

  --v[x];
  swap(v[0], v[1]);
  swap(v[2], v[3]);
  ++v[x];
}

void CheckAndPush(vector<int>& v, int x, int d){
  Flip(v, x);
  CheckAndPush(v, d);
  Flip(v, x);
}
 
int Solve(){
  int n;
  scanf("%d", &n);

  scanf("%s", S);
  scanf("%s", T);
 
  Initialise(n);

  while(!Q.empty()){
    vector<int> v = Q.front().first;
    int d = Q.front().second;
    Q.pop();

    if(v[1] == 0 && v[2] == 0){
      return d;
    }

    CheckAndPush(v, 1, d + 1);
    CheckAndPush(v, 3, d + 1);
  }

  return -1;
}
 
int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}