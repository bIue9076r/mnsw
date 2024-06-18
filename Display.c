// file: Display.c
#ifndef __DISPLAY_C__
#define __DISPLAY_C__

static const char* color(tile_c c){
	return colors[c];
}

void colorTestRBGK(void){
	printf("REGULAR BACKGROUNDS:\n\n");
	printf(_BLKB "    \n" _reset);printf(_BLKB "    \n" _reset);
	printf(_BLKB "    \n" _reset);printf(_BLKB "    \n" _reset);
	printf("\n");
	
	printf(_REDB "    \n" _reset);printf(_REDB "    \n" _reset);
	printf(_REDB "    \n" _reset);printf(_REDB "    \n" _reset);
	printf("\n");
	
	printf(_GRNB "    \n" _reset);printf(_GRNB "    \n" _reset);
	printf(_GRNB "    \n" _reset);printf(_GRNB "    \n" _reset);
	printf("\n");
	
	printf(_YELB "    \n" _reset);printf(_YELB "    \n" _reset);
	printf(_YELB "    \n" _reset);printf(_YELB "    \n" _reset);
	printf("\n");
	
	printf(_BLUB "    \n" _reset);printf(_BLUB "    \n" _reset);
	printf(_BLUB "    \n" _reset);printf(_BLUB "    \n" _reset);
	printf("\n");
	
	printf(_MAGB "    \n" _reset);printf(_MAGB "    \n" _reset);
	printf(_MAGB "    \n" _reset);printf(_MAGB "    \n" _reset);
	printf("\n");
	
	printf(_CYNB "    \n" _reset);printf(_CYNB "    \n" _reset);
	printf(_CYNB "    \n" _reset);printf(_CYNB "    \n" _reset);
	printf("\n");
	
	printf(_WHTB "    \n" _reset);printf(_WHTB "    \n" _reset);
	printf(_WHTB "    \n" _reset);printf(_WHTB "    \n" _reset);
	printf("\n");
}

void colorTestHBGK(void){
	printf("HIGH INTENSITY BACKGROUNDS:\n\n");
	printf(_BLKHB "    \n" _reset);printf(_BLKHB "    \n" _reset);
	printf(_BLKHB "    \n" _reset);printf(_BLKHB "    \n" _reset);
	printf("\n");
	
	printf(_REDHB "    \n" _reset);printf(_REDHB "    \n" _reset);
	printf(_REDHB "    \n" _reset);printf(_REDHB "    \n" _reset);
	printf("\n");
	
	printf(_GRNHB "    \n" _reset);printf(_GRNHB "    \n" _reset);
	printf(_GRNHB "    \n" _reset);printf(_GRNHB "    \n" _reset);
	printf("\n");
	
	printf(_YELHB "    \n" _reset);printf(_YELHB "    \n" _reset);
	printf(_YELHB "    \n" _reset);printf(_YELHB "    \n" _reset);
	printf("\n");
	
	printf(_BLUHB "    \n" _reset);printf(_BLUHB "    \n" _reset);
	printf(_BLUHB "    \n" _reset);printf(_BLUHB "    \n" _reset);
	printf("\n");
	
	printf(_MAGHB "    \n" _reset);printf(_MAGHB "    \n" _reset);
	printf(_MAGHB "    \n" _reset);printf(_MAGHB "    \n" _reset);
	printf("\n");
	
	printf(_CYNHB "    \n" _reset);printf(_CYNHB "    \n" _reset);
	printf(_CYNHB "    \n" _reset);printf(_CYNHB "    \n" _reset);
	printf("\n");
	
	printf(_WHTHB "    \n" _reset);printf(_WHTHB "    \n" _reset);
	printf(_WHTHB "    \n" _reset);printf(_WHTHB "    \n" _reset);
	printf("\n");
}

void colorTest(void){
	colorTestRBGK();
	colorTestHBGK();
}

