;******************************************************************************
; 			PROYECTO FINAL (Leonel Brunet, Martin Brunet)
;******************************************************************************
; 		DEFINICION DEL MAPA DE MEMORIA DEL MC68HC908QY4A
;******************************************************************************
RAM_INI		EQU	$0080		;Direccion de Inicio de la RAM
RAM_FIN		EQU	$00FF		;(+1) 128 Bytes.p/QY4
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

RETARDO1	ds		1	;Estado del Cont de salida
RETARDO2	ds		1	;Estado del Cont de Entrada
CONT0           ds              1
aumento1        ds              1
desplazador     ds              1
comunicacion    ds              1
detector        ds              1
compa1          ds              1
compa2          ds              1


;******************************************************************************
; 		INICIO del PROGRAMA PRINCIPAL
;******************************************************************************
; 	Arranca AQUI cada vez que se APAGA el Equipo (Power On Reset)
;------------------------------------------------------------------------------
	org	FLASH_INI

TABLA            DB      $0,180t,175t,170t,165t,160t,155t,150t,135t,130t,125t,120t,115t,110t,105t,100t,95t,90t
                 DB      85t,80t,75t,70t,65t,60t,55t,50t,45t,40t,35t,30t,25t,20t,18t,16t,14t,12t,10t,8t,5t,$0

start:

	clra				;Inicializo los Registros del CPU
	clrx				;
	clrh				;
        rsp
	sei				;Desabilito Interrupciones



;******************************************************************************
;                              	CONFIGURACION
;******************************************************************************
	mov	#%10000000,CONFIG2	;Configuracion del registro
;		   \\\\\\\\_____________;RSTEN= 0 Funcion inactiva en pin
;		    \\\\\\\_____________;OSCENINSTOP= 0 Oscilador desab en STOP
;		     \\\\\\_____________;none
;		      \\\\\_____________;none
;		       \\\\_____________;none
;		        \\\_____________;none
;		         \\_____________;IRQEN= 0 IRQ desabilitada
;		          \_____________;IRQPUD= 1 Pull Up desconectada


        mov	#%00001101,CONFIG1	;Configuracion del registro
;                  \\\\\\\\_____________;COPD= 1 COP desabilitado
;                   \\\\\\\_____________;STOP= 0 instruccion STOP desabilitada
;                    \\\\\\_____________;SSREC= 1 Recup de modo STOP 32 ciclos
;                     \\\\\_____________;LVITRIP= 1 LVI operate en 5V
;                      \\\\_____________;LVIPWRD= 0 LVI habilitado
;                       \\\_____________;LVIRSTD= 0 Reset desde LVI habilitado
;                        \\_____________;LVISTOP= 0 LVI desabilitado en STOP
;                         \_____________;COPRS= 0 COP reset long cycle

	nop				; aseguran la configuracion
	nop				;
	nop				;

;-------------- Programacion del OSCILADOR QTA/QYA-----------------------------
; Fclock=12.8 MHz -> Fbus=3.2 MHz -> Ciclo T=312,50 nseg
;------------------------------------------------------------------------------
	mov	#%00100000,OSCSC	; OSCILLATOR STATUS & CONTROL REGISTER
;		   \\\\\\\\_____________;ECGST= Read Only
;		    \\\\\\\_____________;ECGON= 0 Oscilador Externo desabilitado
;		     \\\\\\_____________;ECFS0= 0 \ 00= Xtal Externo 8-32 MHz
;		      \\\\\_____________;ECFS1= 0 /
;		       \\\\_____________;ICFS0= 0 \ 10= Osc 12.8 MHz
;		        \\\_____________;ICSF1= 1 /
;		         \\_____________;OSCOPT0= 0 \ 00= Oscilador Interno
;		          \_____________;OSCOPT1= 0 /

	mov	#$81,OSCTRIM		;Ajuste Fino del Oscilador

