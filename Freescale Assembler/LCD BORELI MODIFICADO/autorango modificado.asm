**************************************************
**    PROGRAMA PARA EL INDUCTOMETRO/CAPACIMETRO **
**************************************************
**                                              **
**    MICROCONTROLADOR MC68HC908QY4A            **
**                                              **
**          ENERO DE 2014                       **
**                                              **
**       RICARDO JAVIER BORELLI                 **
**************************************************
$BASE 10T

RAM_START  EQU  $0080
ROM_START  EQU  $EE00
VECTORS    EQU  $FFDE
PTA        EQU  $0000
PTB        EQU  $0001
DDRA       EQU  $0004
DDRB       EQU  $0005
CONFIG2    EQU  $001E
CONFIG1    EQU  $001F
TOF        EQU   7
TSC        EQU  $0020
TCNTH      EQU  $0021
TCNTL      EQU  $0022
OSCSC      EQU  $0036
E          EQU   0
RWR        EQU   5
RS         EQU   4

*************************************
***********VARIABLES DE RAM**********
           ORG  RAM_START
AUX      RMB   1

COSA     RMB   1


FRECH    RMB   1
FRECL    RMB   1

AUXI     RMB   1
DH       RMB   1
DM       RMB   1
DL       RMB   1
DNDAH    RMB   1
DNDAM    RMB   1
DNDAL    RMB   1
DNDH     RMB   1
DNDM     RMB   1
DNDL     RMB   1
DSRH     RMB   1
DSRM     RMB   1
DSRL     RMB   1
QH       RMB   1
QM       RMB   1
QL       RMB   1
PRODH    RMB   1
PRODMH   RMB   1
PRODML   RMB   1
PRODL    RMB   1
MNDH     RMB   1
MNDL     RMB   1
MNDAH    RMB   1
MNDAL    RMB   1
MDRH     RMB   1
MDRL     RMB   1
UNDEC    RMB   1
CENTML   RMB   1
DECEMIL  RMB   1
UMLDML   RMB   1
CMLMML   RMB   1
B        RMB   1
MSB      RMB   1
MHSB     RMB   1
MLSB     RMB   1
LSB      RMB   1

REFH     RMB   1
REFL     RMB   1
INCOGH   RMB   1
INCOGL   RMB   1
BYTE     RMB   1
MSTRA    RMB   1
RESH     RMB   1
RESM     RMB   1
RESL     RMB   1
CONT     RMB   1
OCONT    RMB   1

RANGO	 RMB   1
MARK	 RMB   1
**************************************************************************************************************************

           ORG  ROM_START
START:
           CLR  OSCSC	; Oscilador interno a 4 MHz
           RSP          ;INICIALIZACION DEL MICROCONTROLADOR
           CLRA
           CLRH
           CLRX
           CLC

           MOV  #%00001001,CONFIG1   ;PROGRAMACION DE LOS CONFIGS
           NOP
           NOP
           MOV  #%10000000,CONFIG2
           NOP
           NOP

           MOV  #$FF,DDRB             ;PUERTO B TODO COMO SALIDA
           MOV  #%00110001,DDRA       ;PTA5, PTA4 Y PTA3 SON SALIIDAS. PTA2, PTA1 Y PTA0 SON ENTRADAS


           CLR  PTA
           CLR  PTB
           JSR  RETARDO


**************************************************************************************************************************
INICIO_LCD:                           ;PREPARA AL MODULO LCD PARA MODO 8 BITS


           LDA  #%00111000
           JSR  ESCRIBE_IR
           LDA  #%00001110
           JSR  ESCRIBE_IR
           LDA  #%00000001
           JSR  ESCRIBE_IR
           LDA  #%00000110
           JSR  ESCRIBE_IR
           LDA  #%01000000
           JSR  ESCRIBE_IR
           LDA  #%00001100
           JSR  ESCRIBE_IR
**************************************************************************************************************************
SALUDO:
           LDA  #$01                 ;CLEAR DISPLAY
           JSR  ESCRIBE_IR
           LDA  #$0C                 ;DISPLAY ON
           JSR  ESCRIBE_IR

           LDA  #%10000011           ;SET DDRAM $03. Va a la posicion 3 de la primera fila
           JSR  ESCRIBE_IR
           LDX  #$15
           LDA  TABLA,X                ;c
           JSR  ESCRIBE_DR
           LDX  #$14
           LDA  TABLA,X                ;a
           JSR  ESCRIBE_DR
           LDX  #$1C
           LDA  TABLA,X                ;r
           JSR  ESCRIBE_DR

           JSR  RETARDO                ;Retardo para dar tiempo a que se lea el nombre
           JSR  RETARDO
           JSR  RETARDO
           JSR  RETARDO
           JSR  RETARDO
           JSR  RETARDO
           JSR  RETARDO
