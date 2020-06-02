#include <uuid4.h>
#include <iostream>

using namespace uuid4;
using namespace std;

int main() {
  auto u = make_uuid4();
  cout << u << '\n';
  return 0;
}
