#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

char op[10];
map<int,int> C;
int cnt;

void Add(int x){
  ++C[x], ++cnt;
}

void Delete(int x){
  if(C.count(x) == 0){
    return;
  }
  
  --cnt;
  if(--C[x] == 0){
    C.erase(x);
  }
}

string GetStatus(){
  if(cnt < 2){
    return "neither";
  }

  bool is_homo = C.size() != cnt;
  bool is_hetero = C.size() > 1;

  if(is_homo && is_hetero){
    return "both";
  }

  return is_homo ? "homo" : "hetero";
}

int main(){
  int q;
  scanf("%d", &q);

  while(q--){
    int x;
    scanf("%s%d", op, &x);

    if(op[0] == 'i'){
      Add(x);
    }
    else{
      Delete(x);
    }

    printf("%s\n", GetStatus().c_str());
  }

  return 0;
}