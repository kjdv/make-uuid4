#include <uuid4.h>
#include <iostream>
#include <cxxopts.hpp>

using namespace uuid4;
using namespace std;

int main(int argc, char **argv) {
  cxxopts::Options options("Uuid4", "Tiny utility to generate uuid4 style guids");

  options.add_options()
    ("h,help", "Print usage")
    ("n,number", "number of guids to generate", cxxopts::value<unsigned>()->default_value("1"))
    ("s,seperator", "seperator to use when printing (default: \\n)", cxxopts::value<string>());

  auto args = options.parse(argc, argv);

  if (args.count("help")) {
      cout << options.help() << '\n';
      return 0;
  }

  auto sep = args.count("seperator") ? args["seperator"].as<string>() : "\n";

  for (unsigned i = 0; i < args["number"].as<unsigned>(); ++i) {
      cout << make_uuid4() << sep;
  }

  return 0;
}
