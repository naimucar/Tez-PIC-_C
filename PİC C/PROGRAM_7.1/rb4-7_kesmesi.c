#include<16f877.h>
#fuses xt,noprotect,nowdt
#use delay (clock=4000000)
#int_rb                      //rb4_7  kesmesini aktif et(RB4,RB5,RB6,RB7)  
void rb4_7_kesme()
{
       if(input(pin_b4))
       
     { delay_ms(50);     
       output_high(pin_d0);
              
     }
       if(input(pin_b5))
     { delay_ms(50);
       output_high(pin_d1);
     }
       if(input(pin_b6))
     { delay_ms(50);
       output_high(pin_d2);
     }
       if(input(pin_b7))
     { delay_ms(50);
       output_high(pin_d3);                     
     }
}
void main()
{

enable_interrupts(int_rb);                 //RB4-7 kesmesini aktif et
enable_interrupts(global);                 //t�m kesmelere izin ver 
while(1);
}
