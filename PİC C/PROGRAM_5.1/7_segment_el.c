#include<16f877.h>
#fuses xt,noprotect,nowdt
#use delay(clock=4000000)

void main()
{
int i=0,a=0,c=(-1),x=0;
const int8 bcd[10]={0x40,0x79,0x24,0x30,0x19,0x12,0x02,0x78,0x00,0x10};
output_b(0x00);
output_d(0x00);

goster:
   for(x=0;x<50;++x)                    // say�y� ekranda 30 defa g�ster    
 {             output_low(pin_d0);     
               output_high(pin_d1);
               output_b(bcd[i]);
               delay_ms(5);
               output_low(pin_d1);
               output_high(pin_d0);          
               output_b(bcd[a]);
               delay_ms(5);
               output_low(pin_d0);
               }
      goto ana;


ana:
   if(input(pin_a0)==1)
                { delay_ms(50);
                  i++;
                  if(i==10){i=0;a++;}
                  if(a==10)
                     {a=0;}
                  goto goster;
                }
if(input(pin_a1)==1)
                   {delay_ms(50);
                   if(i==0 & a==0){i=10;a=9;}
                   if(i==0){i=10;a--;}
                   i--;
                   goto goster;
                   }
if(input(pin_a2)==1)
                   { delay_ms(50);
                   i=0;a=0;
                   goto goster;
                   }
         
goto goster;
                    
}
