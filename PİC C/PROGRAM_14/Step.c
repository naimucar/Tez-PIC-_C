#include<16f877.h>
#fuses xt,noprotect,nowdt
#use delay(clock=4000000)
#define step_i input(pin_B0) 
#define step_g input(pin_B1)
int i=0;
const int step_tablo[8]={
0b00000001,
0b00000011,
0b00000010,
0b00000110,
0b00000100,
0b00001100,
0b00001000,
0b00001001
};
                          
     
void main()        
{ set_tris_c(0x00);
output_c(0);
while(1)
{
///////////ileri step//////////////
if(step_i==1)
{                         
delay_ms(100);
i++;
step_tablo[i];
output_c(step_tablo[i]);
delay_ms(100);
if(i==7)i=0;  
}                       
 ///////////geri step//////////////            
if(step_g==1)                                           
{
delay_ms(100);                     
i--;
//step_tablo[i];
output_c(step_tablo[i]);
delay_ms(100);
if(i==0)i=7;  
}
}
}
                                