;------------------------------------------------------------------------------
	jsr	demora_qy		;Demora de 81,761 mseg
	jsr	demora_qy		;Demora de 81,761 mseg
	jsr	demora_qy		;Demora de 81,761 mseg
	jsr	demora_qy		;Demora de 81,761 mseg
	jsr	demora_qy		;Demora de 81,761 mseg
	jsr	demora_qy		;Demora de 81,761 mseg

;------------------------------------------------------------------------------


;******************************************************************************
; 	DEFINICION DE LOS PINES DE ENTRADA/SALIDA DEL EQUIPO Micro 1
;******************************************************************************
;---------------------- Puerto A
motor0		equ	0		;salida,motor 0 manejado por PWM del canal 0 del timmer
fila0          	equ	1		;entrada,kbi1 para la fila 0
fila1		equ	2		;entrada,kbi2 para la fila 1
columna0        equ	3		;salida,columna 0
columna2	equ	4		;salida,columna 2
columna3	equ	5		;salida,columna 3
nousado0	equ	6		;no se usa
nousado1	equ	7		;no se usa

;---------------------- Puerto B
com_sal1	equ	0		;salida,comunicacion con otro micro
com_sal2	equ	1		;salida,comunicacion con otro micro
indef1		equ	2		;salida,todavia nose
indef2		equ	3		;salida,todavia nose
com_ent5	equ	4		;entrada,comunicacion con otro micro
columna1	equ	5		;salida,columna 1
com_sal3	equ	6		;salida,comunicacion con otro micro
com_sal4	equ	7		;salida,comunicacion con otro micro

;******************************************************************************
; 			PROGRAMO LOS PUERTOS DE ENTRADA Y SALIDA
;******************************************************************************

        mov     #%11111001,PORTA
        mov     #%11111001,DDRA		;Configuracion de entradas y salidas PUERTO A
        mov     #%00000110,PTAPUE	;Activo resistencia PULL-UP a las Entradas
        mov     #%00111000,PORTA        ;Valores por Defecto

        mov     #%11101111,PORTB
        mov     #%11101111,DDRB		;Configuracion de entradas y salidas PUERTO A
        mov     #%00010000,PTBPUE       ;Activo resistencia PULL-UP a las Entradas
        mov     #%00000000,PORTB	;Valores por Defecto

;******************************************************************************
; 			PROGRAMO KBI - TECLADO -
;******************************************************************************

        bset    imaskk,kbscr                  ;Detengo la interrupcion pata configurar
        mov     #%00000110,kbier              ;Habilito los pines de Interrupcion
        bclr    ackk,kbscr
        bclr    imaskk,kbscr                  ;Habilito interrupcion de Teclado

;******************************************************************************
;              PROGRAMO EL PWM POR EL CANAL 0 DEL TIMMER MICRO 1
;******************************************************************************

	mov	#$36,TSC
	mov	#$03,TMODH
	mov	#$E8,TMODL		;Configuro el PWM para tener un periodo de 20mS
	mov	#$00,TCH0H
	mov	#100t,TCH0L              ;configuro p/ que comienze con un ancho de 0,5ms
	mov	#%01101010,TSC0         ;Configuro registro TSC0
	mov	#$46,TSC		;Arranca el TIMER, utilizo desbordamiento
	nop
	nop

;******************************************************************************

         cli

;******************************************************************************
; 			PROGRAMA PRINCIPAL
;******************************************************************************

          Clr      RETARDO1
          Clr      RETARDO2
          Clr      CONT0
          Clr      aumento1
          clr      desplazador
          mov      #15t,desplazador
          mov      #10t,compa1
          mov      #135t,compa2
          clrx

start_00:




         bra    start_00





  ;       jsr    retardo_1s

  ;       ldx    desplazador

  ;       incx
   ;      lda    tabla,x
   ;      sta    TCH0L
   ;      stx    desplazador


        bra     start_00

   		;
