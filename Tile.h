#ifndef TILE_H
#define TILE_H

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

class Tile{
    public:

    Tile();
    std::vector<std::vector<int>> loadImage(const std::string& filename, int& PixelWidth, int& PixelHeight);//read image
    std::vector<std::vector<std::vector<int>>> createSubImages(const std::vector<std::vector<int>>& pixels, int PixelWidth, int PixelHeight, int odd_number); //create sub images
	void LoadNewPixels(const std::string& filename, const std::vector<std::vector<int>>& pixels, int PixelWidth, int PixelHeight);//write image
    
};


#endif