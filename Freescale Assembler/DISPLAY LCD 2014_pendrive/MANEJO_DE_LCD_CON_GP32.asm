$INCLUDE 'C:\pemicro\ics08gpgtz\GPGTREGS.INC'        ;definición de Registros de la CPU

FLASH_INIT      EQU     $8000   ;inicio de EEPROM para gp32 y $E000 para jk3
RAM_INIT        EQU     $0040   ;Inicio de RAM
RESET_VECTOR    EQU     $FFFE   ;Vector de Reset
MENSAJE         EQU     $FDED   ;ACA SE GUARDA EL MENSAJE (PRIMERA LINEA DEL LCD)
FDM             EQU     $80
K               EQU     100T
K2              EQU     4T      ; RETARDO DE 3mS
K2A             EQU     227T    ; RETARDO DE 3mS
ENABLE          EQU     5
RS              EQU     0
COPD            EQU     0


**************************************************************************
***************inicializacion del programa********************************
**************************************************************************
           ORG  RAM_INIT

RESULTADO  DS        1

           ORG  FLASH_INIT

INICIO:
       RSP
       BSET     0,CONFIG1
       CLRA
       CLR      RESULTADO
       CLRH
       CLRX
       MOV      #%01000000,ADCLK   ;se escoge el bus externo para el relog de ADC
                                   ;y se divide por 4
       MOV      #$FF,DDRB
       MOV      #$FF,DDRA
       MOV      #$FF,DDRD
       MOV      #$FF,DDRC
       CLR      PTC
       CLR      PTB
       JSR      DELAY

*********************************************************
*Rutina de inicio,demora para el display de unos 64 mseg*
*********************************************************
LCD:
                               ;bits d4 RS(0 contr. 1 dato) y d5 Habil.por 1
     BCLR       ENABLE,PORTD   ;lcd deshabilitado (ya realizado)
     JSR        DELAY          ;llamado a subrutina de retardo de aprox 64 ms
     JSR        DELAY
     JSR        DELAY

*******************************************
*Configuracion de inicial del display LCD*
*******************************************

    LDA         #$01       ;borra la pantalla
    JSR         CONTROL
    LDA         #$02       ;vuelve a posicion inicial
    JSR         CONTROL
    LDA         #$38       ;interface de 8 bits,2 lineas,matriz de 7x5
    JSR         CONTROL
    LDA         #$06       ;desplazamiento del cursor con cada dato
    JSR         CONTROL
    LDA         #$0F       ;cursor encendido (ON) con parpadeo o "blink"
    JSR         CONTROL

*****************************************
********Visualizacion del mensaje********
*****************************************

      LDA       #$80       ; direcciono primera linea del display
      JSR       CONTROL
      LDHX      #MENSAJE   ;registro indice en direccion del mensaje
MENS: LDA       ,X         ;carga byte del mensaje ASCII
      CMP       #FDM       ;verifica fin de caracteres
      BEQ       FIN        ;ultimo caracter?
      JSR       DATA
      AIX       #1         ;Incrementa indice
      BRA       MENS
FIN:  LDA       #$0C       ;DESAPARECE EL CURSOR (INVENCIBLE Y NO PARPADEA)
      JSR       CONTROL
      BSET      4,PTC
      WAIT


******************************
*Subrutina de control del LCD*
******************************

CONTROL: NOP
         STA    PORTA        ;pongo palabra de control en el puerto b
         NOP
         BCLR   RS,PORTD     ;indico que es un comando de control RS (control) = 0
         NOP
         BSET   ENABLE,PORTD ;habilitacion LCD  E (pulso a 1 para habilitacion)
         NOP
         BCLR   ENABLE,PORTD ;deshabilitacion LCD
         NOP
         BSR    DELAY
         RTS

********************************
*Subrutina de datos para el LCD*
********************************

DATA:  NOP
       STA      PORTA        ;datos en el puerto b
       NOP
       BSET     RS,PORTD     ;es un dato, RS = 1 (dato)
       NOP
       BSET     ENABLE,PORTD ;habilitacion LCD E (pulso a 1 para habilitacion)
       NOP
       BCLR     ENABLE,PORTD ;deshabilitacion LCD
       NOP
       RTS

**************************************
*retardo aproximado a 3 milisegundos*
**************************************
DELAY: NOP
       PSHX                   ;salvo registros
       PSHA
       LDA   #K2
       LDX   #K2A
LOOP:  DBNZX *
       DBNZA LOOP
       LDA   #K
       DBNZA *
       PULA                  ;restauro registros
       PULX
       RTS

       ORG   MENSAJE
       DB    "CONTADOR DE 0_99" ;defino cadena de caracteres
       DB    FDM              ;a escribir en el LCD

***************************************************************************
;*              definicion de vectores                                    *
;**************************************************************************

       ORG      RESET_VECTOR
       DW       INICIO
