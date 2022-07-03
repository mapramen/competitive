#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define B 26

int parent[B];

void Reset(){
  iota(parent, parent + B, 0);
}

int Find(int i){
  return i == parent[i] ? i : parent[i] = Find(parent[i]);
}

void Union(int i, int j){
  i = Find(i), j = Find(j);
  if(i == j){
    return;
  }

  if(i > j){
    swap(i, j);
  }

  parent[j] = i;
}

string Solve(){
  int n, k;
  scanf("%d%d", &n, &k);

  string s;
  cin >> s;

  Reset();

  for(char c: s){
    int i = c - 'a';
    while(Find(i) != 0 && k != 0){
      Union(i - 1, i);
      --i, --k;
    }
  }

  for(char& c: s){
    c = 'a' + Find(c - 'a');
  }

  return s;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%s\n", Solve().c_str());
  }
  return 0;
}