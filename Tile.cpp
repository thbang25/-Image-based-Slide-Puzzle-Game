/** Thabang  sambo
 * tile class 
 * 06/04/2024
 * this class will generally be used to read in the image and split it into subimages and then write out the image after transformation
 **/

#include "Tile.h"

Tile::Tile(){}

// Function to read PGM file and store pixel values
std::vector<std::vector<int>> Tile::loadImage(const std::string& filename, int& PixelWidth, int& PixelHeight) {
    std::ifstream file(filename, std::ios::binary);

    if (!file) {//check file
        std::cerr << "Error opening file: " << filename << std::endl;
        return {};
    }

    std::string line;
    std::getline(file, line); // Read the first line
	
	//checking the first lines
    if (line != "P5") {//use it as your magic string
        std::cerr << "Invalid PGM file format." << std::endl;
        return {};
    }

// Handle line comments
    while (std::getline(file, line) && line[0] == '#'); // the comment has a hash

//use srring stream to get the height and width
    std::istringstream headerStream(line);
    headerStream >> PixelWidth >> PixelHeight;

//get the mmaximum value of the pixels in the image
    int maxPixelValue;
    file >> maxPixelValue;

// Read pixels stored in the image and store it in a vector
    std::vector<std::vector<int>> pixels(PixelHeight, std::vector<int>(PixelWidth, 0));

    for (int i = 0; i < PixelHeight; ++i) {
        for (int j = 0; j < PixelWidth; ++j) {
            pixels[i][j] = file.get(); // Read pixel value
        }
    }

    return pixels; //return the array
}



// Function to split the image into a grid of tiles
std::vector<std::vector<std::vector<int>>> Tile::createSubImages(const std::vector<std::vector<int>>& pixels, int PixelWidth, int PixelHeight, int odd_number) {
    const int tileSizeX = PixelWidth / odd_number;
    const int tileSizeY = PixelHeight / odd_number;

    std::vector<std::vector<std::vector<int>>> tiles(odd_number, std::vector<std::vector<int>>(odd_number, std::vector<int>(tileSizeX * tileSizeY, 0)));

    for (int i = 0; i < odd_number; ++i) {
        for (int j = 0; j < odd_number; ++j) {
            for (int y = 0; y < tileSizeY; ++y) {
                for (int x = 0; x < tileSizeX; ++x) {
                    tiles[i][j][y * tileSizeX + x] = pixels[i * tileSizeY + y][j * tileSizeX + x];
                }
            }
        }
    }

    return tiles; //our grids
}


// Function to write pixels to a PGM file
void Tile::LoadNewPixels(const std::string& filename, const std::vector<std::vector<int>>& pixels, int PixelWidth, int PixelHeight) {
    std::ofstream file(filename, std::ios::binary);

//check if the file is being written
    if (!file) {
        std::cerr << "Error opening file for writing: " << filename << std::endl;
        return;
    }

    file << "P5\n" << PixelWidth << " " << PixelHeight << "\n255\n";

    for (int i = 0; i < PixelHeight; ++i) {
        for (int j = 0; j < PixelWidth; ++j) {
            file.put(pixels[i][j]);
        }
    }
//show the new name that the images have been written to
    std::cout << "Image written to: " << filename << std::endl;
}