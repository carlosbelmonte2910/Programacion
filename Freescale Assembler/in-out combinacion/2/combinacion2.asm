RAM_INI         EQU     $0080
FLASH_INI       EQU     $EE00
VECTORES        EQU     $FFD0
IN_1            EQU     7
IN_2            EQU     6
OUT_1           EQU     1
OUT_2           EQU     0

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
	        mov	#%10000001,OSCTRIM

                jsr	demora_qy
                jsr	demora_qy
                jsr	demora_qy
                jsr	demora_qy
                jsr	demora_qy
                jsr	demora_qy


                mov             #%00000011,PORTB
                mov             #%00000011,DDRB
                mov             #%11000000,PTBPUE
                mov             #%00000011,PORTB



start_00:
                jsr     demora_1000ms
                jsr	encender
                jsr     demora_1000ms
                jsr     apagar                 
                bra     start_00               

encender:
                jsr     entrada1
                nop
                nop
                rts
entrada1:
                brset IN_1,PORTB,enc1
                rts

enc1:
                bclr    OUT_1,PORTB
                rts

apagar:
                jsr     entrada2
                nop
                nop
                rts
entrada2:
                brset IN_1,PORTB,apa1
                rts

apa1:
                bset   OUT_1,PORTB
                rts



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
