#include<iostream.h>
void fetch()
{
	CP++;
	PC.e(); MR.l(); PC.val++;
	CP++;
	read(); IR.L(); MS.l();      //IF MS AND IR ARE SAME PLEASE REMOVE ACCORDINGLY
//	rom(RAM[PC.val]);  //this may eliminate IR and MS alltogether
}
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
				RG[RAM[PC.val]-26].e();
				PC.val++;
				OR.l(); 
				CP++;
				AR.e(); ALU(add);  AR.l();
				fetch();
				break;
	
		case 10: 							//sub<R>
				CP++;
				RG[RAM[PC.val]-26].e();
				PC.val++;
				OR.l(); 
				CP++;
				AR.e(); ALU(sub);  AR.l();
				fetch();
				break;
	
		case 11: 								//xor<R>
				CP++;
				RG[RAM[PC.val]-26].e();
				PC.val++;
				OR.l(); 
				CP++;
				AR.e(); ALU(xr);  AR.l();
				fetch();
				break;
		
		case 12: 											//AND<R>		
				CP++;
				RG[RAM[PC.val]-26].e();
				PC.val++;
				OR.l(); 
				CP++;
				AR.e(); ALU(land);  AR.l();
				fetch();
				break;
		
		case 13: 												//OR<R>
				CP++;
				RG[RAM[PC.val]-26].e();
				PC.val++;
				OR.l(); 
				CP++;
				AR.e(); ALU(lor);  AR.l();
				fetch();
				break;
		
		case 14: 													//cmp<R>
				CP++;
				RG[RAM[PC.val]-26].e();
				PC.val++;
				OR.l(); 
				CP++;
				AR.e(); ALU(cmp);
				fetch();
				break;
	
		case 15:   												//movs()
				CP++
				RG[RAM[PC.val]-26].e();
				PC.val++;
				ALU(pass0);
				AR.l();
				fetch();
				break;
		 
		case 16: 													//movd()
				CP++;
				AR.l();		
				RG[RAM[PC.val]-26].l();
				PC.val++;
				break;
	
	
	}

}
