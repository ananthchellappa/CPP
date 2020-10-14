#include <string>
#include <vector>
#include <regex>  
#include <filesystem>

using std::stof;
using std::string;
using std::vector;

namespace fs = std::filesystem;

std::string target_dir = "/proc";

vector<int> Pids() {
  vector<int> pids;
  std::regex rgx ("^\\d+$"); // only digits
  std::smatch match;
  for( auto& p: fs::directory_iterator( target_dir ) ) {
    string file( p.path().filename() );
    if ( std::regex_search( file, match, rgx ) ) {
      int pid = stoi( file );
      pids.push_back(pid);
    }
  }
  return pids;
}
