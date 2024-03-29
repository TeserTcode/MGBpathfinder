#include <iostream>
#include <windows.h>
#include <gl/gl.h>
#include <math.h>
#include <fstream>
#include <algorithm>

#include <unordered_set>
#include <vector>

#include <cmath>
#include <ctime>
#include <cstdlib>

#include "customtiles.h"
#include "drawer.h"
#include "fileoutput.h"
#include "movestuff.h"
/* run this program using the console pauser or add your own getch, system("pause") or input lxoodg */
const std::string introi=
//"\n           Welcome to the MinerGunBuilderPathFinder MGBpf \n\n";
"";

const std::string intro=
" 0-custom ship input  \n 1-named custom ship / bruteforce   \n 4-lite bruteforce  \n 7-classic ships (mayhaps be broken)\n";
const std::string intro1=
" \n 0 -sanil  \n 1 -beast  \n 2 -fat trident  \n 3 -thunder  \n 4 -staricase \n 5 -piano  \n-1 -ultrabeast  \n-2 -one of captivates ship  \n-3 -stealth bomber  \n-4 -hyperbeast  \n  \n 6-random(reccomend)  \n 7-extreme random(no reccomend) \n  8-perfect bruteforce(long time)  \n 9-wave bruteforce  \n 10-optimised random (reccomend)"
;
 
const int mania = 1;
std::unordered_set<long long> idset;
//std::vector<long long> idlist;

void appindx(long long x) {
    //idlist.push_back(x);
    idset.insert(x);
}

bool isapp(long long x) {
	return false;
    return idset.count(x) > 0;
}
bool isapp2(long long x) {
	//return false;
    return idset.count(x) > 0;
}

double max(double a,double b){
	if(a<b){
		return b;
	}else{
		return a;	}
};
int main(int argc, char** argv) {
	srand (time(NULL));
	std::cout<<introi;
	while(true){
	
	//settings
	int raytr=3;//1-3  3 should be good
	int telo=5;//telorance for shwoing the best 1=show same performance 0=dont show anything until something better
	int strr=1;//extra quality for tile bruteforce (makis it longer N times)
	int minemp=-1;//number of empty tiles   set it to -1
	//int tile[]{};//usable tiles in tile bruteforce ex {5,6,7} {6,9,12} {6,7}
	int klma=500;//retry for fail (not matter much)
	double wem[]={0,0,0,0,-3,0,0,0,0,0,0,0,0};//weights of tiles ex.{0,0,0,0,-2.5,.5,0,0,0,0,0,0,0}
	int maxit=50000;//maximum iteration for pathfinding (not matter much)
	int rndrta=30;//randomly turns wrongly
int rndrt=30;
	int isprt=1;//use prtals
	bool isoutput=1;
	
	int boll[12][12];
		int doneport=0;
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
            //std::cout << name << " " << value << '\n';
            int num=std::atoi((value).c_str());
            
            	if(name=="0"){raytr=num;}
            	if(name=="1"){telo=num;}
            	if(name=="2"){strr=num;}
            	if(name=="3"){minemp=num;}
            		if(name=="9"){isprt=num;}
            	//case 4: raytr=value; break;
            	if(name=="5"){klma=num;}
            	//case 6: raytr=value; break;
            	if(name=="7"){maxit=num;}
            	if(name=="8"){rndrta=num;}
            	if(name=="10"){isoutput=num;}
            	if(name=="4"){
            		
            		int lngng=0;
            //	if(line.find("01")!=line.npos){ptile[lngng]=1;lngng++;}	
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
				if(line.find("16")!=line.npos){ptile[lngng]=16;lngng++;}
				if(line.find("17")!=line.npos){ptile[lngng]=17;lngng++;}
				if(line.find("18")!=line.npos){ptile[lngng]=18;lngng++;}
				if(line.find("19")!=line.npos){ptile[lngng]=19;lngng++;}
				if(line.find("20")!=line.npos){ptile[lngng]=20;lngng++;}
				if(line.find("21")!=line.npos){ptile[lngng]=21;lngng++;}
				
				tilelen=lngng;
			}
				
				if(name=="y")
            	//std::atoi((line.substr(line.find("01")+2,4)).c_str())
            		
            		if(line.find("01")!=line.npos){wem[0]=std::atof((line.substr(line.find("01")+2,4)).c_str());}
					
					if(line.find("05")!=line.npos){wem[4]=std::atof((line.substr(line.find("05")+2,4)).c_str());}
				//	if(line.find("06")!=line.npos){wem[5]=std::atof((line.substr(line.find("06")+2,4)).c_str());}
					if(line.find("07")!=line.npos){wem[6]=std::atof((line.substr(line.find("07")+2,4)).c_str());}	
            		
            		
				
            	
            	
            	
            	
            	
			
        }
        
    }
    else {
        std::cerr << "get the config2.txt file\n";
    }
    int tile[tilelen];
				for(int tileset=0;tileset<tilelen;tileset++){
					tile[tileset]=ptile[tileset];
			//	 std::cout  << "->" << tile[tileset] << '\n';
}for(int tileset=0;tileset<12;tileset++){
	if(wem[tileset]!=0){
//	std::cout << tileset+1 << " weighs " << wem[tileset] << '\n';
}
}
    
