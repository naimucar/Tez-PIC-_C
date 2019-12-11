#include<16f877.h>
#fuses nowdt,xt
#use delay(clock=4000000)
#include<lcd420.c> 
#use rs232 (baud=9600,xmit=pin_c6,rcv=pin_c7,parity=N,stop=1)

char klavye[80];
#int_rda
void serihaber_kesme()
 {
 disable_interrupts(int_rda);
 output_high(pin_c5); 
 gets(klavye);
 printf("\n\ryazdýðýnýz metin> %s\n",klavye);
 printf(lcd_putc,"\f%s"klavye); 
 output_low (pin_c5); 
 printf("\n\rklavyeden metin gir ve entere bas>");      
  }


void main()
{                                                     
  output_low (pin_c5); 
  lcd_init();
   printf("\**********slm*******");
    printf("\n\rklavyeden girilen bilgi lcd de görünecek\n\n");
    printf("\n\rklavyeden metin gir ve entere bas>"); 
    enable_interrupts(global);
    while(1)
{
  enable_interrupts(int_rda);
}
}
                                                                                
