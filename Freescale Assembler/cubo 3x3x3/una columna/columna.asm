RAM_INI		EQU	$0080
FLASH_INI	EQU	$EE00
VECTORES	EQU	$FFDE
col_1           EQU     0       ;PTB0
col_2           EQU     1       ;PTB1
col_3           EQU     0       ;PTA0
col_4           EQU     1       ;PTA1
col_5           EQU     2       ;PTB2
col_6           EQU     3       ;PTB3
col_7           EQU     3       ;PTA3
col_8           EQU     4       ;PTB4
col_9		EQU     5       ;PTB5
fil_1           EQU     5       ;PTA5
fil_2           EQU     6       ;PTB6
fil_3           EQU     7       ;PTB7


$base		10t
$Include        'QTQY_registers.inc'



	org	FLASH_INI
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

        mov     #%00100000,OSCSC
        mov     #$81,OSCTRIM

        jsr     demora_qy
        jsr     demora_qy
        jsr     demora_qy
        jsr     demora_qy
        jsr     demora_qy
        jsr     demora_qy

        mov     #%00000000,PORTB
        mov     #%11111111,DDRB
        mov     #%00000000,PORTB
        nop
        nop


        mov     #%00000000,PORTA
        mov     #%11111111,DDRA
        mov     #%00000000,PORTA
        nop
        nop




iniciar:

	bclr	col_1,PORTB
        bclr	col_2,PORTB
        bclr	col_3,PORTA
        bclr	col_4,PORTA
        bclr	col_5,PORTB
        bclr	col_6,PORTB
        bclr	col_7,PORTA
        bclr	col_8,PORTB
        bclr	col_9,PORTB
        bclr	fil_1,PORTA
        bclr	fil_2,PORTB
        bclr	fil_3,PORTB
        jsr	demora_1000ms

        bset    fil_1,PORTA
        bset    fil_2,PORTB
        bset    fil_3,PORTB
        bset	col_9,PORTB
        jsr	demora_1000ms




        bra     iniciar



demora_qy:
        ldx     #$FF
dem_2:
        lda     #$FF
dem_1:
        deca
        bne     dem_1
        decx
        bne     dem_2
        rts

demora_1000ms:
	jsr	demora_qy
	jsr	demora_qy
	jsr	demora_qy
	jsr	demora_qy
	jsr	demora_qy
	jsr	demora_qy
demora_500ms:
	jsr	demora_qy
	jsr	demora_qy
demora_320ms:
	jsr	demora_qy
demora_240ms:
	jsr	demora_qy
demora_rapida:
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

tim1_1_isr:
        nop
	rti

tim1_0_isr:
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
