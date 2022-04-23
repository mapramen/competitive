#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define HOURS 24
#define MINUTES 60

int ReadTime(){
  int h, m;
  scanf("%d%d", &h, &m);
  return MINUTES * h + m;
}

void DisplayTime(int m){
  m %= (HOURS * MINUTES);
  printf("%02d %02d\n", m / MINUTES, m % MINUTES);
}

int main(){
  DisplayTime(ReadTime() + ReadTime());
  return 0;
}