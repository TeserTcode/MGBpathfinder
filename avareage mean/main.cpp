#include <iostream>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int tryy=100;
	double out[tryy];
	srand(69);
	unsigned long long avg=0;
	unsigned long long geo=1;
	unsigned long long qua=0;
	long double agm[3];
	long double har=0;
	
	int percent=4;
	double multipler=10;
	int repeat=1;
	std::cout<<"percent";
	std::cin>>percent;
	std::cout<<"multipler";
	std::cin>>multipler;
	if(multipler>99){multipler/=100;}
		std::cout<<"number of crits";
	std::cin>>repeat;
	for(int i=0;i<tryy;i++){
			out[i]=1;
	}for(int j=0;j<repeat;j++){
	for(int i=0;i<tryy;i++){
		
		if((i)%100<percent){
			out[i]*=multipler;
		}
	}}
	for(int i=0;i<tryy;i++){
		avg+=out[i];
		qua+=out[i]*out[i];
		geo*=out[i];
		har+=1/(double)out[i];
		}
		
		
		
	long double 	avgo=avg/(double)tryy;
	long double 	geoo=pow(geo,1/(double)tryy);
	long double 	haro=tryy/har;
	long double 	quao=sqrt(qua/(double)tryy);
	long double 	coha=(qua/(double)tryy)/avgo;	
	long double 	ghm=sqrt(haro*geoo);	
	
	agm[1]=avgo;agm[0]=geoo;agm[3]=geoo;
		
		agm[0]=sqrt(agm[1]*agm[3]);agm[1]=(agm[3]+agm[1])/2;agm[3]=agm[0];
		agm[0]=sqrt(agm[1]*agm[3]);agm[1]=(agm[3]+agm[1])/2;agm[3]=agm[0];
		agm[0]=sqrt(agm[1]*agm[3]);agm[1]=(agm[3]+agm[1])/2;agm[3]=agm[0];
		agm[0]=sqrt(agm[1]*agm[3]);agm[1]=(agm[3]+agm[1])/2;agm[3]=agm[0];
		agm[0]=sqrt(agm[1]*agm[3]);agm[1]=(agm[3]+agm[1])/2;agm[3]=agm[0];
	 std::cout<<std::endl<<"contra h.:"<<coha<<std::endl;
	std::cout<<"quadratic:"<<quao<<std::endl;
	std::cout<<"avarage  :"<<avgo<<std::endl;
	std::cout<<"AGM      :"<<agm[1]<<std::endl;
	std::cout<<"geometric:"<<geoo<<std::endl;
	std::cout<<"GHM      :"<<ghm <<std::endl;
	std::cout<<"harmonic :"<<haro<<std::endl;
   
	
	return 0;
}
