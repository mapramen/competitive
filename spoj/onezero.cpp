#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 20001

int parent[N], parentEdge[N];
queue<int> Q;

void Reset(int n){
  for(int i = 0; i < n; ++i){
    parent[i] = -1;
  }

  while(!Q.empty()){
    Q.pop();
  }
}

void CheckAndPush(int r, int p, int pEdge){
  if(parent[r] == -1){
    parent[r] = p, parentEdge[r] = pEdge;
    Q.push(r);
  }
}

string Solve(){
  int n;
  scanf("%d", &n);

  Reset(n);

  CheckAndPush(1 % n, INT_MIN, 1);

  while(parent[0] == -1){
    int i = Q.front();
    Q.pop();

    CheckAndPush((10 * i) % n, i, 0);
    CheckAndPush((10 * i + 1) % n, i, 1);
  }

  string ans;
  for(int r = 0; r != INT_MIN; r = parent[r]){
    ans.push_back('0' + parentEdge[r]);
  }
  reverse(ans.begin(), ans.end());

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%s\n", Solve().c_str());
  }
  return 0;
}