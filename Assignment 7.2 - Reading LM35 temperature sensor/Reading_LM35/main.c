#include <main.h>
float value;

void main()
{
set_tris_a(0xff);
setup_adc_ports(SAN2);
setup_adc_reference(VSS_VDD);
setup_adc(ADC_CLOCK_INTERNAL);

lcd_init();

   while(TRUE)
   {
set_adc_channel(2);
delay_us(10);
value = read_adc() / 2.046;
lcd_gotoxy(1, 1);
printf(lcd_putc,"Trong 20146107");
lcd_gotoxy(1,2);
printf(lcd_putc, "Temp = %.1f C", value);

   }

}
