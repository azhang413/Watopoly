#ifndef __INFO_H__
#define __INFO_H__
#include <vector>

class Player;

struct Info {
  int BuildingRow, BuildingCol, PlayerRow, PlayerCol;
  std::vector<char> players;
  int improvements;
};

#endif


