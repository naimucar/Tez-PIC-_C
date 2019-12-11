#include<16f877.h>
#fuses xt,noprotect,nowdt
#use delay(clock=4000000) 
#include<lcd420.c>
 int sayac=0,sayac1=0,x;

#int_timer0                          //timer0 kesmesini aktif et
void timer0_kesmesi()                
{set_timer0(255);                    // timer0 de�eri 255 iken set olsun 
sayac++; 
lcd_gotoxy(1,2); 
printf(lcd_putc,"sayac=%03u",sayac);
delay_ms(20);
}

void main()
{
set_tris_b(0x0);
output_b(0x0);
setup_timer_0(rtcc_ext_h_to_l|rtcc_div_1); 
// timer ayar�(d��en kenarda tetikle,b�lme oran� 1 dir. )b�lme oran�:gelen sinyalin ka� kerede al�naca��n� belirtir  
// �rne�in rtcc_div_2 olsayd� butona 2 kere bas�l�nca 1 de�er y�kselecekti

set_timer0(255);                  // bu de�eri hem yukar�da hem bu dizinde g�stermek zorunday�z.
enable_interrupts(GLOBAL);        //kesmelere izin ver
enable_interrupts(INT_TIMER0);    //timer1 kesmesini aktif et
lcd_init();
delay_ms(10);
lcd_putc("\f");
delay_ms(10);
lcd_gotoxy(1,1);
lcd_putc("timer0 deger");
while(1);
}



