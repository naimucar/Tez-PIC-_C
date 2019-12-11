#include<16f877.h>  
#use delay(clock=4000000)
#include<lcd420.C>               //lcd dosyasýný tanýmla
void main()
{ 
 unsigned int8 i;
 delay_ms(100);
 lcd_init();                     // lcd yi hazýrla
 delay_ms(100);
 lcd_putc("\f");                 // ekraný siler kursörü 1,1 e çek 
 lcd_putc("MERHABA");            //ekrana MERHABA yaz
 for(;;)                         //sonsuz döngü
 {                              
   for(i=0 ; i<255 ;++i)
   {                              
      lcd_gotoxy(1,2);           //lcd de 2. satýr 1 sütuna git                      
      printf(lcd_putc "%3u",i); //"i" deðerini 3 haneli olarak pozitif 8 bit desimal olarak göster
      delay_ms(300);              
   }
 }
 
}                        
