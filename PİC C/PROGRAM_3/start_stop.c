#include<16f877.h>                  //Pic'i tan�mla  
#fuses xt,noprotect,nowdt           //osilat�r� se�,wdt'yi durdur 
#use delay(clock=4000000)           //osilat�r frekans�n� 4 Mhz olarak  belirle
#define YAN output_high(pin_b0)     //YAN komutu ile B0 pinini 1 durumuna getir 
#define SON output_low(pin_b0)      //SON komutu ile B0 pinini 0 durumuna getir 
#define start input(pin_a0)         //A0 pinini "start " diye tan� 
#define stop input(pin_a1)          //A1 pinini "stop "diye tan� 

void main()
{
while(1)                            //sonsuz d�ng�(1 iken s�rekli yap)
 {

if(start==0)                       //pin A0 0 ise 
   {
    delay_ms(200);                 // 200 ms bekle
    YAN;                           //b0 pinini 1 durumuna getir 
   }
if(stop==0)                        //pin A1 0 ise 
   {
   delay_ms(200);                  // 200 ms bekle
   SON;                       //b0 pinini 0 durumuna getir  
   }
 }

}
