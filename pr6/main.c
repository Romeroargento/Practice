#include <8051.h>
#include <string.h>

void tput(unsigned char c1) {
	SBUF = c1; 
	while(!TI); 
	TI = 0; 
}

void main() {
	int i;
	unsigned char src[] = {"Rublev Andrey"};

	int size = strlen(src);

	PCON = 0x80; //smod = 1
	TMOD = 0x20; // t/c1 mode 2
	TR1 = 1; //timer enable
	TH1 = 0xFF;
	for(i=0; i<size; i++) {
		ACC = src[i]; 
		SCON = 0x40; //port mode 1
		tput(src[i]);
	}
	while(1){} 
}