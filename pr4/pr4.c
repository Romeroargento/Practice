#include <8051.h>  

void msec(int x){ 
	while(x-- > 0) { 
		TH0 = (-10000)>>8;
		TL0=-10000;   
		TR0=1;         
		TF0=0;       
		TR0=0;      
	} 
} 

struct NOTE {
	unsigned char Number;
	unsigned int Time;
}; 

void main() {
	struct NOTE A[4] = {{0x82,4}, 
						{0x41,8},
						{0x14,3},
						{0x28,6}};
	int i; 
	TMOD=0x1;
	P1=0x0; 
	msec(2); 
	for(i=0;i<4;i++){ 
		P1 = A[i].Number;   
		msec(A[i].Time*40);   
	} 
	P1=0x0;
	while(1);
} 