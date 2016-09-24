RAM_INI         EQU     $0080
FLASH_INI       EQU     $EE00
VECTORES        EQU     $FFD0
DB0             EQU     5
DB1             EQU     6
DB2             EQU     7
DB3             EQU     0
DB4             EQU     1
DB5             EQU     0
DB6             EQU     1
DB7             EQU     2
RS              EQU     4
RW              EQU     5
E               EQU     4

$base   10t
$include   'QTQY_Registers.inc'

                org     FLASH_INI
start:
                rsp
                clra
                clrh
                clrx
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

                mov             #%11110111,DDRB
                mov             #%00000000,PORTB

                mov             #%11110011,DDRA
                mov             #%00000000,PORTA

start_00:
                
                bclr   E,PORTA
                bclr   RS,PORTB
                bclr   RW,PORTB
                bclr   DB7,PORTB
                bclr   DB6,PORTA
                bclr   DB5,PORTA
                bclr   DB4,PORTB
                bset   DB3,PORTB
                bset   DB2,PORTB
                bset   DB1,PORTB
                bset   DB0,PORTA
                jsr     demora_1000ms

                bra     start_00

demora_qy:
	         ldx	#$02
dem_2:
	         lda	#$02
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
