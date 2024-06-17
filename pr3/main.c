#include <8051.h> 

void move_left() {
	P0 = 0x04;
	P2 = 0x1;  
	P2 = 0x0;
}

void move_right() {
	P0 = 0x06;
	P2 = 0x1;  
	P2 = 0x0;
}

void cursor_to_line1_end() {
	P0 = 0x90;
	P2 = 0x1;  
	P2 = 0x0;
}

void cursor_to_line2_start() {
	P0 = 0xC0;  
	P2 = 0x1;  
	P2 = 0x0;
}

void print_char(char ch) {
	P0 = ch;
	P2 = 0x3;
	P2 = 0x2;
}

void move_cursor(unsigned int position) {
	P0 = position; 
	P2 = 0x1; 
	P2 = 0x0;
}

void print(const char* str, unsigned int size, unsigned int position, unsigned int absolute_pos) {
	unsigned int i, j;

	move_cursor(0xC0 + position); 

	if (absolute_pos >= size) {
    	for (i=size; i>0; i--) {
      		print_char(str[i-1]);
      		if (size - position == i) {
        		move_cursor(0xCF);
      		}
    	}
  	}
	else {
		for (j = size; j > 0; j--) {
			if (absolute_pos >= size - j) {
				print_char(str[j-1]);
			}
		}
	}
}
 
void main() {  
	unsigned int i,j=0;  
	const char *str = "\xB1\xB4\xA1\xAC\xA6\xA2"; 
	const char *str2 = "  \xA0\xAE\xA4\xB1\xA5\xAA";
	unsigned int len1 = 0;
	unsigned int len2 = 0;
	for (len1=0; str[len1] != '\0'; ++len1);
	for (len2=0; str2[len2] != '\0'; ++len2);
	
	move_cursor(0x38);
	cursor_to_line1_end();
	move_left();

	for(i=len1;i>0;i--){  
		print_char(str[i-1]);
	} 
 
	cursor_to_line2_start();

	while(1) {
		for (i=0; i<16; i++) {
			if (i % 2 == 0) {
				print(str2, len2, i, j);
			}
			j++;
		}
	}
}