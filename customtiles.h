int cts(int indx, int indy){
	int op;
	int arr[3][3];
	switch(indx){
			case 0:
					
					arr[0][0]= 1;  arr[0][1]= 1;  arr[0][2]= 1;
					arr[1][0]= 1;  arr[1][1]= 1;  arr[1][2]= 1;
					arr[2][0]= 1;  arr[2][1]= 1;  arr[2][2]= 1;
				break;
				case 1:
			
					arr[0][0]= 1;  arr[0][1]= 1;  arr[0][2]= 1;
					arr[1][0]= 1;  arr[1][1]= 9;  arr[1][2]= 1;
					arr[2][0]= 1;  arr[2][1]= 0;  arr[2][2]= 0;
				break;
				case 2:
				
					arr[0][0]= 1;  arr[0][1]= 0;  arr[0][2]= 0;
					arr[1][0]= 1;  arr[1][1]= 1;  arr[1][2]= 0;
					arr[2][0]= 1;  arr[2][1]= 0;  arr[2][2]= 0;
				break;
				case 3:
				
					arr[0][0]= 1;  arr[0][1]= 0;  arr[0][2]= 0;
					arr[1][0]= 1;  arr[1][1]= 0;  arr[1][2]= 1;
					arr[2][0]= 0;  arr[2][1]= 0;  arr[2][2]= 1;
				break;
				case 4:
				
					arr[0][0]= 1;  arr[0][1]= 0;  arr[0][2]= 1;
					arr[1][0]= 0;  arr[1][1]= 0;  arr[1][2]= 0;
					arr[2][0]= 1;  arr[2][1]= 0;  arr[2][2]= 1;
				break;
				case 5:
				
					arr[0][0]= 0;  arr[0][1]= 0;  arr[0][2]= 0;
					arr[1][0]= 0;  arr[1][1]= 0;  arr[1][2]= 0;
					arr[2][0]= 0;  arr[2][1]= 0;  arr[2][2]= 0;
				break;
				case 6:
				
					arr[0][0]= 0;  arr[0][1]= 0;  arr[0][2]= 1;
					arr[1][0]= 0;  arr[1][1]= 0;  arr[1][2]= 1;
					arr[2][0]= 0;  arr[2][1]= 0;  arr[2][2]= 1;
				break;
				case 7:
				
					arr[0][0]= 0;  arr[0][1]= 0;  arr[0][2]= 0;
					arr[1][0]= 0;  arr[1][1]= 0;  arr[1][2]= 0;
					arr[2][0]= 1;  arr[2][1]= 1;  arr[2][2]= 1;
				break;
				case 8:
				
					arr[0][0]= 0;  arr[0][1]= 1;  arr[0][2]= 1;
					arr[1][0]= 0;  arr[1][1]= 0;  arr[1][2]= 0;
					arr[2][0]= 1;  arr[2][1]= 1;  arr[2][2]= 0;
				break;
				case 9:
				
					arr[0][0]= 1;  arr[0][1]= 1;  arr[0][2]= 0;
					arr[1][0]= 1;  arr[1][1]= 0;  arr[1][2]= 0;
					arr[2][0]= 0;  arr[2][1]= 0;  arr[2][2]= 0;
				break;
				case 10:
				
					arr[0][0]= 1;  arr[0][1]= 0;  arr[0][2]= 0;
					arr[1][0]= 0;  arr[1][1]= 1;  arr[1][2]= 0;
					arr[2][0]= 0;  arr[2][1]= 0;  arr[2][2]= 1;
				break;
				case 11:
			
					arr[0][0]= 1;  arr[0][1]= 1;  arr[0][2]= 1;
					arr[1][0]= 0;  arr[1][1]= 9;  arr[1][2]= 0;
					arr[2][0]= 1;  arr[2][1]= 1;  arr[2][2]= 1;
				break;
				case 12:
				
					arr[0][0]= 1;  arr[0][1]= 0;  arr[0][2]= 1;
					arr[1][0]= 1;  arr[1][1]= 0;  arr[1][2]= 1;
					arr[2][0]= 0;  arr[2][1]= 0;  arr[2][2]= 0;
				break;
				case 13:
					
					arr[0][0]= 1;  arr[0][1]= 0;  arr[0][2]= 1;
					arr[1][0]= 0;  arr[1][1]= 0;  arr[1][2]= 0;
					arr[2][0]= 1;  arr[2][1]= 0;  arr[2][2]= 0;
				break;
				case 14:
					
					arr[0][0]= 1;  arr[0][1]= 0;  arr[0][2]= 0;
					arr[1][0]= 1;  arr[1][1]= 0;  arr[1][2]= 0;
					arr[2][0]= 1;  arr[2][1]= 0;  arr[2][2]= 0;
				break;
				case 15:
					
					arr[0][0]= 1;  arr[0][1]= 1;  arr[0][2]= 1;
					arr[1][0]= 0;  arr[1][1]= 0;  arr[1][2]= 0;
					arr[2][0]= 0;  arr[2][1]= 0;  arr[2][2]= 0;
				break;
				case 16:
					
					arr[0][0]= 0;  arr[0][1]= 0;  arr[0][2]= 1;
					arr[1][0]= 0;  arr[1][1]= 0;  arr[1][2]= 0;
					arr[2][0]= 1;  arr[2][1]= 0;  arr[2][2]= 0;
				break;
				case 17:
					
					arr[0][0]= 1;  arr[0][1]= 0;  arr[0][2]= 0;
					arr[1][0]= 0;  arr[1][1]= 0;  arr[1][2]= 1;
					arr[2][0]= 1;  arr[2][1]= 0;  arr[2][2]= 0;
				break;
			
		
		
		
	}
	switch(indy){
		case 1:op=arr[0][0];break;
		case 2:op=arr[0][1];break;
		case 3:op=arr[0][2];break;
		
		case 4:op=arr[1][0];break;
		case 5:op=arr[1][1];break;
		case 6:op=arr[1][2];break;
		
		case 7:op=arr[2][0];break;
		case 8:op=arr[2][1];break;
		case 9:op=arr[2][2];break;
		
		
	}
	
	
	
	
	
	return op;
}
