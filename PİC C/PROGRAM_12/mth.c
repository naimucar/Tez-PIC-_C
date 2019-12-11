#include<16f877.h>   
#DEViCE ADC=8                         
#fuses xt,nowdt,NOprotect                       
#use delay(clock=4000000)             
#include<LCD420.C>                      
#define calis output_high(pin_d0);     
#define dur   output_low(pin_d0);   

void main()
{
                                                                                                                                 
unsigned int16 devir,sayac;                                                                                                    
unsigned int8 i,PVM;

setup_timer_1(T1_external|T1_div_by_1);   
setup_timer_2( T2_DIV_BY_1,249,1 );       
setup_ccp1(ccp_pwm); 
setup_adc_ports( RA0_ANALOG );      // RA0 kanalýný analog okuma için ayarla
setup_adc(ADC_CLOCK_INTERNAL);     // adc için iç saati kullan
set_adc_channel(0);                // analog kanalý sýfýrýncý kanal seç
delay_ms(20);                    
ana_p: 
set_pwm1_duty(0);         
dur;                             
lcd_init();                         
delay_ms(50);                      
lcd_putc("\f");
delay_ms(50);                 
lcd_gotoxy(1,1);                     
printf(lcd_putc,"MERHABA " );
delay_ms(50); 
lcd_gotoxy(1,2);                     
printf(lcd_putc,"STARTA BASIN" ) ; 
 do
   { 
    if(input(pin_D7)==0) break;      
    delay_ms(50);                   
   } 
while(1);
lcd_putc("\f");                                  
lcd_putc("MOTOR CALISIYOR");                  
calis; 
lcd_putc("\f");                         
for(;;)
 {
  pvm=read_adc();                    
  delay_ms(30);                                  
  set_pwm1_duty(pvm); 
  lcd_gotoxy(1,1);
  printf(lcd_putc,"PWM=%03u"pvm);      
  delay_ms(30); 
  devir=0;                                

   for(i=0;i<10;i++)    // bu kýsým 100 ms aralýklarla durdurma butonuna basýlýp basýlmadýðýný kontrol eder   
     {                  // bu arada  timer0 gelen palsleri sayar 
      delay_ms(100); 
      if(input(pin_d6)==0)
      {goto ana_p;} 
   }

  sayac=get_timer1(); 
  devir=sayac;                             
  devir=devir*60;                         
  lcd_gotoxy(1,2);                          
  printf(lcd_putc,"devir=%05lud/d",devir);
 }
}
                                                                                                                                 