//	std::cout << '\n';
	
		int gfgg=0;
	
	
	std::cout<<'\n'<<intro ;
	std::cin>>mod;
	if(mod==4 or mod==5){
		std::cout<<'\n'<<"how long";
		std::cin>>brtf;
		std::cout<<'\n'<<"choose mod 0-custom  1-named cutsom  ";
      	std::cin>>mod;
      	if(mod==5){
      		lite=1;
		  }
		
}
if(mod==6){
		std::cout<<'\n'<<"how long";
		std::cin>>srtf;
		std::cout<<'\n'<<"choose mod 0-custom  1-named cutsom ";
      	std::cin>>mod;
      	site=1;
		
}

	
	int modd=0;
	if(mod==0){
	

	std::cout<<'\n'<<"give 16 tiles ranged from 1-12"<<'\n'<<"everything goes left to right then top to bottom"<<'\n';
	std::cin>>
	inp[0][0]>>inp[0][1]>>inp[0][2]>>inp[0][3]>>
	inp[1][0]>>inp[1][1]>>inp[1][2]>>inp[1][3]>>	
	inp[2][0]>>inp[2][1]>>inp[2][2]>>inp[2][3]>>
	inp[3][0]>>inp[3][1]>>inp[3][2]>>inp[3][3];
}
	if(mod==1){
		std::cout<<'\n'<<intro1;
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
	
	inp[0][0]=1; inp[0][1]=5;  inp[0][2]=5; inp[0][3]=5;
	inp[1][0]=5; inp[1][1]=5;  inp[1][2]=5; inp[1][3]=5;	
	inp[2][0]=5; inp[2][1]=5;  inp[2][2]=5; inp[2][3]=5;
	inp[3][0]=5; inp[3][1]=5;  inp[3][2]=5; inp[3][3]=5;
	
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
	case -4:
	inp[0][0]=5; inp[0][1]=5;  inp[0][2]=5; inp[0][3]=5;
	inp[1][0]=5; inp[1][1]=7;  inp[1][2]=5; inp[1][3]=5;	
	inp[2][0]=5; inp[2][1]=1;  inp[2][2]=5; inp[2][3]=5;
	inp[3][0]=5; inp[3][1]=5;  inp[3][2]=5; inp[3][3]=5;
	break;
	case 6:
		brtf=2147483645;
	//	std::cout<<"seed this will be used for tile brutefroce(6)";
	//int gfgf;
//	std::cin>>gfgf;
//	srand(gfgf);
	
	break;
		case 7:
			brtf=2147483645;
	//		std::cout<<"seed this will be used for tile brutefroce dont use";

	//std::cin>>gfgg;
	//srand(gfgg+code);
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
	std::cout<<'\n';}
	if (mod==7){
		int shipi=0;
				std::cout<<'\n'<<"ship waht 0-rider used 1-rider ... use ship id ";
				std::cin>>shipi;
				shipid=shipi;
	}

