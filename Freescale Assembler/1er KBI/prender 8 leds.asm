*********************************************************************************
*
*
*               PROGRAMA DE PRUEBA Nro 001  -  PARA CURSO HC908
*
*
*
* Programa que maneja Leds a intervalos distintos de Tiempo, implementado en
*
* Microcontroladores MC68HC908QT1/QY4 (MC68HC908QT1)
*
*
*
*********************************************************************************
* Definicion del mapa de Memoria del 68HC908QY4
*
*********************************************************************************

RAM_START       EQU     $0080           ;128 Bytes
ROM_START       EQU     $EE00
; ROM_START      EQU     $F800           ;1,5KBytes, Debería ser $EE00 para el QY4
VECTORES        EQU     $FFDE           ;Comienzo de la Tabla de Vectores
*********************************************************************************



*********************************************************************************
* PROGRAMA PRINCIPAL - En este punto arranca el micro luego del Reset
*
*********************************************************************************
$base    10t                            ;Base decimal por Default
$Include        'QTQY_Registers.inc'    ;Definiciones de Reg. para QT, QY


        org     RAM_START

blink   rmb      $01



        org     ROM_START

start:
        rsp                             ;Reset del stack pointer
        clra                            ;Limpio registros
        clrh
        clrx
        cli                             ;Borro Bit I (habilita interrupciones)

;------ PROGRAMACION DE LOS DISTINTOS MODULOS (HC08) ----------------------------

;------ Programo el CONFIG  -----------------------------------------------------
        mov     #%00001001,config1      ;b7=0 COP Reset cycle (largo)
                                        ;b6=0 LVI deshabilitado en Modo Stop
                                        ;b5=0 Señal Reset desde LVI habilida
                                        ;b4=0 LVI habilitado
                                        ;b3=1 LVI opera en modo 5V
                                        ;b2=0 Recup.M/STOP en 4096 2OSCOUT cycl.
                                        ;b1=0 Instruccion STOP Deshabilitada
                                        ;b0=1 Modulo COP Deshabilitado

        mov     #%00000000,config2      ;b7=0 Pull-Up Interna Conectada (IRQ1)
                                        ;b6=0 Funcion Pin IRQ1 desactivada
                                        ;b4,3=00 selecciona Oscilador Interno
                                        ;b0=0 Funcion Pin RST (Reset)
inactiva
        nop                             ;Las inst. NOP hacen de Delay para
        nop                             ;  asegurar la configuracion

;------ Programo los Puertos ----------------------------------------------------
        mov     #%11111111,ddrb         ; Programo Puerto B como Salida
        mov     #%00001111,portb        ; Est.Inicial: b0=1 Led Rojo Apagado
                                        ; b1=1 Led Verde Apagado
       mov      #%00000000,ptbpue       ;Habilita pullup pines del porta no usados
;------ Programo el Timer -------------------------------------------------------
        mov     #%01110110,tsc          ;Frec=1Hz (3200000/64=50000=$C350)
;       mov     #%01110000,tsc          ;Frec=1Hz (3200000/64=50000=$C350)

                                        ;b7=0 (TOF) Timer no fue reseteado
                                        ;b6=1 (TOE) Habilita interrupción Timer Overflow
                                        ;b5=1 Timer Detenido (Timer stopped)
                                        ;b4=1 Resetea el Contador y el Prescaler
                                       ;b2,1,0=110 Divide Frec Int Bus en 64
        mov     #$C3,tmodh              ;
        mov     #$50,tmodl              ;TMODH:TMODL=C350

         ; mov     #$00,tmodh              ;
         ; mov     #$04,tmodl              ;TMODH:TMODL=0004
        mov     #%01000110,tsc          ;Arranco el timer (b5=0)
                                        ;b4=0 No tiene efecto
                                        
;----------------PROGRAMA EL KBI----------
        mov     #%00000010,kbscr        ; Arranco con el modulo deshabilitado por precaucion
        mov     #%00010000,kbier        ; habilito el bit4 como interrupcion                            
        mov     #%00000000,kbscr        ; inicializo el modulo kbi                                      

;------ Lazo Principal del Programa ---------------------------------------------
main_01:
; bra     main_01
;________________________________________



        bclr   1,portb
        jsr     demora
        jsr     demora
        jsr     demora
        bset   1,portb

        bclr   2,portb
        jsr     demora
        jsr     demora
        jsr     demora
        bset   2,portb

        bclr   3,portb
        jsr     demora
        jsr     demora
        jsr     demora
        bset   3,portb

        bclr   4,portb
        jsr     demora
        jsr     demora
        jsr     demora
        bset   4,portb


        bclr   6,portb
        jsr     demora
        jsr     demora
        jsr     demora
        bset   6,portb

        bclr   7,portb
        jsr     demora
        jsr     demora
        jsr     demora
        jsr     demora
        bset   7,portb


       bra     main_01

