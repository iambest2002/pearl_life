

#include <string>
#include <vector>

#include "move_change_simulate.h"

using namespace std;
using namespace pearl::algorithm::array_and_string;


int MoveChangeSimulate::titleToNumber(string columnTitle) {
    int sum = 0;
    for(int i =0; i < columnTitle.size(); i++) {
      sum = sum * 26;
      sum = sum + (int(columnTitle[i] - 'A') + 1);
    }
    return sum;
}