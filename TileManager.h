#ifndef TILEMANAGER_H
#define TILEMANAGER_H

#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <cstdlib>
#include <ctime>

class TileManager{
    public:
    TileManager();
    void swapTiles(std::vector<std::vector<std::vector<int>>>& tiles, int BlackOutRow, int BlackOutColumn, int checkPointRow, int checkPointCol); //swap tiles with
    void NewImageState(std::vector<std::vector<std::vector<int>>>& tiles, int& BlackOutRow, int& BlackOutColumn); //create new image state

};

#endif