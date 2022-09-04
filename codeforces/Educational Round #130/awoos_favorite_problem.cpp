#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100001

char S[N], T[N];
set<int> A, B, C, indexes;

void Erase(int i){
  if(S[i] == 'a'){
    A.erase(i);
  }
  else if(S[i] == 'b'){
    B.erase(i);
  }
  else{
    C.erase(i);
  }
  indexes.erase(i);
}

bool IsPossible(set<int>& indexes, set<int>& A, set<int>& B, set<int>& C){
  if(B.empty() || (!C.empty() && *C.begin() < *B.begin())){
    return false;
  }

  int j = *B.begin();
  Erase(j);
  return true;
}

bool Solve(){
  int n;
  scanf("%d%s%s", &n, S, T);

  A.clear(), B.clear(), C.clear(), indexes.clear();
  
  for(int i = 0; i < n; ++i){
    indexes.insert(i);
    if(S[i] == 'a'){
      A.insert(i);
    }
    else if(S[i] == 'b'){
      B.insert(i);
    }
    else{
      C.insert(i);
    }
  }

  for(int i = 0; i < n; ++i){
    int j = *indexes.begin();
    if(S[j] == T[i]){
      Erase(j);
      continue;
    }

    if(T[i] == 'a'){
      return false;
    }

    if(T[i] == 'b' && !IsPossible(indexes, A, B, C)){
      return false;
    }

    if(T[i] == 'c' && !IsPossible(indexes, B, C, A)){
      return false;
    }
  }

  return true;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%s\n", Solve() ? "YES" : "NO");
  }
  return 0;
}