*********************************************************************************
* DEMORA - Subrutina de demora para el Blink del Led (aprox150mseg)
*
*********************************************************************************
demora:
         ldx     #$FF            ;[2]
;         ldx     #$02           ;[2]
delay02:
;        lda     #$02           ;[2]
         lda     #$FF            ;[2]
delay01:
         deca                    ;[1]
         cmp     #$00            ;[2]
         bne     delay01         ;[3] ((3x2xff)+1+2+3+2)xff+6=392196d
         decx                    ;[1]
         cpx     #$00            ;[2]
         bne     delay02         ;[3]
         rts                     ;[4]

; -----------------demora _100---------------
demora_100:
           jsr demora   
           jsr demora   
           jsr demora    
           jsr demora   
           jsr demora
           
           rti                  ; retorna       



*********************************************************************************
* ADC_ISR - Rutina de Servicio de Conversion Analogico Digital Completada
*
*********************************************************************************
adc_isr:
        nop
        rti                     ;retorna

*********************************************************************************
* KEYB_ISR - Keyboard Interrupt Service Routine
*
*********************************************************************************
keyb_isr:
         mov #%00011100,portb
         
         jsr demora_100
         
         bset  ackk,KBSCR
         mov #%00010000,KBIER
         bclr  ackk,KBSCR
         bclr  imaskk,KBSCR
         rti
         
        
        

*********************************************************************************
* TIM_OV_ISR - Rutina de Servicio de Interrupcion por Overflow del Timer
*
* Es llamada cuando existe un Overflow en el Modulo Contador del Timer, es usada
* como base de tiempos para la visualizacion en display
*
*********************************************************************************
tim_ov_isr:
        lda blink

enciende:
        brset   0,portb,encender
        bset    0,portb
        
        bra     salida
encender:
         bclr   0,portb
         
salida:
        bclr    tof,tsc
        rti                             ;retorna

*********************************************************************************
swi_isr:

        rti

*********************************************************************************
* TIM_0_ISR - Rutina de Servicio de Interrupcion del Canal 0 del Timer
*
*********************************************************************************
tim_0_isr:
        nop
        rti                     ;retorna

*********************************************************************************
* TIM_1_ISR - Rutina de Servicio de Interrupcion del Canal 1 del Timer
*
*********************************************************************************
tim_1_isr:
        nop
        rti                     ;retorna
*********************************************************************************
* IRQ_ISR - Interrupt Request Service Routine
*
*********************************************************************************
irq_isr:
        nop
        rti                     ;retorna

*********************************************************************************
* DUMMY_ISR - Dummy Interrupt Service Routine
*
* Rutina de servicio de Interupcion Fantasma, se pone por razones de seguridad  *
*********************************************************************************
dummy_isr:

        rti                     ; vuelve sin hacer nada

*********************************************************************************
* VECTORES - Definicion de Vectores del Sistema
*
*********************************************************************************
        org     VECTORES

        dw      adc_isr         ; ADC Conv.Complete Vector ($FFDE-$FFDF)
        dw      keyb_isr        ; Keyboard Vector ($FFE0-$FFE1)
        dw      dummy_isr       ; (No Vector Assigned) ($FFE2-$FFE3)
        dw      dummy_isr       ; (No Vector Assigned) ($FFE4-$FFE5)
        dw      dummy_isr       ; (No Vector Assigned) ($FFE6-$FFE7)
        dw      dummy_isr       ; (No Vector Assigned) ($FFE8-$FFE9)
        dw      dummy_isr       ; (No Vector Assigned) ($FFEA-$FFEB)
        dw      dummy_isr       ; (No Vector Assigned) ($FFEC-$FFED)
        dw      dummy_isr       ; (No Vector Assigned) ($FFEE-$FFEF)
        dw      dummy_isr       ; (No Vector Assigned) ($FFF0-$FFF1)
        dw      tim_ov_isr      ; TIM1 Overflow Vector ($FFF2-$FFF3)
        dw      tim_1_isr       ; TIM1 Channel 1 Vector($FFF4-$FFF5)
        dw      tim_0_isr       ; TIM1 Channel 0 Vector($FFF6-$FFF7)
        dw      dummy_isr       ; (No Vector Assigned) ($FFF8-$FFF9)
        dw      irq_isr         ; ~IRQ1                ($FFFA-$FFFB)
        dw      dummy_isr       ; SWI Vector           ($FFFC-$FFFD)
        dw      start           ; Reset Vector         ($FFFE-$FFFF)

*********************************************************************************
end

