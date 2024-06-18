// file: Tiles.h
#ifndef __TILE__
#define __TILE__

typedef signed char s4int;
typedef signed short int s8int;
typedef signed int s16int;
typedef signed long int s32int;
typedef signed long long int s64int;

typedef unsigned char u4int;
typedef unsigned short int u8int;
typedef unsigned int u16int;
typedef u16int uint;
typedef unsigned long int u32int;
typedef unsigned long long int u64int;

typedef enum tilec_e {
	BLK,RED,GRN,YEL,BLU,MAG,CYN,WHT,
	BBLK,BRED,BGRN,BYEL,BBLU,BMAG,BCYN,BWHT,
	UBLK,URED,UGRN,UYEL,UBLU,UMAG,UCYN,UWHT,
	BLKB,REDB,GRNB,YELB,BLUB,MAGB,CYNB,WHTB,
	BLKHB,REDHB,GRNHB,YELHB,BLUHB,MAGHB,CYNHB,WHTHB,
	HBLK,HRED,HGRN,HYEL,HBLU,HMAG,HCYN,HWHT,
	BHBLK,BHRED,BHGRN,BHYEL,BHBLU,BHMAG,BHCYN,BHWHT,
	reset,CRESET,COLOR_RESET,
	WHTTC,BLKTC,BWHTTC,BBLKTC,UWHTTC,UBLKTC,WHTBTC,
	BLKBTC,REDBTC,GRNBTC,YELBTC,BLUBTC,MAGBTC,CYNBTC,
	WHTHBTC,LBLUBTC,GRYBTC,ORNBTC,
} tile_c;

typedef struct tile_s {
	s8int	value;
	u8int	clicked:	1;
	u8int	flaged:		1;
	tile_c	b_color;
	tile_c	t_color;
} tile_t;

int ifbomb(tile_t*);
int checkNeighbors(int,int,int lx,int ly,tile_t[ly][lx]);
int bCheckNeighbors(int,int,int lx, int ly, tile_t BRD[ly][lx]);
void checkALLNeighbors(int lx,int ly,tile_t[ly][lx]);
void bcheckALLNeighbors(int lx,int ly,tile_t BRD[ly][lx]);
int checkVictory(int lx,int ly,tile_t BRD[ly][lx]);
int mcheckVictory(int lx,int ly,tile_t BRD[ly][lx]);

// table vars
uint	y;
uint	x;

// option vars
uint	mr;
uint	dol;
uint	sdu;
uint	hdn;
uint	esd;

// selection vars
uint	sx;
uint	sy;
tile_t*	stile;

#endif