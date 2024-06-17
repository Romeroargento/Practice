#include <8051.h> 
void delay() {
	int j;
	for(j=0;j<75;j++) 
		continue;
}
void main() {
	unsigned char i;
	unsigned char massiv [11]= {0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90,0xFF};
	P2=0xFF;
	P3=0x00;
	while(1) {
		if (P30 == 1) {
			for(i=0;i<10;i++){
				P2=massiv[i]; 
				delay();
				P2=0xF9;
				delay();
			}
		}
	} 
} 