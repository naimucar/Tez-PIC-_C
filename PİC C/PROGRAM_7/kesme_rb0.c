#include<16f877.h>
#fuses xt,noprotect,nowdt
#use delay(clock=40000000)
int i,a;
#int_ext                        //harici kesmeyi aktif et(RB0 için)
void rb0_kesme()                // rb0_kesme dizini oluþtur(istenilen isim verilebilir)
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
ext_int_edge(h_to_l) ;          //kesme iþlemini yükselen kenardan düþen kenara doðru iken algýla
enable_interrupts(int_ext);     //harici kesmeyi aktif et
enable_interrupts(global);      //tüm kesmeleri izin ver                        
while(1);                       //sonsuz döngü(sürekli yap)                       
}                                                  