**************************************************************************************************************************
           LDA  #$01         ;CLEAR DISPLAY
           JSR  ESCRIBE_IR
**************************************************************************************************************************
ESCRIBE_IR:                  ;SUBRUTINA QUE SIRVE PARA MANDARLE INSTRUCCIONES AL MODULO LCD
           BCLR  RS,PTA
           BCLR  RWR,PTA
           BSET  E,PTA
           STA   PTB
           JSR   DEMORA100
           BCLR  E,PTA
           JSR   DEMORA100
           BCLR  RS,PTA
           RTS
**************************************************************************************************************************
ESCRIBE_DR:                  ;SUBRUTINA QUE SIRVE PARA MANDARLE DATOS (CARACTERES) AL MODULO LCD
           BSET  RS,PTA
           BCLR  RWR,PTA
           BSET  E,PTA
           STA   PTB
           JSR   DEMORA100
           BCLR  E,PTA
           JSR   DEMORA100
           BCLR  RS,PTA
           RTS
**************************************************************************************************************************
RETARDO
        PSHA
        PSHH
        PSHX
        LDA     #$FF
DELAY
        LDHX    #$00EF
LOOP1
        AIX     #-1
        CPHX    #0
        BNE     LOOP1
        DECA
        BNE     DELAY
        PULX
        PULH
        PULA
        RTS
**************************************************************************************************************************
DEMORA100:                        ;RUTINA QUE GENERA UNA DEMORA DE APROX.
           PSHA
           LDA  #$FF
RESTA3:
           DECA
           BNE  RESTA3

           PULA
           RTS
**************************************************************************************************************************
TABLA:                                ;TABLA EN DONDE SE DEFINEN LOS CARACTERES QUE SE USARAN
           DB  %00110000;0 X = $00
           DB  %00110001;1 X = $01
           DB  %00110010;2 X = $02
           DB  %00110011;3 X = $03
           DB  %00110100;4 X = $04
           DB  %00110101;5 X = $05
           DB  %00110110;6 X = $06
           DB  %00110111;7 X = $07
           DB  %00111000;8 X = $08
           DB  %00111001;9 X = $09
           DB  %01010000;P X = $0A
           DB  %01010010;R X = $0B
           DB  %01010100;T X = $0C
           DB  %01010101;U X = $0D
           DB  %01000011;C X = $0E
           DB  %01000101;E X = $0F
           DB  %01000110;F X = $10
           DB  %01001000;H X = $11
           DB  %01001100;L X = $12
           DB  %01001110;N X = $13
           DB  %01100001;a X = $14
           DB  %01100011;c X = $15
           DB  %01100111;g X = $16
           DB  %01101001;i X = $17
           DB  %01101010;j X = $18
           DB  %01101100;l X = $19
           DB  %01101111;o X = $1A
           DB  %01110000;p X = $1B
           DB  %01110010;r X = $1C
           DB  %01110011;s X = $1D
           DB  %01110101;u X = $1E
           DB  %00101110;punto X = $1F
           DB  %00101100;coma X = $20
           DB  %00111111;pregunta X = $21
           DB  %00111101;igual X = $22
           DB  %00000000; mu X=$23
           DB  %00100000;ESPACIO X=$24
           DB  %00000001; Yaz X=$25
           DB  %01100101;e  X = $26
           DB  %00111010;dos puntos X = $27
           DB  %01101110;n  X = $28
           DB  %01000010;B  X = $29
           DB  %01100100;d  X = $2A
           DB  %01001010;J  X = $2B
           DB  %01110110;v  X = $2C
**************************************************************************************************************************
**************************************************************************************************************************



**************************************************************************************************************************
BOBO                       ;Rutina para los vectores no utilizados. Se pone "por las dudas"
           NOP
           RTI
**************************************************************************************************************************

**************************************************************************************************************************

*************************************TABLA DE VECTORES*******************************************************************

           ORG  VECTORS

           DW   BOBO  ;FFDE-FFDF
           DW   BOBO  ;FFE0-FFE1
           DW   BOBO  ;FFE2-FFE3
           DW   BOBO  ;FFE4-FFE5
           DW   BOBO  ;FFE6-FFE7
           DW   BOBO  ;FFE8-FFE9
           DW   BOBO  ;FFEA-FFEB
           DW   BOBO  ;FFEC-FFED
           DW   BOBO  ;FFEE-FFEF
           DW   BOBO  ;FFF0-FFF1
           DW   BOBO  ;FFF2-FFF3
           DW   BOBO  ;FFF4-FFF5
           DW   BOBO  ;FFF6-FFF7
           DW   BOBO  ;FFFF8-FFF9
           DW   BOBO  ;FFFA-FFFB
           DW   BOBO  ;FFFC-FFFD
           DW   START ;FFFE-FFFF
**************************************************************************************************************************
END
**************************************************************************************************************************











1



