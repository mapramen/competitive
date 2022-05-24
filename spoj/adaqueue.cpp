#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

char op[10];
deque<int> Q;

void Push(bool reverse, bool front, int val){
  if(reverse){
    front = !front;
  }

  if(front){
    Q.push_front(val);
  }
  else{
    Q.push_back(val);
  }
}

string Pop(bool reverse, bool front){
  if(Q.empty()){
    return "No job for Ada?";
  }

  if(reverse){
    front = !front;
  }

  int ans = front ? Q.front() : Q.back();

  if(front){
    Q.pop_front();
  }
  else{
    Q.pop_back();
  }

  return to_string(ans);
}

int main(){
  int n;
  scanf("%d", &n);

  bool reverse = false;
  while(n--){
    scanf("%s", op);
    char op_code = op[0];

    if(op_code == 't' || op_code == 'p'){
      int x;
      scanf("%d", &x);
      Push(reverse, op_code == 't', x);
    }

    if(op_code == 'f' || op_code == 'b'){
      printf("%s\n", Pop(reverse, op_code == 'f').c_str());
    }

    if(op_code == 'r'){
      reverse = !reverse;
    }
  }

  return 0;
}