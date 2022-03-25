#define FMT_HEADER_ONLY
#include "fmt/format.h"

using namespace std;

//          foreground background
// black        30         40
// red          31         41
// green        32         42
// yellow       33         43
// blue         34         44
// magenta      35         45
// cyan         36         46
// white        37         47

// reset             0  (everything back to normal)
// bold/bright       1  (often a brighter shade of the same colour)
// underline         4
// inverse           7  (swap foreground and background colours)
// bold/bright off  21
// underline off    24
// inverse off      27

string red(string msg) {
  return fmt::format("\033[1;31m{}\033[0m", msg);
}

string green(string msg) {
  return fmt::format("\033[1;32m{}\033[0m", msg);
}

string yellow(string msg) {
  return fmt::format("\033[1;33m{}\033[0m", msg);
}

string blue(string msg) {
  return fmt::format("\033[1;34m{}\033[0m", msg);
}

string magenta(string msg) {
  return fmt::format("\033[1;35m{}\033[0m", msg);
}

string cyan(string msg) {
  return fmt::format("\033[1;36m{}\033[0m", msg);
}