
_main:

;blinking_led.c,1 :: 		void main() {
;blinking_led.c,2 :: 		TRISB = 0x00;
	CLRF       TRISB+0
;blinking_led.c,3 :: 		TRISA = 0x1F;
	MOVLW      31
	MOVWF      TRISA+0
;blinking_led.c,5 :: 		do {
L_main0:
;blinking_led.c,6 :: 		PORTB = 0b11111111;
	MOVLW      255
	MOVWF      PORTB+0
;blinking_led.c,7 :: 		Delay_ms(500);
	MOVLW      6
	MOVWF      R11+0
	MOVLW      19
	MOVWF      R12+0
	MOVLW      173
	MOVWF      R13+0
L_main3:
	DECFSZ     R13+0, 1
	GOTO       L_main3
	DECFSZ     R12+0, 1
	GOTO       L_main3
	DECFSZ     R11+0, 1
	GOTO       L_main3
	NOP
	NOP
;blinking_led.c,8 :: 		PORTB = 0b00000000;
	CLRF       PORTB+0
;blinking_led.c,9 :: 		Delay_ms(500);
	MOVLW      6
	MOVWF      R11+0
	MOVLW      19
	MOVWF      R12+0
	MOVLW      173
	MOVWF      R13+0
L_main4:
	DECFSZ     R13+0, 1
	GOTO       L_main4
	DECFSZ     R12+0, 1
	GOTO       L_main4
	DECFSZ     R11+0, 1
	GOTO       L_main4
	NOP
	NOP
;blinking_led.c,10 :: 		} while(2);
	GOTO       L_main0
;blinking_led.c,11 :: 		}
L_end_main:
	GOTO       $+0
; end of _main
