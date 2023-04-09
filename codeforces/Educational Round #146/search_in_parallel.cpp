#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

void Print(vector<int>& v){
  printf("%lu ", v.size());
  for(int x: v){
    printf("%d ", x);
  }
  printf("\n");
}

void Solve(){
  int n, s1, s2;
  scanf("%d%d%d", &n, &s1, &s2);

  vector<pii> a(n);
  for(int i = 0; i < n; ++i){
    scanf("%d", &a[i].first);
    a[i].second = i + 1;
  }
  sort(a.begin(), a.end(), greater<pii>());

  vector<int> A, B;
  ll T1 = s1, T2 = s2;
  for(auto [_, i]: a){
    if(T1 < T2){
      A.push_back(i);
      T1 += s1;
    }
    else{
      B.push_back(i);
      T2 += s2;
    }
  }

  Print(A);
  Print(B);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}