#include<16f877.h>  
#use delay(clock=4000000)
#include<lcd420.C>               //lcd dosyas�n� tan�mla
void main()
{ 
 unsigned int8 i;
 delay_ms(100);
 lcd_init();                     // lcd yi haz�rla
 delay_ms(100);
 lcd_putc("\f");                 // ekran� siler kurs�r� 1,1 e �ek 
 lcd_putc("MERHABA");            //ekrana MERHABA yaz
 for(;;)                         //sonsuz d�ng�
 {                              
   for(i=0 ; i<255 ;++i)
   {                              
      lcd_gotoxy(1,2);           //lcd de 2. sat�r 1 s�tuna git                      
      printf(lcd_putc "%3u",i); //"i" de�erini 3 haneli olarak pozitif 8 bit desimal olarak g�ster
      delay_ms(300);              
   }
 }
 
}                        
