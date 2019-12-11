////////////////////////////////////////////////////////////////////////////////// 
///********************* �� S�RES� HESABI ***********************************///// 
// tan�mlar:                                                                    // 
//                                                                              // 
// i� s�resi: bu s�re PWM in +5 volt ta durma zaman�n� ifade eder ortalama de�er// 
// form�l�ne g�re bu s�re ne kadar uzun olursa ��k�� geriliminin ortalama de�eri// 
// o kadar fazla olur.                                                          // 
// frekans: frekans PWM in saniyedeki pals say�s�n� ifade eder. hesaplamalarda // 
// frekans t=1/f form�l� ile s�reye d�n��t�r�lerek hesaplamaya kat�l�r.         // 
// PWM �al��ma mant���: PWM timer2 yi kullan�r. timer2 de gerekli ayarlanmalar  // 
// yap�larak istenilen pwm frekans� elde edilir. set_pwm1_duty() komutu ile de  // 
// i� s�resi ayar edilir. Burada dikkat edilmesi gereken nokta biraz sonra hesap// 
// edece�imiz maksimum i� s�resi de�erinden daha fazla de�erin i� s�resi olarak // 
// y�klenmemesi gerekti�idir.                                                   // 
//                                                                              // 
// �rnek: 8MHz lik bir kristal kulland���m�z� ve 1KHz lik PWM elde edece�imizi  // 
// varsayarak gerekli hesaplar�m�z� yapal�m                                     // 
// �nce 1KHz in maksimum pals geni�li�ini t=1/f form�l� ile hesaplayal�m        // 
// t=1/1000 = 1ms olarak buluruz. Bu PWM sinyalinin gei�li�inin 1ms olaca��     // 
// anlam�na gelir.                                                              // 
// y�klenebilecek maksimum i� s�resini ise a�a��daki form�lle hesaplar�z        // 
// i� s�resi = t/(t2 de�eri*(1/osilat�r frekans�)) buradan elde edilen de�er    // 
// maksimum y�klenebilecek de�erdir ve bu de�erde ��k��tan tam 5 volt elde      // 
// edilir. timer2 ye 16 y�klersek buna g�re                                     // 
// i�_s�resi = 0.001/(16/(1/8000000)) = 500 bulunur                             // 
// 0 ile 500 aras�ndaki de�erde ��k��ta bu de�erlerle orant�l� olarak 0 ile 5   // 
// volt aras� de�er elde edilir.                                                //
// pr2 de�eri hesab�: bu de�er setup_timer_2(p1,p2,p3) de�erlerinin ikincisi    //
// (p2) pr2 registerine y�klenen frekans� belirleyen de�erdir a�a��daki form�lle//
// hesaplan�r                                                                   // 
// (pr2+1) = t/(4*t2_de�eri*(1/Fosc)) bu form�le g�re hesaplarsak               //
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
setup_timer_2(T2_DIV_BY_16,124,1);     //pwm i�in timer2 ayar�n� yap
setup_ccp1(ccp_pwm);                  //ccp1 ��k��� (RC2 pini) kullanacak

setup_adc_ports( RA0_ANALOG );      
setup_adc(ADC_CLOCK_INTERNAL);   
set_adc_channel(0);               
set_pwm1_duty(0);

while(1)                        
{pvm=read_adc();                //analog de�erini pvm de�i�kenine ata 
delay_ms(20); 
set_pwm1_duty(pvm);             //pwm de�eri anologtan gelen bilgi ile y�nlendir.  
delay_ms(50); 
}                         
}                      


                                                                                                            
