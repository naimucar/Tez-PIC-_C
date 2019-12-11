#include<16f877.h>
#fuses XT,NOWDT,NOPROTECT
#use delay(clock=4000000)
#include<lcd420.c>               
#define SAT1 PIN_D0
#define SAT2 PIN_D1
#define SAT3 PIN_D2
#define SUT1 PIN_D4
#define SUT2 PIN_D5                        
#define SUT3 PIN_D6
#define SUT4 PIN_D7

char KEY_PAD()   
{
set_tris_d (0x00); 

output_low(SUT1);
output_high(SUT2);                 
output_high(SUT3); 
output_high(SUT4); 

if (input(SAT1)==0)
                   {delay_ms(20);return '1';} 
if (input(SAT2)==0)
                   {delay_ms(20);return '2';}
if (input(SAT3)==0)
                   {delay_ms(20);return '3';}

output_high(SUT1);
output_low(SUT2);
output_high(SUT3);
output_high(SUT4); 

if (input(SAT1)==0)
                   {delay_ms(20);return '4';}
if (input(SAT2)==0)
                   {delay_ms(20);return '5';}
if (input(SAT3)==0)
                   {delay_ms(20);return '6';}

output_high(SUT1);
output_high(SUT2);
output_low(SUT3);
output_high(SUT4);      
if (input(SAT1)==0)
                   {delay_ms(20);return '7';}
if (input(SAT2)==0)
                   {delay_ms(20);return '8';}        
if (input(SAT3)==0)
                   {delay_ms(20);return '9';}

output_high(SUT1);
output_high(SUT2);
output_high(SUT3);
output_low(SUT4);      
if (input(SAT1)==0)
                   {delay_ms(20);return '*';}
if (input(SAT2)==0)
                   {delay_ms(20);return '0';}
if (input(SAT3)==0)
                   {delay_ms(20);return '#';}

return 0;        
}

 void main()                                      
{
char oku;
lcd_init();  
delay_ms(20);
lcd_putc("\fBiR TUSA BASIN ");                                            
 while(1)
{
oku=KEY_PAD();
lcd_gotoxy(1,2);
printf(lcd_putc,"key=%c",oku); 
delay_ms(10);
 }

   

}                                  
