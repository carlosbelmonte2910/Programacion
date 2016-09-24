;******************************************************************************
; 			CURSO HC908QY 
;******************************************************************************
;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
;utilizo el timer y kbi, los dos por interrupciones mientras que en el programa 
;principal se este desarrollando otro trabajo independientes de las interrupciones,
;en el kbi cuando se presiones el pul_kbi se habilitara la interrupcion que sera 
;prender el led_3 del ptb, mientras que el timer overflow prendera y apagara cada
; 1 seg el led_7 del ptb.
;++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
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
	cli                             ; habilito interrupciones
;******************************************************************************
;                          configuro el KBI
;******************************************************************************
        MOV #%00000001,KBIER            ;configuro que solo el pin 13 KBI0, es
                                        ;el pin de entrada del kbi
        bset ACKK,KBSCR                 ;desabilito interrupciones pendientes ACKK
        bclr MODEK,KBSCR                ;solo int. por flanco descendente MODEK
        bclr IMASKK,KBSCR               ;hab. int. no enmascaradas IMASKK
;******************************************************************************
;                          configuro el timer
;******************************************************************************
        mov #%00100110,TSC              ;desabilito el timer y programo el
         ;bit 76543210                  ;prescaler
                                        ;bit 0,1,2--->prescaler en este
                                        ;caso 110(divido por 64)
                                        ;bit4---> trts=0 deshabilitado
                                        ;bit5---> tstop=1 deshabilitado
                                        ;bit6---> toie=0 desabilitado
                                        ;bit7---> tof=0 desabiltado xq
                                        ;el timer no comenzo a contar.                                      

;************************************
;*            rango*frec. oscilador  * 1[seg]*(12,8*10^6)[Hz]
;*TMOD H,L= ------------------------ *----------------------- = 50000 =$C350
;*                4*prescaler        *          4* 64
;************************************


        mov #$C3,TMODH                  ;part alta del tmod
        mov #$50,TMODL                  ;part baja del tmod
        mov #%01000110,TSC              ;habilito el timer y programo el
         ;bit 76543210                  ;prescaler
                                        ;bit 0,1,2--->prescaler en este
                                        ;caso 110(divido por 64)
                                        ;bit4---> trts=0 habilitado
                                        ;bit5---> tstop=1 habilitado
                                        ;bit6---> toie=0 habilitado
                                        ;bit7---> tof=0 hasta que termine el 
                                        ;conteo cambia de estado
                                        

;******************************************************************************
; 	DEFINICION DE LOS PINES DE ENTRADA/SALIDA DEL EQUIPO
;******************************************************************************
;---------------------- Puerto B-----------------------------------------------
        mov     #%00000000,PORTB         ;Programo el PTB y luego el DDRA
        mov     #%11111111,DDRB		 ;DDRA todos salidas
        mov     #%00000000,PORTB         ;Escribo Valores por default

led_1		equ	0		;Salida Control de Led 1
led_2		equ	1		;Salida Control de Led 2
led_3		equ	2		;Salida Control de Led 3
led_4		equ	3		;Salida Control de Led 4
led_5		equ	4		;Salida Control de Led 5
led_6		equ	5		;Salida Control de Led 6
led_7		equ	6		;Salida Control de Led 7
led_8		equ	7		;Salida Control de Led 8

;*******************************************************************************
;                          puerto A
;*******************************************************************************
         mov     #%11100111,PORTA	;Programo el PTA y luego el DDRA
         mov     #%11111110,DDRA	;programo al ddra bit 1-7 salidas
                                        ;y el bit o como entrada en nuestro
                                        ;para usarlo en el KBI
         mov     #%11100111,PORTA	;Escribo Valores por default
        
pul_kbi         equ     0               ;nombro al bit 0 del ptA como pul_kbi

;******************************************************************************
; 			PROGRAMA PRINCIPAL
;******************************************************************************

