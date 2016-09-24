RAM_INI         EQU     $0080
FLASH_INI       EQU     $EE00
VECTORES        EQU     $FFD0
LED_1           EQU     7
LED_2           EQU     6
LED_3           EQU     5
LED_4           EQU     4


$base   10t
$include   'QTQY_Registers.inc'

                org     FLASH_INI
start:
                rsp
                clra
                clrh
                clrx
                sei

                mov             #%10000000,CONFIG2
                mov             #%00001101,CONFIG1
                nop
                nop
                nop

                mov             #%00100000,OSCSC
                mov             #$81,OSCTRIM

                jsr	demora_qy
                jsr	demora_qy
                jsr	demora_qy
                jsr	demora_qy
                jsr	demora_qy
                jsr	demora_qy

                mov             #%01110101,TSC
                mov             #$80,TMODH
                mov             #$00,TMODL
                nop
                nop
         
                
                mov             #%11110000,DDRB
                mov             #%11110000,PORTB
                cli
                

start_00:

                bclr    led_1,PORTB
                jsr	demora_1000ms
                bclr    led_2,PORTB
                bset    led_1,PORTB
                jsr	demora_1000ms
                bclr    led_3,PORTB
                bset    led_2,PORTB
                jsr     demora_1000ms
                bclr    led_4,PORTB
                bset    led_3,PORTB
                jsr     demora_1000ms
                bset    led_4,PORTB
                jsr     demora_1000ms
                jsr     demora_1000ms
                jsr     demora_1000ms
                bclr    led_1,PORTB
                bclr    led_2,PORTB
                bclr    led_3,PORTB
                bclr    led_4,PORTB
                jsr     demora_1000ms
                bset    led_1,PORTB
                bset    led_2,PORTB
                bset    led_3,PORTB
                bset    led_4,PORTB
                bclr	tstop,TSC		;Arranca el TIMER
                
                

                bra     start_00

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
                brset	LED_4,PTB,encender
	        bset	LED_4,PTB		;Apaga LED
                bra	apagado

encender:
                bclr	LED_4,PTB		;Enciende LED

apagado:
                bclr	tof,TSC
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
