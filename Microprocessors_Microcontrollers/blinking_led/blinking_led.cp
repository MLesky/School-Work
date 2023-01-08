#line 1 "D:/My Files/Documents/School-Work/Microprocessors_Microcontrollers/blinking_led/blinking_led.c"
void main() {
 TRISB = 0x00;
 TRISA = 0x1F;

 do {
 PORTB = 0b11111111;
 Delay_ms(500);
 PORTB = 0b00000000;
 Delay_ms(500);
 } while(2);
}
