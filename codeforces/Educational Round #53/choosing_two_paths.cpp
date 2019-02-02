#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define tiiii tuple< int, int, int, int >
#define tiiiiii tuple< int, int, int, int, int, int >
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define N 200001

vector< vector<int> > adj(N);
pii onePathUp[N], onePathDown[N];
tiiii dpDown[N], dpUp[N];
tiiiiii ans;

void DFS1(int i, int p = 0){
  int a1 = 0, b1 = 0, c1 = 0, x1 = 0, x2 = 0, x3 = 0;
  for(auto j : adj[i]){
    if(j == p){
      continue;
    }
    DFS1(j, i);
    int a2, b2, c2, y1, y2, y3;
    tie(a2, b2, y1, y2) = dpDown[j];
    tie(c2, y3) = onePathDown[j];
    ++a2, b2 += 2, ++c2;
    if(min(x1, x2) > 0 && min(y1, y2) > 0){
      ans = max(ans, MT(a1 + a2, b1 + b2, x1, x2, y1, y2));
    }
    if(min(x3, y3)){
      tie(a1, b1, x1, x2) = max(MT(a1, b1, x1, x2), MT(0, c1 + c2, x3, y3));
    }
    if(min(y1, y2)){
      tie(a1, b1, x1, x2) = max(MT(a1, b1, x1, x2), MT(a2, b2, y1, y2));
    }
    if(y3){
      tie(c1, x3) = max(MP(c1, x3), MP(c2, y3));
    }
  }
  onePathDown[i] = max(MP(c1, x3), MP(0, i));
  if(min(x1, x2) > 0){
    dpDown[i] = MT(a1, b1, x1, x2);
  }
}

void KeepTop3(vector< pii > &v){
  while(v.size() > 3){
    for(int i = 0, k = v.size() - 1; i < k; ++i){
      if(v[i] < v[k]){
        swap(v[i], v[k]);
      }
    }
    v.pop_back();
  }
}

void DFS2(int i, int p = 0){
  vector< pii > v(3);
  v.PB(onePathUp[i]);

  for(auto j : adj[i]){
    if(j == p){
      continue;
    }
    v.PB(MP(1 + onePathDown[j].first, onePathDown[j].second));
    KeepTop3(v);
  }

  int a, b, z1, z2;
  tie(a, b, z1, z2) = dpUp[i];

  for(auto j : adj[i]){
    if(j == p){
      continue;
    }
    int a1 = a, b1 = b, x1 = z1, x2 = z2;
    int a2, b2, c1, c2, y1 = 0, y2 = 0;
    for(int k = 0, c = 0; k < v.size(); ++k){
      if(v[k].second == onePathDown[j].second){
        continue;
      }
      if(c){
        tie(c1, y1) = v[k];
      }
      else{
        tie(c2, y2) = v[k];
      }
      ++c;
    }
    if(min(y1, y2)){
      tie(a1, b1, x1, x2) = max(MT(a1, b1, x1, x2), MT(0, c1 + c2, y1, y2));
    }
    onePathUp[j] = max(MP(1 + c1, y1), MP(1 + c2, y2));
    ++a1, b1 += 2;
    tie(a2, b2, y1, y2) = dpDown[j];
    if(min(x1, x2) > 0 && min(y1, y2) > 0){
      ans = max(ans, MT(a1 + a2, b1 + b2, x1, x2, y1, y2));
    }
    if(min(x1, x2)){
      dpUp[j] = MT(a1, b1, x1, x2);
    }
    DFS2(j, i);
  }
}

int main(){
  int n;

  scanf("%d", &n);
  for(int x = 1; x < n; ++x){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].PB(j);
    adj[j].PB(i);
  }

  int root = 1;
  for( ; adj[root].size() < 1; ++root);

  DFS1(root);
  DFS2(root);

  int a, b, x1, x2, y1, y2;
  tie(a, b, x1, x2, y1, y2) = ans;

  printf("%d %d\n%d %d\n", x1, y1, x2, y2);

  return 0;
}
