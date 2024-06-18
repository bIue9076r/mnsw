// file: Display.h
#ifndef __DISPLAY__
#define __DISPLAY__

static const char* color(tile_c);

void colorTestRBGK(void);
void colorTestHBGK(void);
void colorTest(void);

void changeColor(tile_t*,int);
void __tileDraw(tile_t*);
void lineDraw(tile_t*,int,int);
void drawBoard(int lx,int ly,tile_t BRD[ly][lx]);

void resetBoard(int lx,int ly,tile_t[ly][lx]);
void showBoard(int lx,int ly,tile_t[ly][lx]);
void plantBombs(int,int,int lx,int ly,tile_t[ly][lx]);
tile_t* selectTile(int,int,int lx,int ly,tile_t BRD[ly][lx]);
void revealTile(tile_t*);

#endif