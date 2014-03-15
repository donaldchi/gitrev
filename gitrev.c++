#include <cstdlib>
#include <iostream>
#include <fstream>
#include <random>
#include <string>
#include <vector>

using namespace std;

class Log {
  public:
  int a;
  double b;
};

int main(int argc, char **argv, char **envp) {
  const char *x = getenv("PROJECT_REV");
  string project_rev = x == NULL ? string() : string(x);

  std::mt19937 rand_mt;

  vector<Log> log;

  double sum = 0;
  for (int i = 1; i <= 10000; i++) {
    sum += rand_mt() % 10000;
    log.push_back({ i, sum/i });
  }

  ofstream out_csv;
  out_csv.open(project_rev + ".csv");
  for (auto iter = log.begin(); iter != log.end(); ++iter) {
    Log entry = *iter;
    out_csv << entry.a << ", " << entry.b << endl;
  }
}
