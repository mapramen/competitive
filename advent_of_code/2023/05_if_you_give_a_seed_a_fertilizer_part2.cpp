#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

vector<ll> ExtractNumbers(string& s) {
  vector<ll> numbers;

  reverse(s.begin(), s.end());

  string t;
  while (!s.empty()) {
    char c = s.back();
    s.pop_back();

    if (isdigit(c)) {
      t.push_back(c);
    }

    if (!s.empty() && isdigit(s.back()) || t.empty()) {
      continue;
    }

    ll number = stoll(t);
    t.clear();

    numbers.push_back(number);
  }

  return numbers;
}

vector<pll> ReadSeeds() {
  string s;
  getline(cin, s);

  vector<ll> numbers = ExtractNumbers(s);

  vector<pll> seeds;
  for (int i = 1; i < numbers.size(); i += 2) {
    seeds.push_back({numbers[i], numbers[i - 1]});
  }

  return seeds;
}

void AddRange(vector<pll>& ranges, ll range_start, ll range_end) {
  ranges.push_back({range_end - range_start + 1, range_start});
}

vector<pll> SplitSourceValues(vector<pll> source_values, ll range_size, ll range_start) {
  ll range_end = range_start + range_size - 1;

  vector<pll> ans;
  for (auto [source_range_size, source_range_start] : source_values) {
    ll source_range_end = source_range_start + source_range_size - 1;

    if (source_range_end < range_start || range_end < source_range_start) {
      AddRange(ans, source_range_start, source_range_end);
      continue;
    }

    if (source_range_start < range_start) {
      AddRange(ans, source_range_start, range_start - 1);
      source_range_start = range_start;
    }

    if (source_range_end <= range_end) {
      AddRange(ans, source_range_start, source_range_end);
      continue;
    }

    AddRange(ans, source_range_start, range_end);
    AddRange(ans, range_end + 1, source_range_end);
  }
  return ans;
}

vector<pll> MapToDestination(string source_name, string destination_name, vector<pll>& source_values) {
  string s;

  while (s != source_name + "-to-" + destination_name + " map:") {
    getline(cin, s);
  }

  vector<tuple<ll, ll, ll>> mappings;
  while (getline(cin, s) && !s.empty()) {
    vector<ll> numbers = ExtractNumbers(s);
    ll destination_range_start = numbers[0];
    ll source_range_start = numbers[1];
    ll range_size = numbers[2];

    mappings.push_back({range_size, source_range_start, destination_range_start});
    source_values = SplitSourceValues(source_values, range_size, source_range_start);
  }

  vector<pll> ans;
  for (auto [sn1, sl1] : source_values) {
    for (auto [range_size, source_range_start, destination_range_start] : mappings) {
      if (source_range_start <= sl1 && sl1 + sn1 - 1 < source_range_start + range_size) {
        sl1 = destination_range_start + (sl1 - source_range_start);
        break;
      }
    }
    ans.push_back({sn1, sl1});
  }

  return ans;
}

int main() {
  vector<pll> seeds = ReadSeeds();
  vector<pll> soils = MapToDestination("seed", "soil", seeds);
  vector<pll> fertilizers = MapToDestination("soil", "fertilizer", soils);
  vector<pll> waters = MapToDestination("fertilizer", "water", fertilizers);
  vector<pll> lights = MapToDestination("water", "light", waters);
  vector<pll> temperatures = MapToDestination("light", "temperature", lights);
  vector<pll> humidities = MapToDestination("temperature", "humidity", temperatures);
  vector<pll> locations = MapToDestination("humidity", "location", humidities);

  ll ans = locations.front().second;
  for (auto [range_size, range_start] : locations) {
    ans = min(ans, range_start);
  }

  cout << ans << endl;

  return 0;
}