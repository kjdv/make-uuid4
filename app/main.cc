#include <cxxopts.hpp>
#include <iostream>
#include <uuid4.h>

using namespace uuid4;
using namespace std;

int main(int argc, char** argv)
{
  cxxopts::Options options("make-uuid4", "Tiny utility to generate uuid4 style guids");

  options.add_options()
          ("h,help", "Print usage")("n,number", "number of guids to generate", cxxopts::value<unsigned>()->default_value("1"));

  auto args = options.parse(argc, argv);

  if(args.count("help"))
  {
    cout << options.help() << '\n';
    return 0;
  }

  for(unsigned i = 0; i < args["number"].as<unsigned>(); ++i)
  {
    cout << make_uuid4() << '\n';
  }

  return 0;
}
