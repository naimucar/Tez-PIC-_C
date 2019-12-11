#include<16f877.h>
#fuses xt,noprotect,nowdt
#use delay(clock=4000000)
void main()
{ 
// Aþaðýdaki tablo ortak anotlu 7 segment display için olþturulmuþtur.
unsigned int8 const  Tablo[10]={0x40,0x79,0x24,0x30,0x19,0x12,0x02,0x78,0x00,0x10}; 
//8 bitlik pozitif tamsayýlardan oluþan "Tablo" isimli bir dizin oluþturuldu.
//NOT:Sýra olarak 1,2,3,4,5,6,7,8,9,10 þeklinde olmasýna raðmen Tablo dizinideki sýralama 0,1,2,3,4,5,6,7,8,9 þeklinde 10 tane deðerdir,
//Örnek verecek olursak 5.sýradaki(0x19 deðeri) için Tablo[4] þeklinde olmalýdýr.

int x=0, i,a=0;
set_tris_b(0x00);                       //b portunu çýkýþ yap
output_b(0x00);                         // b portunu sýfýrla
basamak_1:
for(i=0;i<=10;i++)                      //i=10 olana kadar sayýyý artýr
 {    
          for(x=0;x<50;++x)             // sayýyý ekranda 50 defa göster    
          {                                     
               output_low(pin_d0);      //D0 pinini 0 durumuna getir  
               output_high(pin_d1);     //D1 pinini 1 durumuna getir 
               output_b(Tablo[i]);      //Tablo dizinindeki i sayýsýna denk gelen sayýyý b portunda göster 
               delay_ms(5);
               output_low(pin_d1);      //D0 pinini 0 durumuna getir    
          
               output_high(pin_d0);     //D0 pinini 1 durumuna getir  
               output_b(Tablo[a]);      //Tablo dizinindeki a sayýsýna denk gelen sayýyý b portunda göster
               delay_ms(5);               
               output_low(pin_d0);     //D0 pinini 0 durumuna getir                       
            
               if(i==10)
               goto basamak_10;
          }
 }
     basamak_10:                                      
               a++;
               output_high(pin_d0);
               output_b(Tablo[a]);
               output_low(pin_d0);
               if(a==10)
               {a=0;}
               goto basamak_1;
}
