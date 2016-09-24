;******************************************************************************
; 			CURSO HC908QY - TP01
;******************************************************************************
; 		DEFINICION DEL MAPA DE MEMORIA DEL MC68HC908QT1
;******************************************************************************
RAM_INI		EQU	$0080		;Direccion de Inicio de la RAM
RAM_FIN		EQU	$0100		;(+1) 128 Bytes.p/QY4
FLASH_INI	EQU	$F800		;Dir.de Inicio de FLASH ($F800 p/QY1)
FLASH_END	EQU	$FDFF		;4 KBytes p/QY4 - 1 KByte p/QY1
VECTORES	EQU	$FFDE		;Vectores de Interrupcion

;******************************************************************************
; 			ARCHIVOS DE DEFINICION INCLUIDOS
;******************************************************************************
$base		10t			;Base decimal por Default
$Include        'QTQY_registers.inc'	;Definiciones de Registros p/QTxx

;******************************************************************************
; 	DEFINICION DE LAS VARIABLES DE RAM DEL EQUIPO
;******************************************************************************
	org	RAM_INI

contador	rmb	$01		;Estado del Cont de salida
contador_2	rmb	$01		;Estado del Cont de Entrada

;******************************************************************************
; 		INICIO del PROGRAMA PRINCIPAL
;******************************************************************************
; 	Arranca AQUI cada vez que se APAGA el Equipo (Power On Reset)
;------------------------------------------------------------------------------
	org	FLASH_INI
start:
	clra				;Inicializo los Registros del CPU
	clrx				;
	clrh				;
	sei				;Desabilito Interrupciones
;---------------------------------------;
	jsr	prog_modulos		;> Programo TODOS los Modulos
;---------------------------------------;
	cli

;******************************************************************************
; 			PROGRAMA PRINCIPAL
;******************************************************************************
start_00:
           Bset   0,PORTA
           jsr    demora_tecla       
           jsr    demora_tecla
           Bclr   0,PORTA
           jsr    demora_1000ms
           jsr    demora_1000ms
           jsr    demora_1000ms
           jsr    demora_1000ms
           jmp	  start_00
;---------------------------------------;--------------------------------------
;******************************************************************************
; DEMORA_QY - Demora de 81,761 mseg segun el calculo
; Fclock=12.8 MHz -> Fbus=3.2 MHz -> Ciclo T=312,50 nseg
;******************************************************************************
demora_qy:
	ldx	#$ff			;[2]\
dem_2:
	lda	#$ff			;[2] |
dem_1:
	deca				;[1] |(((4x255)+4+2)x255)+2+4=261636d
        cmp     #$00
	bne	dem_1			;[3] |  261636 x 312,5nseg =
	decx				;[1] |  Total= 81,761 mseg
        cpx     #$00
	bne	dem_2			;[3]/
	rts				;
;---------------------------------------;--------------------------------------
;******************************************************************************
demora_tecla:
               ldx	#$e0			;[2]\
dem_02:
	       lda	#$e0			;[2] |
dem_01:
	       deca				;[1] |(((4x255)+4+2)x255)+2+4=261636d
               cmp     #$00
	       bne	dem_01			;[3] |  261636 x 312,5nseg =
	       decx				;[1] |  Total= 81,761 mseg
               cpx     #$00
    	       bne	dem_02			;[3]/
               rts				;
;******************************************************************************
;******************************************************************************
; DEMORA_1000MS - demora de 1 seg aproximadamente para usos varios
; DEMORA_500MS - demora de 500 mseg aproximadamente para usos varios
; DEMORA_320MS - demora de 320 mseg aproximadamente para usos varios
; DEMORA_240MS - demora de 240 mseg aproximadamente para usos varios
;******************************************************************************
demora_1000ms:
	jsr	demora_qy		;Demora de 81,761 mseg
	jsr	demora_qy		;Demora de 81,761 mseg
	jsr	demora_qy		;Demora de 81,761 mseg
	jsr	demora_qy		;Demora de 81,761 mseg
	jsr	demora_qy		;Demora de 81,761 mseg
	jsr	demora_qy		;Demora de 81,761 mseg
