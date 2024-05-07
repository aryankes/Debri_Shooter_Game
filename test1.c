/*
    author_name= Aryan Kesharwani
    Roll_No= 2201CS19

    Declaration of Authorship
    This cpp file, gameplay.c, is part of the miniproject  phase2 of CS209/CS210 at the 
    department of Computer Science and Engg, IIT Patna . 
    
*/
#include <time.h>
	// for(int i=80;i<160;i++){
	// 	for(int j=80;j<160;j++){
	// 		write_pixel(i,j,0x0ff8);
	// 	}
	// }
	// while(1){}
// #include "address_map_arm.h"
/* set a single pixel on the screen at x,y
 * x in [0,319], y in [0,239], and colour in [0,65535]
 */
#define block_size 20
#define bul_size 5
#define max_shots 100
#define brick_size 10
#define PUSHBUTTONS ((volatile long *) 0xFF200050)
#define no_of_brick 32
#define HEX3_HEX0_BASE ((volatile long *)	0xFF200020)
#define HEX5_HEX4_BASE	((volatile long *) 0xFF200030)
#define LEDR_BASE             0xFF200000
volatile int * HEX3_HEX0_ptr = (int *) HEX3_HEX0_BASE;
volatile int * HEX5_HEX4_ptr = (int *) HEX5_HEX4_BASE;
int dis[240][320]={};
volatile int * KEYS = PUSHBUTTONS;
typedef struct{
  int first;
  int second;
}pair;
pair shots[max_shots];
int FLAG=0;
int counter1;
char seg7[10] =	{0b00111111, 0b00000110, 0b01011011, 0b01001111, 0b01100110, 
						 0b01101101, 0b01111101, 0b00000111, 0b01111111, 0b01100111};
void write_pixel(int x, int y, short colour) {
  volatile short *vga_addr=(volatile short*)(0x08000000 + (y<<10) + (x<<1));
  *vga_addr=colour;
}

void write_char(int x, int y, char c) {
  // VGA character buffer
  volatile char * character_buffer = (char *) (0x09000000 + (y<<7) + x);
  *character_buffer = c;
}
/* use write_pixel to set entire screen to black (does not clear the character buffer) */

void clearchar() {
  int x, y;
	char hw2='\0';
  for (x = 0; x < 80; x++) {
    for (y = 0; y < 60; y++) {
		write_char(x,y,hw2);
	}
  }

}
void clear_screen(){
	int x, y;
  for (x = 0; x < 320; x++) {
    for (y = 0; y < 240; y++) {
	  write_pixel(x,y,0x0000);
	}
  }
}
/* write a single character to the character buffer at x,y
 * x in [0,79], y in [0,59]
 */