int best=0;
for(int gf=0;gf<144;gf++){
					boll[gf/12][gf%12]=0;
					}
	for(int bst=0;bst<brtf;bst++){
		
	//	rndrt=rndrta*(double)(((double)(strr)+1.0)/(bst%strr)+1.0)/5-1;
		rndrt=rndrta*(double) (   ( (double)(strr)+0.1 ) / (   (bst%strr)+0.1    )    ) / 5.0-2 ;
	//	rndrt*=5;
		
		if(GetKeyState('Q') & 0x8000){
			break;
		}
		if(GetKeyState('W') & 0x8000){
		srand (time(NULL));
		}
		if(GetKeyState('E') & 0x8000){
		bst=0;
		}
	int sest=0;
if(mod==1){

	
	if(modd==6 and bst%5==0){
				inp[0][0]=5+rand()%3; inp[0][1]=5+rand()%3;  inp[0][2]=5+rand()%3; inp[0][3]=6;
	inp[1][0]=5+rand()%3;inp[1][1]=5+rand()%3;  inp[1][2]=5+rand()%3; inp[1][3]=6;	
	inp[2][0]=5+rand()%3; inp[2][1]=5+rand()%3; inp[2][2]=5+rand()%3; inp[2][3]=6;
	inp[3][0]=5+rand()%3; inp[3][1]=5+rand()%3;  inp[3][2]=5+rand()%3;inp[3][3]=6;	
	//inp[rand()%4][rand()%3]=1;
	inp[2][1]=mania;
		brtf=2147483645;
			}
			
		if(modd==10 and bst%tilelen==0){
			
			while (true){
			
			brtf=2147483647;
		//	tile[rand()%tilelen]
				inp[0][0]=tile[rand()%tilelen]; inp[0][1]=tile[rand()%tilelen];  inp[0][2]=tile[rand()%tilelen]; inp[0][3]=6;
	inp[1][0]=tile[rand()%tilelen];inp[1][1]=tile[rand()%tilelen];  inp[1][2]=tile[rand()%tilelen]; inp[1][3]=6;	
	inp[2][0]=tile[rand()%tilelen]; inp[2][1]=tile[rand()%tilelen]; inp[2][2]=tile[rand()%tilelen]; inp[2][3]=6;
	inp[3][0]=tile[rand()%tilelen]; inp[3][1]=tile[rand()%tilelen];  inp[3][2]=5+rand()%3;inp[3][3]=6;	
	//inp[rand()%4][rand()%3]=1;
	inp[rand()%4][rand()%3]=mania;
	
		long long id=0;
		for (int intar=0;intar<4;intar++){
		for (int intak=0;intak<4;intak++){
			int inpw=inp[intar][intak];

		id=id<<(long long)4;
		id+=(long long)inpw;
	}
	}
	
	

	


	if(isapp2(id)==false){
		appindx(id);
		break;
			
	}else{
	//	std::cout<<id<<'\n';
	}
			}	}	
			
			
			
			if(modd==8){//////////////////////////////////////////////////////////////////////////////////////////////////////////
		//	std::cout<<"eyey";
				int s = tilelen;
				int div=strr;
				int ejx=1;
				int ejy=2;
				//std::cout<<code;
				if(tile[s-1]!=mania){
	ejx=(code/div)%2; div*=2;
	ejy=(code/div)%3; div*=3;
}
	brtf=2147483645;
				//srand(code);
			//	inp[rand()%4][rand()%3]=1;
	inp[0][0]=tile[(code/div)%s];div*=s;inp[0][1]=tile[(code/div)%s];div*=s;inp[0][2]=tile[(code/div)%s];div*=s;inp[0][3]=6;
	inp[1][0]=tile[(code/div)%s];div*=s;inp[1][1]=tile[(code/div)%s];div*=s;inp[1][2]=tile[(code/div)%s];div*=s;inp[1][3]=6;	
	inp[2][0]=tile[(code/div)%s];div*=s;inp[2][1]=tile[(code/div)%s];div*=s;inp[2][2]=tile[(code/div)%s];div*=s;inp[2][3]=6;
	inp[3][0]=tile[(code/div)%s];div*=s;inp[3][1]=tile[(code/div)%s];div*=s;inp[3][2]=tile[(code/div)%s];inp[3][3]=6;
	if(tile[s-1]!=mania){
//std::cout<<inp[2][3];
	inp[3][2]=inp[ejy][ejx];
	inp[ejy][ejx]=mania;
}
code++;
}
	
	
			if(modd==7){
				int t=7;
	inp[0][0]=1+rand()%t; inp[0][1]=1+rand()%t;  inp[0][2]=1+rand()%t; inp[0][3]=1+rand()%t;
	inp[1][0]=1+rand()%t; inp[1][1]=1+rand()%t;  inp[1][2]=1+rand()%t; inp[1][3]=1+rand()%t;	
	inp[2][0]=1+rand()%t; inp[2][1]=1+rand()%t;  inp[2][2]=1+rand()%t; inp[2][3]=1+rand()%t;
	inp[3][0]=1+rand()%t; inp[3][1]=1+rand()%t;  inp[3][2]=1+rand()%t; inp[3][3]=6;	
	srand(gfgg+code);
	inp[rand()%4][rand()%3]=mania;
	code+=+1;
		brtf=2147483645;
			}
			
			
			if(modd==9){
				int s = tilelen;
				int div=strr;
				int ejx=1;
				int ejy=2;
				if(tile[s-1]!=1){
	ejx=(code/div)%2; div*=2;
	ejy=(code/div)%4; div*=4;}
			brtf=2147483645;		
			//	inp[rand()%4][rand()%3]=1;
	inp[0][0]=tile[(code/div)%s];div*=s;inp[0][1]=tile[(code/div)%s];div*=s;inp[0][2]=6;inp[0][3]=6;
	inp[1][0]=tile[(code/div)%s];div*=s;inp[1][1]=tile[(code/div)%s];div*=s;inp[1][2]=6;inp[1][3]=6;	
	inp[2][0]=tile[(code/div)%s];div*=s;inp[2][1]=tile[(code/div)%s];div*=s;inp[2][2]=6;inp[2][3]=6;
	inp[3][0]=tile[(code/div)%s];div*=s;inp[3][1]=tile[(code/div)%s];inp[3][2]=6;inp[3][3]=6;
	if(tile[s-1]!=mania){

	inp[3][1]=inp[ejy][ejx];
	inp[ejy][ejx]=mania;

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
	
	for(int kol=0;kol<12;kol++){
	for(int bol=0;bol<12;bol++){
		arr[kol][bol]=0;
		sarr[kol][bol]=0;
		farr[kol][bol]=0;
	}	
		
	}
	
	long long id=0;
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
		id<<4;
		id+=inpw;
	}
	iax+=3;
	}
	if(isapp(id)==false){
		
	
	appindx(id);
	
	
	int xt=10;
	int yt=11;
		int kx=xt;
	
	int ky=yt;
	int dd=0;
		doneport=0;
					doneport=0;
				prtin[0]=-2;
				prtot[0]=-2;
						
			if(mod==7 and modd<1){
			
				
				
				int	karr[12][12]={
				1,1,1,1,1,1,1,1,1,1,1,1,	
				1,1,1,1,1,1,1,1,1,1,1,1,
				1,1,1,1,1,1,1,1,1,1,1,1,
				1,1,1,1,1,1,1,1,1,1,1,1,
				1,1,1,1,1,1,1,1,1,1,1,1,
				1,1,1,1,1,1,1,1,1,1,1,1,
				1,1,1,1,1,1,1,1,1,1,1,1,
				1,1,1,1,1,1,1,1,1,1,1,1,
				1,1,1,1,1,1,1,1,1,1,1,1,
				1,1,1,1,1,1,1,1,1,1,1,1,
				1,1,1,1,1,1,1,1,1,1,1,1,
				1,1,1,1,1,1,1,1,1,1,1,1};
				

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
							//if(krr==11 or trr==11 or trr==10 or krr==10){
						//	otot=1;	
						//	}
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
//	std::cout<<'\n'<<bst;
	
	for (int ggar=0;ggar<12;ggar++){
		
		for (int ggak=0;ggak<12;ggak++){
			
		//	std::cout<<arr[ggar][ggak];
	}
//	std::cout<<'\n';
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
//	int isprt=1;
//dir    1up 2right 3 down 4 left	
		if(inp[3][2]==7){
			arr[11][9]=1;}
			if(buff[6]!=minemp and minemp!=-1){
			it=maxit;
		}
	
		bool strtcrs=0;
	while(arr[y][x]!=9 and it < maxit){
		if(GetKeyState(VK_SHIFT) & 0x8000)
{
    break;
}
		it++;
		
		//	std::cout<<x<<","<<y<<"'"<<dir<<","<<ogdir<<"w"<<arr[y][x];
		//	std::cout<<'\n';-
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
		
if (((arr[y][x]==0 or arr[y][x]==9  or arr[y][x]==6)and(x<12 and x>-1 and y<12 and y>-1))  ){
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
			 (modd==8 and strr!=1 and 1+rand()%strr>strr/2 )or(inp[y/3][(x/3-1)]==9 and rnd>bst or (x==3 and y==5 and 0))){	
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
				if(!(((arr[y][x]==0 or arr[y][x]==9 or arr[y][x]==12345  or arr[y][x]==6)and(x<12 and x>-1 and y<12 and y>-1))) 
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
						arr[y][x]=6;
						y--;break;
					case 2:
						sarr[y][x]=6;arr[y][x]=6;
						x++;break;
					case 3:
						sarr[y][x]=6;arr[y][x]=6;
						y++;break;
					case 4:
						sarr[y][x]=6;arr[y][x]=6;
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
			
			isprt=1;
		//if( bst%5!=0  and   arr[y][x]!=1 and (  doneport==1 or isprt==0 and ( rand()%(rndrt*20)>20))    or bst<5  ){
			if( arr[y][x]!=1 and ( rand()%(rndrt)>1 or doneport==1  or (y==0) )){
		//	std::cout<<"ccc";
		arr[y][x]=0;}else{
		//	std::cout<<"k";
			int prtit=0;
			if(doneport==0 and isprt==1){
			//	std::cout<<"d";
				doneport=1;
				if(arr[y][x]==1){
					it=maxit;
				}
					prtin[0]=y;
					prtin[1]=x;
				//	bool boll[144];
				if(strr==1024){
					x=(bst/2)%12;
					y=(bst/12/2)%12;
					
					
					if(arr[y][x]==0){
					
					prtot[0]=y;
					prtot[1]=x;
				}else{
					prtin[0]=-1;
					prtin[1]=-1;
					
				}
					prtdir=(bst/144/2)%4+1;
					
					if(prtot[0]==0 and prtdir==4){prtdir=2;}
					if(prtot[0]==1 and prtdir==2){prtdir=4;}
					if(prtot[1]==0 and prtdir==1){prtdir=3;}
					if(prtot[1]==1 and prtdir==3){prtdir=1;}
				
				//std::cout<<"s";
					dir=prtdir;
					ogdir=dir;
					switch(dir){
					case 1:y--;break;
					case 2:x++;break;
					case 3:y++;break;
					case 4:x--;break;
					
			}
				}else{
				
				while(arr[y][x]!=0 and prtit<144){
					prtit++;
					if(mod==7){
					
					x=rand()%11;
					y=1+rand()%11;}else{
						while(boll[x][y]!=0 and rand()%5!=1){
						
					x=rand()%12;
					y=rand()%12;
					
					if(boll[x][y]==1 and x>1){
						x--;
					}
					if(bst<144*144*4){
					x=bst%12;
					y=(bst/12)%12;	
						
					}
				}
					}
					if(arr[y][x]!=0){
						prtot[0]=y;
					prtot[1]=x;
					boll[x][y]=1;
					}
				}
				if(prtit==144){
					it=maxit;
					doneport=0;
					for(int gf=0;gf<144;gf++){
					boll[gf/12][gf%12]=0;
					}
				}else{
					prtot[0]=y;
					prtot[1]=x;
					prtdir=1+rand()%4;
					if(prtot[0]==0 and prtdir==4){prtdir=2;}
					if(prtot[0]==1 and prtdir==2){prtdir=4;}
					if(prtot[1]==0 and prtdir==1){prtdir=3;}
					if(prtot[1]==1 and prtdir==3){prtdir=1;}
				
				//std::cout<<"s";
					dir=prtdir;
					ogdir=dir;
					switch(dir){
					case 1:y--;break;
					case 2:x++;break;
					case 3:y++;break;
					case 4:x--;break;
				}
				}}
				
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
	if (rand() % klma > dirch or rand() % rndrt == 2) {
  switch (ogdir) {
        case 1:
            switch (dir) {
                case 1:
                    dir = 4;
                    break;
                case 4:
                    dir = 2;
                    break;
                case 2:
                    y--;
                    break;
            }
            break;
        case 2:
            switch (dir) {
                case 2:
                    dir = 1;
                    break;
                case 1:
                    dir = 3;
                    break;
                case 3:
                    x--;
                    break;
            }
            break;
        case 3:
            switch (dir) {
                case 3:
                    dir = 2;
                    break;
                case 2:
                    dir = 4;
                    break;
                case 4:
                    y++;
                    break;
            }
            break;
        case 4:
            switch (dir) {
                case 4:
                    dir = 3;
                    break;
                case 3:
                    dir = 1;
                    break;
                case 1:
                    x++;
                    break;
            }
            break;
    }
} else {
    switch (ogdir) {
        case 1:
            switch (dir) {
                case 1:
                    dir = 2;
                    break;
                case 2:
                    dir = 4;
                    break;
                case 4:
                    y--;
                    break;
            }
            break;
        case 2:
            switch (dir) {
                case 2:
                    dir = 3;
                    break;
                case 3:
                    dir = 1;
                    break;
                case 1:
                    x--;
                    break;
            }
            break;
        case 3:
            switch (dir) {
                case 3:
                    dir = 4;
                    break;
                case 4:
                    dir = 2;
                    break;
                case 2:
                    y++;
                    break;
            }
            break;
        case 4:
            switch (dir) {
                case 4:
                    dir = 1;
                    break;
                case 1:
                    dir = 3;
                    break;
                case 3:
                    x++;
                    break;
            }
            break;
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

if(doneport==0 or false){
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

x=10;y=11;dir=1;it=0;
int ptrn=0;
for(int hj=0;hj<12;hj++){for(int hjs=0;hjs<12;hjs++){
	farr[hj][hjs]=sarr[hj][hjs];
	if(
	 (arr[hj][hjs-1]==3 and (arr[hj-1][hjs]==4 or arr[hj+1][hjs]==2)) or
	(arr[hj][hjs+1]==5 and (arr[hj-1][hjs]==4 or arr[hj+1][hjs]==2))
	){
		arr[hj][hjs]=6 ;farr[hj][hjs]=6 ;
	}
}
}
while(farr[y][x]!=9 and it<maxit){
	it++;
	int movedir=dir;
	if(movedir!=farr[y][x]-1){
		ptrn++;
	}
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
	if(sarr[x][y]==6){
		farr[x][y]=6;
		arr[x][y]=6;
	}
	switch(arr[y][x]){
		
		case 0:  break;
		case 1: it=maxit;farr[y][x]=9; break;
		case 2: if(dir!=1){dir=1;farr[y][x]=100+dir+movedir*10;} break;
		case 3: if(dir!=2){dir=2;farr[y][x]=100+dir+movedir*10;} break;
		case 4: if(dir!=3){dir=3;farr[y][x]=100+dir+movedir*10;} break;
		case 5: if(dir!=4){dir=4;farr[y][x]=100+dir+movedir*10;} break;
		case 6: farr[y][x]=6 ;break;
		case 8: it=maxit;farr[y][x]=9; break;
	}
	
	if((x==prtin[1] and y==prtin[0] and prtin[0]>-1)){
	//	farr[y][x]=11;
		x=prtot[1];y=prtot[0];dir=prtdir;
		
	}
	if(x<0 or x>11 or y<0 or y>11){
		it=maxit;
	}
	
	
}//std::cout<<ptrn;
if(prtin[0]>-1 and prtin[1]<13){

//farr[prtin[0]][prtin[1]]=11;
//farr[prtot[0]][prtot[1]]=12;
}

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
	pth4=pth3-trn;
	}if(it==maxit ){
	pth4-=100;}
		wem[6]=0;	wem[6]=0;
	
	for(int buffc=0;buffc<12;buffc++){
		pth4+=buff[buffc]*wem[buffc-1];
	}
	
	if(pth4>254){
		pth4=0;
		
	}
	
	//pth4-=ptrn;//std::cout<<trn;
	if((pth4>best-telo /*and (pth4>best or isapp(id) )*/) or brtf<10){
		
		
		/////////////////////////////////////////////////////
		
		
		
		
		
		
		if(pth4>best){//////////////////////////////////////////////
	best=pth4;}
	int pth2=0;
	int empt=0;
	
	


	std::cout<<'\n';
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if(doneport==1){
		std::cout<<"(uses portals)"<<'\n';
	sarr[prtin[0]][prtin[1]]=11;
	sarr[prtot[0]][prtot[1]]=12;
	arr[prtin[0]][prtin[1]]=11;
	arr[prtot[0]][prtot[1]]=12;
	farr[prtin[0]][prtin[1]]=11;
	farr[prtot[0]][prtot[1]]=12;	}

	
	for (int ggar=0;ggar<12;ggar++){
		
		for (int ggak=0;ggak<12;ggak++){
			
			int search;
			
				search=arr[ggar][ggak];
				if(sarr[ggar][ggak]!=0 and search!=6){
					search=sarr[ggar][ggak];
					arr[ggar][ggak]=sarr[ggar][ggak];
				}
			//	search=farr[ggar][ggak];
			SetConsoleTextAttribute(hConsole,color(mod,ggar,ggak,inp,search));
			
			
			draw(search,empt,pth2,farr[ggar][ggak],prtdir);
			SetConsoleTextAttribute(hConsole, 15);}
	std::cout<<'\n';
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
	 if(pth3-trn<0){
	 	it=maxit;
	 }
	if(it==maxit){
		std::cout<<"there no path thogh"<<'\n';
		std::cout<<'\n'<<best<<"-"<<bst;
		bst--;
		kilo++;
		if(kilo>klma){
			kilo=0;
			bst++;
		}
	}else{
		}
		ptrn=trn;//
	std::cout<<'\n';
//	std::cout<<strr<<'\n';

double bsdmg=((500)*1.3*6*5)*(1+ptrn/10.0+ptrn/10.0+.6);
double dps=(  bsdmg*(pow(1.4,(pth3-12)))    )*(3.2-(.2*buff[5]))*((pow(0.333,buff[5])));
	std::cout<<'\n';
	std::cout<<"TIER RANK - ";
	int ranka =(int)floor(log10(dps));
	int rankb = max(0,((pth3-buff[5]*3)/2.5)-19);
	int rankc = max(0,(((pth3-buff[5]*2.5))/75*5)*2-6);
	int rankd = floor(2.0*best/37.0);
	int ranke = ((best)*(pth3-buff[5]*2.5)/300);
	int rankf = ranke+rankd-30+19;
	switch(rankf){
		case -11: SetConsoleTextAttribute(hConsole, 12); std::cout<<"Congrats"<<'\n'; break;
		case -10: SetConsoleTextAttribute(hConsole, 9); std::cout<<"Cant get any worse than that"<<'\n'; break;
		case -9: SetConsoleTextAttribute(hConsole, 6); std::cout<<"???"<<'\n'; break;
		case -8: SetConsoleTextAttribute(hConsole, 6); std::cout<<"??"<<'\n'; break;
		case -7: SetConsoleTextAttribute(hConsole, 6); std::cout<<"?"<<'\n'; break;
		case -6: SetConsoleTextAttribute(hConsole, 6); std::cout<<"F---"<<'\n'; break;
		case -5: SetConsoleTextAttribute(hConsole, 6); std::cout<<"F---"<<'\n'; break;
		case -4: SetConsoleTextAttribute(hConsole, 6); std::cout<<"F--"<<'\n'; break;
		case -3: SetConsoleTextAttribute(hConsole, 6); std::cout<<"F--"<<'\n'; break;
		case -2: SetConsoleTextAttribute(hConsole, 6); std::cout<<"F-"<<'\n'; break;
		case -1: SetConsoleTextAttribute(hConsole, 6); std::cout<<"F-"<<'\n'; break;
		case 0: SetConsoleTextAttribute(hConsole, 6); std::cout<<"F"<<'\n'; break;
		case 1: SetConsoleTextAttribute(hConsole, 6); std::cout<<"F+"<<'\n'; break;
		case 2: SetConsoleTextAttribute(hConsole, 4); std::cout<<"D"<<'\n'; break;
		case 3: SetConsoleTextAttribute(hConsole, 4); std::cout<<"D+"<<'\n'; break;
		case 4: SetConsoleTextAttribute(hConsole, 2); std::cout<<"C"<<'\n'; break;
		case 5: SetConsoleTextAttribute(hConsole, 2); std::cout<<"C+"<<'\n'; break;
		case 6: SetConsoleTextAttribute(hConsole, 1); std::cout<<"B"<<'\n'; break;
		case 7: SetConsoleTextAttribute(hConsole, 1); std::cout<<"B+"<<'\n'; break;
		case 8: SetConsoleTextAttribute(hConsole, 9); std::cout<<"A"<<'\n'; break;
		case 9: SetConsoleTextAttribute(hConsole, 9); std::cout<<"A+"<<'\n'; break;
		case 10: SetConsoleTextAttribute(hConsole, 14); std::cout<<"S"<<'\n'; break;
		case 11: SetConsoleTextAttribute(hConsole, 14); std::cout<<"S+"<<'\n'; break;
		case 12: SetConsoleTextAttribute(hConsole, 14); std::cout<<"SS"<<'\n'; break;
		case 13: SetConsoleTextAttribute(hConsole, 14); std::cout<<"SS+"<<'\n'; break;
		case 14: SetConsoleTextAttribute(hConsole, 14); std::cout<<"SSS"<<'\n'; break;
		case 15: SetConsoleTextAttribute(hConsole, 14); std::cout<<"SSS+"<<'\n'; break;
		case 16: SetConsoleTextAttribute(hConsole, 11); std::cout<<"L"<<'\n'; break;
		default: SetConsoleTextAttribute(hConsole, 13); std::cout<<"G"<<'\n'; break;
	}
	std::cout<<ranka<<" - "<<rankb<<" - "<<rankc<<" - "<<rankd<<" - "<<ranke<<" - "<<rankf;
	 SetConsoleTextAttribute(hConsole, 15);
	std::cout<<'\n';
	std::cout<<"WAVE RANK - ";
	int wranka =(int)floor(log10(dps));
	int wrankb = max(0,((pth3-buff[5]*3+buff[6]*2+buff[7]+buff[12])/2.5)-19);
	int wrankc = max(0,(((pth3-buff[5]*2.5)+buff[6]*2+buff[7])/75*5)*2-6);
	int wrankd = floor(2.0*(best+buff[6]*buff[6]+buff[7])/37.0);
	int wranke = ((best)*(pth3-buff[5]*6+buff[6]*4+buff[7])/300);
	int wrankf = wrankb+wrankd-30+19-3-6;
	switch(wrankf){
		case -11: SetConsoleTextAttribute(hConsole, 12); std::cout<<"Congrats"<<'\n'; break;
		case -10: SetConsoleTextAttribute(hConsole, 9); std::cout<<"Cant get any worse than that"<<'\n'; break;
		case -9: SetConsoleTextAttribute(hConsole, 6); std::cout<<"???"<<'\n'; break;
		case -8: SetConsoleTextAttribute(hConsole, 6); std::cout<<"??"<<'\n'; break;
		case -7: SetConsoleTextAttribute(hConsole, 6); std::cout<<"?"<<'\n'; break;
		case -6: SetConsoleTextAttribute(hConsole, 6); std::cout<<"F---"<<'\n'; break;
		case -5: SetConsoleTextAttribute(hConsole, 6); std::cout<<"F---"<<'\n'; break;
		case -4: SetConsoleTextAttribute(hConsole, 6); std::cout<<"F--"<<'\n'; break;
		case -3: SetConsoleTextAttribute(hConsole, 6); std::cout<<"F--"<<'\n'; break;
		case -2: SetConsoleTextAttribute(hConsole, 6); std::cout<<"F-"<<'\n'; break;
		case -1: SetConsoleTextAttribute(hConsole, 6); std::cout<<"F-"<<'\n'; break;
		case 0: SetConsoleTextAttribute(hConsole, 6); std::cout<<"F"<<'\n'; break;
		case 1: SetConsoleTextAttribute(hConsole, 6); std::cout<<"F+"<<'\n'; break;
		case 2: SetConsoleTextAttribute(hConsole, 4); std::cout<<"D"<<'\n'; break;
		case 3: SetConsoleTextAttribute(hConsole, 4); std::cout<<"D+"<<'\n'; break;
		case 4: SetConsoleTextAttribute(hConsole, 2); std::cout<<"C"<<'\n'; break;
		case 5: SetConsoleTextAttribute(hConsole, 2); std::cout<<"C+"<<'\n'; break;
		case 6: SetConsoleTextAttribute(hConsole, 1); std::cout<<"B"<<'\n'; break;
		case 7: SetConsoleTextAttribute(hConsole, 1); std::cout<<"B+"<<'\n'; break;
		case 8: SetConsoleTextAttribute(hConsole, 9); std::cout<<"A"<<'\n'; break;
		case 9: SetConsoleTextAttribute(hConsole, 9); std::cout<<"A+"<<'\n'; break;
		case 10: SetConsoleTextAttribute(hConsole, 14); std::cout<<"S"<<'\n'; break;
		case 11: SetConsoleTextAttribute(hConsole, 14); std::cout<<"S+"<<'\n'; break;
		case 12: SetConsoleTextAttribute(hConsole, 14); std::cout<<"SS"<<'\n'; break;
		case 13: SetConsoleTextAttribute(hConsole, 14); std::cout<<"SS+"<<'\n'; break;
		case 14: SetConsoleTextAttribute(hConsole, 14); std::cout<<"SSS"<<'\n'; break;
		case 15: SetConsoleTextAttribute(hConsole, 14); std::cout<<"SSS+"<<'\n'; break;
		case 16: SetConsoleTextAttribute(hConsole, 11); std::cout<<"L"<<'\n'; break;
		case 17: SetConsoleTextAttribute(hConsole, 11); std::cout<<"L+"<<'\n'; break;
		case 18: SetConsoleTextAttribute(hConsole, 11); std::cout<<"L++"<<'\n'; break;
		case 19: SetConsoleTextAttribute(hConsole, 11); std::cout<<"L+++"<<'\n'; break;
		default: SetConsoleTextAttribute(hConsole, 13); std::cout<<"G"<<'\n'; break;
	}
	std::cout<<wranka<<" - "<<wrankb<<" - "<<wrankc<<" - "<<wrankd<<" - "<<wranke<<" - "<<wrankf;
	
	int qualitt[12]={ranka,rankb,rankc,rankd,ranke,rankf,wranka,wrankb,wrankc,wrankd,wranke,wrankf};
	
	
/*	switch(rankd){
		case 0: SetConsoleTextAttribute(hConsole, 6); std::cout<<"F"<<'\n'; break;
		case 1: SetConsoleTextAttribute(hConsole, 4); std::cout<<"D"<<'\n'; break;
		case 2: SetConsoleTextAttribute(hConsole, 2); std::cout<<"C"<<'\n'; break;
		case 3: SetConsoleTextAttribute(hConsole, 1); std::cout<<"B"<<'\n'; break;
		case 4: SetConsoleTextAttribute(hConsole, 9); std::cout<<"A"<<'\n'; break;
		case 5: SetConsoleTextAttribute(hConsole, 14); std::cout<<"S"<<'\n'; break;
		case 6: SetConsoleTextAttribute(hConsole, 11); std::cout<<"L"<<'\n'; break;
		default: SetConsoleTextAttribute(hConsole, 13); std::cout<<"G"<<'\n'; break;
	}*/
	 SetConsoleTextAttribute(hConsole, 15);
	
	std::cout<<'\n';
	std::cout<<"path lenght"<<pth3-trn<<'\n';
	std::cout<<"turns"<<trn<<'\n';
	std::cout<<"firerate"<<3.2-(.2*buff[5])<<'\n';
	
	std::cout<<"basedmg"<<bsdmg<<'\n';
	std::cout<<"dps(not so accurate)"<<dps<<'\n';
	
	if(buff[5]>0){std::cout<<"damage reduction: "<<(1-pow(0.333,buff[5]))<<'\n';}
	if(buff[3]>0){std::cout<<"additional trys: "<<buff[3]<<'\n';}
	if(buff[9]>0){std::cout<<"chane to skip a wave: "<<(1-pow(0.9,buff[9]))<<'\n';}
	if(buff[7]){std::cout<<"wave countdown lasts longer: "<<(1+3*buff[7])<<'\n';}
	if(buff[10]>0){std::cout<<"more rc: "<<(1-pow(0.995,buff[10]))<<'\n';}
	if(buff[12]>0){std::cout<<"chance to get 1 rc pefour wave: "<<(1+3*buff[12])<<'\n';}
	if(buff[6]>0){std::cout<<"increased speed between waves: "<<5*(pow(0.8,buff[6]))<<'\n';}
	if(buff[2]>0){std::cout<<"has autopilot: "<<'\n';}
	if(buff[8]>0){std::cout<<"skip last distance by: "<<(1-pow(0.85,buff[8]))<<'\n';}
	if(brtf>10){std::cout<<'\n'<<best<<"@"<<bst<<"-"<<code<<" -%"<<rndrt;}
	//std::cout<<'\n'<<wem[5];
	
	
	if(isoutput){
		outfileput(farr,inp,sarr,qualitt);
	}
	
	
}}appindx(id);
}

	system("pause");}
	return 0;
}
