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
desplazador2    ds              1
comunicacion    ds              1
pw1a            ds              1
pw1b            ds              1
aux1            ds              1
aux2            ds              1
aux1pwm         ds              1
aux2pwm         ds              1
pw2a            ds              1
pw2b            ds              1
compa1          ds              1
compa2          ds              1
automatico1     ds              1


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
	mov	#%01000000,CONFIG2	;Configuracion del registro
;		   \\\\\\\\_____________;RSTEN= 0 Funcion inactiva en pin
;		    \\\\\\\_____________;OSCENINSTOP= 0 Oscilador desab en STOP
;		     \\\\\\_____________;none
;		      \\\\\_____________;none
;		       \\\\_____________;none
;		        \\\_____________;none
;		         \\_____________;IRQEN= 1 IRQ Habilitado
;		          \_____________;IRQPUD= 0 Pull Up Conectada


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
; 	DEFINICION DE LOS PINES DE ENTRADA/SALIDA DEL EQUIPO Micro 2
;******************************************************************************
;---------------------- Puerto A
motor1		equ	0		;salida,motor 1 manejado por PWM del canal timmer
motor2		equ	1		;salida,motor 2 manejado por PWM del Puerto A
entIRQ		equ	2		;enrada,IRQ
indef1         	equ	3		;indefinido
indef2		equ	4		;indefinido
indef3		equ	5		;indefinido
nousado0	equ	6		;no se usa
nousado1	equ	7		;no se usa

;---------------------- Puerto B
com_ent1	equ	0		;entrada,comunicacion con otro micro
com_ent2	equ	1		;entrada,comunicacion con otro micro
motor3		equ	2		;salida,motor 3 manejado por PWM del Puerto B
motor4		equ	3		;salida,motor 4 manejado por PWM del Puerto B
com_sal5	equ	4		;Salida,comunicacion con otro micro
indef4		equ	5		;salida,todavia nose
com_ent3	equ	6		;entrada,comunicacion con otro micro
com_ent4	equ	7		;entrada,comunicacion con otro micro

;******************************************************************************
; 			PROGRAMO LOS PUERTOS DE ENTRADA Y SALIDA
;******************************************************************************

        mov     #%10111011,PORTA
        mov     #%10111011,DDRA		        ;Configuracion de entradas y salidas Puerto B
        mov     #%01000100,PTBPUE               ;Activo resistencia PULLUP a las Entradas
        mov     #%00000000,PORTA		;Valores por Defecto

        mov     #%00111100,PORTB
        mov     #%00111100,DDRB		        ;Configuracion de entradas y salidas PUERTO B
        mov     #%11000011,PTBPUE		;Activo resistencia PULL-UP a las Entradas
        mov     #%00000000,PORTB                ;Valores por Defecto

;******************************************************************************
; 			PROGRAMO INTERRUPCION EXTERNA IRQ
;******************************************************************************

        bclr    imask,INTSCR         ;habilita interrupcion IRQ
        bclr    mode,INTSCR          ;IRQ por flanco descendente

;******************************************************************************
; 		PROGRAMO EL PWM POR EL CANAL 0 DEL TIMMER MICRO 2
;******************************************************************************

        mov	#$36,TSC
	mov	#$03,TMODH
	mov	#$E8,TMODL		;Configuro el PWM para tener un periodo de 20mS
	mov	#$00,TCH0H
	mov	#120t,TCH0L              ;configuro p/ que comienze con un ancho de 0,5ms
	mov	#%01101010,TSC0         ;Configuro registro TSC0
	mov	#$06,TSC		;El Timmer queda en STOP, porque no uso el desbordamiento
	nop
	nop

;******************************************************************************

         cli            ;habilito interrupciones

;******************************************************************************
; 			PROGRAMA PRINCIPAL
;******************************************************************************

          Clr      RETARDO1
          Clr      RETARDO2
          Clr      CONT0
          Clr      aumento1
          clr      desplazador
          clr      desplazador2
          mov      #3t,pw1a
          mov      #3t,pw1b
          mov      #15t,desplazador
          clr      aux1
          clr      aux2
          clr      aux1pwm
          clr      aux2pwm
          mov      #10t,compa1
          mov      #135t,compa2
          bclr    com_sal5,PORTB
          clrx
;---------------------- inicializo motor 2------------
 	mov     #$2A,CONT0
