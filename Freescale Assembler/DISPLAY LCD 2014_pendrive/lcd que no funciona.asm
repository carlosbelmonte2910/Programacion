*********************************************************************************
* Definicion del mapa de Memoria del 68HC908QY4 (68HC908QT1-2/QY1-2)            *
*********************************************************************************

RAM_START       EQU     $0080           ;128 Bytes
ROM_START       EQU     $EE00           ;1,5KBytes, Debería ser $F800 para el QY1
VECTORES        EQU     $FFDE           ;Comienzo de la Tabla de Vectores

E               EQU     0
RS              EQU     4
RW              EQU     5

*********************************************************************************
* Definicion de las variables de RAM                                            *
*********************************************************************************

        org     RAM_START

CONT            rmb     1       ;Variable Contador (1 BYTE DE MEMORIA. UBICADO EN LA POSICION $0080.)
CONT1           rmb     1       ;VARIABLE CONTADOR (1 BYTE DE MEMORIA. UBICADO EN LA POSICION $0081.)
MAX             rmb     1       ;VARIABLE CONTADOR (1 BYTE DE MEMORIA. UBICADO EN LA POSICION $0082.)
CARACTER        rmb     1       ;VARIABLE CARACTER (1 BYTE DE MEMORIA. UBICADO EN LA POSICION $0083.)

*********************************************************************************
* PROGRAMA PRINCIPAL - En este punto arranca el micro luego del Reset           *
*********************************************************************************

$base    10t                            ;Base decimal por Default
$Include        'QTQY_Registers.inc'    ;Definiciones de Reg. para QT, QY


        org     ROM_START

start:
        rsp                             ;Reset del stack pointer
        clra                            ;Limpio registros
        clrh
        clrx
        cli                             ;Borro Bit I (habilita interrupciones)

;------ PROGRAMACION DE LOS DISTINTOS MODULOS (HC08) ----------------------------

;------ Programo el CONFIG ------------------------------------------------------
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
                                        ;b0=0 Funcion Pin RST (Reset) inactiva
        nop                             ;Las inst. NOP hacen de Delay para
        nop                             ;  asegurar la configuracion

;------ Programo el Puerto a ----------------------------------------------------

        mov     #%00110001,ddra         ;Programo Pta0, 4, 5 como salida

;------ Programo el Puerto b ----------------------------------------------------

        mov     #%11111111,ddrb         ;Programo Puerto B como Salida
        mov     #%00000000,portb
;--------------------------------------------------------------------------------

        clr MAX
        mov #$FF,MAX

        clr CONT
        mov MAX,CONT

        clr CONT1
        mov #$10,CONT1

;---------------- Programa ------------------------------------------------------

        jsr InitLCD

        mov 'H',CARACTER
        jsr Mandar
        mov 'O',CARACTER
        jsr Mandar
        mov 'L',CARACTER
        jsr Mandar
        mov 'A',CARACTER
        jsr Mandar

Lazo:

        bra Lazo

;---------------- Subrutina de Inicializacion del LCD ---------------------------

InitLCD:

        jsr Ret                         ;Demora de 15 mseg o mas

        bclr E,Porta
        bclr RS,Porta
        bclr RW,Porta

        mov #$38,Portb                  ;Function Set

        bset E,Porta

        mov #$54,MAX                    ;Para producir un retardo de aprox 5 mseg
        jsr Ret                         ;Demora de 5 mseg

        bclr E,Porta
        bclr RS,Porta
        bclr RW,Porta

        mov #$38,Portb                  ;Function Set

        bset E,Porta

        mov #$02,MAX                    ;Para producir un retardo de aprox 100 useg
        jsr Ret                         ;Demora de 100 useg o mas

        bclr E,Porta
        bclr RS,Porta
        bclr RW,Porta

        mov #$38,Portb                  ;Function Set

        bset E,Porta

        mov #$54,MAX                    ;Para producir un retardo de aprox 5 mseg
        jsr Ret                         ;Demora de 5 mseg

        bclr E,Porta
        bclr RS,Porta
        bclr RW,Porta

        mov #$38,Portb                  ;Function Set

        bset E,Porta

        mov #$01,MAX                    ;Para producir un retardo de aprox 40 useg
        jsr Ret                         ;Demora de 40 useg o mas

        bclr E,Porta
        bclr RS,Porta
        bclr RW,Porta

        mov #$38,Portb                  ;Function Set

        bset E,Porta

        mov #$01,MAX                    ;Para producir un retardo de aprox 40 useg
        jsr Ret                         ;Demora de 40 useg o mas

        bclr E,Porta
        bclr RS,Porta
        bclr RW,Porta

        mov #$08,Portb                  ;Display OF. Apagar pantalla,
                                        ;quitar cursor
        bset E,Porta

        mov #$01,MAX                    ;Para producir un retardo de aprox 40 useg
        jsr Ret                         ;Demora de 40 useg o mas

        bclr E,Porta
        bclr RS,Porta
        bclr RW,Porta

        mov #$01,Portb                  ;Display Clear

        bset E,Porta

        mov #$22,MAX                    ;Para producir un retardo de aprox 2 mseg
        jsr Ret                         ;Demora de 2 mseg

        bclr E,Porta
        bclr RS,Porta
        bclr RW,Porta

        mov #$06,Portb                  ;Entry Mode Set

        bset E,Porta

        mov #$01,MAX                    ;Para producir un retardo de aprox 40 useg
        jsr Ret                         ;Demora de 40 useg o mas

        rts

