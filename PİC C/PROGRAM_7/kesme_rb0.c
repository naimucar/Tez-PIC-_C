#include<16f877.h>
#fuses xt,noprotect,nowdt
#use delay(clock=40000000)
int i,a;
#int_ext                        //harici kesmeyi aktif et(RB0 i�in)
void rb0_kesme()                // rb0_kesme dizini olu�tur(istenilen isim verilebilir)
{                     
  for(i=0;i<10;i++)

      {
        a=0xff;
        output_c(a);                     
        delay_ms(200);
        a=0x00;                                                         
        output_C(a);
        delay_ms(200);
      }
}

void main()
{
ext_int_edge(h_to_l) ;          //kesme i�lemini y�kselen kenardan d��en kenara do�ru iken alg�la
enable_interrupts(int_ext);     //harici kesmeyi aktif et
enable_interrupts(global);      //t�m kesmeleri izin ver                        
while(1);                       //sonsuz d�ng�(s�rekli yap)                       
}                                                  