salida_2a:
	dec     CONT0
	bset	motor2,PORTA
	jsr	retardo_05ms
        jsr     retardo_02ms
	bclr	motor2,PORTA
	jsr	retardo_10ms
	jsr	retardo_05ms
	jsr	retardo_1ms
	jsr	retardo_2ms
	jsr	retardo_5ms
	clra
    	cbeq    CONT0,seguir_2a
	bra	salida_2a
seguir_2a:
        jsr     retardo_100ms
;---------------------- inicializo motor 3------------
 	mov     #$2A,CONT0
salida_2b:
	dec     CONT0
	bset	motor3,PORTB
	jsr	retardo_05ms
        jsr	retardo_01ms
       jsr	retardo_01ms
        jsr	retardo_02ms
	bclr	motor3,PORTB
	jsr	retardo_10ms
	jsr	retardo_05ms
	jsr	retardo_1ms
	jsr	retardo_2ms
	jsr	retardo_5ms
	clra
    	cbeq    CONT0,seguir_2b
	bra	salida_2b
seguir_2b:
        jsr     retardo_100ms
;---------------------------------------------

start_00:



         jsr    codigo
         bra    start_00

codigo:
         brset    0,PORTB,Sigamos1
         brset    1,PORTB,Sigamos2
         brset    6,PORTB,Sigamos3
         brset    7,PORTB,ocho             ;ocho (1000)
         bra    cero                       ;cero(0000)
Sigamos1:
         brset    1,PORTB,Sigamos4
         brset    6,PORTB,Sigamos5
         brset    7,PORTB,nueve       ;nueve(1001)
         bra    uno                   ;uno(0001)

Sigamos2:
         brset  6,PORTB,Sigamos7
         brset  7,PORTB,diez           ;diez(1010)
         bra    dos                    ;dos(0010)

Sigamos3:
         brset  7,PORTB,doce            ;doce (1100)
         bra    cuatro                  ;cuatro(0100)
Sigamos4:
         brset  6,PORTB,sigamos6
         brset  7,PORTB,once             ;once(1011)
         bra    tres                     ;tres (0011)
Sigamos5:
         brset  7,PORTB,trece          ;trece(1101)
         bra    cinco                  ;cinco(0101)

Sigamos6:
         brset  7,PORTB,quince          ;quince(1111)
         bra    siete                   ;siete (0111)
Sigamos7:
         brset    7,PORTB,catorce        ;catorce(1110)
         bra    seis                     ;seis(0110)
salir
         rts
 ;---------------------------------------------------------------
cero:
         jsr     scero
         rts
uno:
        jsr     suno
        rts
dos:
        jsr     sdos
        rts
tres:
        jsr     stres
        rts
cuatro:
        jsr     scuatro
        rts
cinco:
        jsr     scinco
        rts
seis:
        jsr     sseis
        rts
siete:
        jsr     ssiete
        rts
ocho:
        jsr     socho
        rts
nueve:
        jsr     snueve
        rts
diez:
        jsr     sdiez
        rts
once:
        jsr     sonce
        rts
doce:
        jsr     sdoce
        rts
trece:
        jsr     strece
        rts
catorce:
        jsr     scatorce
        rts
quince:
        jsr     squince
        rts
;******************************************************************************
; 			SUBRUTINAS DE CODIGOS
;******************************************************************************
;******************************************************************************
; 			CODIGO (0000)
;******************************************************************************
scero:
        nop
        nop
        rts
;******************************************************************************
; 			CODIGO 1 (0001) - TECLA 1
;******************************************************************************

suno:
         nop
         rts
;******************************************************************************
; 			CODIGO 2 (0002) - TECLA 2
;******************************************************************************

sdos:
         nop
         rts
;******************************************************************************
; CODIGO 3 (0011) - TECLA 3 - AVANCE DEL MOTOR 1 (PWM DEL CANAL 0 DEL TIMMER)
;******************************************************************************
stres:
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
;******************************************************************************
; CODIGO 4 (0100) - TECLA 4 - RETROCESO DEL MOTOR 1 (PWM DEL CANAL 0 DEL TIMMER)
;******************************************************************************
scuatro:
         ldx    desplazador      ;retroceso motor 1 pwm timer micro 2
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
; CODIGO 5 (0101) - TECLA 5 - AVANCE DEL MOTOR 2 (PWM CON PUERTO A)
;******************************************************************************
scinco:
         clr    CONT0
         clr    aux1
         mov    #3t,CONT0
         mov    pw1a,aux1
