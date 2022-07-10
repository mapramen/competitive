#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define pdi pair<double,int>

double PI = 4 * atan(1), EPS = 1E-12;

ll CrossProduct(pii a, pii b){
  return 1ll * a.first * b.second - 1ll * a.second * b.first;
}

void AddAngleEvents(vector<pdi>& angle_events, double theta1, double theta2){
  angle_events.push_back({theta1, 1});
  angle_events.push_back({theta2 + EPS, -1});
}

void AddAngleEvents(vector<pdi>& angle_events, pii a, pii b){
  if(CrossProduct(a, b) < 0){
    swap(a, b);
  }

  double theta1 = atan2(a.second, a.first), theta2 = atan2(b.second, b.first);
  if(theta1 > 0 && theta2 < 0){
    AddAngleEvents(angle_events, -PI, theta2);
    AddAngleEvents(angle_events, theta1, PI);
  }
  else{
    AddAngleEvents(angle_events, theta1, theta2);
  }
}

int Solve(){
  int n;
  scanf("%d", &n);

  vector<pdi> angle_events;
  while(n--){
    int x1, y1, x2, y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    AddAngleEvents(angle_events, {x1, y1}, {x2, y2});
  }
  sort(angle_events.begin(), angle_events.end());

  int ans = 0, ansx = 0;
  for(pdi& angle_event: angle_events){
    ansx += angle_event.second;
    ans = max(ans, ansx);
  }

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}