#include<iostream.h>

void fetch()
{
	CP++;
	PC.e(); MR.l(); PC.val++;
	CP++;
	read(); IR.L(); MS.l();      //IF MS AND IR ARE SAME PLEASE REMOVE ACCORDINGLY
//	rom(RAM[PC.val]);  //this may eliminate IR and MS alltogether
}

int CP; 			 	//declaration of Clock Pulse 

void rom(int n)
{
	switch(n)
	{
		case 0:											//nop
				fetch();   					//fetch() must be a globally declared function
				CP++;
				break;
		case 1:  										//adi xx
				CP++; 
				PC.e(); MR.l(); PC.val++;
				CP++;
				read(); OR.l();
				CP++
				AR.e(); ALU(add);  AR.l();  
				fetch();
				break;
		
		case 2: 								//subi xx
				CP++; 
				PC.e(); MR.l(); PC.val++;
				CP++;
				read(); OR.l();
				CP++
				AR.e(); ALU(sub);  AR.l();  
				fetch();
				break;


		case 3: 									//xri xx
				CP++; 
				PC.e(); MR.l(); PC.val++;
				CP++;
				read(); OR.l();
				CP++
				AR.e(); ALU(xr);  AR.l();  
				fetch();
				break;


		case 4:
				CP++; 								//ani xx
				PC.e(); MR.l(); PC.val++;
				CP++;
				read(); OR.l();
				CP++
				AR.e(); ALU(land);  AR.l();  
				fetch();
				break;


		case 5:
				CP++; 								//ori xx
				PC.e(); MR.l(); PC.val++;
				CP++;
				read(); OR.l();
				CP++
				AR.e(); ALU(lor);  AR.l();  
				fetch();
				break;


		case 6:
				CP++; 							//cmi xx
				PC.e(); MR.l(); PC.val++;
				CP++;
				read(); OR.l();
				CP++
				AR.e(); ALU(cmp);   
				fetch();
				break;
		
		case 7:
				CP++;  						//stop 
				
				break;
		case 8:
				//return flag function		
				break;
		
		case 9: 							//add <R>
				CP++;
				PC.val++;
				RG[RAM[PC.val]-26].e();
				OR.l(); 
				CP++;
				AR.e(); ALU(add);  AR.l();
				fetch();
				break;
	
		case 10: 							//sub<R>
				CP++;
				PC.val++;
				RG[RAM[PC.val]-26].e();
				OR.l(); 
				CP++;
				AR.e(); ALU(sub);  AR.l();
				fetch();
				break;
	
		case 11: 								//xor<R>
				CP++;
				PC.val++;
				RG[RAM[PC.val]-26].e();
				OR.l(); 
				CP++;
				AR.e(); ALU(xr);  AR.l();
				fetch();
				break;
		
		case 12: 											//AND<R>		
				CP++;
				PC.val++;
				RG[RAM[PC.val]-26].e();
				OR.l(); 
				CP++;
				AR.e(); ALU(land);  AR.l();
				fetch();
				break;
		
		case 13: 												//OR<R>
				CP++;
				PC.val++;
				RG[RAM[PC.val]-26].e();
				OR.l(); 
				CP++;
				AR.e(); ALU(lor);  AR.l();
				fetch();
				break;
		
		case 14: 													//cmp<R>
				CP++;
				PC.val++;
				RG[RAM[PC.val]-26].e();
				OR.l(); 
				CP++;
				AR.e(); ALU(cmp);
				fetch();
				break;
	
		case 15:   												//movs()
				CP++
				PC.val++;
				RG[RAM[PC.val]-26].e();
				ALU(pass0);
				AR.l();
				fetch();
				break;
		 
		case 16: 													//movd()
				CP++;
				AR.l();		
				PC.val++;
				RG[RAM[PC.val]-26].l();
				break;
		
		case 17: 						//movi <R>	xx										
				CP++;
				Pc.e(); MR.l(); PC.val++;
				CP++;
				read(); 
				PC.val++;
				RG[RAM[PC.val]-26].l();
				fetch();
				break;

		case 18:  					//stor <R>
				CP++;
				AR.e(); MR.l();
				CP++;
				PC.val++;
				RG[RAM[PC.val]-26].e();
				write();
				fetch();
				break;
		
		case 19: 				//load <R>
				CP++;
				AR.e(); MR.l();
				CP++;
				read();
				PC.val++;
				RG[RAM[PC.val]-26].l();
				fetch()
				break;
	
		case 20:  			//push <R>
				CP++;
				SP.val--;
				SP.e(); MR.l();
				CP++;
				PC.val++;
				RG[RAM[PC.val]-26].e();
				write();
				fetch();
				break;

		 case 21: 					//pop <R>
				CP++;
				SP.e(); MR.l(); SP.val++;
				CP++
				read(); 
				PC.val++;
				RG[RAM[PC.val]-26].l();
				fetch();
				break;

			case 22: 					//jumpd <FL> xx
				CP++;
				PC.e(); MR.l(); PC.val++; //put flag function here
				CP++;
				read(); PC.l();
				fetch();
				break;

			case 23: 				//jmpr <FL>
				CP++;
				//flag operations
				CP++;	
				AR.e(); PC.l();
				fetch();
				break;
			
			case 24:  				//cd <FL> xx
					CP++;
					PC.e(); MR.l(); PC.val++; 
					//flag operations
					CP++;
					read(); OR.l(); SP.val--;
					CP++;
					SP.e(); MR.l();
					CP++;
					PC.e(); write();
					CP++;
					OR.e(); PC.l();
					fetch();
					break;

			case 25:   		//cr <FL>
					CP++;
					//flag operations
					CP++;
					SP.val--;
					CP++;
					SP.e(); MR.l();
					CP++;
					PC.e(); write();
					CP++;
					AR.e(); PC.l();
					fetch();
					break;



	}

}