bucle_3_5:
        jsr     retardo_10ms
        jsr	retardo_02ms
	jsr	retardo_02ms
	jsr	retardo_02ms
        bset    motor2,PORTA
        jsr     tiemp_var1
        bclr    motor2,PORTA
        dec     CONT0
        clra
        cbeq   CONT0,salida_3_5
        bra    bucle_3_5
salida_3_5:
        mov       aux1,pw1a
        dec       pw1a
        clr       aux1
        nop
        rts

;******************************************************************************
; CODIGO 6 (0110) - TECLA 6 - RETROCESO DEL MOTOR 2 (PWM CON PUERTO A)
;******************************************************************************
sseis:
        clr    CONT0
        clr    aux1
        mov    #3t,CONT0
        mov    pw1a,aux1
bucle_3_6:
        jsr     retardo_10ms
        jsr	retardo_1ms
	jsr	retardo_1ms
	jsr	retardo_1ms
	jsr	retardo_1ms
	jsr	retardo_1ms
	jsr	retardo_1ms
        jsr	retardo_1ms
        bset    motor2,PORTA
        jsr     tiemp_var1
        bclr    motor2,PORTA
        dec     CONT0
        clra
        cbeq    CONT0,salida_3_6
        bra     bucle_3_6
salida_3_6:
        mov       aux1,pw1a
        inc       pw1a
        clr       aux1
        nop
        rts


;******************************************************************************
; CODIGO 7 (0111) - TECLA 7 - AVANCE DEL MOTOR 3 (PWM CON PUERTO B)
;******************************************************************************
ssiete:
        clr    CONT0
        clr    aux2
        mov    #3t,CONT0
        mov    pw1b,aux2
bucle_3_7:
        jsr     retardo_10ms
        jsr	retardo_1ms
	jsr	retardo_1ms
	jsr	retardo_1ms
	jsr	retardo_1ms
	jsr	retardo_1ms
	jsr	retardo_1ms
        jsr	retardo_1ms
        bset    motor3,PORTB
        jsr     tiemp_var2
        bclr    motor3,PORTB
        dec     CONT0
        clra
        cbeq   CONT0,salida_3_7
        bra    bucle_3_7
salida_3_7:
        mov       aux2,pw1b
        dec       pw1b
        clr       aux2
        rts
;******************************************************************************
; CODIGO 8 (1000) - TECLA 8 - RETROCESO DEL MOTOR 3 (PWM CON PUERTO B)
;******************************************************************************
socho:
        clr     CONT0
        clr     aux2
        mov     #3t,CONT0
        mov     pw1b,aux2
bucle_3_8:
        jsr     retardo_10ms
        jsr	retardo_1ms
	jsr	retardo_1ms
	jsr	retardo_1ms
	jsr	retardo_1ms
	jsr	retardo_1ms
	jsr	retardo_1ms
  	jsr	retardo_1ms
        bset    motor3,PORTB
        jsr     tiemp_var2
        bclr    motor3,PORTB
        dec     CONT0
        clra
        cbeq    CONT0,salida_3_8
        bra     bucle_3_8
salida_3_8:
        mov       aux2,pw1b
        inc       pw1b
        clr       aux2
        rts
;******************************************************************************
; DEMAS CODIGOS NO USADOS
;******************************************************************************
snueve:
sdiez:
sonce:
sdoce:
strece:
scatorce:
squince:

rts
;******************************************************************************
; Tiempo variable 1
;******************************************************************************
tiemp_var1:
        mov     pw1a,aux1pwm
bucle_2_v1:
        clr     pw2a
	mov     #22t,pw2a	      ;[4]
bucle_1_v1:
	dec	pw2a        	      ;[4]
	clra			      ;[1]
    	cbeq    pw2a,salida_1_v1      ;[5]4+4+[((4+1+5+3)x22)+4+4+1+5+3)x001]
	bra	bucle_1_v1	      ;[3](((13)x244)+17)x001)+8+3=3200c
salida_1_v1:			      ;     3200 x 312,5nseg = 1.000.000ns
	dec	pw1a	              ;[4]  1ms
	clra		              ;[1]
   	cbeq    pw1a,salida_2_v1      ;[5]
	bra	bucle_2_v1	      ;[3]
