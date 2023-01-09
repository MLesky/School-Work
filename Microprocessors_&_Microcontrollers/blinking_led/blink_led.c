int i;
void main() {
     TRISB = 0x00;

     // blinking 10 times
     i = 1;
     while(i <= 10) {
              PORTB = 0b11111111; // PORTB On
              Delay_ms(500);
              PORTB = 0b00000000; // PORTB Off
              Delay_ms(500);
              i++;
     }
     
     // blinking first 4 LED's 10 times
     i = 1;
     while(i <= 10) {
             PORTB = 0b11110000; // first LED's on
             Delay_ms(500);
             PORTB = 0b00000000; // PORTB Off
             Delay_ms(500);
             i++;
     }
     
     // blinking last 4 LED's 10 times
     i = 1;
     while(i <= 10) {
             PORTB = 0b00001111; // last LED's on
             Delay_ms(500);
             PORTB = 0b00000000; // PORTB Off
             Delay_ms(500);
             i++;
     }
     
     // blinking 10101010 10 times
      i = 1;
     while(i <= 10) {
             PORTB = 0b10101010; // last LED's on
             Delay_ms(500);
             PORTB = 0b00000000; // PORTB Off
             Delay_ms(500);
             i++;
     }
     
     // blinking 01010101 10 times
      i = 1;
     while(i <= 10) {
             PORTB = 0b01010101; // last LED's on
             Delay_ms(500);
             PORTB = 0b00000000; // PORTB Off
             Delay_ms(500);
             i++;
     }
}