void changeColor(tile_t* tile,int light){
	int tv = tile->value;
	int tc = tile->clicked;
	int tf = tile->flaged;
	if(tc == 1 || tf == 1){
		if(light > 0){
			if(tv == -1){ tile->b_color = REDHB; tile->t_color = WHTTC;}
			if(tv == 0 ){ tile->b_color = WHTBTC; tile->t_color = BLKTC;}
			if(tv == 1 ){ tile->b_color = MAGBTC; tile->t_color = BLKTC;}
			if(tv == 2 ){ tile->b_color = GRNBTC; tile->t_color = BLKTC;}
			if(tv == 3 ){ tile->b_color = ORNBTC; tile->t_color = BLKTC;}
			if(tv == 4 ){ tile->b_color = REDBTC; tile->t_color = BLKTC;}
			if(tv == 5 ){ tile->b_color = BLUBTC; tile->t_color = BLKTC;}
			if(tv == 6 ){ tile->b_color = LBLUBTC; tile->t_color = BLKTC;}
			if(tv == 7 ){ tile->b_color = CYNBTC; tile->t_color = BLKTC;}
			if(tv == 8 ){ tile->b_color = GRYBTC; tile->t_color = BLKTC;}
		}else{
			if(tv == -1){ tile->b_color = REDHB; tile->t_color = WHTTC;}
			if(tv == 0 ){ tile->b_color = GRYBTC; tile->t_color = BLKTC;}
			if(tv == 1 ){ tile->b_color = CYNBTC; tile->t_color = BLKTC;}
			if(tv == 2 ){ tile->b_color = LBLUBTC; tile->t_color = BLKTC;}
			if(tv == 3 ){ tile->b_color = BLUBTC; tile->t_color = BLKTC;}
			if(tv == 4 ){ tile->b_color = REDBTC; tile->t_color = BLKTC;}
			if(tv == 5 ){ tile->b_color = ORNBTC; tile->t_color = BLKTC;}
			if(tv == 6 ){ tile->b_color = GRNBTC; tile->t_color = BLKTC;}
			if(tv == 7 ){ tile->b_color = MAGBTC; tile->t_color = BLKTC;}
			if(tv == 8 ){ tile->b_color = WHTBTC; tile->t_color = BLKTC;}
		}
	} else {
		tile->b_color = CYNB; tile->t_color = WHT;
	}
}

void __tileDraw(tile_t* tile){
	printf("%s%s",color(tile->t_color),color(tile->b_color));
	printf("     \n");
	printf("  %d  \n",tile->value);
	printf("     \n");
	printf("%s",color(reset));
}

void lineDraw(tile_t* tiles,int len,int dark){
	for (int i = 0; i < len; i++) {
		changeColor(&tiles[i],dark);
	}
	for (int i = 0; i < len; i++) {
		printf("%s%s",color(tiles[i].t_color),color(tiles[i].b_color));
		printf("     ");
	}
	printf("%s\n",color(reset));
	for (int i = 0; i < len; i++) {
		printf("%s%s",color(tiles[i].t_color),color(tiles[i].b_color));
		
		if(!tiles[i].flaged == 1){
			if(tiles[i].clicked == 1){
				if(tiles[i].value > -1 && tiles[i].value < 10){
				if(tiles[i].value == 0){
					printf("     ");
				}else{
					printf("  %d  ",tiles[i].value);
				}
				}else{
				printf(" %d  ",tiles[i].value);
			}
			}else{
				printf("  x  ");
			}
		}else{
			printf("  F  ");
		}
		
	}
	printf("%s\n",color(reset));
	for (int i = 0; i < len; i++) {
		printf("%s%s",color(tiles[i].t_color),color(tiles[i].b_color));
		printf("     ");
	}
	printf("%s\n",color(reset));
}

void drawBoard(int lx,int ly, tile_t BRD[ly][lx]){
	for (int i = 0; i < ly; i++) {
		lineDraw(BRD[i],lx,dol); // draw the Board
	}
}

void resetBoard(int lx, int ly, tile_t BRD[ly][lx]){
	for (int i = 0; i < ly; i++) {
		for (int j = 0; j < lx; j++) {
			BRD[i][j] = (tile_t){0,0,0,CYNB,WHT};
		}
	}
}

void showBoard(int lx, int ly, tile_t BRD[ly][lx]){
	for (int i = 0; i < ly; i++) {
		for (int j = 0; j < lx; j++) {
			BRD[i][j].clicked = 1;
		}
	}
}

void plantBombs(int rv,int su,int lx, int ly, tile_t BRD[ly][lx]){
	static int trys = 1;
	for (int i = 0; i < ly; i++) {
		for (int j = 0; j < lx; j++) {
			if(rand_i() % rv == ((rand_i() % 2) == 0)){
				// if ran num % rv = 1 or 0
				trys += ((rand_i() % 2) == 0);
				if( trys > su ){ randseed(clock()); trys = 0; }
				BRD[i][j] = (tile_t){-1,0,0,CYNB,WHT};
			}
		}
	}
}

tile_t* selectTile(int tx,int ty,int lx, int ly, tile_t BRD[ly][lx]){
	tx = tx - 1;
	ty = ty - 1;
	if((tx < lx && tx > -1) && (ty < ly && ty > -1)){
		return &BRD[ty][tx];
	} else {
		return NULL;
	}
}

void revealTile(tile_t* tile){
	tile->clicked = 1;
}

#endif