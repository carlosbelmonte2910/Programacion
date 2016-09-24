;******************************************************************************
; 			Brazo robotico leonel brunet, martin brunet
;******************************************************************************
; 		DEFINICION DEL MAPA DE MEMORIA DEL MC68HC908QY4
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
$Include        'REGISTRO_QY4A_1.inc'	;Definiciones de Registros p/QTxx

;******************************************************************************
; 	DEFINICION DE LAS VARIABLES DE RAM DEL EQUIPO
;******************************************************************************
	org	RAM_INI
CONT0         	   ds      1
RETARDO1           ds      1
RETARDO2           ds      1
aumento1	   ds	   1
simulacion         ds	   1

;******************************************************************************
; 		INICIO del PROGRAMA PRINCIPAL
;******************************************************************************
; 	Arranca AQUI cada vez que se APAGA el Equipo (Power On Reset)
;------------------------------------------------------------------------------
	org	FLASH_INI

tabla	db	$0,15t,30t,45t,75t,90t,105t,120t,$0

start:
	rsp
	clra				;Inicializo los Registros del CPU
	clrx				;
	clrh				;
	sei				;Desabilito Interrupciones
					;resetea stank pointer

;---------------------------------------;
	jsr	prog_modulos		;> Programo TODOS los Modulos
;---------------------------------------;

;-------------- Programo el TIMER-------;--------------------------------------
;Fclock=12.8 MHz -> Fbus=3.2 MHz -> Ciclo T =312.50 nseg
;
	mov	#$36,TSC

	mov	#$03,TMODH
	mov	#$FF,TMODL		;20mS
	mov	#$00,TCH0H
	mov	#$69,TCH0L
	mov	#%01101010,TSC0
	mov	#$06,TSC		;Arranca el TIMER
	nop
	nop
	cli

;-------------- Programo el KBI-------;--------------------------------------

;	mov	#%00000001,KBSCR
;	mov	#%00010000,KBIER
;	nop
;	nop

;******************************************************************************
; 			PROGRAMA PRINCIPAL
;******************************************************************************


;*************************************TECLADO**********************************
	clr     CONT0
start_00:
	bset	0,PORTB
	jsr	demora_1s
	bclr	0,PORTB
	jsr	demora_1s

	bra	start_00







;---------------------------------------;--------------------------------------
;******************************************************************************





retardo_1ms:

	mov     #$01,RETARDO1	      ;[4]
ret_1:
	mov     #$F4,RETARDO2	      ;[4]
ret_2:
	dec	RETARDO2	      ;[4]
	clra			      ;[1]
    	cbeq    RETARDO2,ret_1a	      ;[5]4+4+[((4+1+5+3)x244)+4+4+1+5+3)x001]
	bra	ret_2		      ;[3](((13)x244)+17)x001)+8+3=3200c
ret_1a				      ;     3200 x 312,5nseg = 1.000.000ns
	dec	RETARDO1	      ;[4]  1ms
	clra		              ;[1]
   	cbeq    RETARDO2,finret	      ;[5]
	bra	ret_1		      ;[3]
finret:
	nop
	nop
	nop
	rts

retardo_10ms:
	jsr	retardo_1ms
	jsr	retardo_1ms
	jsr	retardo_1ms
	jsr	retardo_1ms
	jsr	retardo_1ms
	jsr	retardo_1ms
	jsr	retardo_1ms
	jsr	retardo_1ms
	jsr	retardo_1ms
	jsr	retardo_1ms
	rts

retardo_100ms:

	jsr	retardo_10ms
	jsr	retardo_10ms
	jsr	retardo_10ms
	jsr	retardo_10ms
	jsr	retardo_10ms
	jsr	retardo_10ms
	jsr	retardo_10ms
	jsr	retardo_10ms
	jsr	retardo_10ms
	jsr	retardo_10ms
	rts

retardo_1s:
	jsr	retardo_100ms
	jsr	retardo_100ms
	jsr	retardo_100ms
	jsr	retardo_100ms
	jsr	retardo_100ms
	jsr	retardo_100ms
	jsr	retardo_100ms
	jsr	retardo_100ms
	jsr	retardo_100ms
	jsr	retardo_100ms
	rts





