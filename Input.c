// file: Input.c
#ifndef __INPUT_C__
#define __INPUT_C__

void help(void){
	printf("Usage:\n");
	printf("Tmine [options]:\n");
	printf("Game options:\n");
	printf("    -help:   shows this message\n");
	printf("    -easy:   sets game to easy\n");
	printf("    -ez:     shorter -easy\n");
	printf("    -medium: sets game to medium\n");
	printf("    -med:    shorter -medium\n");
	printf("    -hard:   sets game to hard\n\n");
	printf("Variable options:\n");
	printf("    -s: set random seed\n");
	printf("    -x: set width\n");
	printf("    -y: set height\n");
	printf("    -r: set chance var\n");
	printf("    -d: turn on dark mode\n");
	printf("    -l: turn on light mode\n");
	printf("    -t: seed refresh rate\n");
	printf("    -h: unhide Board\n");
	printf("    -e: show endseed\n\n");
}

int stl(char* in){
	int lenght = 0;
	for (int i = 0; in[i] != '\0' ; i++) { lenght++; }
	return lenght;
}

int sti(char* in){
	int value = 0;
	int sign = 1;
	if(in[0] == '-'){ sign = -1; }
	for (int i = 0; in[i] != '\0' ; i++) {
		if(in[i] > ('0' - 1) && in[i] < ('9' + 1) ){
			value = value * 10 + in[i] - '0';
		}
	}
	return value * sign;
}

uint stui(char* in){
	int value = 0;
	int sign = 1;
	if(in[0] == '-'){ sign = -1; }
	for (int i = 0; in[i] != '\0' ; i++) {
		if(in[i] > ('0' - 1) && in[i] < ('9' + 1) ){
			value = value * 10 + in[i] - '0';
		}
	}
	return value;
}

int stn(char* in){
	int value = 0;
	for (int i = 0; in[i] != '\0' ; i++) {
		value = value + (int) in[i];
	}
	return value;
}

int cmpstri(char* in1,char* in2){
	return (stn(in1) - stn(in2));
}

int cmpstr(char* in1,char* in2){
	return ( (stn(in1) - stn(in2)) == 0 );
}

void inputArgs(int ac,char** av,uint* tx,uint* ty,uint* mr,uint* dl,uint* su,uint* hn,uint* es){
	short int flags = 0; // 0000 0000 0000
	int pos[5];
	if(ac > 1){
		for (int i = 1; i < ac; i++) {
			if(cmpstr(av[i],"-s")){ // Random Seed
				flags = flags ^ 1; // 0000 0000 0001 2^0
				pos[0] = i;
			}
			if(cmpstr(av[i],"-x")){ // X lenght
				flags = flags ^ 2; // 0000 0000 0010 2^1
				pos[1] = i;
			}
			if(cmpstr(av[i],"-y")){ // Y lenght
				flags = flags ^ 4; // 0000 0000 0100 2^2
				pos[2] = i;
			}
			if(cmpstr(av[i],"-r")){ // Random Var
				flags = flags ^ 8; // 0000 0000 1000 2^3
				pos[3] = i;
			}
			if(cmpstr(av[i],"-d")){ // Dark Mode
				flags = flags ^ 16; // 0000 0001 0000 2^4
			}
			if(cmpstr(av[i],"-l")){ // Light Mode
				flags = flags ^ 32; // 0000 0010 0000 2^5
			}
			if(cmpstr(av[i],"-t")){ // randseed Refresh Rate
				flags = flags ^ 64; // 0000 0100 0000 2^6
				pos[4] = i;
			}
			if(cmpstr(av[i],"-h")){ // Board hidden
				flags = flags ^ 128; // 0000 1000 0000 2^7
			}
			if(cmpstr(av[i],"-e")){ // Show end seed
				flags = flags ^ 256; // 0001 0000 0000 2^8
			}
			
			if(cmpstr(av[i],"-easy") || cmpstr(av[i],"-ez")){ // Easy Setting
				// -x 5 -y 5 -r 7 -t 10
				flags = flags ^ 512; // 0010 0000 0000 2^9
			}
			if(cmpstr(av[i],"-medium") || cmpstr(av[i],"-med")){ // Medium Setting
				// -x 7 -y 7 -r 7 -t 5
				flags = flags ^ 1024; // 0100 0000 0000 2^10
			}
			if(cmpstr(av[i],"-hard")){ // Hard Setting
				// -x 10 -y 10 -r 4 -t 2
				flags = flags ^ 2048; // 1000 0000 0000 2^11
			}
			
			if(cmpstr(av[i],"-help")){ // Help
				help();
			}
		}
		
		if((flags & 1) > 0){
			randseed(sti(av[pos[0] + 1]));
		}
		if((flags & 2) > 0){
			(*ty) = (*tx) = stui(av[pos[1] + 1]);
		}
		if((flags & 4) > 0){
			(*tx) = (*ty) = stui(av[pos[2] + 1]);
		}
		if((flags & 8) > 0){
			(*mr) = stui(av[pos[3] + 1]);
		}
		if((flags & 16) > 0){
			(*dl) = 0;
		}
		if((flags & 32) > 0){
			(*dl) = 1;
		}
		if((flags & 64) > 0){
			(*su) = stui(av[pos[4] + 1]);
		}
		if((flags & 128) > 0){
			(*hn) = 1;
		}
		if((flags & 256) > 0){
			(*es) = 1;
		}
		if((flags & 512) > 0){
			(*ty) = (*tx) = 5;
			(*mr) = 7;
			(*su) = 10;
		}
		if((flags & 1024) > 0){
			(*ty) = (*tx) = 7;
			(*mr) = 7;
			(*su) = 5;
		}
		if((flags & 2048) > 0){
			(*ty) = (*tx) = 10;
			(*mr) = 4;
			(*su) = 2;
		}
	}
}

#endif