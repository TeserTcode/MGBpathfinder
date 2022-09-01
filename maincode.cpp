#include <iostream>
#include <windows.h>
#include <gl/gl.h>
#include <math.h>
#include <fstream>
#include <algorithm>
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
				 std::cout << tileset << "->" << tile[tileset] << '\n';
}for(int tileset=0;tileset<12;tileset++){
	if(wem[tileset]!=0){
	std::cout << tileset+1 << " weighs " << wem[tileset] << '\n';
}
}
    
	std::cout << '\n';
	
	
	
	
	std::cout<<std::endl<<"choose mod 0-custom 1-named cutsom  4-lite bruteforce " ;
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
				std::cout<<std::endl<<"ship waht 0-rþder used 1-rider ... 7-fighter";
				std::cin>>shipi;
				shipid=shipi;
	}
 int code=0;
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
			if(modd==8){
				int s = tilelen;
				int div=strr;
				int ejx=1;
				int ejy=2;
				if(tile[s-1]!=1){
	ejx=(code/div)%2; div*=2;
	ejy=(code/div)%4; div*=4;}
				
			//	inp[rand()%4][rand()%3]=1;
	inp[0][0]=tile[(code/div)%s];div*=s;inp[0][1]=tile[(code/div)%s];div*=s;inp[0][2]=tile[(code/div)%s];div*=s;inp[0][3]=6;
	inp[1][0]=tile[(code/div)%s];div*=s;inp[1][1]=tile[(code/div)%s];div*=s;inp[1][2]=tile[(code/div)%s];div*=s;inp[1][3]=6;	
	inp[2][0]=tile[(code/div)%s];div*=s;inp[2][1]=tile[(code/div)%s];div*=s;inp[2][2]=tile[(code/div)%s];div*=s;inp[2][3]=6;
	inp[3][0]=tile[(code/div)%s];div*=s;inp[3][1]=tile[(code/div)%s];div*=s;inp[3][2]=tile[(code/div)%s];inp[3][3]=6;
	if(tile[s-1]!=1){

	inp[3][2]=inp[ejy][ejx];
	inp[ejy][ejx]=1;

    //inp[3][2]=inp[ejy][ejx];
//		inp[ejy][ejx]=1;
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
}

	code++;
}
}
	int gre=0;//greed burst
	int ejy=0;//upwards ejecter
	int ejx=0;//sideways ejector
	int emp=0;//empty
	int trr=0;//extra try0
	int skp=0;//chance to skip
	int cnt=0;//countdown
	int xrc=0;//extre rc
	int crc=0;//change to get
	int wbw=0;//wave to wave
	int aut=0;//autopilot
	int srt=0;//start
	
	if (site==1){
		
	}
	int iax=0;
	int iay=0;
		for (int intar=0;intar<4;intar++){
			iay=0;
		for (int intak=0;intak<4;intak++){
			
			
			switch(inp[intar][intak]){
				case 0:
					
					arr[iax+0][iay+0]= 1;  arr[iax+0][iay+1]= 1;  arr[iax+0][iay+2]= 1;
					arr[iax+1][iay+0]= 1;  arr[iax+1][iay+1]= 1;  arr[iax+1][iay+2]= 1;
					arr[iax+2][iay+0]= 1;  arr[iax+2][iay+1]= 1;  arr[iax+2][iay+2]= 1;
				break;
				case 1:
					ejy++;
					arr[iax+0][iay+0]= 1;  arr[iax+0][iay+1]= 1;  arr[iax+0][iay+2]= 1;
					arr[iax+1][iay+0]= 1;  arr[iax+1][iay+1]= 9;  arr[iax+1][iay+2]= 1;
					arr[iax+2][iay+0]= 1;  arr[iax+2][iay+1]= 0;  arr[iax+2][iay+2]= 0;
				break;
				case 2:
					aut++;
					arr[iax+0][iay+0]= 1;  arr[iax+0][iay+1]= 0;  arr[iax+0][iay+2]= 0;
					arr[iax+1][iay+0]= 1;  arr[iax+1][iay+1]= 1;  arr[iax+1][iay+2]= 0;
					arr[iax+2][iay+0]= 1;  arr[iax+2][iay+1]= 0;  arr[iax+2][iay+2]= 0;
				break;
				case 3:
					trr++;
					arr[iax+0][iay+0]= 1;  arr[iax+0][iay+1]= 0;  arr[iax+0][iay+2]= 0;
					arr[iax+1][iay+0]= 1;  arr[iax+1][iay+1]= 0;  arr[iax+1][iay+2]= 1;
					arr[iax+2][iay+0]= 0;  arr[iax+2][iay+1]= 0;  arr[iax+2][iay+2]= 1;
				break;
				case 4:
					gre++;
					arr[iax+0][iay+0]= 1;  arr[iax+0][iay+1]= 1;  arr[iax+0][iay+2]= 1;
					arr[iax+1][iay+0]= 0;  arr[iax+1][iay+1]= 0;  arr[iax+1][iay+2]= 0;
					arr[iax+2][iay+0]= 1;  arr[iax+2][iay+1]= 0;  arr[iax+2][iay+2]= 1;
				break;
				case 5:
					emp++;
					arr[iax+0][iay+0]= 0;  arr[iax+0][iay+1]= 0;  arr[iax+0][iay+2]= 0;
					arr[iax+1][iay+0]= 0;  arr[iax+1][iay+1]= 0;  arr[iax+1][iay+2]= 0;
					arr[iax+2][iay+0]= 0;  arr[iax+2][iay+1]= 0;  arr[iax+2][iay+2]= 0;
				break;
				case 6:
					wbw++;
					arr[iax+0][iay+0]= 0;  arr[iax+0][iay+1]= 0;  arr[iax+0][iay+2]= 1;
					arr[iax+1][iay+0]= 0;  arr[iax+1][iay+1]= 0;  arr[iax+1][iay+2]= 1;
					arr[iax+2][iay+0]= 0;  arr[iax+2][iay+1]= 0;  arr[iax+2][iay+2]= 1;
				break;
				case 7:
					cnt++;
					arr[iax+0][iay+0]= 0;  arr[iax+0][iay+1]= 0;  arr[iax+0][iay+2]= 0;
					arr[iax+1][iay+0]= 0;  arr[iax+1][iay+1]= 0;  arr[iax+1][iay+2]= 0;
					arr[iax+2][iay+0]= 1;  arr[iax+2][iay+1]= 1;  arr[iax+2][iay+2]= 1;
				break;
				case 8:
					srt++;
					arr[iax+0][iay+0]= 0;  arr[iax+0][iay+1]= 1;  arr[iax+0][iay+2]= 1;
					arr[iax+1][iay+0]= 0;  arr[iax+1][iay+1]= 0;  arr[iax+1][iay+2]= 0;
					arr[iax+2][iay+0]= 1;  arr[iax+2][iay+1]= 1;  arr[iax+2][iay+2]= 0;
				break;
				case 9:
					skp++;
					arr[iax+0][iay+0]= 1;  arr[iax+0][iay+1]= 1;  arr[iax+0][iay+2]= 0;
					arr[iax+1][iay+0]= 1;  arr[iax+1][iay+1]= 0;  arr[iax+1][iay+2]= 0;
					arr[iax+2][iay+0]= 0;  arr[iax+2][iay+1]= 0;  arr[iax+2][iay+2]= 0;
				break;
				case 10:
					xrc++;
					arr[iax+0][iay+0]= 1;  arr[iax+0][iay+1]= 0;  arr[iax+0][iay+2]= 0;
					arr[iax+1][iay+0]= 0;  arr[iax+1][iay+1]= 1;  arr[iax+1][iay+2]= 0;
					arr[iax+2][iay+0]= 0;  arr[iax+2][iay+1]= 0;  arr[iax+2][iay+2]= 1;
				break;
				case 11:
					ejx++;
					arr[iax+0][iay+0]= 1;  arr[iax+0][iay+1]= 1;  arr[iax+0][iay+2]= 1;
					arr[iax+1][iay+0]= 0;  arr[iax+1][iay+1]= 9;  arr[iax+1][iay+2]= 0;
					arr[iax+2][iay+0]= 1;  arr[iax+2][iay+1]= 1;  arr[iax+2][iay+2]= 1;
				break;
				case 12:
					crc++;
					arr[iax+0][iay+0]= 1;  arr[iax+0][iay+1]= 0;  arr[iax+0][iay+2]= 1;
					arr[iax+1][iay+0]= 1;  arr[iax+1][iay+1]= 0;  arr[iax+1][iay+2]= 1;
					arr[iax+2][iay+0]= 0;  arr[iax+2][iay+1]= 0;  arr[iax+2][iay+2]= 0;
				break;
				case 13:
					
					arr[iax+0][iay+0]= 1;  arr[iax+0][iay+1]= 0;  arr[iax+0][iay+2]= 1;
					arr[iax+1][iay+0]= 0;  arr[iax+1][iay+1]= 0;  arr[iax+1][iay+2]= 0;
					arr[iax+2][iay+0]= 1;  arr[iax+2][iay+1]= 0;  arr[iax+2][iay+2]= 0;
				break;
				case 14:
					
					arr[iax+0][iay+0]= 1;  arr[iax+0][iay+1]= 0;  arr[iax+0][iay+2]= 0;
					arr[iax+1][iay+0]= 1;  arr[iax+1][iay+1]= 0;  arr[iax+1][iay+2]= 0;
					arr[iax+2][iay+0]= 1;  arr[iax+2][iay+1]= 0;  arr[iax+2][iay+2]= 0;
				break;
				case 15:
					
					arr[iax+0][iay+0]= 1;  arr[iax+0][iay+1]= 1;  arr[iax+0][iay+2]= 1;
					arr[iax+1][iay+0]= 0;  arr[iax+1][iay+1]= 0;  arr[iax+1][iay+2]= 0;
					arr[iax+2][iay+0]= 0;  arr[iax+2][iay+1]= 0;  arr[iax+2][iay+2]= 0;
				break;
				case 16:
					
					arr[iax+0][iay+0]= 0;  arr[iax+0][iay+1]= 0;  arr[iax+0][iay+2]= 1;
					arr[iax+1][iay+0]= 0;  arr[iax+1][iay+1]= 0;  arr[iax+1][iay+2]= 0;
					arr[iax+2][iay+0]= 1;  arr[iax+2][iay+1]= 0;  arr[iax+2][iay+2]= 0;
				break;
				case 17:
					
					arr[iax+0][iay+0]= 1;  arr[iax+0][iay+1]= 0;  arr[iax+0][iay+2]= 0;
					arr[iax+1][iay+0]= 0;  arr[iax+1][iay+1]= 0;  arr[iax+1][iay+2]= 1;
					arr[iax+2][iay+0]= 1;  arr[iax+2][iay+1]= 0;  arr[iax+2][iay+2]= 0;
				break;
				
				
			}
			
		
			
			
			
		iay+=3;
	}
	iax+=3;
	}
	int xt=10;
	int yt=11;
		int kx=xt;
	
	int ky=yt;
	int dd=0;
	
			
			if(mod==7){
			
				
				
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
				
				
		/*		switch(shipid){
					case 0://rider used
					karr[4][5]=9;
					karr[5][5]=0;
					karr[6][5]=0;
					yt=6;
					xt=5;
					break;
					case 1://rider 
					karr[4][5]=9;
					karr[5][5]=0;
					karr[6][5]=0;
					karr[7][5]=0;
					yt=7;
					xt=5;
					break;
					case 7://fighter
					karr[4][3]=0;	karr[5][3]=0;
					karr[6][3]=0;	karr[7][3]=0;
					karr[4][4]=0;	karr[5][4]=0;
					karr[6][4]=0;	karr[6][5]=0;
					karr[6][6]=0;	karr[5][6]=0;
					karr[4][6]=0;karr[3][6]=9;
					yt=7;
					xt=3;
					break;
					case 11://fbacksword
					karr[8][5]=0;
					karr[7][2]=9;karr[7][3]=0;karr[7][4]=0;karr[7][5]=0;karr[7][6]=0;karr[7][7]=0;karr[7][8]=9;
					karr[6][4]=0;karr[6][5]=0;karr[6][6]=0;
					karr[5][3]=0;karr[5][4]=0;karr[5][5]=0;karr[5][6]=0;karr[5][7]=0;
					karr[4][3]=0;karr[4][4]=0;karr[4][5]=0;karr[4][6]=0;karr[4][7]=0;
					karr[3][4]=0;karr[3][5]=0;karr[3][6]=0;
					yt=8;
					xt=5;
					break;
					case 11://containership
					
					break;
					
					
				}*/
			
				
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
			if(wbw!=minemp and minemp!=-1){
			it=maxit;
		}
		int doneport=0;
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
			arr[3*cros+2][3*croc+1]=0;
			arr[3*cros+1][3*croc+2]=0;}
			if(inp[cros][croc]==12){
			if(arr[3*cros+2][3*croc+1]!=0){sarr[3*cros+2][3*croc+1]=arr[3*cros+2][3*croc+1];arr[3*cros+2][3*croc+1]=0;}}
			
			
			
			}}
	//	x--;break;
	int nofront =   0 ;
			switch(dir){
				case 1: if(arr[y+1][x]!=0){nofront=1;}break;
				case 2: if(arr[y][x+1]!=0){nofront=1;}break; 
				case 3: if(arr[y-1][x]!=0){nofront=1;}break; 
				case 4: if(arr[y][x-1]!=0){nofront=1;}break;  
			}
		nofront =   0 ;
			if((modd!=9 and modd!=8  and (rnd>bst or (mod==4 and nofront)))or
			 (modd==8 and strr!=1 and 1+rand()%strr>strr/2 and bst%strr!=0)){	
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
					//arr[y][x]=0;
			
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
			if(doneport==0){
				if(arr[y][x]==1){
					it=maxit;
				}
					prtin[0]=y;
					prtin[1]=x;
				while(arr[y][x]!=0 and prtit<144){
					prtit++;
					x=rand()%12;
					y=rand()%12;
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
			
			it=maxit;
	}
			
		}
	
			if(dir-ogdir==1 or dir-ogdir==-3 and prt==0){
				prt=1;
				
				if(arr[y][x]!=1){
			
		arr[y][x]=0;}
				x=dx;
			y=dy;
			pth--;
			trn++;
			
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
			
if(inp[3][3]==6 and arr[11][9]==1){
arr[11][9]=0;
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
	pth4+=ejy*wem[1];
	pth4+=aut*wem[2];
	pth4+=trr*wem[3];
	pth4+=gre*wem[4];
	pth4+=emp*wem[5];
	pth4+=wbw*wem[6];
	pth4+=cnt*wem[7];
	pth4+=srt*wem[8];
	pth4+=skp*wem[9];
	pth4+=xrc*wem[10];
	pth4+=ejy*wem[11];
	pth4+=crc*wem[12];
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
				}
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
	std::cout<<std::endl;
	std::cout<<strr<<std::endl;
	std::cout<<std::endl;
	std::cout<<"path lenght"<<pth3-trn<<std::endl;
	std::cout<<"turns"<<trn<<std::endl;
	std::cout<<"firerate"<<3.2-(.2*emp)<<std::endl;
	int bsdmg=((500)*1.3*6*5)*(1+trn/10.0+trn/10.0+.6);
	std::cout<<"basedmg"<<bsdmg<<std::endl;
	std::cout<<"dps(not so accurate)"<<(  bsdmg*(pow(1.4,(pth3-12)))    )*(3.2-(.2*emp))*((pow(0.333,emp)))<<std::endl;
	
	if(emp>0){std::cout<<"damage reduction: "<<(1-pow(0.333,emp))<<std::endl;}
	if(trr>0){std::cout<<"additional trys: "<<trr<<std::endl;}
	if(skp>0){std::cout<<"chane to skip a wave: "<<(1-pow(0.9,skp))<<std::endl;}
	if(cnt>0){std::cout<<"wave countdown lasts longer: "<<(1+3*cnt)<<std::endl;}
	if(xrc>0){std::cout<<"more rc: "<<(1-pow(0.995,wbw))<<std::endl;}
	if(crc>0){std::cout<<"chance to get 1 rc per wave: "<<(1+3*crc)<<std::endl;}
	if(wbw>0){std::cout<<"increased speed between waves: "<<5*(pow(0.8,wbw))<<std::endl;}
	if(aut>0){std::cout<<"has autopilot: "<<std::endl;}
	if(srt>0){std::cout<<"skip last distance by: "<<(1-pow(0.85,srt))<<std::endl;}
	if(brtf>10){std::cout<<std::endl<<best<<"-"<<bst;}
	
}
}
}

	system("pause");
	return 0;
}
