#include<16f877.h>
#fuses xt,noprotect,nowdt
#use delay(clock=4000000)
void main()
{ 
// A�a��daki tablo ortak anotlu 7 segment display i�in ol�turulmu�tur.
unsigned int8 const  Tablo[10]={0x40,0x79,0x24,0x30,0x19,0x12,0x02,0x78,0x00,0x10}; 
//8 bitlik pozitif tamsay�lardan olu�an "Tablo" isimli bir dizin olu�turuldu.
//NOT:S�ra olarak 1,2,3,4,5,6,7,8,9,10 �eklinde olmas�na ra�men Tablo dizinideki s�ralama 0,1,2,3,4,5,6,7,8,9 �eklinde 10 tane de�erdir,
//�rnek verecek olursak 5.s�radaki(0x19 de�eri) i�in Tablo[4] �eklinde olmal�d�r.

int x=0, i,a=0;
set_tris_b(0x00);                       //b portunu ��k�� yap
output_b(0x00);                         // b portunu s�f�rla
basamak_1:
for(i=0;i<=10;i++)                      //i=10 olana kadar say�y� art�r
 {    
          for(x=0;x<50;++x)             // say�y� ekranda 50 defa g�ster    
          {                                     
               output_low(pin_d0);      //D0 pinini 0 durumuna getir  
               output_high(pin_d1);     //D1 pinini 1 durumuna getir 
               output_b(Tablo[i]);      //Tablo dizinindeki i say�s�na denk gelen say�y� b portunda g�ster 
               delay_ms(5);
               output_low(pin_d1);      //D0 pinini 0 durumuna getir    
          
               output_high(pin_d0);     //D0 pinini 1 durumuna getir  
               output_b(Tablo[a]);      //Tablo dizinindeki a say�s�na denk gelen say�y� b portunda g�ster
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
