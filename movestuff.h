void ogdircng(int ogdir,int dir,int x, int y){

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
			}}
			
			
void ogdircngl(int ogdir,int dir,int x, int y){
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




 void turnaa(int ogdir,int dir,int x ,int y){



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
    }}
			