demora_500ms:
	jsr	demora_qy		;Demora de 81,761 mseg
	jsr	demora_qy		;Demora de 81,761 mseg
demora_320ms:
	jsr	demora_qy		;Demora de 81,761 mseg
demora_240ms:
	jsr	demora_qy		;Demora de 81,761 mseg
demora_rapida:
	jsr	demora_qy		;Demora de 81,761 mseg
	jsr	demora_qy		;Demora de 81,761 mseg
	rts


;******************************************************************************
; CLR_RAM - Borro toda la RAM desde donde apunta HX hasta el final
;******************************************************************************
clr_all_ram:
	ldhx	#RAM_INI		;\ Inicializo Totalmente la RAM
clr_a_ram_0:
        clr     0,x
        aix     #$01
        cphx    #{RAM_INI + 50}		;Borro 50 Bytes de Memoria RAM
        bne     clr_a_ram_0		;menos los ultimos bytes porque sino
	rts				;no puedo volver de la JSR



;******************************************************************************
;******************************************************************************
;			ARCHIVOS INCLUIDOS
;******************************************************************************
;******************************************************************************
$Include	'prog_modul_qtqyA.inc'	;Programacion de los Modulos de QT/QY


;******************************************************************************
;******************************************************************************
;			RUTINAS DE INTERUPCION
;******************************************************************************
;******************************************************************************

;******************************************************************************
; ADC_ISR - Rutina de Interrupcion del ADC
;******************************************************************************
adc_isr:
	rti				;

;******************************************************************************
; KEYB_ISR - Rutina de Interrupcion del KBI
;******************************************************************************
keyb_isr:
CONTROL_TECLA:

               
               JSR       demora_tecla
               brclr     3,PORTA,jumper2
               jmp       fin_00

jumper2:
                jsr     ENC_01
                jmp     fin_00

ENC_01:
        bclr	led_1,PORTB
	jsr      demora_320ms
       	bset	led_1,PORTB
	jsr      demora_320ms
      	bclr	led_1,PORTB
	jsr      demora_320ms
        bset	led_1,PORTB
	jsr      demora_320ms
    	bclr	led_1,PORTB
	jsr      demora_320ms
        bset	led_1,PORTB
	jsr      demora_320ms
        bclr	led_1,PORTB
	jsr      demora_320ms
        bset	led_1,PORTB
        jsr      demora_320ms
        rts
fin_00:
        bset    2,kbscr              ;borro interrupciones pendientes
        bclr    1,kbscr            ;habilito interrupcion por teclado
        rti



;******************************************************************************
; TIM1_OV_ISR - Rutina de Interrupcion por Overflow del Timer 1
;******************************************************************************
tim1_ov_isr:
	rti


;******************************************************************************
; TIM1_1_ISR - Rutina de Interrupcion del Canal 1 del Timer 1
;******************************************************************************
tim1_1_isr:
	rti				;


;******************************************************************************
; TIM1_0_ISR - Rutina de Interrupcion del Canal 0 del Timer 1
;******************************************************************************
tim1_0_isr:
	rti				;

;******************************************************************************
; IRQ_ISR - Rutina de Interrupcion Externa
;******************************************************************************
irq_isr:
	nop				;
	rti				;

;******************************************************************************
; SWI_ISR - Rutina de Interrupcion por Software
;******************************************************************************
swi_isr:
        nop				;
        rti                     	;

;******************************************************************************
; DUMMY_ISR - Dummy Interrupt Service Routine
; Rutina de servicio de Interupcion Fantasma, se pone por razones de seguridad
;******************************************************************************
dummy_isr:
        nop				;
        rti                     	; vuelve sin hacer nada

;******************************************************************************
; FLASH BLOCK PROTECT - Grabacion del Mismo
;******************************************************************************
;	Org	FLBPR
;	fcb	$ff			;Toda!!! la memoria esta desprotegida
;
;******************************************************************************
; VECTORES - Definicion de Vectores del Sistema
;******************************************************************************
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
