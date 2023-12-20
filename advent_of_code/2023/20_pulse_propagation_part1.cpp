#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define tmodule tuple<char, vector<string>, vector<string>>
#define MAX_BUTTON_CLICKS 1000

char ExtractModuleType(string& s) {
  if (s.front() != '%' && s.front() != '&') {
    return '=';
  }

  char module_type = s.front();

  reverse(s.begin(), s.end());
  s.pop_back();
  reverse(s.begin(), s.end());

  return module_type;
}

string ExtractWord(string& s) {
  reverse(s.begin(), s.end());

  while (!s.empty() && !isalpha(s.back())) {
    s.pop_back();
  }

  string t;
  while (!s.empty() && isalpha(s.back())) {
    t.push_back(s.back());
    s.pop_back();
  }

  reverse(s.begin(), s.end());

  return t;
}

string ExtractModuleName(string& s) {
  return ExtractWord(s);
}

vector<string> ParseModuleDestination(string& s) {
  vector<string> destinations;
  while (!s.empty()) {
    string destination = ExtractWord(s);
    if (!destination.empty()) {
      destinations.push_back(destination);
    }
  }
  return destinations;
}

void AddModuleType(map<string, tmodule>& modules, string& module_name, char module_type) {
  auto it = modules.find(module_name);
  if (it == modules.end()) {
    modules[module_name] = tmodule(module_type, {}, {});
  } else {
    get<0>(it->second) = module_type;
  }
}

void AddSource(map<string, tmodule>& modules, string& module_name, string& source_name) {
  auto it = modules.find(module_name);
  if (it == modules.end()) {
    modules[module_name] = tmodule('=', {source_name}, {});
  } else {
    get<1>(it->second).push_back(source_name);
  }
}

void AddDestination(map<string, tmodule>& modules, string& module_name, string& destination_name) {
  auto it = modules.find(module_name);
  if (it == modules.end()) {
    modules[module_name] = tmodule('=', {}, {destination_name});
  } else {
    get<2>(it->second).push_back(destination_name);
  }
}

map<string, tmodule> ReadModules() {
  map<string, tmodule> modules;
  while (true) {
    string s;
    if (!getline(cin, s)) {
      break;
    }

    char module_type = ExtractModuleType(s);
    string module_name = ExtractModuleName(s);

    AddModuleType(modules, module_name, module_type);
    for (string& destination : ParseModuleDestination(s)) {
      AddSource(modules, destination, module_name);
      AddDestination(modules, module_name, destination);
    }
  }
  return modules;
}

map<string, vector<pii>> GetInitialModuleStates(map<string, tmodule>& modules, map<string, bool>& flip_flop_states) {
  map<string, vector<pii>> module_states;
  for (auto [module_name, _] : modules) {
    module_states[module_name] = {{0, 0}};
  }

  for (auto [module_name, state] : flip_flop_states) {
    module_states[module_name] = {{0, state}};
  }

  return module_states;
}

pii GetLatestTimeAndSignal(map<string, vector<pii>>& module_states, string& module_name, int timer) {
  auto it = lower_bound(module_states[module_name].begin(), module_states[module_name].end(), pii{timer + 1, 0});
  it = prev(it);
  return *it;
}

int CalculateModuleSignal(map<string, tmodule>& modules, map<string, vector<pii>>& module_states, map<string, bool>& flip_flop_states, string& module_name, int timer) {
  if (module_name == "broadcaster") {
    return 0;
  }

  auto [module_type, sources, _] = modules[module_name];

  if (module_type == '=') {
    return -1;
  }

  if (module_type == '%') {
    pii latest_time_and_signal = {0, 0};
    for (string& source : sources) {
      latest_time_and_signal = max(latest_time_and_signal, GetLatestTimeAndSignal(module_states, source, timer));
    }

    auto [_, latest_signal] = latest_time_and_signal;
    if (latest_signal == 1) {
      return -1;
    }

    flip_flop_states[module_name] = !flip_flop_states[module_name];
    return flip_flop_states[module_name];
  }

  if (module_type == '&') {
    for (auto& source : sources) {
      if ((GetLatestTimeAndSignal(module_states, source, timer)).second == 0) {
        return 1;
      }
    }
    return 0;
  }

  assert(false);
}

pll OneClick(map<string, tmodule>& modules, map<string, bool>& flip_flop_states) {
  int timer = 0;

  map<string, vector<pii>> module_states = GetInitialModuleStates(modules, flip_flop_states);

  queue<pair<int, string>> Q;
  Q.push({timer, "broadcaster"});

  ll low_pulse_cnt = 1, high_pulse_cnt = 0;

  while (!Q.empty()) {
    auto [signal_time, module_name] = Q.front();
    Q.pop();

    ++timer;

    int module_signal = CalculateModuleSignal(modules, module_states, flip_flop_states, module_name, signal_time);

    if (module_signal == -1) {
      continue;
    }

    module_states[module_name].push_back({timer, module_signal});

    vector<string> destinations = get<2>(modules[module_name]);

    if (module_signal == 1) {
      high_pulse_cnt += destinations.size();
    } else {
      low_pulse_cnt += destinations.size();
    }

    for (string& destination : destinations) {
      Q.push({timer, destination});
    }
  }

  return {low_pulse_cnt, high_pulse_cnt};
}

int main() {
  map<string, tmodule> modules = ReadModules();

  map<string, bool> flip_flop_states;
  for (auto [module_name, module] : modules) {
    if (get<0>(module) == '%') {
      flip_flop_states[module_name] = false;
    }
  }

  ll low_pulse_cnt = 0, high_pulse_cnt = 0;
  for (int button_click = 1; button_click <= MAX_BUTTON_CLICKS; ++button_click) {
    auto [l, h] = OneClick(modules, flip_flop_states);
    low_pulse_cnt += l, high_pulse_cnt += h;
  }

  ll ans = low_pulse_cnt * high_pulse_cnt;

  printf("%lld\n", ans);

  return 0;
}