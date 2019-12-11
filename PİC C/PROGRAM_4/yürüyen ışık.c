#include<16f877.h>
#fuses noprotect,nowdt,XT
#use delay(clock=4000000)

void main()
{                                
unsigned int i;                 //"i" isimli iþaretsiz(8 bit pozitif tamsayý) tanýmla 

basla:  
for(i=1;i<=128;i=i*2)           //i=128 sayýsýna eþit olana kadar "i"deðerini
                                // 2'nin katý þeklinde artýr
  {                        
   output_B(i);                 //i deðerini B portunda göster                       
   delay_ms(500);               // 500 ms  saniye bekle
   if(i==128)                   //i =128 olursa aþaðýdakileri yap
    {                                  
       output_b(0xff);          //B portunu tamamen 1  yap
       delay_ms(500);           // 500 ms  saniye bekle
       for(i=128;i>=1;i=i/2)     //i=1 sayýsýna eþit olana kadar "i"deðerini
                                // 2'ye böl     
        {                                    
         output_B(i);           //i deðerini B portunda göster
         delay_ms(500); 
         if(i==1)               //i=1 olursa  
          {   
            output_b(0xff);      //B portunu 1 yap
            delay_ms(500);       //500 ms  saniye bekle
            goto basla;          // basla dizininin baþýna dön 
          }                       
        } 
     }                              
   }                                                                                     
}                 
         
                          
