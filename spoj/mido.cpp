#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define SECONDS_PER_MINUTE 60
#define GAME_TIME_IN_MINUTES 48
#define B 2

int score_cnt[B], lead_time[B];

int GetTime(int min, int sec) {
  return min * SECONDS_PER_MINUTE + sec;
}

int GetMinutes(int sec) {
  return sec / SECONDS_PER_MINUTE;
}

int GetSeconds(int sec) {
  return sec % SECONDS_PER_MINUTE;
}

int main() {
  int n;
  scanf("%d", &n);

  vector<pii> a;
  a.push_back({0, 0});
  while (n--) {
    int i, min, sec;
    scanf("%d %d:%d", &i, &min, &sec);
    --i;

    a.push_back({GetTime(min, sec), i});
  }
  a.push_back({GetTime(GAME_TIME_IN_MINUTES, 0), 0});
  sort(a.begin(), a.end());

  for (int k = 2; k < a.size(); ++k) {
    int i = a[k - 1].second;
    ++score_cnt[i];

    if (score_cnt[0] == score_cnt[1]) {
      continue;
    }

    int lead = score_cnt[0] > score_cnt[1] ? 0 : 1;
    int time = a[k].first - a[k - 1].first;
    lead_time[lead] += time;
  }

  for (int i = 0; i < B; ++i) {
    printf("%02d:%02d\n", GetMinutes(lead_time[i]), GetSeconds(lead_time[i]));
  }

  return 0;
}