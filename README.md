# -Image-based-Slide-Puzzle-Game

**class Tile()** encapsulates individual tile and image states.

**The following functions below are from the class**

loadImage(): load image is declared a public function in the tile class, it loads a PGM file and checks whether the file is the right format extracts the pixel values, and stores them in a vector, the vector contains the height and the width of the pixel. 

createSubImages(): with the pixels now stored in a vector we now need a function, to create sub-images that will present a tile, the tiles are created using an odd_number inserted by the user, and the size of the tiles is determined by that and split them up accordingly store them in a vector of vectors to create a dynamic storage system.

LoadPixels(): is used to write the newly generated image, after each move is complete, load pixels is used to write the new pixels into the new image state and write out the program to allow the user to view changes after the swapping

SummaryImage(): I have created an image summary that displays the board state after each move. The game state images are laid out in a way that makes the summary image as square as possible. From left to right, the game state images should are ordered from Image 1 to Image N.

**class TileManager()** is responsible for swapping the tiles and checking whether the random move chosen is a valid move or not, the blacked tile can only move if it's adjacent to a tile.

**The following functions below are from the class**

SwapTiles(): To complete a tile-swapping puzzle game, we use a grid that contains several tiles. The blacked-out tile is used as a reference point to swap with the surrounding tiles on the grid. After each swap, we keep track of the new position of the blacked-out tile and can consistently keep track of it. We can perform swaps until we run out of moves.

NewImageState(): We first check if the tile chosen to swap with the black tile is a valid option. If it is, we confirm the swap. The tile chosen to perform the swap is randomly selected and assigned once its position is confirmed to be valid.

**Main(): Puzzle.cpp**

The program accepts input from the terminal, an odd number, a file, and the number of moves. It creates an object of the Tile and TileManager classes, which allows the program to pass on arguments to the functions. Then, it performs a loop operation to reconstruct the image after the tiles are swapped. Finally, the program loads the new image to be written.
