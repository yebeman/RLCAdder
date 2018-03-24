#define COMMENT_STRING         "This program adds resistors, capacitors and inductors that are in parallel and series"
#define COMMENT_PROGRAM_NAME   "RLC Component ADDER"
#define COMMENT_VERSION_STRING "rlc 1.0"
#define COMMENT_VERSION_NUMBER 1,0,0,0 /* major, minor, revision, subrevision */
#define COMMENT_AUTHORS        "Yebeltal Asseged /Yebeman/"



#include <tigcclib.h>
#include <math.h>
#include <stdio.h>
#include "rlcadd.h" // include our special header file

// pause the program
inline void pause(void) {

    printf("\nPress any key to return tothe Menu.\nPress ESC key twice to go to the Home Screen...");
    ngetchx();    
}



double inputs(int type){
	int maxNumb=50;
	char numbers[maxNumb];
	int counter=0;
	
	long double Answer; // This is the answer
	
	short int get=1;
	short int afterD=1;
	
	long double numbersD[maxNumb];
	long double wantedN[maxNumb-40];
	int wantedCount=0;
	
	long double temp=0;
	int signComma[maxNumb];
	int commaCount=0;
	
	int signPeri[maxNumb];
	int periCount=0;
	
	int milli[20];
	int m=0;
	int killo[20];
	int k=0;
	int micro[20];
	int u=0;
	int pico[20];
	int p=0;
	int nano[20];
	int n=0;
	int mega[20];
	int g=0;
	
	int tempC=0;
	while (tempC<20) {
		milli[tempC]=-1;
		killo[tempC]=-1;
		micro[tempC]=-1;
		pico[tempC]=-1;
		nano[tempC]=-1;
		mega[tempC]=-1;
		tempC++;
	}
	
	
		tempC=0;
	while (tempC<10) {
		wantedN[tempC]=-1;
		tempC++;
	}	
	
	
	tempC=0;
	while (tempC<50) {
		numbersD[tempC]=-1;
		tempC++;
	}	
	
	
	int perZ=1;
	
	if(type==1||type==3)
		printf("\n Enter as many components as you want with a comma  in between.Use k or K for killo, p for pico, m for milli, u for mico, n for nano and M for mega. Avoid using SI units and press Enter when you are done\n Enter the values:\n");
	else if(type==4||type==5||type==6)
		printf("\n Enter frequency, resistance and capacitance with a comma in between.Use k or K for killo, p for pico, m for milli, u for mico, n for nano and M for mega. Avoid using SI units and press Enter when you are done\n Enter the values:\n");
	else if(type==8||type==9||type==10)
		printf("\n Enter frequency, resistance and Inductance with a comma in between.Use k or K for killo, p for pico, m for milli, u for mico, n for nano and M for mega. Avoid using SI units and press Enter when you are done\n Enter the values:\n");
	else if(type==7||type==11)
		printf("\n Enter frequency, resistance, capacitance and Inductace with a comma in between.Use k or K for killo, p for pico, m for milli, u for mico, n for nano and M for mega. Avoid using SI units and press Enter when you are done\n Enter the values:\n");
	
	 
	
		 while (get) {
		 	numbers[counter]='d';
		 
		 						while (!((numbers[counter] >= '0' && numbers[counter] <= '9') ||((double)numbers[counter]-48)==-35||((double)numbers[counter]-48)==-2||((double)numbers[counter]-48)==-4|| numbers[counter]=='K'||numbers[counter]=='k'||numbers[counter]=='p'||numbers[counter]=='m'||numbers[counter]=='M'||numbers[counter]=='n'||numbers[counter]=='u')) {
            numbers[counter]= ngetchx();
        }
       				      
       				     printf("%c", numbers[counter]);
       				     if(numbers[counter]=='K'||numbers[counter]=='k'||numbers[counter]=='p'||numbers[counter]=='m'||numbers[counter]=='M'||numbers[counter]=='n'||numbers[counter]=='u')
       				      {
       				      if(numbers[counter]=='K'||numbers[counter]=='k')
       				      {killo[k]=commaCount;
       				      k++;}
       				      else if(numbers[counter]=='M')
       				      {mega[g]=commaCount;
       				      g++;}
       				      else if(numbers[counter]=='m')
       				      {milli[m]=commaCount;
       				      m++;}
       				      else if(numbers[counter]=='u')
       				      {micro[u]=commaCount;
       				      u++;}
       				      else if(numbers[counter]=='p')
       				      {pico[p]=commaCount;
       				      p++;}
       				      else
       				      {nano[n]=commaCount;
       				      n++;}
       				      continue;	
       				      }
       				     numbersD[counter]=(double)numbers[counter]-48;
       				     
       				    
       				     if(numbersD[counter]==-4)
       				     {signComma[commaCount]=counter;
       				     commaCount++;
       				     if(perZ)
       				    {signPeri[periCount]=counter; 
       				    periCount++;}
       				     perZ=1;}
       				     
       				     if(numbersD[counter]==-2)
       				    {perZ=0; 
       				    signPeri[periCount]=counter; 
       				    periCount++;}
       				  
       				     
       				     if(counter>=maxNumb||numbersD[counter]==-35)
       				    { get=0;
       				    if(perZ)
       				    {signPeri[periCount]=counter; 
       				    periCount++;}
       				    }
       				     counter++;
      }
      
      get=1;
      counter=0;
      periCount=0;
      
     
      while (get) {
      
      
      if(	numbersD[counter]==-4||numbersD[counter]==-35)
      	{
      	counter++;
      	afterD=1;
      	wantedN[wantedCount]=temp;
      	temp=0;
      	wantedCount++;
      	periCount++;
      	if(	numbersD[counter]==-35)
   			{	afterD=1;
   			break;}
      	continue;
      	}
      	
      	if(afterD-2)
      	{if(	numbersD[counter]!=-2&&afterD-2)
      	{temp=temp+(double)numbersD[counter]*raisto(10,signPeri[periCount]-1-counter); }
      	else
      	{
      	afterD=2;
      	counter++;
      	continue;
      	}}
      	
      	if(afterD-1)
      		temp=temp+(double)numbersD[counter]*raisto(10,signPeri[periCount]-counter); 
      	
      	if(	numbersD[counter]==-35)
   				break;
   
      	counter++;
      	
      	if(numbersD[counter]==-1)//terminate
      	break;
      	
      }
      
      
     	get=1;
      counter=0;
      k=0;g=0;m=0;u=0;n=0;k=0;p=0;
      while (get) {
      
    						  if(killo[counter]!=-1)
       				     wantedN[killo[counter]]=wantedN[killo[counter]]*1000;
       				   if(milli[counter]!=-1)
       				     wantedN[milli[counter]]=wantedN[milli[counter]]*0.001;
       				    if(micro[counter]!=-1)
       				     wantedN[micro[counter]]=wantedN[micro[counter]]*0.000001;
       				    if(pico[counter]!=-1)
       				     wantedN[pico[counter]]=wantedN[pico[counter]]* 1.e-12;
       				   if(nano[counter]!=-1)
       				     wantedN[nano[counter]]=(double)wantedN[nano[counter]]*0.000000001;
       				    if(mega[counter]!=-1)
       				     wantedN[mega[counter]]=wantedN[mega[counter]]*1000000;
       				      
       	counter++;
      	 if(commaCount+1==counter)
      	 {
      	 	break;
      	 }
       	
      }			      

 
			Answer=0;
			get=1;
      counter=0;
switch(type){
/////////// Series:R-R,L-L  Parallel: C-C///////////////////////// 
		case 1:
      while (get) {
      	
      	Answer+=wantedN[counter];
      	
      	counter++;
      	if(commaCount+1==counter)
      	 	break;	
      }
    break;
/////////// Series:C-C Parallel:R-R,L-L///////////////////////// 
    case 3:
      while (get) {
      	Answer+=1/wantedN[counter];
      	counter++;
      	if(commaCount+1==counter)
      	 	break;	
      }
      Answer=1/Answer;
    break;
    
/////////// Series:R-L /////////////////////////
    
    case 4:
      Answer=2*PI*wantedN[0]*wantedN[2];
      printf("\n\nComplex Impedance:\n%g + j%gohms\n", wantedN[1],Answer);
      break;
/////////// Series:R-C /////////////////////////   
    case 5:
      Answer=1/(2*PI*wantedN[0]*wantedN[2]);
      printf("\n\nComplex Impedance:\n%g - j%gohms\n", wantedN[1],Answer);
      break;
/////////// Series:C-L /////////////////////////
    case 6:
      Answer=(-1/(2*PI*wantedN[0]*wantedN[2]))+(2*PI*wantedN[0]*wantedN[2]);
      printf("\n\nComplex Impedance:\nj%gohms\n", Answer);
      break;
/////////// Series:R-C-L /////////////////////////
    case 7:
      Answer=(2*PI*wantedN[0]*wantedN[3]-(1/(2*PI*wantedN[0]*wantedN[2])));
      printf("\n\nComplex Impedance:\n%g+j%gohms\n", wantedN[1], Answer);
      break;  
/////////// Parallel:C-L ///////////////////////// 
    case 8:
      Answer=((-1/(2*PI*wantedN[0]*wantedN[2]))*2*PI*wantedN[0]*wantedN[2])/((-1/(2*PI*wantedN[0]*wantedN[2]))+2*PI*wantedN[0]*wantedN[2]);
      printf("\n\nComplex Impedance:\nj%gohms\n", Answer);
      break;
  
/////////// Parallel:R-C /////////////////////////
   	case 9:
      Answer=-1/(2*PI*wantedN[0]*wantedN[2]);
      printf("\n\nComplex Impedance:\n%g - j%gohms\n", (wantedN[1]*Answer*Answer)/(wantedN[1]*wantedN[1]+Answer*Answer),(wantedN[1]*wantedN[1]*Answer)/(wantedN[1]*wantedN[1]+Answer*Answer));
      break;
/////////// Parallel:R-L /////////////////////////
   	case 10:
      Answer=2*PI*wantedN[0]*wantedN[2];
      printf("\n\nComplex Impedance:\n%g + j%gohms\n", (wantedN[1]*Answer*Answer)/(wantedN[1]*wantedN[1]+Answer*Answer),(wantedN[1]*wantedN[1]*Answer)/(wantedN[1]*wantedN[1]+Answer*Answer));
      break; 

/////////// Parallel:R-C-L /////////////////////////
    case 11:
      Answer=(-1*wantedN[3]/wantedN[2])/(2*PI*wantedN[0]*wantedN[3]-(1/(2*PI*wantedN[0]*wantedN[2])));
      printf("\n\nComplex Impedance:\n%g - j%gohms\n",(wantedN[1]*Answer*Answer)/(wantedN[1]*wantedN[1]+Answer*Answer),(wantedN[1]*wantedN[1]*Answer)/(wantedN[1]*wantedN[1]+Answer*Answer));
      break; 
 

      
}
return Answer;}

