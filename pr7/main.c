#include <8052.h>
#include <htc.h>
 
int flag;

void delay(unsigned int cnt) {
    while (cnt--);
}

void imp(unsigned int cnt) {
	do { 
    	if (cnt != 0){cnt--; P1 = 0;}
    	else {P1 = 255;}
	} while(TF2 == 0);

	TF2 = 0; 
	if(P36 == 1){ flag = 1;}
	if(P37 == 1){ flag = 0;}
}

void sawtooth() {
	int i;
	for (i = 0; i <= 245; i++) {
		P1 = i; 
		delay(10); // Delay to control period
	}
    P1 = 0;
	if(P36 == 1){ flag = 1;}
    if(P37 == 1){ flag = 0;}
}

void main() {
  flag = 0;

  P1 = 0xFE; 
  //65536 - (15MHz/12) * 0.03 = 6D84h
  RCAP2H = 0x6D; 
  RCAP2L = 0x84; 
 
  T2CON &= 0xFC;
  ET2 = 1; 
  EA = 1; 
  T2CON |= 0x4; 

  while(1) {
    if (flag == 1){ imp(1320);}
    else sawtooth();

    if(P36 == 1){ flag = 1;}
    if(P37 == 1){ flag = 0;}
  }
}