inicio:
	bset	led_1,PORTB
	jsr	demora_rapida


	bclr	led_1,PORTB
	jsr	demora_rapida


	bra	inicio		;

;---------------------------------------;--------------------------------------
;******************************************************************************
; DEMORA_QY - Demora de 81,761 mseg segun el calculo
; Fclock=12.8 MHz -> Fbus=3.2 MHz -> Ciclo T=312,50 nseg
;******************************************************************************
demora_teclado:
	ldx	#$0E			;[2]\
dem_2:
	lda	#$0E			;[2] |
dem_1:
	deca
        cmp    	#00			;[1] |
	bne	dem_1			;[3] |  
	decx
        cmp	#00	         	;[1] |  
	bne	dem_2			;[3]/
	rts				;
        



;---------------------------------------;--------------------------------------
;******************************************************************************
; DEMORA_QY - Demora de 81,761 mseg segun el calculo
; Fclock=12.8 MHz -> Fbus=3.2 MHz -> Ciclo T=312,50 nseg
;******************************************************************************
demora_qy:
	ldx	#$ff			;[2]\
dem_2_:
	lda	#$ff			;[2] |
dem_1_:
	deca
        cmp    	#00			;[1] |(((4x255)+4+2)x255)+2+4=261636d
	bne	dem_1_			;[3] |  261636 x 312,5nseg =
	decx
        cmp	#00	         	;[1] |  Total= 81,761 mseg
	bne	dem_2_			;[3]/
	rts				;

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
TECLADO:
                jsr     demora_teclado          ;salto una pequeña demora por soft
                                                ;ya que el micro trabaja a altas velocidades
                                                ;la pulsacion del boton es como de 10mseg
                                                ;para ello esa pequeña demora
                brclr   pul_kbi,PTA,PRENDER     ;pregunto si esta en 0 el pulsador
                                                ;si esta en 0 salta a prender
                jmp     FIN                     ;si no esta en 0 salte a fin

PRENDER:
                jsr     TRABAJO                 ;salte a la subrutina trabajo
                jmp     FIN                     ;salte a fin cuando vuelve del rts de trabajo

TRABAJO:
                bset    led_3,ptb               ;prendo led del ptb
                jsr     demora_qy               ;salto a la demora para el encendido del led
                jsr     demora_qy               ;salto a la demora para el encendido del led
                bclr    led_3,ptb               ;apago el led del ptb
                jsr     demora_qy               ;salto a la demora para el apagado del led
                jsr     demora_qy               ;salto a la demora para el apagado del led
                rts                             ;como es una subrutina que mediante un jsr
                                                ;(salto a subrutina) se realiza el trabajo
                                                ;y vuelve a la ultima posicion donde apuntaba el pc
                                                ;mediante un rts (retorn de subrutina)

FIN:
                bset    ACKK,KBSCR              ;borro interrupciones pendientes
                bclr    IMASKK,KBSCR            ; hab. int. no enmascaradas
         
	rti                                     ;retorno de interrupcion


;******************************************************************************
; TIM1_OV_ISR - Rutina de Interrupcion por Overflow del Timer 1
;******************************************************************************
tim1_ov_isr:
	brclr	led_7,PTB,encender               ;pregunta si el led esta apagado
                                                 ; si no esta apagado sigue,
                                                 ; y si esta apagado salte a encender
	bclr	led_7,PTB		         ;apaga LED
	bra	apagado                          ;salte a apagado
encender:
	bset	led_7,PTB		         ;Enciende LED
apagado:
	bclr	tof,TSC                          ;Pone a 0 el bit "tof" del registro tsc": esto permite
                                                 ;que al salir de esta subrrutina (del vector de interrup
                                                 ;"TIM_OV_ISR") se borre la máscara de interrup I de modo
                                                 ;que cuando el módulo TIM genere el próximo pedido de
                                                 ;interrup, el micro lo atienda.
                                                 ;retorna al programa principal
               
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
