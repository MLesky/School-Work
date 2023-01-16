
_main:

;blink_led.c,2 :: 		void main() {
;blink_led.c,3 :: 		TRISB = 0x00;
	CLRF       TRISB+0
;blink_led.c,6 :: 		i = 1;
	MOVLW      1
	MOVWF      _i+0
	MOVLW      0
	MOVWF      _i+1
;blink_led.c,7 :: 		while(i <= 10) {
L_main0:
	MOVLW      128
	MOVWF      R0+0
	MOVLW      128
	XORWF      _i+1, 0
	SUBWF      R0+0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main21
	MOVF       _i+0, 0
	SUBLW      10
L__main21:
	BTFSS      STATUS+0, 0
	GOTO       L_main1
;blink_led.c,8 :: 		PORTB = 0b11111111; // PORTB On
	MOVLW      255
	MOVWF      PORTB+0
;blink_led.c,9 :: 		Delay_ms(500);
	MOVLW      6
	MOVWF      R11+0
	MOVLW      19
	MOVWF      R12+0
	MOVLW      173
	MOVWF      R13+0
L_main2:
	DECFSZ     R13+0, 1
	GOTO       L_main2
	DECFSZ     R12+0, 1
	GOTO       L_main2
	DECFSZ     R11+0, 1
	GOTO       L_main2
	NOP
	NOP
;blink_led.c,10 :: 		PORTB = 0b00000000; // PORTB Off
	CLRF       PORTB+0
;blink_led.c,11 :: 		Delay_ms(500);
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
;blink_led.c,12 :: 		i++;
	INCF       _i+0, 1
	BTFSC      STATUS+0, 2
	INCF       _i+1, 1
;blink_led.c,13 :: 		}
	GOTO       L_main0
L_main1:
;blink_led.c,16 :: 		i = 1;
	MOVLW      1
	MOVWF      _i+0
	MOVLW      0
	MOVWF      _i+1
;blink_led.c,17 :: 		while(i <= 10) {
L_main4:
	MOVLW      128
	MOVWF      R0+0
	MOVLW      128
	XORWF      _i+1, 0
	SUBWF      R0+0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main22
	MOVF       _i+0, 0
	SUBLW      10
L__main22:
	BTFSS      STATUS+0, 0
	GOTO       L_main5
;blink_led.c,18 :: 		PORTB = 0b11110000; // first LED's on
	MOVLW      240
	MOVWF      PORTB+0
;blink_led.c,19 :: 		Delay_ms(500);
	MOVLW      6
	MOVWF      R11+0
	MOVLW      19
	MOVWF      R12+0
	MOVLW      173
	MOVWF      R13+0
L_main6:
	DECFSZ     R13+0, 1
	GOTO       L_main6
	DECFSZ     R12+0, 1
	GOTO       L_main6
	DECFSZ     R11+0, 1
	GOTO       L_main6
	NOP
	NOP
;blink_led.c,20 :: 		PORTB = 0b00000000; // PORTB Off
	CLRF       PORTB+0
;blink_led.c,21 :: 		Delay_ms(500);
	MOVLW      6
	MOVWF      R11+0
	MOVLW      19
	MOVWF      R12+0
	MOVLW      173
	MOVWF      R13+0
L_main7:
	DECFSZ     R13+0, 1
	GOTO       L_main7
	DECFSZ     R12+0, 1
	GOTO       L_main7
	DECFSZ     R11+0, 1
	GOTO       L_main7
	NOP
	NOP
;blink_led.c,22 :: 		i++;
	INCF       _i+0, 1
	BTFSC      STATUS+0, 2
	INCF       _i+1, 1
;blink_led.c,23 :: 		}
	GOTO       L_main4
L_main5:
;blink_led.c,26 :: 		i = 1;
	MOVLW      1
	MOVWF      _i+0
	MOVLW      0
	MOVWF      _i+1
;blink_led.c,27 :: 		while(i <= 10) {
L_main8:
	MOVLW      128
	MOVWF      R0+0
	MOVLW      128
	XORWF      _i+1, 0
	SUBWF      R0+0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main23
	MOVF       _i+0, 0
	SUBLW      10
L__main23:
	BTFSS      STATUS+0, 0
	GOTO       L_main9
;blink_led.c,28 :: 		PORTB = 0b00001111; // last LED's on
	MOVLW      15
	MOVWF      PORTB+0
;blink_led.c,29 :: 		Delay_ms(500);
	MOVLW      6
	MOVWF      R11+0
	MOVLW      19
	MOVWF      R12+0
	MOVLW      173
	MOVWF      R13+0
L_main10:
	DECFSZ     R13+0, 1
	GOTO       L_main10
	DECFSZ     R12+0, 1
	GOTO       L_main10
	DECFSZ     R11+0, 1
	GOTO       L_main10
	NOP
	NOP
;blink_led.c,30 :: 		PORTB = 0b00000000; // PORTB Off
	CLRF       PORTB+0
;blink_led.c,31 :: 		Delay_ms(500);
	MOVLW      6
	MOVWF      R11+0
	MOVLW      19
	MOVWF      R12+0
	MOVLW      173
	MOVWF      R13+0
L_main11:
	DECFSZ     R13+0, 1
	GOTO       L_main11
	DECFSZ     R12+0, 1
	GOTO       L_main11
	DECFSZ     R11+0, 1
	GOTO       L_main11
	NOP
	NOP
;blink_led.c,32 :: 		i++;
	INCF       _i+0, 1
	BTFSC      STATUS+0, 2
	INCF       _i+1, 1
;blink_led.c,33 :: 		}
	GOTO       L_main8
L_main9:
;blink_led.c,36 :: 		i = 1;
	MOVLW      1
	MOVWF      _i+0
	MOVLW      0
	MOVWF      _i+1
;blink_led.c,37 :: 		while(i <= 10) {
L_main12:
	MOVLW      128
	MOVWF      R0+0
	MOVLW      128
	XORWF      _i+1, 0
	SUBWF      R0+0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main24
	MOVF       _i+0, 0
	SUBLW      10
L__main24:
	BTFSS      STATUS+0, 0
	GOTO       L_main13
;blink_led.c,38 :: 		PORTB = 0b10101010; // last LED's on
	MOVLW      170
	MOVWF      PORTB+0
;blink_led.c,39 :: 		Delay_ms(500);
	MOVLW      6
	MOVWF      R11+0
	MOVLW      19
	MOVWF      R12+0
	MOVLW      173
	MOVWF      R13+0
L_main14:
	DECFSZ     R13+0, 1
	GOTO       L_main14
	DECFSZ     R12+0, 1
	GOTO       L_main14
	DECFSZ     R11+0, 1
	GOTO       L_main14
	NOP
	NOP
;blink_led.c,40 :: 		PORTB = 0b00000000; // PORTB Off
	CLRF       PORTB+0
;blink_led.c,41 :: 		Delay_ms(500);
	MOVLW      6
	MOVWF      R11+0
	MOVLW      19
	MOVWF      R12+0
	MOVLW      173
	MOVWF      R13+0
L_main15:
	DECFSZ     R13+0, 1
	GOTO       L_main15
	DECFSZ     R12+0, 1
	GOTO       L_main15
	DECFSZ     R11+0, 1
	GOTO       L_main15
	NOP
	NOP
;blink_led.c,42 :: 		i++;
	INCF       _i+0, 1
	BTFSC      STATUS+0, 2
	INCF       _i+1, 1
;blink_led.c,43 :: 		}
	GOTO       L_main12
L_main13:
;blink_led.c,46 :: 		i = 1;
	MOVLW      1
	MOVWF      _i+0
	MOVLW      0
	MOVWF      _i+1
;blink_led.c,47 :: 		while(i <= 10) {
L_main16:
	MOVLW      128
	MOVWF      R0+0
	MOVLW      128
	XORWF      _i+1, 0
	SUBWF      R0+0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main25
	MOVF       _i+0, 0
	SUBLW      10
L__main25:
	BTFSS      STATUS+0, 0
	GOTO       L_main17
;blink_led.c,48 :: 		PORTB = 0b01010101; // last LED's on
	MOVLW      85
	MOVWF      PORTB+0
;blink_led.c,49 :: 		Delay_ms(500);
	MOVLW      6
	MOVWF      R11+0
	MOVLW      19
	MOVWF      R12+0
	MOVLW      173
	MOVWF      R13+0
L_main18:
	DECFSZ     R13+0, 1
	GOTO       L_main18
	DECFSZ     R12+0, 1
	GOTO       L_main18
	DECFSZ     R11+0, 1
	GOTO       L_main18
	NOP
	NOP
;blink_led.c,50 :: 		PORTB = 0b00000000; // PORTB Off
	CLRF       PORTB+0
;blink_led.c,51 :: 		Delay_ms(500);
	MOVLW      6
	MOVWF      R11+0
	MOVLW      19
	MOVWF      R12+0
	MOVLW      173
	MOVWF      R13+0
L_main19:
	DECFSZ     R13+0, 1
	GOTO       L_main19
	DECFSZ     R12+0, 1
	GOTO       L_main19
	DECFSZ     R11+0, 1
	GOTO       L_main19
	NOP
	NOP
;blink_led.c,52 :: 		i++;
	INCF       _i+0, 1
	BTFSC      STATUS+0, 2
	INCF       _i+1, 1
;blink_led.c,53 :: 		}
	GOTO       L_main16
L_main17:
;blink_led.c,54 :: 		}
L_end_main:
	GOTO       $+0
; end of _main
