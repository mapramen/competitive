#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int main(){
  int n;
  scanf("%d", &n);

  stack<int> stack, min_stack;
  char op[10];

  while(n--){
    scanf("%s", op);
    char ch = op[1];

    if((ch == 'O' || ch == 'I') && stack.empty()){
      printf("EMPTY\n");
      continue;
    }

    if(ch == 'I'){
      printf("%d\n", min_stack.top());
      continue;
    }

    if(ch == 'O'){
      if(min_stack.top() == stack.top()){
        min_stack.pop();
      }
      stack.pop();
      continue;
    }

    int x;
    scanf("%d", &x);

    stack.push(x);
    if(min_stack.empty() || min_stack.top() >= x){
      min_stack.push(x);
    }
  }
  
  return 0;
}