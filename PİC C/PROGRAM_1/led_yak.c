#include<16F877.h>                     //Pic'i tan�mla  
#fuses xt,NOWDT,NOPROTECT              //osilat�r� se�,wdt'yi durdur                          
#use delay(clock=4000000)              //osilat�r frekans�n� 4 Mhz olarak  belirle                           
#define motor_calis output_high(pin_b0)//motor_calis komutu ile B0 pinini 1 durumuna getir                            
#define motor_stop output_low(pin_b0)  //motor_stop komutu ile B0 pinini 0 durumuna getir   
void main ()
 {                                             
 output_b(0x00);                       //b portuna s�f�rla
ana: 
   motor_calis;                          //b0 pinini 1 durumuna getir
   delay_ms(500);                         //500 milisaniye bekle 
   motor_stop;                            //b0 pinini 0 durumuna getir
   delay_ms(500);                          //500 milisaniye bekle
goto ana;                              //ba�a d�n
}
               

