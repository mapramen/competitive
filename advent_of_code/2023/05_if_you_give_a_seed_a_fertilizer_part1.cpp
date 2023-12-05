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

vector<ll> ReadSeeds() {
  string s;
  getline(cin, s);
  return ExtractNumbers(s);
}

vector<ll> MapToDestination(string source_name, string destination_name, vector<ll>& source_values) {
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
  }

  for (ll& source_value : source_values) {
    for (auto [range_size, source_range_start, destination_range_start] : mappings) {
      if (source_value >= source_range_start && source_value < source_range_start + range_size) {
        source_value = destination_range_start + (source_value - source_range_start);
        break;
      }
    }
  }

  return source_values;
}

int main() {
  vector<ll> seeds = ReadSeeds();
  vector<ll> soils = MapToDestination("seed", "soil", seeds);
  vector<ll> fertilizers = MapToDestination("soil", "fertilizer", soils);
  vector<ll> waters = MapToDestination("fertilizer", "water", fertilizers);
  vector<ll> lights = MapToDestination("water", "light", waters);
  vector<ll> temperatures = MapToDestination("light", "temperature", lights);
  vector<ll> humidities = MapToDestination("temperature", "humidity", temperatures);
  vector<ll> locations = MapToDestination("humidity", "location", humidities);

  cout << *min_element(locations.begin(), locations.end()) << endl;

  return 0;
}