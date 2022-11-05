#include <iostream>
#include <windows.h>
#include <gl/gl.h>
#include <math.h>
#include <fstream>
#include <algorithm>
int color(int mod,int ggar,int ggak,int inp[4][4],int search){
		int output=15;
if(mod==1 or mod==2 or mod==0){

				switch(inp[ggar/3][ggak/3]){
					case 0:output=8;break;
					case 1:output=12;break;
					case 2:output=2;break;
					case 3:output=9;break;
					case 4:output=4;break;
					case 5:output=7;break;
					case 6:output=11;break;
					case 7:output=13;break;
					case 8:output=10;break;
					case 9:output=5;break;
					case 10:output=4;break;
					case 11:output=12;break;
					case 12:output=14;break;
					case 13:output=3;break;
					case 14:output=1;break;
					case 15:output=6;break;
					case 16:output=7;break;
					case 17:output=10;break;
					case 18:output=11;break;
					case 19:output=14;break;
					case 20:output=13;break;
					
					
					
					
				}
			}
	
		switch(search){
			case 1:if(mod==7){output=8;}break;
			case 2:output=15;break;
			case 3:output=15;break;
			case 4:output=15;break;
			case 5:output=15;break;
			case 6:output=15;break;
			case 9:output=12;break;
			case 11:output=14;break;
			case 12:output=9;break;
			default:output=15;
			
		}
		
	
	
			return output;	
};
draw(int search,int empt,int pth2,int rs){
	int indx=rs;
/*	switch(search){
				case 0:std::cout<<" ";empt++;break;
				case 1:std::cout<<"#";break;
				case 2:std::cout<<"^";pth2++;break;
				case 3:std::cout<<">";pth2++;break;
				case 4:std::cout<<"V";pth2++;break;
				case 5:std::cout<<"<";pth2++;break;
				case 6:std::cout<<"X";break;
				case 8:std::cout<<" ";break;
				case 9:std::cout<<"@";break;
				case 11:std::cout<<"O";break;
				case 12:std::cout<<"O";break;
				default:std::cout<<" ";empt++;break;}*/
				if(search==1){
					indx=1;
				}
				if(search==9){
					indx=9;
				}
				if(indx<0){
					indx=indx;
				}if(indx==0){
			//		indx=search;
				}
				
				switch(indx){
    	
				case 0: std::cout<<' ';empt++;break;
				case 1: std::cout<<'#';break;
				
				case 2: std::cout<<'|';pth2++;break;
				case 3: std::cout<<'-';pth2++;break;
				case 4: std::cout<<'|';pth2++;break;
				case 5: std::cout<<'-';pth2++;break;
				
				
				case 6: std::cout<<'+';break;
				case 9: std::cout<<'@';break;
				case 11:std::cout<<'O' ;break;
				case 12: std::cout<<'O';break;
				
				case 112: std::cout<<'>'; break;
				case 114: std::cout<<'<'; break;
				
				case 121: std::cout<<'^'; break;
				case 123: std::cout<<'v'; break;
				
				case 132: std::cout<<'>'; break;
				case 134: std::cout<<'<'; break;
				
				case 141: std::cout<<'^'; break;
				case 143: std::cout<<'v'; break;
				
				
				default: std::cout<<'?'; break;}
	
}