salida_2_v1:
	nop
        nop
        nop
        nop
        mov     aux1pwm,pw1a
        rts
;******************************************************************************
; Tiempo variable 2
;******************************************************************************
tiemp_var2:
        mov     pw1b,aux2pwm
bucle_2_v2:
        clr     pw2b
	mov     #22t,pw2b	      ;[4]
bucle_1_v2:
	dec	pw2b        	      ;[4]
	clra			      ;[1]
    	cbeq    pw2b,salida_1_v2	      ;[5]4+4+[((4+1+5+3)x22)+4+4+1+5+3)x001]
	bra	bucle_1_v2	      ;[3](((13)x244)+17)x001)+8+3=3200c
salida_1_v2:			      ;     3200 x 312,5nseg = 1.000.000ns
	dec	pw1b	              ;[4]  1ms
	clra		              ;[1]
   	cbeq    pw1b,salida_2_v2	      ;[5]
	bra	bucle_2_v2	      ;[3]
salida_2_v2:
	nop
        nop
        nop
        nop
        mov     aux2pwm,pw1b
        rts

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
retardo_5ms:
	jsr	retardo_1ms
	jsr	retardo_1ms
	jsr	retardo_1ms
retardo_2ms:
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

        bclr          7,TSC0
        nop
	rti				;

;******************************************************************************
; IRQ_ISR - Rutina de Interrupcion Externa
;******************************************************************************
irq_isr:
        bset    com_sal5,PORTB
        mov	#120t,TCH0L
        jsr	retardo_10ms
        mov     #$2A,CONT0
salida_movini:
	dec     CONT0
	bset	motor4,PORTB
	jsr	retardo_1ms
	bclr	motor4,PORTB
	jsr	retardo_10ms
	jsr	retardo_05ms
	jsr	retardo_1ms
	jsr	retardo_2ms
	jsr	retardo_5ms
	clra
    	cbeq    CONT0,seguir_movini
	bra	salida_movini
seguir_movini:
        jsr     retardo_100ms
        mov     #$2A,CONT0
salida_2airq:
	dec     CONT0
	bset	motor2,PORTA
	jsr	retardo_05ms
        jsr     retardo_02ms
	bclr	motor2,PORTA
	jsr	retardo_10ms
	jsr	retardo_05ms
	jsr	retardo_1ms
	jsr	retardo_2ms
	jsr	retardo_5ms
	clra
    	cbeq    CONT0,seguir_2airq
	bra	salida_2airq
seguir_2airq:
        jsr     retardo_100ms
;---------------------- inicializo motor 3------------
 	mov     #$3A,CONT0
salida_2birq:
	dec     CONT0
	bset	motor3,PORTB
	jsr	retardo_05ms
        jsr	retardo_01ms
       jsr	retardo_01ms
        jsr	retardo_02ms
	bclr	motor3,PORTB
	jsr	retardo_10ms
	jsr	retardo_05ms
	jsr	retardo_1ms
	jsr	retardo_2ms
	jsr	retardo_5ms
	clra
    	cbeq    CONT0,seguir_2birq
	bra	salida_2birq
seguir_2birq:
        jsr     retardo_100ms
        bclr    com_sal5,PORTB
 ;--------------------------------------------------
        mov     #$3A,CONT0
salida_mov1:
	dec     CONT0
	bset	motor3,PORTB
        jsr	retardo_01ms
        jsr	retardo_01ms
        jsr	retardo_02ms
	bclr	motor3,PORTB
	jsr	retardo_10ms
	jsr	retardo_05ms
	jsr	retardo_1ms
	jsr	retardo_2ms
	jsr	retardo_5ms
	clra
    	cbeq    CONT0,seguir_mov1
	bra	salida_mov1
seguir_mov1:
        jsr     retardo_100ms
        jsr     retardo_100ms
        jsr	retardo_05ms
 ;----------------------------------------------------
        mov	#70t,TCH0L
        jsr     retardo_100ms
        jsr     retardo_100ms
        jsr     retardo_100ms
  ;--------------------------------------------------
 	mov     #$0A,CONT0