;---------------------------------------;--------------------------------------
;******************************************************************************
; DEMORA_QY - Demora de 81,761 mseg segun el calculo
; Fclock=12.8 MHz -> Fbus=3.2 MHz -> Ciclo T=312,50 nseg
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

retardo_01ms:
	lda	#$4f			;[2] |
dem_1a:
	deca				;[1] |((4x79)+2+2=320d
	bne	dem_1a			;[3] |  320 x 312,5nseg = 100.000ns
	nop
	nop		  		;    |  Total= 0,1 mseg
	rts

retardo_05ms:
	jsr	retardo_01ms
	jsr	retardo_01ms
	jsr	retardo_01ms
retardo_02ms:
	jsr	retardo_01ms
	jsr	retardo_01ms
	rts

demora_qy:
	ldx	#$ff			;[2]\
dem_2:
	lda	#$ff			;[2] |
dem_1:
	deca				;[1] |(((4x255)+4+2)x255)+2+4=261636d
	bne	dem_1			;[3] |  261636 x 312,5nseg =
	decx				;[1] |  Total= 81,761 mseg
	bne	dem_2			;[3]/
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

cambiar1:
       ldx    desplazador
       incx
       lda    tabla,x
       cbeq   compa1,minimo
       sta    TCH0L
       bra    go1
minimo:
       decx
go1:
       stx    desplazador
       jsr    retardo_10ms
       jsr    retardo_10ms
       rts

cambiar2:
       ldx    desplazador
       decx
       lda    tabla,x
       cbeq   compa2,maximo
       sta    TCH0L
       bra    go2
maximo:
       incx
go2:
       stx    desplazador
       jsr    retardo_10ms
       jsr    retardo_10ms
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
;			RUTINAS DE INTERUPCION
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
        brclr    fila0,PORTA,adelante
        brclr    fila1,PORTA,adelante2
        bset       ackk,kbscr
        rti
adelante:
       lda     #%00000001
       cbeq    Detector,tecla2
       lda     #%00000010
       cbeq    Detector,tecla4
       lda     #%00000011
       cbeq    Detector,tecla6
       lda     #%00000100
       cbeq    Detector,tecla8
       bset       ackk,kbscr
       rti

Tecla2:
       jsr      cambiar1
       bclr   com_sal1,PORTB            ;Mando el codigo 2(0010)
       bset   com_sal2,PORTB
       bclr   com_sal3,PORTB
       bclr   com_sal4,PORTB
       jsr    retardo_1ms
       bclr   com_sal1,PORTB
       bclr   com_sal2,PORTB
       bclr   com_sal3,PORTB
       bclr   com_sal4,PORTB
       bset       ackk,kbscr
       rti

Tecla4:
       bclr   com_sal1,PORTB            ;Mando el codigo 4(0100)
       bclr   com_sal2,PORTB
       bset   com_sal3,PORTB
       bclr   com_sal4,PORTB
       jsr    retardo_1ms
       bclr   com_sal1,PORTB
       bclr   com_sal2,PORTB
       bclr   com_sal3,PORTB
       bclr   com_sal4,PORTB
       bset       ackk,kbscr
       rti
Tecla6:
       bclr   com_sal1,PORTB            ;Mando el codigo 6(0110)
       bset   com_sal2,PORTB
       bset   com_sal3,PORTB
       bclr   com_sal4,PORTB
       jsr    retardo_1ms
       bclr   com_sal1,PORTB
       bclr   com_sal2,PORTB
       bclr   com_sal3,PORTB
       bclr   com_sal4,PORTB
       bset       ackk,kbscr
       rti
Tecla8:
       bclr   com_sal1,PORTB            ;Mando el codigo 8(1000)
       bclr   com_sal2,PORTB
       bclr   com_sal3,PORTB
       bset   com_sal4,PORTB
       jsr    retardo_1ms
       bclr   com_sal1,PORTB
       bclr   com_sal2,PORTB
       bclr   com_sal3,PORTB
       bclr   com_sal4,PORTB
       bset       ackk,kbscr
       rti
Adelante2:
       lda     #%00000001
       cbeq    Detector,tecla1
       lda     #%00000010
       cbeq    Detector,tecla3
       lda     #%00000011
       cbeq    Detector,tecla5
       lda     #%00000100
       cbeq    Detector,tecla7
       bset       ackk,kbscr
       rti


Tecla1:
       jsr    cambiar2
       bset   com_sal1,PORTB            ;Mando el codigo 1(0001)
       bclr   com_sal2,PORTB
       bclr   com_sal3,PORTB
       bclr   com_sal4,PORTB
       jsr    retardo_1ms
       bclr   com_sal1,PORTB
       bclr   com_sal2,PORTB
       bclr   com_sal3,PORTB
       bclr   com_sal4,PORTB
       bset       ackk,kbscr
       rti
Tecla3:
       bset   com_sal1,PORTB            ;Mando el codigo 3(0011)
       bset   com_sal2,PORTB
       bclr   com_sal3,PORTB
       bclr   com_sal4,PORTB
       jsr    retardo_1ms
       bclr   com_sal1,PORTB
       bclr   com_sal2,PORTB
       bclr   com_sal3,PORTB
       bclr   com_sal4,PORTB
       bset       ackk,kbscr
       rti
Tecla5:
       bset   com_sal1,PORTB            ;Mando el codigo (0101)
       bclr   com_sal2,PORTB
       bset   com_sal3,PORTB
       bclr   com_sal4,PORTB
       jsr    retardo_1ms
       bclr   com_sal1,PORTB
       bclr   com_sal2,PORTB
       bclr   com_sal3,PORTB
       bclr   com_sal4,PORTB
       bset       ackk,kbscr
       rti
Tecla7:
       bset   com_sal1,PORTB            ;Mando el codigo (0111)
       bset   com_sal2,PORTB
       bset   com_sal3,PORTB
       bclr   com_sal4,PORTB
       jsr    retardo_1ms
       bclr   com_sal1,PORTB
       bclr   com_sal2,PORTB
       bclr   com_sal3,PORTB
       bclr   com_sal4,PORTB
       bset       ackk,kbscr
       rti



;******************************************************************************
; TIM1_OV_ISR - Rutina de Interrupcion por Overflow del Timer 1
;******************************************************************************
tim1_ov_isr:

        brclr    columna0,PORTA,cambio
        brclr    columna1,PORTB,cambio1
        brclr    Columna2,PORTA,cambio2
        brclr    Columna3,PORTA,cambio3

        bclr    columna0,PORTA            ;mando (1110)
        bset    columna1,PORTB
        bset    columna2,PORTA
        bset    columna3,PORTA
        mov     #%00000001,Detector       ;(tecla 1 o 2 )
        bra     fin
cambio3:
        bset    columna0,PORTA            ;mando (1111)
        bset    columna1,PORTB
        bset    columna2,PORTA
        bset    columna3,PORTA
        bra fin
cambio:
        bset   columna0,PORTA             ;mando  (1101)
        bclr   columna1,PORTB
        bset   columna2,PORTA
        bset   columna3,PORTA
        mov     #%00000010,Detector       ;(tecla 3 o 4)
        bra     fin

cambio1:
        bset   columna0,PORTA             ;mando  (1011)
        bset   columna1,PORTB
        bclr   columna2,PORTA
        bset   columna3,PORTA             ;(tecla 5 o 6)
        mov     #%00000011,Detector
        bra     fin

cambio2:
        bset   columna0,PORTA             ;mando (0111)
        bset   columna1,PORTB
        bset   columna2,PORTA
        bclr   columna3,PORTA
        mov     #%00000100,Detector       ;(tecla 7 o 8)
        bra     fin
fin:
        bclr    7,tsc
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

        bclr          7,TSC0
        nop
	rti				;

;******************************************************************************
; IRQ_ISR - Rutina de Interrupcion Externa
;******************************************************************************
irq_isr:
        nop
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
