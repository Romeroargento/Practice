#include <8051.h> 
void main() {
	int i;
	char xdata *ptr; 
	char test, nabor;
	nabor = 0xAA;
	ptr = (char xdata *) 0x300; 
	for(i=0; i<1024;i++) {
		*ptr=nabor; 
		test=*ptr; 
		if(test!=nabor) {
			P10 = 0;
			break; 
		}
	ptr++;
	}
	P11 = 0;
}
