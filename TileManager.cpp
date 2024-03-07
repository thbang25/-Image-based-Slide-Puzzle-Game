/** Thabang  sambo
 * tilemanager class 
 * 06/04/2024
 * this class will generally be used to swap the tiles around and check if a tile swap is valid
 **/


#include "TileManager.h"

TileManager::TileManager(){}

// Function to swap tiles
void TileManager::swapTiles(std::vector<std::vector<std::vector<int>>>& tiles, int BlackOutRow, int BlackOutColumn, int checkPointRow, int checkPointCol) {
    std::swap(tiles[BlackOutRow][BlackOutColumn], tiles[checkPointRow][checkPointCol]);
}

// Function to generate a new tiled image after a single tile move
void TileManager::NewImageState(std::vector<std::vector<std::vector<int>>>& tiles, int& BlackOutRow, int& BlackOutColumn) {
    // Find adjacent tiles to the empty slot
    std::vector<std::pair<int, int>> validMoves;

    if (BlackOutRow > 0) {
        validMoves.emplace_back(BlackOutRow - 1, BlackOutColumn); // Up
    }
    if (BlackOutRow < 2) {
        validMoves.emplace_back(BlackOutRow + 1, BlackOutColumn); // Down
    }
    if (BlackOutColumn > 0) {
        validMoves.emplace_back(BlackOutRow, BlackOutColumn - 1); // Left
    }
    if (BlackOutColumn < 2) {
        validMoves.emplace_back(BlackOutRow, BlackOutColumn + 1); // Right
    }


    // Randomly choose an adjacent tile to swap with the empty slot
    if (!validMoves.empty()) {
        std::srand(static_cast<unsigned int>(std::time(0))); // Seed for random number generation
        int randomIndex = std::rand() % validMoves.size();

        int checkPointRow = validMoves[randomIndex].first;
        int checkPointCol = validMoves[randomIndex].second;

        swapTiles(tiles, BlackOutRow, BlackOutColumn, checkPointRow, checkPointCol);

        // Update the position of the empty slot
        BlackOutRow = checkPointRow;
        BlackOutColumn = checkPointCol;} //try to keep track of the position of that blacked subimage
		
}//end fuction