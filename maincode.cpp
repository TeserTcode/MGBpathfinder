#include <iostream>
#include <windows.h>
#include <gl/gl.h>
#include <math.h>
#include <fstream>
#include <algorithm>

#include "customtiles.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	//settings
	int raytr=3;//1-3  3 should be good
	int telo=5;//telorance for shwoing the best 1=show same performance 0=dont show anything until something better
	int strr=1;//extra quality for tile bruteforce (makis it longer N times)
	int minemp=-1;//number of empty tiles   set it to -1
	//int tile[]{};//usable tiles in tile bruteforce ex {5,6,7} {6,9,12} {6,7}
	int klma=500;//retry for fail (not matter much)
	double wem[]={0,0,0,0,-3,0,0,0,0,0,0,0,0};//weights of tiles ex.{0,0,0,0,-2.5,.5,0,0,0,0,0,0,0}
	int maxit=50000;//maximum iteration for pathfinding (not matter much)
	int rndrt=30;//randomly turns wrongly
	int isprt=1;//use prtals
	bool isoutput=1;
	
	
	
	 int code=0;
	int tilelen=0;
	int ptile[20]{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	int brtf=1;
	int srtf=1;
	int lite=0;
	int site=0;
	int prtin[2]={-5,-5};
	int prtot[2]={-5,-5};
	int arr[12][12];
	int sarr[12][12];
	int farr[12][12]{
	0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0};
	int kilo=0;
		int shipid=0;
	int inp[4][4]{
	0,0,0,0,
	0,0,0,0,
	0,0,0,0,
	0,0,0,0};
	int mod=0;
	
	std::ifstream cFile ("config2.txt");
    if (cFile.is_open())
    {
        std::string line;
        while(getline(cFile, line)){
            line.erase(std::remove_if(line.begin(), line.end(), isspace),
                                 line.end());
            if(line[0] == '#' || line.empty())
                continue;
            auto delimiterPos = line.find("=");
            auto name = line.substr(0, delimiterPos);
            auto value = line.substr(delimiterPos + 1);
            std::cout << name << " " << value << '\n';
            int num=std::atoi((value).c_str());
            
            	if(name=="0"){raytr=num;}
            	if(name=="1"){telo=num;}
            	if(name=="2"){strr=num;}
            	if(name=="3"){minemp=num;}
            	//case 4: raytr=value; break;
            	if(name=="5"){klma=num;}
            	//case 6: raytr=value; break;
            	if(name=="7"){maxit=num;}
            	if(name=="8"){rndrt=num;}
            	if(name=="9"){isprt=num;}
            	if(name=="10"){isoutput=num;}
            	if(name=="4"){
            		
            		int lngng=0;
            	if(line.find("01")!=line.npos){ptile[lngng]=1;lngng++;}	
            	if(line.find("02")!=line.npos){ptile[lngng]=2;lngng++;}	
            	if(line.find("03")!=line.npos){ptile[lngng]=3;lngng++;}	
            	if(line.find("04")!=line.npos){ptile[lngng]=4;lngng++;}	
					if(line.find("05")!=line.npos){ptile[lngng]=5;lngng++;}		
				if(line.find("06")!=line.npos){ptile[lngng]=6;lngng++;}
				if(line.find("07")!=line.npos){ptile[lngng]=7;lngng++;}		
				if(line.find("08")!=line.npos){ptile[lngng]=8;lngng++;}	
				if(line.find("09")!=line.npos){ptile[lngng]=9;lngng++;}	
				if(line.find("10")!=line.npos){ptile[lngng]=10;lngng++;}	
				if(line.find("11")!=line.npos){ptile[lngng]=11;lngng++;}	
				if(line.find("12")!=line.npos){ptile[lngng]=12;lngng++;}	
				if(line.find("13")!=line.npos){ptile[lngng]=13;lngng++;}	
				if(line.find("14")!=line.npos){ptile[lngng]=14;lngng++;}	
				if(line.find("15")!=line.npos){ptile[lngng]=15;lngng++;}
				
				
				tilelen=lngng;
			}
				
				if(name=="6")
            	//std::atoi((line.substr(line.find("01")+2,4)).c_str())
            		
            		if(line.find("01")!=line.npos){wem[0]=std::atof((line.substr(line.find("01")+2,4)).c_str());}
					
					if(line.find("05")!=line.npos){wem[4]=std::atof((line.substr(line.find("05")+2,4)).c_str());}
					if(line.find("06")!=line.npos){wem[5]=std::atof((line.substr(line.find("06")+2,4)).c_str());}
					if(line.find("07")!=line.npos){wem[6]=std::atof((line.substr(line.find("07")+2,4)).c_str());}	
            		
            		
				
            	
            	
            	
            	
            	
			
        }
        
    }
    else {
        std::cerr << "get the config2.txt file\n";
    }
    int tile[tilelen];
				for(int tileset=0;tileset<tilelen;tileset++){
					tile[tileset]=ptile[tileset];
				 std::cout  << "->" << tile[tileset] << '\n';
}for(int tileset=0;tileset<12;tileset++){
	if(wem[tileset]!=0){
	std::cout << tileset+1 << " weighs " << wem[tileset] << '\n';
}
}
    
	std::cout << '\n';
	
	
	
	
	std::cout<<std::endl<<"choose mod 0-custom 1-named cutsom  4-lite bruteforce 7-classic ships " ;
	std::cin>>mod;
	if(mod==4 or mod==5){
		std::cout<<std::endl<<"how long";
		std::cin>>brtf;
		std::cout<<std::endl<<"choose mod 0-custom  1-named cutsom  ";
      	std::cin>>mod;
      	if(mod==5){
      		lite=1;
		  }
		
}
if(mod==6){
		std::cout<<std::endl<<"how long";
		std::cin>>srtf;
		std::cout<<std::endl<<"choose mod 0-custom  1-named cutsom ";
      	std::cin>>mod;
      	site=1;
		
}

	
	int modd=0;
	if(mod==0){
	

	std::cout<<std::endl<<"give 16 tiles ranged from 1-12"<<std::endl<<"everything goes left to right then top to bottom"<<std::endl;
	std::cin>>
	inp[0][0]>>inp[0][1]>>inp[0][2]>>inp[0][3]>>
	inp[1][0]>>inp[1][1]>>inp[1][2]>>inp[1][3]>>	
	inp[2][0]>>inp[2][1]>>inp[2][2]>>inp[2][3]>>
	inp[3][0]>>inp[3][1]>>inp[3][2]>>inp[3][3];
}
	if(mod==1){
		std::cout<<std::endl<<"0-sanil 1-beast 2-fat trident 3-thunder 4-staricase 5-piano 6-random(reccomend) 7-extreme random(no reccomend) 8-perfect bruteforce(long time) 9-wave bruteforce :O";
				std::cin>>modd;
	
	switch(modd){
	case 0:
	inp[0][0]=5; inp[0][1]=7;  inp[0][2]=7; inp[0][3]=6;
	inp[1][0]=6; inp[1][1]=7;  inp[1][2]=6; inp[1][3]=6;	
	inp[2][0]=6; inp[2][1]=1;  inp[2][2]=6; inp[2][3]=6;
	inp[3][0]=7; inp[3][1]=7;  inp[3][2]=7; inp[3][3]=6;
	
	break;
	case 1:
	inp[0][0]=5; inp[0][1]=5;  inp[0][2]=5; inp[0][3]=6;
	inp[1][0]=5; inp[1][1]=7;  inp[1][2]=5; inp[1][3]=6;	
	inp[2][0]=5; inp[2][1]=1;  inp[2][2]=5; inp[2][3]=6;
	inp[3][0]=5; inp[3][1]=5;  inp[3][2]=5; inp[3][3]=6;
	break;
	case 2:
	inp[0][0]=6; inp[0][1]=6;  inp[0][2]=1; inp[0][3]=6;
	inp[1][0]=6; inp[1][1]=6;  inp[1][2]=5; inp[1][3]=6;	
	inp[2][0]=6; inp[2][1]=6;  inp[2][2]=5; inp[2][3]=6;
	inp[3][0]=7; inp[3][1]=7;  inp[3][2]=7; inp[3][3]=6;
	break;
	case 3:
	inp[0][0]=1; inp[0][1]=6;  inp[0][2]=6; inp[0][3]=6;
	inp[1][0]=12;inp[1][1]=6;  inp[1][2]=6; inp[1][3]=6;	
	inp[2][0]=6; inp[2][1]=12; inp[2][2]=6; inp[2][3]=6;
	inp[3][0]=6; inp[3][1]=6;  inp[3][2]=12;inp[3][3]=6;
	break;
	case 4:
	inp[0][0]=1; inp[0][1]=5;  inp[0][2]=5; inp[0][3]=6;
	inp[1][0]=5; inp[1][1]=5;  inp[1][2]=5; inp[1][3]=6;	
	inp[2][0]=5; inp[2][1]=5;  inp[2][2]=5; inp[2][3]=6;
	inp[3][0]=5; inp[3][1]=5;  inp[3][2]=5; inp[3][3]=6;
	break;
	case 5:
	inp[0][0]=6; inp[0][1]=6;  inp[0][2]=6; inp[0][3]=1;
	inp[1][0]=6; inp[1][1]=6;  inp[1][2]=6; inp[1][3]=6;	
	inp[2][0]=6; inp[2][1]=6;  inp[2][2]=6; inp[2][3]=6;
	inp[3][0]=7; inp[3][1]=7;  inp[3][2]=7; inp[3][3]=6;	
	break;
	case -1:
	inp[0][0]=5; inp[0][1]=5;  inp[0][2]=5; inp[0][3]=5;
	inp[1][0]=5; inp[1][1]=5;  inp[1][2]=5; inp[1][3]=5;	
	inp[2][0]=5; inp[2][1]=1;  inp[2][2]=5; inp[2][3]=5;
	inp[3][0]=5; inp[3][1]=5;  inp[3][2]=5; inp[3][3]=5;	
	break;
	case -2:
	inp[0][0]=9; inp[0][1]=6;  inp[0][2]=6; inp[0][3]=6;
	inp[1][0]=6; inp[1][1]=6;  inp[1][2]=6; inp[1][3]=6;	
	inp[2][0]=6; inp[2][1]=6;  inp[2][2]=6; inp[2][3]=6;
	inp[3][0]=1; inp[3][1]=5;  inp[3][2]=6; inp[3][3]=6;	
	break;
	case -3:
	inp[0][0]=1; inp[0][1]=9;  inp[0][2]=6; inp[0][3]=6;
	inp[1][0]=9; inp[1][1]=6;  inp[1][2]=6; inp[1][3]=6;	
	inp[2][0]=6; inp[2][1]=6;  inp[2][2]=6; inp[2][3]=6;
	inp[3][0]=6; inp[3][1]=6;  inp[3][2]=6; inp[3][3]=6;	
	break;
	case 6:
		brtf=5000000;
		std::cout<<"seed this will be used for tile brutefroce(6)";
	int gfgf;
	std::cin>>gfgf;
	srand(gfgf);
	
	break;
		case 7:
			brtf=5000000;
			std::cout<<"seed this will be used for tile brutefroce dont use 123";
	int gfgg;
	std::cin>>gfgg;
	srand(gfgg);
	break;
	case 8:
		
		
		
	//	std::cout<<"weight of wavesoed3x3 (0-tier 3-wave)";
	//	std::cin>>wwb;
	brtf=2147483645;
	
break;
case 9:
		
	brtf=177147*8*8*8;
	
	break;
}
	std::cout<<std::endl;}
	if (mod==7){
		int shipi=0;
				std::cout<<std::endl<<"ship waht 0-rþder used 1-rider ... use ship id  (33broken :( )";
				std::cin>>shipi;
				shipid=shipi;
	}

int best=0;

	for(int bst=0;bst<brtf;bst++){
	int sest=0;
if(mod==1){

	
	if(modd==6 and bst%5==0){
				inp[0][0]=5+rand()%3; inp[0][1]=5+rand()%3;  inp[0][2]=5+rand()%3; inp[0][3]=6;
	inp[1][0]=5+rand()%3;inp[1][1]=5+rand()%3;  inp[1][2]=5+rand()%3; inp[1][3]=6;	
	inp[2][0]=5+rand()%3; inp[2][1]=5+rand()%3; inp[2][2]=5+rand()%3; inp[2][3]=6;
	inp[3][0]=5+rand()%3; inp[3][1]=5+rand()%3;  inp[3][2]=5+rand()%3;inp[3][3]=6;	
	//inp[rand()%4][rand()%3]=1;
	inp[2][1]=1;
			}
			if(modd==8){//////////////////////////////////////////////////////////////////////////////////////////////////////////
		//	std::cout<<"eyey";
				int s = tilelen;
				int div=strr;
				int ejx=1;
				int ejy=2;
				//std::cout<<code;
				if(tile[s-1]!=1){
	ejx=(code/div)%2; div*=2;
	ejy=(code/div)%4; div*=4;
}
				//srand(code);
			//	inp[rand()%4][rand()%3]=1;
	inp[0][0]=tile[(code/div)%s];div*=s;inp[0][1]=tile[(code/div)%s];div*=s;inp[0][2]=tile[(code/div)%s];div*=s;inp[0][3]=6;
	inp[1][0]=tile[(code/div)%s];div*=s;inp[1][1]=tile[(code/div)%s];div*=s;inp[1][2]=tile[(code/div)%s];div*=s;inp[1][3]=6;	
	inp[2][0]=tile[(code/div)%s];div*=s;inp[2][1]=tile[(code/div)%s];div*=s;inp[2][2]=tile[(code/div)%s];div*=s;inp[2][3]=6;
	inp[3][0]=tile[(code/div)%s];div*=s;inp[3][1]=tile[(code/div)%s];div*=s;inp[3][2]=tile[(code/div)%s];inp[3][3]=6;
	if(tile[s-1]!=1){
//std::cout<<inp[2][3];
	inp[3][2]=inp[ejy][ejx];
	inp[ejy][ejx]=1;
}
code++;
}
	
	
			if(modd==7){
				inp[0][0]=1+rand()%12; inp[0][1]=1+rand()%12;  inp[0][2]=1+rand()%12;inp[0][3]=1+rand()%12;
	inp[1][0]=1+rand()%12;inp[1][1]=1+rand()%12;  inp[1][2]=rand()%12; inp[1][3]=1+rand()%12;	
	inp[2][0]=1+rand()%12; inp[2][1]=1+rand()%12; inp[2][2]=rand()%12; inp[2][3]=1+rand()%12;
	inp[3][0]=1+rand()%12; inp[3][1]=1+rand()%12;  inp[3][2]=rand()%12;inp[3][3]=6;	
	
	inp[rand()%4][rand()%3]=1;
			}
			if(modd==9){
				int s = tilelen;
				int div=strr;
				int ejx=1;
				int ejy=2;
				if(tile[s-1]!=1){
	ejx=(code/div)%2; div*=2;
	ejy=(code/div)%4; div*=4;}
				
			//	inp[rand()%4][rand()%3]=1;
	inp[0][0]=tile[(code/div)%s];div*=s;inp[0][1]=tile[(code/div)%s];div*=s;inp[0][2]=6;inp[0][3]=6;
	inp[1][0]=tile[(code/div)%s];div*=s;inp[1][1]=tile[(code/div)%s];div*=s;inp[1][2]=6;inp[1][3]=6;	
	inp[2][0]=tile[(code/div)%s];div*=s;inp[2][1]=tile[(code/div)%s];div*=s;inp[2][2]=6;inp[2][3]=6;
	inp[3][0]=tile[(code/div)%s];div*=s;inp[3][1]=tile[(code/div)%s];inp[3][2]=6;inp[3][3]=6;
	if(tile[s-1]!=1){

	inp[3][1]=inp[ejy][ejx];
	inp[ejy][ejx]=1;

    //inp[3][2]=inp[ejy][ejx];
//		inp[ejy][ejx]=1;
}code++;}
}
	int buff[20]={
	0,0,0,0,
	0,0,0,0,
	0,0,0,0,
	0,0,0,0,
	0,0,0,0};
	
	if (site==1){
		
	}
	int iax=0;
	int iay=0;
		for (int intar=0;intar<4;intar++){
			iay=0;
		for (int intak=0;intak<4;intak++){
			int inpw=inp[intar][intak];
		arr[intar*3][intak*3]=cts(inpw,1);
		arr[intar*3][intak*3+1]=cts(inpw,2);
		arr[intar*3][intak*3+2]=cts(inpw,3);
		
		arr[intar*3+1][intak*3]=cts(inpw,4);
		arr[intar*3+1][intak*3+1]=cts(inpw,5);
		arr[intar*3+1][intak*3+2]=cts(inpw,6);
		
		arr[intar*3+2][intak*3]=cts(inpw,7);
		arr[intar*3+2][intak*3+1]=cts(inpw,8);
		arr[intar*3+2][intak*3+2]=cts(inpw,9);
		buff[inpw]++;
		iay+=3;
	}
	iax+=3;
	}
	int xt=10;
	int yt=11;
		int kx=xt;
	
	int ky=yt;
	int dd=0;
	
			
			if(mod==7 and modd<1){
			
				
				
				int	karr[12][12]={
				0,0,0,0,0,0,0,0,0,0,0,0,	
				1,1,1,1,1,1,1,1,1,1,1,0,
				1,1,1,1,1,1,1,1,1,1,1,0,
				1,1,1,1,1,1,1,1,1,1,1,0,
				1,1,1,1,1,1,1,1,1,1,1,0,
				1,1,1,1,1,1,1,1,1,1,1,0,
				1,1,1,1,1,1,1,1,1,1,1,0,
				1,1,1,1,1,1,1,1,1,1,1,0,
				1,1,1,1,1,1,1,1,1,1,1,0,
				1,1,1,1,1,1,1,1,1,1,1,0,
				1,1,1,1,1,1,1,1,1,1,1,0,
				1,1,1,1,1,1,1,1,1,1,1,0};
				
				
				
				std::ifstream cFile ("class.txt");
    if (cFile.is_open())
    {
        std::string line;
       
            	
            	int readline=0;
            	//readline=shipid*144;
            int otot=0;
            char lineread='1';
            getline(cFile, line);
            int shipidc=shipid;
            for(int shipidf=0;shipidf<shipidc;shipidf++){
            getline(cFile, line);getline(cFile, line);getline(cFile, line);
			getline(cFile, line);getline(cFile, line);getline(cFile, line);
			getline(cFile, line);getline(cFile, line);getline(cFile, line);
			getline(cFile, line);getline(cFile, line);getline(cFile, line);	
			}
            
					for(int trr=0;trr<12;trr++){
						for(int krr=0;krr<12;krr++){
							readline++;
							lineread=line[readline];
						//	std::cout<<lineread;
							if(lineread=='0'){
							otot=0;}
							if(lineread=='1'){
							otot=1;}
							if(lineread=='9'){
							otot=9;}
							if(lineread=='6'){
							otot=6;}
							if(lineread=='s'){
							xt=krr;yt=trr;otot=-0;}
						if(otot!=-69){
						
						karr[trr][krr]=otot;}
					}
								
                                 readline=0;
                                 getline(cFile, line);
        }
		}else{
			std::cout<<"get the class.txt file to use classcccsic ships";
		}
			
				
			
				
				
				
			
				
				kilo=klma/2;
				for(int karg=0;karg<12;karg++){
					
				for(int karl=0;karl<12;karl++){
					arr[karg][karl]=karr[karg][karl];
					
					
				}	
					
				}
				
				
				
				}
				
				
				
			
	for(int g=0;g<144;g++){
		int halb=g;
		sarr[halb/12][halb%12]=arr[halb/12][halb%12];
	//	farr[halb/12][halb%12]=arr[halb/12][halb%12];
	}
//	std::cout<<std::endl<<bst;
	
	for (int ggar=0;ggar<12;ggar++){
		
		for (int ggak=0;ggak<12;ggak++){
			
		//	std::cout<<arr[ggar][ggak];
	}
//	std::cout<<std::endl;
	}
	
	
	
	//oh no
	int x=xt;
	int y=yt;
	int dir=1;
	int ogdir=1;
	int it=0;
	int dx=0;
	int dy=0;
	int prt=0;
	int pth=0;
	int trn=0;
	int prtdir=2;
/*	if(
	inp[3][2]==6 and 
	inp[3][3]==6 
	){
	prtin[0]=11;prtin[1]=9;
	//prtot[0]=11;prtot[1]=7;
	int prtdir=0;
	switch(0*bst%4){
		
	case 0:
	prtot[0]=0;prtot[1]=7;prtdir=3;break;
	case 1:
	prtot[0]=11;prtot[1]=7;prtdir=1;break;
	case 2:
	prtot[0]=10;prtot[1]=8;prtdir=1;break;
	case 3:
	prtot[0]=1;prtot[1]=4;prtdir=4;break;		
	}}
		
	arr[prtin[0]][prtin[1]]=11;
	
	arr[prtot[0]][prtot[1]]=12;	*/	
	int isprt=0;
//dir    1up 2right 3 down 4 left	
		if(inp[3][2]==7){
			arr[11][9]=1;}
			if(buff[6]!=minemp and minemp!=-1){
			it=maxit;
		}
		int doneport=0;
		bool strtcrs=0;
	while(arr[y][x]!=9 and it < maxit){
		it++;
		
		//	std::cout<<x<<","<<y<<"'"<<dir<<","<<ogdir<<"w"<<arr[y][x];
		//	std::cout<<std::endl;-
		int rnd=rand()%brtf;
		if(modd!=8){
		
		int rnd=rand()%brtf;}else{
			int rnd=rand()%srtf;
		}
		if(brtf-bst<10){
			rnd=-69;
		}
		if(brtf<10){
			rnd=-69;
		}
		
		/*
		//if(lite==1){rnd-69;}
		for(int cros=0;cros<4;cros++){
		for(int croc=0;croc<4;croc++){
			if(inp[cros][croc]==999 and inp[cros+1][croc]==6 and inp[cros][croc+1]==6){
			arr[3*cros+2][3*croc+1]=0;
			arr[3*cros+1][3*croc+2]=0;
		//	arr[0][3]=8;//empty blockage;
		}
		}	
		}*/
		
		if (((arr[y][x]==0 or arr[y][x]==9 or arr[y][x]==12  or arr[y][x]==6)and(x<12 and x>-1 and y<12 and y>-1))  ){
		//	if(!(rnd<bst+brtf)){
		for(int cros=0;cros<4;cros++){
		for(int croc=0;croc<4;croc++){
			if(inp[cros][croc]==9){
			sarr[3*cros+2][3*croc+1]=arr[3*cros+2][3*croc+1];  arr[3*cros+2][3*croc+1]=0;
			sarr[3*cros+1][3*croc+2]=arr[3*cros+1][3*croc+2];  arr[3*cros+1][3*croc+2]=0;}
			if(inp[cros][croc]==12){
			if(arr[3*cros+2][3*croc+1]!=0){sarr[3*cros+2][3*croc+1]=arr[3*cros+2][3*croc+1];arr[3*cros+2][3*croc+1]=0;}}
			
			
			
			}}
			if(arr[yt-1][xt]<6 and arr[yt-1][xt]>1){
			if(sarr[yt-1][xt]!=0){strtcrs=1;	}
			sarr[yt-1][xt]=arr[yt-1][xt];  arr[yt-1][xt]=0;}
			
	//	x--;break;
	int nofront =   0 ;
			switch(dir){
				case 1: if(arr[y+1][x]!=0){nofront=1;}break;
				case 2: if(arr[y][x+1]!=0){nofront=1;}break; 
				case 3: if(arr[y-1][x]!=0){nofront=1;}break; 
				case 4: if(arr[y][x-1]!=0){nofront=1;}break;  
			}
		nofront =   0 ;
			if(modd!=9 and modd!=8  and (rnd>bst or (mod==4 and nofront ))or(mod==7 and rnd*2>bst)or
			 (modd==8 and strr!=1 and 1+rand()%strr>strr/2 and bst%strr>1)){	
			switch (raytr){
			case 3:switch (dir){case 1:
			    	if(x>2 and arr[y][x-1]==0 and arr[y][x-2]==0 and arr[y][x-3]==0){dir=4;trn++;}
					if(x<9 and arr[y][x+1]==0 and arr[y][x+2]==0 and arr[y][x+3]==0){dir=2;trn++;
					}break;case 2:
					if(y>2 and arr[y-1][x]==0 and arr[y-2][x]==0 and arr[y-3][x]==0){dir=1;trn++;}
					if(y<9 and arr[y+1][x]==0 and arr[y+2][x]==0 and arr[y+3][x]==0){dir=3;trn++;
					}break;case 3:
					if(x>2 and arr[y][x-1]==0 and arr[y][x-2]==0 and arr[y][x-3]==0){dir=2;trn++;}
					if(x<9 and arr[y][x+1]==0 and arr[y][x+2]==0 and arr[y][x+3]==0){dir=4;trn++;}
					break;case 4:
					if(y>2 and arr[y-1][x]==0 and arr[y-2][x]==0 and arr[y-3][x]==0){dir=3;trn++;}
					if(y<9 and arr[y+1][x]==0 and arr[y+2][x]==0 and arr[y+3][x]==0){dir=1;trn++;}
					break;}break;
					
			case 2:switch (dir){case 1:
			    	if(x>2 and arr[y][x-1]==0 and arr[y][x-2]==0){dir=4;trn++;}
					if(x<9 and arr[y][x+1]==0 and arr[y][x+2]==0){dir=2;trn++;
					}break;case 2:
					if(y>2 and arr[y-1][x]==0 and arr[y-2][x]==0){dir=1;trn++;}
					if(y<9 and arr[y+1][x]==0 and arr[y+2][x]==0){dir=3;trn++;
					}break;case 3:
					if(x>2 and arr[y][x-1]==0 and arr[y][x-2]==0){dir=2;trn++;}
					if(x<9 and arr[y][x+1]==0 and arr[y][x+2]==0){dir=4;trn++;}
					break;case 4:
					if(y>2 and arr[y-1][x]==0 and arr[y-2][x]==0){dir=3;trn++;}
					if(y<9 and arr[y+1][x]==0 and arr[y+2][x]==0){dir=1;trn++;}
					break;}break;
					
			case 1:switch (dir){case 1:
			    	if(x>2 and arr[y][x-1]==0){dir=4;trn++;}
					if(x<9 and arr[y][x+1]==0){dir=2;trn++;
					}break;case 2:
					if(y>2 and arr[y-1][x]==0){dir=1;trn++;}
					if(y<9 and arr[y+1][x]==0){dir=3;trn++;
					}break;case 3:
					if(x>2 and arr[y][x-1]==0){dir=2;trn++;}
					if(x<9 and arr[y][x+1]==0){dir=4;trn++;}
					break;case 4:
					if(y>2 and arr[y-1][x]==0){dir=3;trn++;}
					if(y<9 and arr[y+1][x]==0){dir=1;trn++;}
					break;}break;
					
					
					
					
				}
		//	dir=1+(dir-1)%4;
}
		
				switch(dir){
					case 1:
						arr[y][x]=2;
						y--;break;
					case 2:
						arr[y][x]=3;
						x++;break;
					case 3:
						arr[y][x]=4;
						y++;break;
					case 4:
						arr[y][x]=5;
						x--;break;
				}
				if(!(((arr[y][x]==0 or arr[y][x]==9 or arr[y][x]==12  or arr[y][x]==6)and(x<12 and x>-1 and y<12 and y>-1))) 
				){
					
			if(mod==7 and arr[y][x]!=1 and (arr[y][x]==dir-2 or arr[y][x]==dir+2 or arr[y][x]==dir)and
			(dir==1 and arr[y-1][x]==0)and
			(dir==2 and arr[y][x+1]==0)and
			(dir==3 and arr[y+1][x]==0)and
			(dir==4 and arr[y][x-1]==0)
			){
			
				
			switch(dir){
					case 1:
						sarr[y][x]=6;
						y--;break;
					case 2:
						sarr[y][x]=6;
						x++;break;
					case 3:
						sarr[y][x]=6;
						y++;break;
					case 4:
						sarr[y][x]=6;
						x--;break;
				}
					//arr[y][x]=0;
		}else{
			switch(dir){
				case 1:
						y++;
					break;
					case 2:
						
						x--;
					break;
					case 3:
						y--;
					break;
					case 4:
						x++;
					break;}
		}
				}else{
					if(dir!=ogdir){trn++;					}
					ogdir=dir;
					pth--;
					dx=x;
					dy=y;
					//prt=0;
				}
	}else if(arr[y][x]==11 or (x==prtin[1] and y==prtin[0])){
		isprt=1;
		}else{
			int nofront=0;
			switch(dir){
				case 1: if(arr[y+1][x]!=0){nofront=1;}
				case 2: if(arr[y][x+1]!=0){nofront=1;}
				case 3: if(arr[y-1][x]!=0){nofront=1;}
				case 4: if(arr[y][x-1]!=0){nofront=1;}
			}
			
			
			
		if(arr[y][x]!=1 and ( rand()%(rndrt*20)>1 )){
			
		arr[y][x]=0;}else{
			int prtit=0;
			if(doneport==0 and isprt==1){
				if(arr[y][x]==1){
					it=maxit;
				}
					prtin[0]=y;
					prtin[1]=x;
				while(arr[y][x]!=0 and prtit<144){
					prtit++;
					if(mod==7){
					
					x=rand()%11;
					y=1+rand()%11;}else{
						x=rand()%12;
					y=rand()%12;
					}
					if(arr[y][x]!=0){
						prtot[0]=y;
					prtot[1]=x;
					}
				}
				if(prtit==144){
					it=maxit;
				}else{
					prtot[0]=y;
					prtot[1]=x;
					prtdir=1+rand()%4;
					doneport=1;
					dir=prtdir;
					ogdir=dir;
					switch(dir){
					case 1:y--;break;
					case 2:x++;break;
					case 3:y++;break;
					case 4:x--;break;
				}
				}
				
			}else{
		//	std::cout<<"";
			it=maxit;
	}
			
		}
	
			if(dir-ogdir==1 or dir-ogdir==-3 and prt==0){
				prt=1;
				
				if(arr[y][x]!=1){
			
		arr[y][x]=0;}
				x=dx;
			y=dy;
		
		
			
					switch(ogdir){
					case 1:
						if(arr[y][x]==5){
							arr[y][x]=6;
						}
						y++;
						if(arr[y][x]==5){
							arr[y][x]=6;
						}
					break;
					case 2:
						
						x--;
					break;
					case 3:
						y--;
					break;
					case 4:
						x++;
					break;}
					dir++;dir++;
					if(dir==5){
						dir=1;
					}
		ogdir=dir;
				if(arr[y][x]!=1){
			
		arr[y][x]=0
		;}
			} else{
		
			
			
			int dirch=kilo;
			if(xt<6 or inp[y/4][x/4]==9){
				dirch=klma-kilo;
			}
			//std::cout<<"asldk";
	if((rand()%klma>dirch)or(rand()%rndrt==2)){		
			if(ogdir==1){
			
				switch(dir){
					case 1:
						dir=4;
					break;
					case 4:
						dir=2;
					break;
					case 2:
						y--;
					break;
				}
			}
			if(ogdir==2){
			
				switch(dir){
					case 2:
						dir=1;
					break;
					case 1:
						dir=3;
					break;
					case 3:
						x--;;
					break;
				}
			}
			if(ogdir==3){
				switch(dir){
					case 3:
						dir=2;
					break;
					case 2:
						dir=4;
					break;
					case 4:
						y++;;
					break;
				}
			}
			if(ogdir==4){
			
			
				switch(dir){
					case 4:
						dir=3;
					break;
					case 3:
						dir=1;
					break;
					case 1:
						x++;;
					break;
				}
			}

}else{
			if(ogdir==3){
			
				switch(dir){
					case 3:
						dir=4;
					break;
					case 4:
						dir=2;
					break;
					case 2:
						y++;
					break;
				}
			}
			if(ogdir==4){
			
				switch(dir){
					case 4:
						dir=1;
					break;
					case 1:
						dir=3;
					break;
					case 3:
						x++;;
					break;
				}
			}
			if(ogdir==1){
				switch(dir){
					case 1:
						dir=2;
					break;
					case 2:
						dir=4;
					break;
					case 4:
						y--;;
					break;
				}
			}
			if(ogdir==2){
			
			
				switch(dir){
					case 2:
						dir=3;
					break;
					case 3:
						dir=1;
					break;
					case 1:
						x--;;
					break;
				}
			}
	
	}
	
	
		}
		}
	
}

	
	int sit=1;
	int sdir=1;
/*if(it!=maxit){while(arr[ky][kx]!=9 and sit<250){
		sit++;
	//	std::cout<<kx<<ky;
		switch(arr[ky][kx]){
			case 0:
				
			break;
			case 1:
				sit+=500;
			break;
			case 2:
				sdir=1;
			break;
			case 3:
				 sdir=2;
			break;
			case 4:
			 sdir=3;
			break;
			case 5:
				 sdir=4;
			break;	}
			
		switch(sdir){
			case 1:
				sarr[ky][kx]=2;ky--;
			break;
	case 2:
				sarr[ky][kx]=3; kx++;
			break;
			case 3:
				sarr[ky][kx]=4; ky++;
			break;
			case 4:
				sarr[ky][kx]=5; kx--;
			break;	}
		if(x<0){x=0;}
		if(y<0){x=0;}
		if(x>11){y=11;}
		if(y>11){y=11;}
}

}*/

if(doneport==0){
//	arr[prtot[0]][prtot[1]]==0;
//	arr[prtin[0]][prtin[1]]==0;
}else{
	arr[prtot[0]][prtot[1]]==0;
	arr[prtin[0]][prtin[1]]==0;
}

for(int cros=1;cros<11;cros++){
		for(int croc=1;croc<11;croc++){
			if(inp[cros/3][croc/3]==12 or inp[cros/3][croc/3]==9){
			int ea=arr[cros][croc-1];
			int es=arr[cros-1][croc];
			int ed=arr[cros][croc+1];
			int ew=arr[cros+1][croc];
			if(ea>1 and ea<6 and es>1 and es<6 and ew>1 and ew<6 and ed>1 and ed<6 and
			 (ea==3 or es==2 or ed==5 or ew==4)
			 
			 
			 ){
				
					arr[cros][croc]=6;
				
			}
			
		}
			
			}}
			if(strtcrs){
				sarr[yt-1][xt]=6;
			}
			
if(inp[3][3]==6 and arr[11][9]==1){
arr[11][9]=0;
}
x=xt;y=yt;dir=1;
while(farr[y][x]!=9 and it<maxit){
	int movedir=dir;
	if(farr[y][x]==0){
		farr[y][x]=dir+1;
}
	switch(dir){
		case 1:y--;break;
		case 2:x++;break;
		case 3:y++;break;
		case 4:x--;break;
	}
	if(sarr[y][x]!=0 and arr[y][x]!=6){
					arr[y][x]=sarr[y][x];
				}
	switch(arr[y][x]){
		
		case 0:  break;
		case 1:;farr[y][x]=9; break;
		case 2: if(dir!=1){dir=1;farr[y][x]=100+dir+movedir*10;} break;
		case 3: if(dir!=2){dir=2;farr[y][x]=100+dir+movedir*10;} break;
		case 4: if(dir!=3){dir=3;farr[y][x]=100+dir+movedir*10;} break;
		case 5: if(dir!=4){dir=4;farr[y][x]=100+dir+movedir*10;} break;
		case 6: farr[y][x]=6 ;break;
		case 8: it=maxit;farr[y][x]=9; break;
	}
	if((x==prtin[1] and y==prtin[0])){
	//	farr[y][x]=11;
		x=prtot[1];y=prtot[0];dir=prtdir;
		
	}
	
	
	
}
farr[prtin[0]][prtin[1]]=-11;
farr[prtot[0]][prtot[1]]=-12;


//std::cout<<mod;
if(mod==7 and modd==8){
	mod=1;
}

	double pth4=0;	
	int pth3=0;
	for (int ggar=0;ggar<12;ggar++){
		
		for (int ggak=0;ggak<12;ggak++){
			if(arr[ggar][ggak]==2 or arr[ggar][ggak]==3 or arr[ggar][ggak]==4 or arr[ggar][ggak]==5  ){
				pth3++;
			}
			
		}
	pth4=pth3;
	}if(it==maxit){
	pth4-=100;}
	for(int buffc=0;buffc<12;buffc++){
		pth4+=buff[buffc]*wem[buffc];
	}
	
	if(pth4>254){
		pth4=0;
		
	}
	pth4-=trn;
	if(pth4>best-telo or brtf<10){
		if(pth4>best){
	best=pth4;}
	int pth2=0;
	int empt=0;
	
	
	
	
	std::cout<<std::endl;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if(doneport==1){
		std::cout<<"(uses portals)"<<std::endl;
	sarr[prtin[0]][prtin[1]]=11;
	sarr[prtot[0]][prtot[1]]=12;	}
	
	for (int ggar=0;ggar<12;ggar++){
		
		for (int ggak=0;ggak<12;ggak++){
			
			int search;
			
				search=arr[ggar][ggak];
				if(sarr[ggar][ggak]!=0 and search!=6){
					search=sarr[ggar][ggak];
					arr[ggar][ggak]=sarr[ggar][ggak];
				}
			//	search=farr[ggar][ggak];
			if(mod==1 or mod==2 or mod==0){
				switch(inp[ggar/3][ggak/3]){
					case 0:SetConsoleTextAttribute(hConsole, 8);break;
					case 1:SetConsoleTextAttribute(hConsole, 12);break;
					case 2:SetConsoleTextAttribute(hConsole, 2);break;
					case 3:SetConsoleTextAttribute(hConsole, 9);break;
					case 4:SetConsoleTextAttribute(hConsole, 4);break;
					case 5:SetConsoleTextAttribute(hConsole, 7);break;
					case 6:SetConsoleTextAttribute(hConsole, 11);break;
					case 7:SetConsoleTextAttribute(hConsole, 13);break;
					case 8:SetConsoleTextAttribute(hConsole, 10);break;
					case 9:SetConsoleTextAttribute(hConsole, 5);break;
					case 10:SetConsoleTextAttribute(hConsole, 4);break;
					case 11:SetConsoleTextAttribute(hConsole, 12);break;
					case 12:SetConsoleTextAttribute(hConsole, 14);break;
					case 13:SetConsoleTextAttribute(hConsole, 3);break;
					case 14:SetConsoleTextAttribute(hConsole, 1);break;
					case 15:SetConsoleTextAttribute(hConsole, 6);break;
					case 16:SetConsoleTextAttribute(hConsole, 7);break;
					case 17:SetConsoleTextAttribute(hConsole, 10);break;
					case 18:SetConsoleTextAttribute(hConsole, 11);break;
					case 19:SetConsoleTextAttribute(hConsole, 14);break;
					case 20:SetConsoleTextAttribute(hConsole, 13);break;
					
					
					
					
				}
			}
			
			switch(search){
				case 0:
				
					std::cout<<" ";
					empt++;
				break;
				case 1:
						
					std::cout<<"#";
				break;
				case 2:
					SetConsoleTextAttribute(hConsole, 15);
					std::cout<<"^";
					pth2++;
					
				break;
				case 3:
					SetConsoleTextAttribute(hConsole, 15);
					std::cout<<">";
					pth2++;
				break;
				case 4:
					SetConsoleTextAttribute(hConsole, 15);
					std::cout<<"V";
					pth2++;
				break;
				case 5:
				SetConsoleTextAttribute(hConsole, 15);
					std::cout<<"<";
					pth2++;
				break;
				case 6:
					SetConsoleTextAttribute(hConsole, 15);
					std::cout<<"X";
				break;
				case 8:
						
					std::cout<<" ";
				break;
				case 9:
					
					 
					
					
					std::cout<<"@";
				break;
				case 11:
					SetConsoleTextAttribute(hConsole, 14);	
					std::cout<<"O";
				break;
				case 12:
					SetConsoleTextAttribute(hConsole, 9);		
					std::cout<<"O";//out
				break;
				default:
					std::cout<<" ";
					empt++;
					break;
					
			}
			SetConsoleTextAttribute(hConsole, 15);}
	std::cout<<std::endl;
	}//SetConsoleTextAttribute(hConsole, 0);
	
	/*emp=0;//empty
	 trr=0;//extra try
	 skp=0;//chance to skip
	 cnt=0;//countdown
	 xrc=0;//extre rc
	 crc=0;//change to get
	 wbw=0;//wave to wave
	 aut=0;//autopilot
	 srt=0;//start*/
	 if(mod==7){
	 	pth3--;
	 }
	if(it==maxit){
		std::cout<<"there no path thogh"<<std::endl;
		std::cout<<std::endl<<best<<"-"<<bst;
		bst--;
		kilo++;
		if(kilo>klma){
			kilo=0;
			bst++;
		}
	}else{
		if(isoutput){
		std::ofstream myfile ("output.txt");
		if (myfile.is_open())
  {
  	
  	
  	char ffarr[12][12];
  	for(int i=0;i<12;i++){
	for(int j=0;j<12;j++){
	 switch(farr[i][j]){
    	
				case 0: ffarr[i][j] = ' ';break;
				case 1: ffarr[i][j] = '#';break;
				
				case 2: ffarr[i][j] = '|';break;
				case 3: ffarr[i][j] = '-';break;
				case 4: ffarr[i][j] = '|';break;
				case 5: ffarr[i][j] = '-';break;
				
				
				case 6: ffarr[i][j] = 'X';break;
				case 9: ffarr[i][j] = 'Q';break;
				case 11:ffarr[i][j] = 'O' ;break;
				case 12: ffarr[i][j] = 'O';break;
				
				case 112: ffarr[i][j] = '>'; break;
				case 114: ffarr[i][j] = '<'; break;
				
				case 121: ffarr[i][j] = '^'; break;
				case 123: ffarr[i][j] = 'v'; break;
				
				case 132: ffarr[i][j] = '>'; break;
				case 134: ffarr[i][j] = '<'; break;
				
				case 141: ffarr[i][j] = '^'; break;
				case 143: ffarr[i][j] = 'v'; break;
				
				
				default: ffarr[i][j] = '0'; break;
	
	}if(sarr[i][j]==1){
		ffarr[i][j] = '\u0219';
	}if(sarr[i][j]==9){
		ffarr[i][j] = '@';
	}
	}}
         
   
  	
	  
	  

myfile<<'\n';
	for(int i=0;i<4;i++){
	for(int j=0;j<4;j++){
		switch(inp[i][j]){
			case 0:myfile<<'#';break;
			case 1:myfile<<'@';break;
			case 2:myfile<<'K';break;
			case 3:myfile<<'S';break;
			case 4:myfile<<'+';break;
			case 5:myfile<<' ';break;
			case 6:myfile<<'I';break;
			case 7:myfile<<'_';break;
			case 8:myfile<<'N';break;
			case 9:myfile<<'^';break;
			case 10:myfile<<'/';break;
			case 11:myfile<<'=';break;
			case 12:myfile<<'"';break;
			
		}}myfile<<'\n';
	}	myfile<<'\n';
	
	for (int filout=0;filout<12;filout++){
    myfile << 
	ffarr[filout][0]<<ffarr[filout][1]<<ffarr[filout][2]<<
	ffarr[filout][3]<<ffarr[filout][4]<<ffarr[filout][5]<<
	ffarr[filout][6]<<ffarr[filout][7]<<ffarr[filout][8]<<
	ffarr[filout][9]<<ffarr[filout][10]<<ffarr[filout][11]<<
	'\n'
	;
}
	
	myfile<<'\n';
	myfile<<'\n';
myfile<<'\n';

    myfile << "1";
    for(int codecc=0;codecc<16;codecc++){
    	if(inp[codecc/4][codecc%4]<10){
    	myfile << "0" << inp[codecc/4][codecc%4];	
		}else{
		myfile << inp[codecc/4][codecc%4];	
		}
	}
	for(int codecc=-1;codecc<13;codecc++){
		for(int codek=-1;codek<13;codek++){
    	if(codecc==-1 or codecc==13 or codek==-1 or codek==13){
    		if(codecc==12 and codek==10){
    				myfile << "020";
			}else{
    	myfile << "010";}
		}else{
			switch(farr[codecc][codek]){
				case 0: myfile << "010";break;
				case 1: myfile << "010";break;
				case 6: myfile << "010";break;
				case 9: myfile << "010";break;
				case 11:myfile << "010" ;break;
				case 12: myfile << "010";break;
				
				case 112: myfile << "050"; break;
				case 114: myfile << "040"; break;
				
				case 121: myfile << "041"; break;
				case 123: myfile << "051"; break;
				
				case 132: myfile << "042"; break;
				case 134: myfile << "052"; break;
				
				case 141: myfile << "053"; break;
				case 143: myfile << "043"; break;
				default:  myfile << "010";break;
				
			}
		}
	}
  
  }}
		
	myfile.close();	
	}}
		
	std::cout<<std::endl;
	std::cout<<strr<<std::endl;
	std::cout<<std::endl;
	std::cout<<"path lenght"<<pth3-trn<<std::endl;
	std::cout<<"turns"<<trn<<std::endl;
	std::cout<<"firerate"<<3.2-(.2*buff[5])<<std::endl;
	int bsdmg=((500)*1.3*6*5)*(1+trn/10.0+trn/10.0+.6);
	std::cout<<"basedmg"<<bsdmg<<std::endl;
	std::cout<<"dps(not so accurate)"<<(  bsdmg*(pow(1.4,(pth3-12)))    )*(3.2-(.2*buff[5]))*((pow(0.333,buff[5])))<<std::endl;
	
	if(buff[5]>0){std::cout<<"damage reduction: "<<(1-pow(0.333,buff[5]))<<std::endl;}
	if(buff[3]>0){std::cout<<"additional trys: "<<buff[3]<<std::endl;}
	if(buff[9]>0){std::cout<<"chane to skip a wave: "<<(1-pow(0.9,buff[9]))<<std::endl;}
	if(buff[7]){std::cout<<"wave countdown lasts longer: "<<(1+3*buff[7])<<std::endl;}
	if(buff[10]>0){std::cout<<"more rc: "<<(1-pow(0.995,buff[10]))<<std::endl;}
	if(buff[12]>0){std::cout<<"chance to get 1 rc per wave: "<<(1+3*buff[12])<<std::endl;}
	if(buff[6]>0){std::cout<<"increased speed between waves: "<<5*(pow(0.8,buff[6]))<<std::endl;}
	if(buff[2]>0){std::cout<<"has autopilot: "<<std::endl;}
	if(buff[8]>0){std::cout<<"skip last distance by: "<<(1-pow(0.85,buff[8]))<<std::endl;}
	if(brtf>10){std::cout<<std::endl<<best<<"-"<<bst<<"@"<<code;}
	
}
}


	system("pause");
	return 0;
}
