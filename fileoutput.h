#include <fstream>
#include <string>
std::string bar(int x,int min,int max){
	std::string a="";
	double dif=(max-min)/10;
	
	if(x>min+dif*0){a+="#";}else{a+=".";}
	if(x>min+dif*1){a+="#";}else{a+=".";}
	if(x>min+dif*2){a+="#";}else{a+=".";}
	if(x>min+dif*3){a+="#";}else{a+=".";}
	if(x>min+dif*4){a+="#";}else{a+=".";}
	if(x>min+dif*5){a+="#";}else{a+=".";}
	if(x>min+dif*6){a+="#";}else{a+=".";}
	if(x>min+dif*7){a+="#";}else{a+=".";}
	if(x>min+dif*8){a+="#";}else{a+=".";}
	if(x>min+dif*9){a+="#";}else{a+=".";}
	if(x>min+dif*10){a+="#";}else{a+=".";}
	
	return a;
}

void outfileput(int farr[12][12],int inp[4][4],int sarr[12][12],int qualitt[12]){


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
		ffarr[i][j] = '#';
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
  
  }
  myfile<<'\n';myfile<<'\n';
  
myfile<<"TIER-RANK DPS - ";myfile<<qualitt[0];myfile<<" --- "<<bar(qualitt[0],6,16)<<'\n';
myfile<<"TIER-RANK 2x reduced DPS - ";myfile<<qualitt[1];myfile<<" --- "<<bar(qualitt[1],7,17)<<'\n';
myfile<<"TIER-RANK round reduced DPS - ";myfile<<qualitt[2];myfile<<" --- "<<bar(qualitt[2],0,6)<<'\n';
myfile<<"TIER-RANK PATH - ";myfile<<qualitt[3];myfile<<" --- "<<bar(qualitt[3],0,4)<<'\n';
myfile<<"TIER-RANK reduced PATH - ";myfile<<qualitt[4];myfile<<" --- "<<bar(qualitt[4],13,23)<<'\n';
myfile<<'\n';
myfile<<"TIER-RANK - ";myfile<<qualitt[5];myfile<<" --- "<<bar(qualitt[5],-11,16)<<'\n';
myfile<<'\n';
myfile<<'\n';
myfile<<"WAVE-RANK DPS - ";myfile<<qualitt[6];myfile<<" --- "<<bar(qualitt[6],6,16)<<'\n';
myfile<<"WAVE-RANK 2x reduced DPS - ";myfile<<qualitt[7];myfile<<" --- "<<bar(qualitt[7],15,25)<<'\n';
myfile<<"WAVE-RANK round reduced DPS - ";myfile<<qualitt[8];myfile<<" --- "<<bar(qualitt[8],0,8)<<'\n';
myfile<<"WAVE-RANK PATH - ";myfile<<qualitt[9];myfile<<" --- "<<bar(qualitt[9],1,11)<<'\n';
myfile<<"WAVE-RANK reduced PATH - ";myfile<<qualitt[10];myfile<<" --- "<<bar(qualitt[10],20,30)<<'\n';
myfile<<'\n';
myfile<<"WAVE-RANK - ";myfile<<qualitt[11];myfile<<" --- "<<bar(qualitt[11],-11,16)<<'\n';
  
  
  }
		
	myfile.close();	};
