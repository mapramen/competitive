#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

vector<vector<int>> V(1, vector<int>(1, 1));

void CalculateFactorial(int n){
  vector<int>& u = V.back();
  vector<int> v;

  int carry = 0;
  for(int i = 0; i < u.size() || carry != 0; ++i, carry /= 10){
    if(i < u.size()){
      carry += n * u[i];
    }
    v.push_back(carry % 10);
  }

  V.push_back(v);
}

string Solve(){
  int n;
  scanf("%d", &n);

  while(V.size() <= n){
    CalculateFactorial(V.size());
  }

  string ans;
  for(int i = V[n].size() - 1; i != -1; --i){
    ans.push_back('0' + V[n][i]);
  }

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