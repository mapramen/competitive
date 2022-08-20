#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int GetValue(char c){
  return c == '(' ? 1 : -1;
}

bool Check(string s){
  int x = 0;
  for(char c: s){
    x += GetValue(c);
    if(x < 0){
      return false;
    }
  }
  return true;
}

bool CheckOneOperation(string s, int i, int j){
  reverse(s.begin() + i, s.begin() + j + 1);
  return Check(s);
}

int GetMaxValueIndex(string s, int l, int r){
  int max_value = 0, max_value_index = l - 1;
  for(int i = l, value = 0; i <= r; ++i){
    value += GetValue(s[i]);
    if(value >= max_value){
      max_value = value, max_value_index = i;
    }
  }
  return max_value_index;
}

void Solve(){
  int n;
  string s;
  cin >> n >> s;

  n *= 2;

  if(Check(s)){
    printf("0\n");
    return;
  }

  int i = 0;
  for(int value = 0; i != n; ++i){
    value += GetValue(s[i]);
    if(value < 0){
      break;
    }
  }

  int j = n - 1;
  for(int value = 0; j != -1; --j){
    if(value < 0){
      break;
    }
    value -= GetValue(s[j]);
  }

  i = GetMaxValueIndex(s, 0, i) + 1, j = GetMaxValueIndex(s, j, n - 1);
  if(CheckOneOperation(s, i, j)){
    printf("1\n");
    printf("%d %d\n", i + 1, j + 1);
    return;
  }

  int k = GetMaxValueIndex(s, 0, n - 1);
  printf("2\n");
  printf("%d %d\n", 1, k + 1);
  printf("%d %d\n", k + 2, n);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}