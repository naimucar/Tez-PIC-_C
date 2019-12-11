#include<16f877a.h>
#fuses noprotect,nowdt,xt
#use delay(clock=4000000)

void main()
{
unsigned int i;
set_tris_c(0x00);          //c portunu çýkýþ yap

ileri: 

  output_c(0x0);           //c portunu sýfýrla
  delay_ms(500);
  for(i=0;i<=255;i=i*2^2)  // i=255 olana kadar i=i*2^2 þeklinde artýr             
   {
    output_c(i+1);         // i+1 deðerini port c de göster   
    delay_ms(500);
    if(i==254)                         
    goto geri;                      
   }                                  

geri: 

    for(i=128;i>=0;i=i/2)         
    {
     output_c(i-1);                            
     delay_ms(500);                
     if(i==0)                            
     goto ileri;  
    }
}        
                            


