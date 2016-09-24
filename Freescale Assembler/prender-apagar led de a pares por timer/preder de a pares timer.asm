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

                mov	#%00100000,OSCSC
	        mov	#$81,OSCTRIM

                jsr	demora_qy
	        jsr	demora_qy
                jsr	demora_qy
                jsr	demora_qy
                jsr	demora_qy
                jsr	demora_qy

                mov	#%01110101,TSC

                mov	#$80,TMODH
                mov	#$00,TMODL		;19MS
                bclr	tstop,TSC		;Arranca el TIMER
                nop
                nop


                mov             #%11110000,DDRB
                mov             #%11110000,PORTB
                cli

start_00:

                bra     start_00

demora_qy:
	ldx	#$ff
dem_2:
	lda	#$ff
dem_1:
	deca
	bne	dem_1
	decx
	bne	dem_2
	rts


adc_isr:
                nop
                rti

keyb_isr:
                nop
                rti

tim1_ov_isr:
                brset	led_1,PTB,encender
                brset	led_3,PTB,encender
                
                brclr   led_2,PTB,encender
                brclr   led_4,PTB,encender
                
                bset	led_1,PTB
                bset	led_3,PTB
                
                bclr	led_2,PTB
                bclr	led_4,PTB
                
                bra	apagado
encender:
                bclr	led_1,PTB		;Enciende LED
                bclr	led_3,PTB
                
                bset    led_2,PTB
                bset    led_4,PTB

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

