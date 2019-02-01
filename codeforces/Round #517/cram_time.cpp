#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

set<int> used;

vector<int> FillDay(int n, bool fixTheDay){
  int s = 0;
  vector<int> v;
  for(int i = 1; s < n; ++i){
    if(used.find(i) != used.end()){
      continue;
    }
    v.PB(i);
    s += i;
  }

  if(fixTheDay && n < s){
    int i = s - n;
    v.erase(v.begin() + i - 1);
    s -= i;
  }

  if(s > n){
    v.pop_back();
  }

  for(auto i : v){
    used.insert(i);
  }

  return v;
}

void Print(vector<int> &A){
  printf("%lu\n", A.size());
  for(auto i : A){
    printf("%d ", i);
  }
  printf("\n");
}

int main(){
  int n, m;

  scanf("%d%d", &n, &m);

  vector<int> A = FillDay(n, 1);
  vector<int> B = FillDay(m, 0);

  Print(A);
  Print(B);

  return 0;
}
