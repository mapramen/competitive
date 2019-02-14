#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define B 19
#define BASE 10

int c[BASE], l[B], r[B], ans, cnt;

bool Check(int pos, bool lf, bool rf);

bool CheckDigit(int from, int to){
  bool check = 0;
  for( ; from < to && check == 0; from++)
    check = (c[from] > 0);
  return check;
}

bool CheckLeftDigit(int pos){
  bool check = 0;
  if(c[l[pos]]){
    c[l[pos]]--;
    check = Check(pos - 1, 1, 0);
    c[l[pos]]++;
  }
  return check;
}

bool CheckRightDigit(int pos){
  bool check = 0;
  if(c[r[pos]]){
    c[r[pos]]--;
    check = Check(pos - 1, 0, 1);
    c[r[pos]]++;
  }
  return check;
}

bool Check(int pos, bool lf, bool rf){
  if(pos < 0)
    return 1;

  bool check = 0;
  if(lf == 1 && rf == 1){
    if(l[pos] == r[pos]){
      if(c[l[pos]]){
        c[l[pos]]--;
        check = Check(pos - 1, 1, 1);
        c[l[pos]]++;
      }
    }
    else{
      check = CheckDigit(l[pos] + 1, r[pos]);
      if(check == 0)
        check = CheckLeftDigit(pos);
      if(check == 0)
        check = CheckRightDigit(pos);
    }
  }
  else if(lf == 1){
    check = CheckDigit(l[pos] + 1, BASE);
    if(check == 0)
      check = CheckLeftDigit(pos);
  }
  else{
    check = CheckDigit(0, r[pos]);
    if(check == 0)
      check = CheckRightDigit(pos);
  }

  return check;
}

void Print(){
  bool check = 1;
  for(int i = 0; i < BASE; i++)
    check &= (c[i] >= 0);

  if(check){
    for(int i = 0; i < BASE; i++){
      int d = c[i];
      while(d--)
        printf("%d", i);
    }
    printf("\n");
  }
}

void DFS(int pos, int x){
  if(pos == B){
    if(x){
      ans += Check(B - 1, 1, 1);
    }
  }
  else{
    for(int y = x; y < BASE; y++){
      c[y]++, c[0]--;
      DFS(pos + 1, y);
      c[y]--, c[0]++;
    }
  }
}

int main(){
  ll a, b;

  cin >> a >> b;

  for(int i = 0; a > 0; i++, a /= BASE)
    l[i] = a % BASE;

  for(int i = 0; b > 0; i++, b /= BASE)
    r[i] = b % BASE;

  c[0] = B;

  DFS(1, 0);

  cout << ans << '\n';

  return 0;
}