motor1antihorario:
 	mov     #$03,CONT0
salida_1a:
	dec     CONT0
	bset	motor1,PORTB
	jsr	demora_01ms
	jsr	demora_01ms
	jsr	demora_01ms
	bclr	motor1,PORTB
	jsr	demora_10ms
	jsr	demora_10ms
	jsr	demora_10ms
	clra
    	cbeq    CONT0,seguir_1a
	bra	salida_1a
seguir_1a:
	rts


motor1horario:
 	mov     #$03,CONT0
salida_1h:
	dec	CONT0
	bset	motor1,PORTB
	jsr	demora_05ms
	jsr	demora_1ms
	jsr	demora_1ms
	bclr	motor1,PORTB
	jsr	demora_10ms
	jsr	demora_10ms
	jsr	demora_1ms
	clra
  	cbeq    CONT0,seguir_1h
	bra	salida_1h
seguir_1h:
	rts


motor2antihorario:
 	mov     #$0A,CONT0
salida_2a:
	dec     CONT0
	bset	motor2,PORTB
	jsr	demora_05ms
	bclr	motor2,PORTB
	jsr	demora_10ms
	jsr	demora_05ms
	jsr	demora_1ms
	jsr	demora_1ms
	jsr	demora_1ms
	jsr	demora_1ms
	jsr	demora_1ms
	jsr	demora_1ms
	jsr	demora_1ms
	jsr	demora_1ms
	clra
    	cbeq    CONT0,seguir_2a
	bra	salida_2a
seguir_2a:
	rts


motor2horario:
 	mov     #$0A,CONT0
salida_2h:
	dec	CONT0
	bset	motor2,PORTB
	jsr	demora_05ms
	jsr	demora_1ms
	jsr	demora_1ms
	jsr	demora_1ms
	bclr	motor2,PORTB
	jsr	demora_10ms
	jsr	demora_05ms
	jsr	demora_1ms
	jsr	demora_1ms
	jsr	demora_1ms
	jsr	demora_1ms
	jsr	demora_1ms
	jsr	demora_1ms
	clra
  	cbeq    CONT0,seguir_2h
	bra	salida_2h
seguir_2h:
	rts


motor3antihorario:
 	mov     #$0A,CONT0
salida_3a:
	dec     CONT0
	bset	motor3,PORTB
	jsr	demora_05ms
	bclr	motor3,PORTB
	jsr	demora_10ms
	jsr	demora_05ms
	jsr	demora_1ms
	jsr	demora_1ms
	jsr	demora_1ms
	jsr	demora_1ms
	jsr	demora_1ms
	jsr	demora_1ms
	jsr	demora_1ms
	jsr	demora_1ms
	clra
    	cbeq    CONT0,seguir_3a
	bra	salida_3a
seguir_3a:
	rts


motor3horario:
 	mov     #$0A,CONT0
salida_3h:
	dec	CONT0
	bset	motor3,PORTB
	jsr	demora_05ms
	jsr	demora_1ms
	jsr	demora_1ms
	jsr	demora_1ms
	bclr	motor3,PORTB
	jsr	demora_10ms
	jsr	demora_05ms
	jsr	demora_1ms
	jsr	demora_1ms
	jsr	demora_1ms
	jsr	demora_1ms
	jsr	demora_1ms
	jsr	demora_1ms
	clra
  	cbeq    CONT0,seguir_3h
	bra	salida_3h
seguir_3h:
	rts



motor4antihorario:
 	mov     #$05,CONT0
salida_4a:
	dec     CONT0
	bset	motor4,PORTB
	jsr	demora_05ms
	bclr	motor4,PORTB
	jsr	demora_10ms
	jsr	demora_05ms
	jsr	demora_1ms
	jsr	demora_1ms
	jsr	demora_1ms
	jsr	demora_1ms
	jsr	demora_1ms
	jsr	demora_1ms
	jsr	demora_1ms
	jsr	demora_1ms
	clra
    	cbeq    CONT0,seguir_4a
	bra	salida_4a
seguir_4a:
	rts


motor4horario:
 	mov     #$0A,CONT0