;----------------------- Subrutina para el envio de un caracter al LCD ---------

Mandar:

        lda CARACTER
        bclr E,Porta
        bset RS,Porta
        bclr RW,Porta
        sta Portb
        bset E,Porta
        mov #$02,MAX                    ;Para producir un retardo de aprox 100 useg
        jsr Ret                         ;Demora de aprox 100 useg

        rts

;----------------------- Subrutina de Retardo ----------------------------------

Ret:

        dec CONT        ;4

Ret1:
        nop
        dec CONT1       ;4
        lda CONT1       ;2
        cmp #$00        ;2
        bne Ret1        ;3
        mov #$10,CONT1  ;4
        lda CONT        ;2
        cmp #$00        ;2
        bne Ret         ;3
        mov MAX,CONT    ;4

        rts             ;4

*********************************************************************************
* ADC_ISR - Rutina de Servicio de Conversion Analogico Digital Completada       *
*                                                                               *
*********************************************************************************
adc_isr:
        nop
        rti                     ;retorna

*********************************************************************************
* KEYB_ISR - Keyboard Interrupt Service Routine                                 *
*********************************************************************************
keyb_isr:

        nop

        rti                     ;retorna

*********************************************************************************
* TIM_OV_ISR - Rutina de Servicio de Interrupcion por Overflow del Timer        *
* Es llamada cuando existe un Overflow en el Modulo Contador del Timer, es usada*
* como base de tiempos para la visualizacion en display                         *
*********************************************************************************
tim_ov_isr:

        nop

        rti                             ;retorna

*********************************************************************************
swi_isr:


rti

*********************************************************************************
* TIM_0_ISR - Rutina de Servicio de Interrupcion del Canal 0 del Timer          *
*********************************************************************************
tim_0_isr:

        nop

        rti                     ;retorna

*********************************************************************************
* TIM_1_ISR - Rutina de Servicio de Interrupcion del Canal 1 del Timer          *
*********************************************************************************
tim_1_isr:
        nop
        rti                     ;retorna
*********************************************************************************
* IRQ_ISR - Interrupt Request Service Routine                                   *
*********************************************************************************
irq_isr:
        nop
        rti                     ;retorna

*********************************************************************************
* DUMMY_ISR - Dummy Interrupt Service Routine                                   *
* Rutina de servicio de Interupcion Fantasma, se pone por razones de seguridad  *
*********************************************************************************
dummy_isr:

        rti                     ; vuelve sin hacer nada

*********************************************************************************
* VECTORES - Definicion de Vectores del Sistema                                 *
*********************************************************************************
        org     VECTORES

        dw      adc_isr         ; ADC Conv.Complete Vector      ($FFDE-$FFDF)
        dw      keyb_isr        ; Keyboard Vector               ($FFE0-$FFE1)
        dw      dummy_isr       ; (No Vector Assigned)          ($FFE2-$FFE3)
        dw      dummy_isr       ; (No Vector Assigned)          ($FFE4-$FFE5)
        dw      dummy_isr       ; (No Vector Assigned)          ($FFE6-$FFE7)
        dw      dummy_isr       ; (No Vector Assigned)          ($FFE8-$FFE9)
        dw      dummy_isr       ; (No Vector Assigned)          ($FFEA-$FFEB)
        dw      dummy_isr       ; (No Vector Assigned)          ($FFEC-$FFED)
        dw      dummy_isr       ; (No Vector Assigned)          ($FFEE-$FFEF)
        dw      dummy_isr       ; (No Vector Assigned)          ($FFF0-$FFF1)
        dw      tim_ov_isr      ; TIM1 Overflow Vector          ($FFF2-$FFF3)
        dw      tim_1_isr       ; TIM1 Channel 1 Vector         ($FFF4-$FFF5)
        dw      tim_0_isr       ; TIM1 Channel 0 Vector         ($FFF6-$FFF7)
        dw      dummy_isr       ; (No Vector Assigned)          ($FFF8-$FFF9)
        dw      irq_isr         ; ~IRQ1                         ($FFFA-$FFFB)
        dw      dummy_isr       ; SWI Vector                    ($FFFC-$FFFD)
        dw      start           ; Reset Vector                  ($FFFE-$FFFF)

*********************************************************************************
