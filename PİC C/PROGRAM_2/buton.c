#include<16F877.h>                //Pic'i tanýmla  
#fuses HS,NOWDT,NOPROTECT         //osilatörü seç,wdt'yi durdur   
#use delay(clock=4000000)         //osilatör frekansýný 4 Mhz olarak  belirle         
#define BAS_YANSON INPUT(PIN_A0)  //A0 pinini BAS_YANSON diye taný         
#define YAN OUTPUT_HIGH(PIN_B0)   //YAN komutu ile B0 pinini 1 durumuna getir 
#define SON OUTPUT_LOW(PIN_B0)    //SON komutu ile B0 pinini 0 durumuna getir                 
void main ()
{                                          
while(1)                   //sonsuz döngü(1 iken sürekli yap)
 {                          
if(BAS_YANSON==1)          //pin A0 1 ise 
  {
   delay_ms(30);           // 30 ms bekle
   YAN;                    //b0 pinini 1 durumuna getir            
  }                                                                  
                                                                 
if(BAS_YANSON==0)          //pin A0 0 ise 
     {                      
      delay_ms(30);        //30 ms bekle
      SON;                 //b0 pinini 0 durumuna getir                    
     }
 }
}