salida_4h:
	dec	CONT0
	mov	#%00000010,PORTB
	jsr	demora_05ms
	jsr	demora_1ms
	jsr	demora_1ms
	jsr	demora_1ms
	mov	#%00000000,PORTB
	jsr	demora_10ms
	jsr	demora_05ms
	jsr	demora_1ms
	jsr	demora_1ms
	jsr	demora_1ms
	jsr	demora_1ms
	jsr	demora_1ms
	jsr	demora_1ms
	clra
  	cbeq    CONT0,seguir_4h
	bra	salida_4h
seguir_4h:
	rts



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
	bne	dem_1			;[3] |  261636 x 312,5nseg =
	decx				;[1] |  Total= 81,761 mseg
	bne	dem_2			;[3]/
	rts

demora_01ms:
	lda	#$4f			;[2] |
dem_1a:
	deca				;[1] |((4x79)+2+2=320d
	bne	dem_1a			;[3] |  320 x 312,5nseg = 100.000ns
	nop
	nop		  		;    |  Total= 0,1 mseg
	rts


demora_05ms:

	jsr	demora_01ms
	jsr	demora_01ms
	jsr	demora_01ms
	jsr	demora_01ms
	jsr	demora_01ms
	rts




demora_1ms:
	ldx	#$47			;[2]\
dem_22:
	lda	#$0b			;[2] |
dem_11:
	deca
	cmp     #$00			;[1] |(((4x71)+4+2)x11)+2+4+4=3200d
	bne	dem_11			;[3] |  3200 x 312,5nseg = 1.000.000ns
	decx
     	cpx     #$00			;[1] |  Total= 1ms
	bne	dem_22			;[3]/
	nop
	nop
	nop
	nop
	rts

demora_10ms:
	jsr	demora_1ms
	jsr	demora_1ms
	jsr	demora_1ms
	jsr	demora_1ms
	jsr	demora_1ms
	jsr	demora_1ms
	jsr	demora_1ms
	jsr	demora_1ms
	jsr	demora_1ms
	jsr	demora_1ms
	rts

demora_100ms:
	jsr	demora_10ms
	jsr	demora_10ms
	jsr	demora_10ms
	jsr	demora_10ms
	jsr	demora_10ms
	jsr	demora_10ms
	jsr	demora_10ms
	jsr	demora_10ms
	jsr	demora_10ms
	jsr	demora_10ms
	rts

demora_1s:
	jsr	demora_100ms
	jsr	demora_100ms
	jsr	demora_100ms
	jsr	demora_100ms
	jsr	demora_100ms
	jsr	demora_100ms
	jsr	demora_100ms
	jsr	demora_100ms
	jsr	demora_100ms
	jsr	demora_100ms
	rts

demora_10s:
	jsr	demora_1s
	jsr	demora_1s
	jsr	demora_1s
	jsr	demora_1s
	jsr	demora_1s
	jsr	demora_1s
	jsr	demora_1s
	jsr	demora_1s
	jsr	demora_1s
	jsr	demora_1s
	rts

demora_1min:
	jsr	demora_10s
	jsr	demora_10s
	jsr	demora_10s
	jsr	demora_10s
	jsr	demora_10s
	jsr	demora_10s
	rts

demora_10min:
	jsr	demora_1min
	jsr	demora_1min
	jsr	demora_1min
	jsr	demora_1min
	jsr	demora_1min
	jsr	demora_1min
	jsr	demora_1min
	jsr	demora_1min
	jsr	demora_1min
	jsr	demora_1min
	rts

demora_1h:

	jsr	demora_10min
	jsr	demora_10min
	jsr	demora_10min
	jsr	demora_10min
	jsr	demora_10min
	jsr	demora_10min
	rts

demora_12h:

	jsr	demora_1h
	jsr	demora_1h
	jsr	demora_1h
	jsr	demora_1h
	jsr	demora_1h
	jsr	demora_1h
	jsr	demora_1h
	jsr	demora_1h
	jsr	demora_1h
	jsr	demora_1h
	jsr	demora_1h
	jsr	demora_1h
	rts

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
$Include	'PROG_MOD_QY4A_1.inc'	;Programacion de los Modulos de QT/QY


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
	bclr	7,TSC0
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
