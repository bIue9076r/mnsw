// file: Tiles.c
#ifndef __TILE_C__
#define __TILE_C__

static const char* colors[] = {
	_BLK,_RED,_GRN,_YEL,_BLU,_MAG,_CYN,_WHT,
	_BBLK,_BRED,_BGRN,_BYEL,_BBLU,_BMAG,_BCYN,_BWHT,
	_UBLK,_URED,_UGRN,_UYEL,_UBLU,_UMAG,_UCYN,_UWHT,
	_BLKB,_REDB,_GRNB,_YELB,_BLUB,_MAGB,_CYNB,_WHTB,
	_BLKHB,_REDHB,_GRNHB,_YELHB,_BLUHB,_MAGHB,_CYNHB,_WHTHB,
	_HBLK,_HRED,_HGRN,_HYEL,_HBLU,_HMAG,_HCYN,_HWHT,
	_BHBLK,_BHRED,_BHGRN,_BHYEL,_BHBLU,_BHMAG,_BHCYN,_BHWHT,
	_reset,_CRESET,_COLOR_RESET,_WHTTC,_BLKTC,_BWHTTC,_BBLKTC,
	_UWHTTC,_UBLKTC,_WHTBTC,_BLKBTC,_REDBTC,_GRNBTC,_YELBTC,_BLUBTC,
	_MAGBTC,_CYNBTC,_WHTHBTC,_LBLUBTC,_GRYBTC,_ORNBTC,
};

int ifbomb(tile_t* tile){
	if(tile->value < 0){ return 1; }
	return 0;
}

int checkNeighbors(int tx,int ty,int lx, int ly, tile_t BRD[ly][lx]){
	int val = 0;
	int rtx = tx + 1;
	int ltx = tx - 1;
	int dty = ty + 1;
	int uty = ty - 1;
	
	if(ifbomb(&BRD[ty][tx]) == 0){
		if(dty < ly){ if(ifbomb(&BRD[dty][tx])){ val++; }}
		if(uty > -1){ if(ifbomb(&BRD[uty][tx])){ val++; }}
		if(rtx < lx){
			if(ifbomb(&BRD[ty][rtx])){ val++; }
			if(dty < ly){ if(ifbomb(&BRD[dty][rtx])){ val++; }}
			if(uty > -1){ if(ifbomb(&BRD[uty][rtx])){ val++; }}
		}
		if(ltx > -1){
			if(ifbomb(&BRD[ty][ltx])){ val++; }
			if(dty < ly){ if(ifbomb(&BRD[dty][ltx])){ val++; }}
			if(uty > -1){ if(ifbomb(&BRD[uty][ltx])){ val++; }}
		}
	}else{
		BRD[ty][tx].value = -1;
		return -1;
	}
	
	BRD[ty][tx].value = val;
	return val;
}

int bCheckNeighbors(int tx,int ty,int lx, int ly, tile_t BRD[ly][lx]){
	int val = 0;
	int rtx = tx + 1;
	int ltx = tx - 1;
	int dty = ty + 1;
	int uty = ty - 1;
	
	if(dty < ly){ if(!ifbomb(&BRD[dty][tx])){ if(BRD[dty][tx].clicked == 0){ val++; }}}
	if(uty > -1){ if(!ifbomb(&BRD[uty][tx])){ if(BRD[uty][tx].clicked == 0){ val++; }}}
	if(rtx < lx){
		if(!ifbomb(&BRD[ty][rtx])){ if(BRD[ty][rtx].clicked == 0){ val++; }}
		if(dty < ly){ if(!ifbomb(&BRD[dty][rtx])){ if(BRD[dty][rtx].clicked == 0){ val++; }}}
		if(uty > -1){ if(!ifbomb(&BRD[uty][rtx])){ if(BRD[uty][rtx].clicked == 0){ val++; }}}
	}
	if(ltx > -1){
		if(!ifbomb(&BRD[ty][ltx])){ if(BRD[ty][ltx].clicked == 0){ val++; }}
		if(dty < ly){ if(!ifbomb(&BRD[dty][ltx])){ if(BRD[dty][ltx].clicked == 0){ val++; }}}
		if(uty > -1){ if(!ifbomb(&BRD[uty][ltx])){ if(BRD[uty][ltx].clicked == 0){ val++; }}}
	}
	
	BRD[ty][tx].flaged = (!val);
	return (!val);
}

void checkALLNeighbors(int lx,int ly,tile_t BRD[ly][lx]){
	for (int i = 0; i < ly; i++) {
		for (int j = 0; j < lx; j++) {
			checkNeighbors(j,i,lx,ly,BRD);
		}
	}
}

void bcheckALLNeighbors(int lx,int ly,tile_t BRD[ly][lx]){
	for (int i = 0; i < ly; i++) {
		for (int j = 0; j < lx; j++) {
			if(ifbomb(&BRD[i][j])){
				bCheckNeighbors(j,i,lx,ly,BRD);
			}
		}
	}
}

int checkVictory(int lx,int ly,tile_t BRD[ly][lx]){
	int fcheck = 0;
	for(int i = 0; i < ly; i++){
		for(int j = 0; j < lx; j++){
			if(ifbomb(&BRD[j][i])){
				if(!BRD[j][i].flaged == 1){
					fcheck++;
				}
			}
		}	
	}
	
	return (fcheck < 1);
}

int mcheckVictory(int lx,int ly,tile_t BRD[ly][lx]){
	int check = 0;
	for(int i = 0; i < ly; i++){
		for(int j = 0; j < lx; j++){
			if(!ifbomb(&BRD[j][i])){
				if(!BRD[j][i].clicked == 1){
					check++;
				}
			}
		}
	}
	
	return (check < 1);
}

#endif