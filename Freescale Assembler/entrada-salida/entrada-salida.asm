RAM_INI         EQU     $0080
FLASH_INI       EQU     $EE00
VECTORES        EQU     $FFD0
IN_1            EQU     7
IN_2            EQU     6
IN_3            EQU     5
IN_4            EQU     4
OUT_1           EQU     0
OUT_2           EQU     1
OUT_3           EQU     2
OUT_4           EQU     3

$base   10t
$include   'QTQY_Registers.inc'

                org     FLASH_INI
start:

                clra
                clrh
                clrx
                rsp
                sei

                mov     #%10000000,CONFIG2
                mov     #%00001101,CONFIG1
                nop
                nop
                nop

                mov	#%00100000,OSCSC
	        mov	#$81,OSCTRIM

                jsr	demora_qy
                jsr	demora_qy
                jsr	demora_qy
                jsr	demora_qy
                jsr	demora_qy
                jsr	demora_qy


                mov     #%00001111,PORTB
                mov     #%00001111,DDRB
                mov     #%11110000,PTBPUE
                mov     #%00001111,PORTB

;Sirve para mandar el estado de la entrada a la salida, no lo mantiene;

start_00:
                bclr    OUT_1,PORTB             ;
                bclr    OUT_2,PORTB             ;Apaga los led en cada inicio
                bclr    OUT_3,PORTB             ;
                bclr    OUT_4,PORTB             ;
                jsr	codigo                  ;Salta a las sub-funciones
                nop
                nop
                bra     start_00                ;

codigo:
                jsr     entrada1
                nop
                ;jsr     entrada2
                ;nop
                ;jsr     entrada3
                ;nop
                ;jsr     entrada4
                nop
                nop
                rts
entrada1:
                brset IN_1,PORTB,enc1           ;Si hay un 1 salta a la sub funcion enc1
                nop
                brclr IN_1,PORTB,apa1           ;Si hay un 0 salta a la sub funcion apa1
                rts

;entrada2:
                ;brset IN_2,PORTB,enc2           ;Si hay un 1 salta a la sub funcion enc2
                ;nop
                ;brclr IN_2,PORTB,apa2           ;Si hay un 0 salta a la sub funcion apa2
                ;rts

;entrada3:
                ;brset IN_3,PORTB,enc3           ;Si hay un 1 salta a la sub funcion enc3
                ;nop
                ;brclr IN_3,PORTB,apa3           ;Si hay un 0 salta a la sub funcion apa3
                ;rts

;entrada4:
                ;brset IN_4,PORTB,enc4           ;Si hay un 1 salta a la sub funcion enc4
                ;nop
                ;brclr IN_4,PORTB,apa4           ;Si hay un 0 salta a la sub funcion apa4
                ;rts
;==========================================================================================;
enc1:
                bset    OUT_1,PORTB             ;Enciende el led
                nop
                rts

;enc2:
                ;bset    OUT_2,PORTB             ;Enciende el led
                ;nop
                ;rts

;enc3:
                ;bset    OUT_3,PORTB             ;Enciende el led
                ;nop
                ;rts

;enc4:
                ;bset    OUT_4,PORTB             ;Enciende el led
                ;nop
                ;rts
;==========================================================================================;
apa1:
                bclr    OUT_1,PORTB             ;Apaga el led
                nop
                rts

;apa2:
                ;bclr    OUT_2,PORTB             ;Apaga el led
                ;nop
                ;rts

;apa3:
                ;bclr    OUT_3,PORTB             ;Apaga el led
                ;nop
                ;rts

;apa4:
                ;bclr    OUT_4,PORTB             ;Apaga el led
                ;nop
                ;rts
;==========================================================================================;

demora_qy:
	         ldx	#$FF
dem_2:
	         lda	#$FF
dem_1:
	         deca
                 bne	dem_1
                 decx
                 bne	dem_2
                 rts

demora_1000ms:
	         jsr	demora_qy
                 jsr	demora_qy
                 jsr	demora_qy
                 jsr	demora_qy
                 jsr	demora_qy
                 jsr	demora_qy
                 rts
adc_isr:
                nop
                rti

keyb_isr:
                nop
                rti

tim1_ov_isr:
                nop
                rti

tim1_0_isr:
                nop
                rti

tim1_1_isr:
                nop
                rti

irq_isr:
                nop
                rti
swi_isr:
                nop
                rti

dummy_isr:
                nop
                rti

                org	VECTORES
	fdb	adc_isr		; ADC Vector
	fdb	keyb_isr	; KEYBOARD Vector

	org	$FFF2
	fdb	tim1_ov_isr	; TIM1 Overflow Vector
	fdb	tim1_1_isr	; TIM1 Channel 1 Vector
	fdb	tim1_0_isr	; TIM1 Channel 0 Vector

	org	$FFFA
	fdb	irq_isr		; IRQ1	Vector
	fdb	swi_isr		; SWI Vector
	fdb	Start		; Reset


end
