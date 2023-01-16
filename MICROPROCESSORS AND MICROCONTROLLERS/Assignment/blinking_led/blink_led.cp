#line 1 "D:/My Files/Documents/School-Work/Microprocessors_&_Microcontrollers/blinking_led/blink_led.c"
int i;
void main() {
 TRISB = 0x00;


 i = 1;
 while(i <= 10) {
 PORTB = 0b11111111;
 Delay_ms(500);
 PORTB = 0b00000000;
 Delay_ms(500);
 i++;
 }


 i = 1;
 while(i <= 10) {
 PORTB = 0b11110000;
 Delay_ms(500);
 PORTB = 0b00000000;
 Delay_ms(500);
 i++;
 }


 i = 1;
 while(i <= 10) {
 PORTB = 0b00001111;
 Delay_ms(500);
 PORTB = 0b00000000;
 Delay_ms(500);
 i++;
 }


 i = 1;
 while(i <= 10) {
 PORTB = 0b10101010;
 Delay_ms(500);
 PORTB = 0b00000000;
 Delay_ms(500);
 i++;
 }


 i = 1;
 while(i <= 10) {
 PORTB = 0b01010101;
 Delay_ms(500);
 PORTB = 0b00000000;
 Delay_ms(500);
 i++;
 }
}
