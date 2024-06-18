#include <stdio.h>
#include <time.h>
#include "Colors.h"
#include "Random.h"
#include "Random.c"
#include "Tiles.h"
#include "Tiles.c"
#include "Display.h"
#include "Display.c"
#include "Input.h"
#include "Input.c"

int main(int argc,char** argv){
	// seed up global vars
	// random seed is current time
	int seed = clock();
	randseed(seed);
	// default moudlus check is 9
	// default mode is dark
	// default seed reset is 1
	mr = 9, dol = 0, sdu = 1, hdn = 0, esd = 0;
	
	// default y and x is 9
	y = x = 9;
	inputArgs(argc,argv,&x,&y,&mr,&dol,&sdu,&hdn,&esd);
	
	// init Board with dimentions y and x
	tile_t Board[y][x];
	resetBoard(x,y,Board);
	// plant bombs
	plantBombs(mr,sdu,x,y,Board);
	// check neighbors
	checkALLNeighbors(x,y,Board);
	
	DRAWSECTION:
	if(hdn){ showBoard(x,y,Board); } // show board for testing
	drawBoard(x,y,Board); // draw the Board
	
	// select Tile x,y
	printf("\nselect tile x,y:");
	scanf("%u,%u",&sx,&sy);
	// get tile
	stile = selectTile(sx,sy,x,y,Board);
	if(ifbomb(stile)){ // if tile is a bomb
		showBoard(x,y,Board); // show the board
		drawBoard(x,y,Board); // draw the Board
		printf("THATS A BOMB\n"); // thats a Bomb
		printf("GAME OVER\n");
		if(esd){ printf("endseed %d\n",rand_i());} // print endseed
		return 0; // no errors
	} else { // if tile is not a bomb
		revealTile(stile); // reveal the Tile
		bcheckALLNeighbors(x,y,Board); // check for surrounding bombs
		// if map clear
		if(checkVictory(x,y,Board) || mcheckVictory(x,y,Board)){
			showBoard(x,y,Board); // show the Board
			drawBoard(x,y,Board); // draw the Board
			printf("Congratulations\n"); // You win
			printf("YOU WIN\n");
			if(esd){ printf("endseed %d\n",rand_i());} // print endseed
		}else{ // if map not clear
			goto DRAWSECTION; // go back
		}
	}
	
	return 0; // no errors
}