int brick[no_of_brick]={};
void checker(){
	for(int i=0;i<240;i++){
		for(int j=0;j<320;j++){
			if(dis[i][j]==0){
				write_pixel(j,i,0x0000);
			}
			else{
				write_pixel(j,i,0xffff);
			}
		}
	}
	for(int i=0;i<350000;i++){
		
	}
}
void brick_generator(int z){
	int flag=1;
	for(int i=0;i<brick_size;i++){
		for(int j=0;j<brick_size;j++){
			if(dis[i][j+z*10]!=0){
				flag=0;break;
			}
		}
	}
	if(flag==1){
		brick[z]++;
		for(int i=0;i<brick_size;i++){
			for(int j=0;j<brick_size;j++){
				int x=j+z*10;
				dis[i][x]=2;
				write_pixel(x,i,0xff88);
			}
		}

	}
}
void brick_refresh(){
	for(int p=0;p<no_of_brick;p++){
		// if(brick[p]>0){
			int j=p*brick_size;
			for(int i=0;i<240;i++){
				if(dis[i][j]==2){
					for(int j=p*10;j<brick_size+p*10;j++){
						dis[i][j]=0;
						write_pixel(j,i,0x0000);
					}
					if(i==239){
						FLAG=0;
						brick[p]--;
					}
					i+=brick_size;
					for(int j=p*10;j<brick_size+p*10;j++){
						if(i<240&&dis[i][j]==0){
							dis[i][j]=2;
							write_pixel(j,i,0xff88);
						}
					}
					// i++;
				}
			}
		// }
	}
}
int offset=220;
int lset=0;
void fr(int arr[block_size][block_size]){
	for(int i=0;i<block_size;i++){
		if(i<block_size/2){
			int j=block_size/2-2-1;
			write_pixel((j+lset+320)%320,i+offset,0x0000);
			j=block_size/2+1;
			write_pixel((j+lset+320)%320,i+offset,0x0ff8);
		}
		else{
			int j=-1;
			write_pixel((j+lset+320)%320,i+offset,0x0000);
			j=block_size-1;
			write_pixel((j+lset+320)%320,i+offset,0x0ff8);
		}
		// int j=-1;
		// write_pixel((j+lset+240)%240,i+offset,0x0000);
		// j=block_size-1;
		// write_pixel((j+lset+240)%240,i+offset,0x0ff8);
	}
}
void fl(int arr[block_size][block_size]){
	for(int i=0;i<block_size;i++){
		if(i<block_size/2){
			int j=block_size/2-2;
			write_pixel((j+lset+320)%320,i+offset,0x0ff8);
			j=block_size/2+2;
			write_pixel((j+lset+320)%320,i+offset,0x0000);
		}
		else{
			int j=0;
			write_pixel((j+lset+320)%320,i+offset,0x0ff8);
			j=block_size;
			write_pixel((j+lset+320)%320,i+offset,0x0000);
		}
		// int j=-1;
		// write_pixel((j+lset+240)%240,i+offset,0x0000);
		// j=block_size-1;
		// write_pixel((j+lset+240)%240,i+offset,0x0ff8);
	}
}
int max(int a,int b){
	if(a>=b){
		return a;
	}
	else{
		return b;
	}
}
int min(int a,int b){
	if(a>b){
		return b;
	}
	else{
		return a;
	}
}
int bullet[bul_size][bul_size]={};
void collision(int z,int ls){
	counter1++;
	// while(1){}
	int y=z,x=(ls+320)%320;x/=10;x*=10;
	for(int i=y;i>=max(0,y-brick_size);i--){
		for(int j=x;j<x+brick_size;j++){
			dis[i][j]=0;
			write_pixel(j,i,0x0000);
		}
	}
	y=z+1;
	for(int i=y;i<=min(239,y+bul_size);i++){
		for(int j=x;j<x+brick_size;j++){
			dis[i][j]=0;
			write_pixel(j,i,0x0000);
		}
	}
	int x1=(ls+bul_size+320)%320;x1/=10;x1*=10;
	if(x1!=x){
		y=z;
		for(int i=y;i>=max(0,y-brick_size);i--){
			for(int j=x1;j<x1+brick_size;j++){
				dis[i][j]=0;
				write_pixel(j,i,0x0000);
			}
		}
		y=z+1;
		for(int i=y;i<=min(239,y+bul_size);i++){
			for(int j=x1;j<x1+brick_size;j++){
				dis[i][j]=0;
				write_pixel(j,i,0x0000);
			}
		}
	}
}
void fire(int z,int ls,int k){
	for(int j=0;j<bul_size;j++){
		int i=0;
		if(i+z>=0){
			write_pixel((j+ls+320)%320,(i+z),0x0ff8);
			if(dis[(i+z)][(j+ls+320)%320]==0){
				dis[(i+z)][(j+ls+320)%320]=1;
			}
			else{
				// int p=(j+ls+320)%320;p%=10;
				// brick[p]--;
				// for(int j=p*10;j<brick_size+p*10;j++){
				// 	for(i=i+z;i>=max(0,z-brick_size);i--){
				// 		dis[i][j]=0;
				// 		write_pixel(j,i,0x0000);
				// 	}
				// }
				// for(i=z;i<=z+bul_size;i++){
				// 	for(int j=0;j<bul_size;j++){
				// 		if(dis[i][(j+ls+320)%320]==1){
				// 			dis[i][(j+ls+320)%320]=0;
				// 			write_pixel((j+ls+320)%320,i,0x0000);
				// 		}
				// 	}
				// }
				shots[k].first=-1;
				collision(z,ls);
				

				return;
			}
		}
		i=bul_size;
		if(i+z>=0){
			write_pixel((j+ls+320)%320,(i+z),0x0000);
			dis[(i+z)][(j+ls+320)%320]=0;
		}
	}
	if(z==0){
		for(int j=0;j<bul_size;j++){
			for(int i=0;i<bul_size;i++){
				write_pixel((j+ls+320)%320,(i+z),0x0000);
				dis[(i+z)][(j+ls+320)%320]=0;
			}
		}
	}
	// for(int i=0;i<bul_size;i++){
	// 	for(int j=0;j<bul_size;j++){
	// 		if(bullet[i][j]==1){
	// 			if(i+z>0){
	// 				write_pixel((j+ls)%240,(i+z),0x0ff8);
	// 			}
	// 		}
	// 	}
	// }
}
void rounds(){
	for(int i=0;i<max_shots;i++){
		if(shots[i].first>=0){
			fire(shots[i].first,shots[i].second,i);
			shots[i].first--;
		}
	}
}
void start2(){
	char *chr1="  HELLO PLAYER, A HUGE ASTEROID HAS BROKEN INTO SMALL PIECES.  ";
	char *chr12="                IT IS APPROACHING YOUR CITY.                  ";

	char *chr2="            THERE IS NO TIME TO EVACUATE THE CITY              ";
	char *chr22="      YOU MUST PROTECT YOUR CITY BY FIRING THE CANNON.        ";

	char *chr3="       PREVENT THE FALLING DEBRI FROM HITTING THE CITY         ";
	int i=10;
	while(*chr1){
		write_char(i,18,*chr1);
		for(int j=0;j<500000;j++);
		chr1++;i++;
	}
	i=10;
	while(*chr12){
		write_char(i,20,*chr12);
		for(int j=0;j<500000;j++);
		chr12++;i++;
	}
	i=10;
	while(*chr2){
		write_char(i,22,*chr2);
		for(int j=0;j<500000;j++);
		chr2++;i++;
	}
	i=10;
	while(*chr22){
		write_char(i,24,*chr22);
		for(int j=0;j<500000;j++);
		chr22++;i++;
	}
	i=10;
	while(*chr3){
		write_char(i,26,*chr3);
		for(int j=0;j<500000;j++);
		chr3++;i++;
	}

}
void start(){
	char *chr1="DEBRI";
	char *chr2="SHOOTER";
	for(int i=0;i<5;i++){
		write_char(33+i*2,20,chr1[i]);
	}
	for(int i=0;i<7;i++){
		write_char(31+i*2,22,chr2[i]);
	}
	int k=25;
	
}
void gameover(){
	
	clear_screen();
	clearchar();
	char*chr2="Congratulations Your Score is";
	char *chr1="G A M E   O V E R";
	int k=29;
	while(*chr1){
		write_char(k++,22,*chr1);
		chr1++;
	}
	k=22;
	while(*chr2){
		write_char(k++,24,*chr2);
		chr2++;
	}
	k+=6;
	while(counter1>0){
		write_char(k--,24,counter1%10+'0');
		counter1/=10;
	}
	for(int i=0;i<240;i++){
		for(int j=0;j<320;j++){
			dis[i][j]=0;
		}
	}
	for(int i=0;i<no_of_brick;i++){
		brick[i]=0;
	}
	counter1=0;
}
void controls(){
	char *chr="                        C O N T R O L S                         ";
	char *chr1="                   PRESS KEY 1 TO MOVE LEFT                    ";
	char *chr12="                  PRESS KEY 4 TO MOVE RIGHT                   ";

	char *chr2="                PRESS KEY 3 TO FIRE THE CANNON                 ";
	int i=10;
	while(*chr){
		write_char(i,15,*chr);
		for(int j=0;j<500000;j++);
		chr++;i++;
	}
	i=10;
	while(*chr1){
		write_char(i,18,*chr1);
		for(int j=0;j<500000;j++);
		chr1++;i++;
	}
	i=10;
	while(*chr12){
		write_char(i,20,*chr12);
		for(int j=0;j<500000;j++);
		chr12++;i++;
	}
	i=10;
	while(*chr2){
		write_char(i,22,*chr2);
		for(int j=0;j<500000;j++);
		chr2++;i++;
	}
	i=10;
	
}
int main(){
	// for(int i=80;i<160;i++){
	// 	for(int j=80;j<160;j++){
	// 		write_pixel(i,j,0x0ff8);
	// 	}
	// }
	// while(1){}
	// counter1=10;
	// volatile int* sw=LEDR_BASE;
	// *sw=0b10001;
	*HEX3_HEX0_ptr=0;*HEX5_HEX4_ptr=0;
	counter1=0;
	srand(time(0));
	clear_screen();
	clearchar();
	int arr[block_size][block_size]={};
	for(int i=0;i<max_shots;i++)shots[i].first=-1,shots[i].second=-1;
	for(int i=0;i<bul_size;i++){
		for(int j=0;j<bul_size;j++){
			bullet[i][j]=1;
		}
	}
	long pb=KEYS[0];
	start();
	while(1){
		pb=KEYS[0];
		if(pb==4||pb==6||pb==5){
			break;
		}
		char *chr3="Press 2nd Key to continue";
		int k=25;
		while(*chr3){
			write_char(k++,28,*chr3);
			chr3++;
		}
		for(int i=0;i<5000000;i++){}
		for(int i=0;i<80;i++){
			write_char(i,28,'\0');
		}
		for(int i=0;i<5000000;i++){}
	}
	clearchar();
	start2();
	while(1){
		pb=KEYS[0];
		if(pb==4||pb==6||pb==5){
			break;
		}
		char *chr3="Press 2nd Key to continue";
		int k=25;
		while(*chr3){
			write_char(k++,28,*chr3);
			chr3++;
		}
		for(int i=0;i<5000000;i++){}
		for(int i=0;i<80;i++){
			write_char(i,28,'\0');
		}
		for(int i=0;i<5000000;i++){}
	}
	clearchar();
	controls();
	while(1){
		pb=KEYS[0];
		char *chr3="Press 2nd Key to Begin Game ";
		int k=25;
		while(*chr3){
			write_char(k++,28,*chr3);
			chr3++;
		}
		for(int i=0;i<5000000;i++){}
		for(int i=0;i<80;i++){
			write_char(i,28,'\0');
		}
		*HEX5_HEX4_ptr=0,*HEX3_HEX0_ptr=0;
		*HEX5_HEX4_ptr |= seg7[counter1/100000];counter1%=100000;
		*HEX5_HEX4_ptr |= seg7[counter1/10000] << 8;counter1%=10000;
		*HEX3_HEX0_ptr |= seg7[counter1/1000]<<24;counter1%=1000;
		*HEX3_HEX0_ptr |= seg7[counter1/100]<<16;counter1%=100;
		*HEX3_HEX0_ptr |= seg7[counter1/10]<<8;counter1%=10;
		*HEX3_HEX0_ptr |= seg7[counter1];
		for(int i=0;i<2000000;i++){}
		if(!(pb==4||pb==12||pb==6||pb==5)){
			continue;
		}
		clear_screen();
		clearchar();
		for(int i=0;i<block_size;i++){
			if(i<block_size/2){
				for(int j=block_size/2-2;j<block_size/2+2;j++){
					write_pixel(j,i+offset,0x0ff8);
					arr[i][j]=1;
				}
			}
			else{
				for(int j=0;j<block_size;j++){
					write_pixel(j,i+offset,0x0ff8);
					arr[i][j]=1;
				}
			}
		}
		FLAG=1;
		int cnt=100;
		int count=0;
		int flag=0;
		int flag2=0;	
		int ll=counter1;
		while(1){
			
			pb=KEYS[0];
			if(pb==2||pb==3||pb==10||pb==11){
				flag=1;
				continue;
			}
			if(flag){
				flag=0;
				for(int i=0;i<max_shots;i++){
					if(shots[i].first==-1){
						shots[i].first=210;
						shots[i].second=lset+block_size/2-3;
						break;
					}
				}
			}
			if(counter1!=ll){
				ll=counter1;
				*HEX5_HEX4_ptr=0,*HEX3_HEX0_ptr=0;
				*HEX5_HEX4_ptr |= seg7[ll/100000];ll%=100000;
				*HEX5_HEX4_ptr |= seg7[ll/10000] << 8;ll%=10000;
				*HEX3_HEX0_ptr |= seg7[ll/1000]<<24;ll%=1000;
				*HEX3_HEX0_ptr |= seg7[ll/100]<<16;ll%=100;
				*HEX3_HEX0_ptr |= seg7[ll/10]<<8;ll%=10;
				*HEX3_HEX0_ptr |= seg7[ll];
			}
			if(pb==1){
				flag2=0;lset++;lset%=320;
				fr(arr);
			}
			else if(pb==8){
				flag2=1;lset--;lset+=320;lset%=320;
				fl(arr);
			}
			if(pb==9){
				if(flag2){
					lset++;lset+=320;lset%=320;
					fr(arr);
				}
				else{
					lset--;lset%=320;
					fl(arr);
				}
			}
			for(int i=0;i<4;i++){
				for(int j=0;j<10000;j++){

				}
				rounds();
			}
			count++;
			if(count%5==0){
				brick_refresh();
			}
			if(FLAG==0){
				lset=0;
				gameover();
				break;
			}
			if(count==cnt){
				count=0;
				int z=rand()%(no_of_brick);
				// clear_screen();
				if(z<32){
					brick_generator(z);
				}
			}
			for(int i=0;i<140000;i++){
				
			}
			
		}
	}
	
	return 0;
}
