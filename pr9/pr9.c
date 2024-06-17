#include <8051.h>

void delay() { //250us
    TH0 = 0xFF; // Set Timer 0 high byte
    TL0 = 0x19; // Set Timer 0 low byte
    TF0 = 0;    // Clear Timer 0 overflow flag
    TR0 = 1;    // Start Timer 0
    while (!TF0); // Wait until Timer 0 overflows
}

void triangle_up(unsigned int lim) {
	int i;
	for (i = P2;i<lim;i+=11) {
		P2 = i;
	}
}

void triangle_down() {
	int j;
	for (j = 221;j>0;j-=17) {
		P2 = j;
	}
}

void main() {
	int j;
	TMOD = 0x01; // Timer 0 mode 1
	ET0 = 1; // Enable Timer 0 interrupt
	P2 = 0;
    while (1) {
        P2 = 64; 
		triangle_up((256/4)*3);
		P2 = 255;
        delay();
		//triangle_down();
		P2 = 238;
		for (j = 221;j>0;j-=17) {
			P2 = j;
		}
		P2 = 0;
        delay();
		P2 = 0;
		delay();
    }
}