double raisto(double x,int no)
{
			double mult=1;
			int i=1;
			
			if(no<0)
			{	no=no*-1;
				for(i=1; i<=no; i++)
				mult*=x;
				mult=1/mult;
			}
			
			else if(no==0)
			mult=1;
			
			else {
			for(i=1; i<=no; i++)
			mult*=x;
			}
		
			return mult;
}


// Main Function
void _main(void)
{
    int done = 0;
    int key = 0;

    // loop until we're finished
    while (!done) {
        // clear the screen
        clrscr();
		   
        // display the messages using printf
        printf("    This program adds \n resistors,capacitors &\ninductors that are in A.C.       networks \n\n");
        printf("Select:");
        printf("\n1: Series Combination\n2: Parallel Combination");
       

        // wait for valid input
        while ((key < '1' || key > '2') && key != KEY_ESC) {
            key = ngetchx();
        }

        // if we pressed ESC, invalidate the loop
        if (key == KEY_ESC) {
            done = 1;

            // go to the next loop iteration
            continue;
        }

        // calculate the numeric value of the keycode and print
        // the selection
        key -= '0';
        printf("\nYou selected:%d\n\n", key);

        // perform actions based on the input
        switch (key) {
            // we chose the double function (times2() function)
            case 1:
                // wait for input and display the selection
        			printf("Choose type of Series\n      componenet\n");
        			printf("1:R-R  2:L-L  3:C-C  4:R-L  5:R-C  6:C-L 7:R-L-C\n");
                // wait for valid input
       					 while ((key < '1' || key > '8') && key != KEY_ESC) {
       				     key = ngetchx();
       					 }

        					// if we pressed ESC, invalidate the loop
       						 if (key == KEY_ESC) {
        				    done = 1;
       					     // go to the next loop iteration
       					     continue;
       							 }
       						key-='0';
       							  printf("You selected:%d\n\n", key);
       				if((key > 2 && key <= 7))
       						{	if((key >= 4 && key <= 7))
       							 inputs(key);
       							 else printf("\nImpedance:\n\n%gohms\n", inputs(key));} 
       				else if(key==2||key==1)
											printf("\nImpedance:\n\n%gohms\n", inputs(1));
                break;

            // we chose the square() function
            case 2:
                // wait for input and display the result
                	printf("Choose type of  Parallel\n      componenet\n");
        					printf("1:C-C 2:R-R 3:L-L  4:C-L  5:R-C  6:R-L   7:R-C-L\n");
                // wait for valid input
       					 while ((key < '1' || key > '8') && key != KEY_ESC) {
       				     key = ngetchx();
       					 }

        					// if we pressed ESC, invalidate the loop
       						 if (key == KEY_ESC) {
        				    done = 1;
       					     // go to the next loop iteration
       					     continue;
       							 }
       							 key-='0';
       							  printf("You selected:%d\n\n", key);
       				if(key==1)
       							  printf("\nImpedance:\n\n%gohms\n", inputs(key));
       			 else if(key==2||key==3)
       							  printf("\nImpedance:\n\n%gohms\n", inputs(3));
       				else if (key >= 4 && key <= 7)
										 inputs(key+4);
                break;

        }

        // pause the program so the user can see the result
        pause();
}
}    

