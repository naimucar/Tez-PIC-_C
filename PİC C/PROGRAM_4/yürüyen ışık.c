#include<16f877.h>
#fuses noprotect,nowdt,XT
#use delay(clock=4000000)

void main()
{                                
unsigned int i;                 //"i" isimli i�aretsiz(8 bit pozitif tamsay�) tan�mla 

basla:  
for(i=1;i<=128;i=i*2)           //i=128 say�s�na e�it olana kadar "i"de�erini
                                // 2'nin kat� �eklinde art�r
  {                        
   output_B(i);                 //i de�erini B portunda g�ster                       
   delay_ms(500);               // 500 ms  saniye bekle
   if(i==128)                   //i =128 olursa a�a��dakileri yap
    {                                  
       output_b(0xff);          //B portunu tamamen 1  yap
       delay_ms(500);           // 500 ms  saniye bekle
       for(i=128;i>=1;i=i/2)     //i=1 say�s�na e�it olana kadar "i"de�erini
                                // 2'ye b�l     
        {                                    
         output_B(i);           //i de�erini B portunda g�ster
         delay_ms(500); 
         if(i==1)               //i=1 olursa  
          {   
            output_b(0xff);      //B portunu 1 yap
            delay_ms(500);       //500 ms  saniye bekle
            goto basla;          // basla dizininin ba��na d�n 
          }                       
        } 
     }                              
   }                                                                                     
}                 
         
                          
