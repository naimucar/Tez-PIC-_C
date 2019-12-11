////////////////////////////////////////////////////////////////////////////////// 
///********************* ÝÞ SÜRESÝ HESABI ***********************************///// 
// tanýmlar:                                                                    // 
//                                                                              // 
// iþ süresi: bu süre PWM in +5 volt ta durma zamanýný ifade eder ortalama deðer// 
// formülüne göre bu süre ne kadar uzun olursa çýkýþ geriliminin ortalama deðeri// 
// o kadar fazla olur.                                                          // 
// frekans: frekans PWM in saniyedeki pals sayýsýný ifade eder. hesaplamalarda // 
// frekans t=1/f formülü ile süreye dönüþtürülerek hesaplamaya katýlýr.         // 
// PWM çalýþma mantýðý: PWM timer2 yi kullanýr. timer2 de gerekli ayarlanmalar  // 
// yapýlarak istenilen pwm frekansý elde edilir. set_pwm1_duty() komutu ile de  // 
// iþ süresi ayar edilir. Burada dikkat edilmesi gereken nokta biraz sonra hesap// 
// edeceðimiz maksimum iþ süresi deðerinden daha fazla deðerin iþ süresi olarak // 
// yüklenmemesi gerektiðidir.                                                   // 
//                                                                              // 
// Örnek: 8MHz lik bir kristal kullandýðýmýzý ve 1KHz lik PWM elde edeceðimizi  // 
// varsayarak gerekli hesaplarýmýzý yapalým                                     // 
// önce 1KHz in maksimum pals geniþliðini t=1/f formülü ile hesaplayalým        // 
// t=1/1000 = 1ms olarak buluruz. Bu PWM sinyalinin geiþliðinin 1ms olacaðý     // 
// anlamýna gelir.                                                              // 
// yüklenebilecek maksimum iþ süresini ise aþaðýdaki formülle hesaplarýz        // 
// iþ süresi = t/(t2 deðeri*(1/osilatör frekansý)) buradan elde edilen deðer    // 
// maksimum yüklenebilecek deðerdir ve bu deðerde çýkýþtan tam 5 volt elde      // 
// edilir. timer2 ye 16 yüklersek buna göre                                     // 
// iþ_süresi = 0.001/(16/(1/8000000)) = 500 bulunur                             // 
// 0 ile 500 arasýndaki deðerde çýkýþta bu deðerlerle orantýlý olarak 0 ile 5   // 
// volt arasý deðer elde edilir.                                                //
// pr2 deðeri hesabý: bu deðer setup_timer_2(p1,p2,p3) deðerlerinin ikincisi    //
// (p2) pr2 registerine yüklenen frekansý belirleyen deðerdir aþaðýdaki formülle//
// hesaplanýr                                                                   // 
// (pr2+1) = t/(4*t2_deðeri*(1/Fosc)) bu formüle göre hesaplarsak               //
// (pr2+1) = 0.001/(4*16*(1/8000000)) = 125 bulunur buradan pr2 = 125-1=124     //
// olarak bulunur.                                                              //
//////////////////////////////////////////////////////////////////////////////////
#include<16f877.h>
#device adc = 10                  
#fuses xt,nowdt,noprotect                  
#use delay(clock=8000000)              


void main()
{
int16 pvm ;  
setup_timer_2(T2_DIV_BY_16,124,1);     //pwm için timer2 ayarýný yap
setup_ccp1(ccp_pwm);                  //ccp1 çýkýþý (RC2 pini) kullanacak

setup_adc_ports( RA0_ANALOG );      
setup_adc(ADC_CLOCK_INTERNAL);   
set_adc_channel(0);               
set_pwm1_duty(0);

while(1)                        
{pvm=read_adc();                //analog deðerini pvm deðiþkenine ata 
delay_ms(20); 
set_pwm1_duty(pvm);             //pwm deðeri anologtan gelen bilgi ile yönlendir.  
delay_ms(50); 
}                         
}                      


                                                                                                            
