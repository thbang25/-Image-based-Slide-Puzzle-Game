/** Thabang  sambo
 * puzzle file receive arguments and connect class input 
 * 06/04/2024
 * main driver 
 **/

#include "Tile.h"
#include "TileManager.h"

#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <cstdlib>
#include <ctime>


int main(int argc, char* argv[]) {
	
	//accept command line arguments
    if (argc < 4) {
        std::cerr << "Usage: " << argv[0] << " <odd_number> <image_filename.pgm> <num_moves>" << std::endl;
        return 1;
    }
    //odd number
    int odd_number = std::atoi(argv[1]);

//check if odd
    if(odd_number%2 == 0){
        std::cerr << "must be an odd number" << std::endl;
        return 1;
    }
    
//proceed if the number is odd
    else{

//get the width and the height of the pixel
    int PixelWidth, PixelHeight;

    Tile Tile; //an object of the tile class
    TileManager TileManager; //an object of the tilemanager class
     
	std::string imagename = argv[2]; //get the name of the file
    std::string filepath = "./data/"+imagename; //file path to get the tile in a folder

//load the image, height and width variable into pixels vector	
    std::vector<std::vector<int>> pixels = Tile.loadImage(filepath, PixelWidth, PixelHeight);

 //load the pixels and parameters into the tiles and the odd number which will represent the number of grids
    std::vector<std::vector<std::vector<int>>> tiles = Tile.createSubImages(pixels, PixelWidth, PixelHeight, odd_number);

 // Initialize empty slot in the bottom right corner
    int BlackOutRow = odd_number - 1; // substract 1 to reference grid at the corner
    int BlackOutColumn =  odd_number - 1; //substract 1 to reference grid at the corner
    tiles[BlackOutRow][BlackOutColumn].assign(tiles[0][0].size(), 0);

// Specify the number of moves to compute
    int numMoves = std::atoi(argv[3]);

 // Generate and write new images after each move
    for (int move = 1; move <= numMoves; ++move) {
		
// Generate a new tiled image after a single tile move
    TileManager.NewImageState(tiles, BlackOutRow, BlackOutColumn);

// Reconstruct the image from the modified tiles
        std::vector<std::vector<int>> newPixels(PixelHeight, std::vector<int>(PixelWidth, 0));
		
		
//for loop to reconstruct image after tiles swap
        for (int i = 0; i < odd_number; ++i) {
            for (int j = 0; j < odd_number; ++j) {
                for (int y = 0; y < tiles[i][j].size(); ++y) {
                    int originalX = j * (PixelWidth / odd_number) + (y % (PixelWidth / odd_number));
                    int originalY = i * (PixelHeight / odd_number) + (y / (PixelWidth / odd_number));
                    newPixels[originalY][originalX] = tiles[i][j][y];
                }
            }
        }

// Write the new image to a file
        std::ostringstream  outputImagName;
        outputImagName << "myimage" << "-" << move << ".pgm";
        Tile.LoadNewPixels( outputImagName.str(), newPixels, PixelWidth, PixelHeight);} //forloop
	 
    }//else
		
    return 0;
}
