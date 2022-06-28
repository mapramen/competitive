#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

void Solve(){
  int n;
  scanf("%d", &n);

  stack<int> stack, max_stack;
  char op[10];

  while(n--){
    scanf("%s", op);
    char ch = op[0];

    if((ch == 'R' || ch == 'Q') && stack.empty()){
      if(ch == 'Q'){
        printf("Empty\n");
      }
      continue;
    }

    if(ch == 'Q'){
      printf("%d\n", max_stack.top());
      continue;
    }

    if(ch == 'R'){
      if(max_stack.top() == stack.top()){
        max_stack.pop();
      }
      stack.pop();
      continue;
    }

    int x;
    scanf("%d", &x);

    stack.push(x);
    if(max_stack.empty() || max_stack.top() <= x){
      max_stack.push(x);
    }
  }
}

int main(){
  int t;
  scanf("%d", &t);
  for(int k = 1; k <= t; ++k){
    printf("Case %d:\n", k);
    Solve();
  }
  return 0;
}