salida_mov2:
	dec     CONT0
	bset	motor2,PORTA
	jsr	retardo_1ms
       	jsr	retardo_05ms
	bclr	motor2,PORTA
	jsr	retardo_10ms
	jsr	retardo_05ms
	jsr	retardo_1ms
	jsr	retardo_2ms
	jsr	retardo_5ms
	clra
    	cbeq    CONT0,seguir_mov2
	bra	salida_mov2
seguir_mov2:
        jsr     retardo_100ms
     ;-----------------------------------------
     mov     #$0A,CONT0
salida_mov2_1:
	dec     CONT0
	bset	motor4,PORTB
	jsr	retardo_1ms
       	jsr	retardo_02ms
	bclr	motor4,PORTB
	jsr	retardo_10ms
	jsr	retardo_05ms
	jsr	retardo_1ms
	jsr	retardo_2ms
	jsr	retardo_5ms
	clra
    	cbeq    CONT0,seguir_mov2_1
	bra	salida_mov2_1
seguir_mov2_1:
        jsr     retardo_1s
  ;--------------------------------------------------
       mov     #$0A,CONT0
salida_mov2_2:
	dec     CONT0
	bset	motor4,PORTB
	jsr	retardo_05ms
        jsr	retardo_02ms
        jsr	retardo_01ms
	bclr	motor4,PORTB
	jsr	retardo_10ms
	jsr	retardo_05ms
	jsr	retardo_1ms
	jsr	retardo_2ms
	jsr	retardo_5ms
	clra
    	cbeq    CONT0,seguir_mov2_2
	bra	salida_mov2_2
seguir_mov2_2:
        jsr     retardo_100ms
        jsr     retardo_100ms
        jsr     retardo_100ms
        jsr     retardo_100ms
  ;--------------------------------------------------
     	mov     #$3A,CONT0
salida_mov3:
	dec     CONT0
	bset	motor3,PORTB
        jsr	retardo_05ms
        jsr	retardo_2ms
	bclr	motor3,PORTB
	jsr	retardo_10ms
	jsr	retardo_05ms
	jsr	retardo_1ms
	jsr	retardo_2ms
	jsr	retardo_5ms
	clra
    	cbeq    CONT0,seguir_mov3
	bra	salida_mov3
seguir_mov3:
        jsr     retardo_1ms
        mov     #$0A,CONT0
salida_mov4:
	dec     CONT0
	bset	motor2,PORTA
 	jsr	retardo_1ms
	bclr	motor2,PORTA
	jsr	retardo_10ms
	jsr	retardo_05ms
	jsr	retardo_1ms
	jsr	retardo_2ms
	jsr	retardo_5ms
	clra
    	cbeq    CONT0,seguir_mov4
	bra	salida_mov4
seguir_mov4:
        mov	#80t,TCH0L
        jsr     retardo_100ms
        mov     #$0A,CONT0
salida_mov5:
	dec     CONT0
	bset	motor2,PORTA
        jsr	retardo_05ms
	jsr	retardo_01ms
	jsr	retardo_02ms
	bclr	motor2,PORTA
	jsr	retardo_10ms
	jsr	retardo_05ms
	jsr	retardo_1ms
	jsr	retardo_2ms
	jsr	retardo_5ms
	clra
    	cbeq    CONT0,seguir_mov5
	bra	salida_mov5
seguir_mov5:
        jsr     retardo_100ms
        mov	#90t,TCH0L
        jsr     retardo_100ms
        mov	#100t,TCH0L
        jsr     retardo_100ms
        mov	#120t,TCH0L
        jsr     retardo_100ms
        jsr     retardo_100ms
        jsr     retardo_100ms
        jsr     retardo_100ms
        jsr     retardo_100ms
        jsr     retardo_100ms
        jsr     retardo_100ms
         mov     #$3A,CONT0
salida_mov6:
	dec     CONT0
	bset	motor2,PORTA
	jsr	retardo_1ms
        jsr	retardo_1ms
	jsr	retardo_05ms
        jsr	retardo_02ms
	bclr	motor2,PORTA
	jsr	retardo_10ms
	jsr	retardo_05ms
	jsr	retardo_1ms
	jsr	retardo_2ms
	jsr	retardo_5ms
	clra
    	cbeq    CONT0,seguir_mov6
	bra	salida_mov6
seguir_mov6:
        jsr     retardo_100ms


        bset            ackk,intscr
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
