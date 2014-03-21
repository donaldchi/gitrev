#include <iostream>
#include <fstream>
#include <random>
#include <string>
#include <vector>

#include <cmath>
#include <cstdlib>

using namespace std;

class Log1 { public: int i; double average; };
class Log2 { public: int i; double average; };

int main(int argc, char **argv, char **envp) {
  const char *x = getenv("PROJECT_REV");
  string project_rev = x == NULL ? string() : string(x);

  std::mt19937 rand_mt;

  vector<Log1> log1;
  vector<Log2> log2;

  double sum1 = 0, sum2 = 0.0;
  for (int i = 1; i <= 10000; i++) {
    int r = rand_mt() % 10000;
    sum1 += r;
    sum2 += log(r);
    log1.push_back({ i, sum1/i });
    log2.push_back({ i, exp(sum2/i) });
  }

  ofstream csv1, csv2;
  csv1.open(project_rev + "/average1.csv");
  for (auto iter1 = log1.begin(); iter1 != log1.end(); ++iter1) {
    Log1 entry1 = *iter1;
    csv1 << entry1.i << ", " << entry1.average << endl;
  }
  csv1.close();
  csv2.open(project_rev + "/average2.csv");
  for (auto iter2 = log2.begin(); iter2 != log2.end(); ++iter2) {
    Log2 entry2 = *iter2;
    csv2 << entry2.i << ", " << entry2.average << endl;
  }
  csv2.close();
}
