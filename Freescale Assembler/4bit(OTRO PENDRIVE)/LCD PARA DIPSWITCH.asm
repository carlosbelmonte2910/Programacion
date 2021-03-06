RAM_START  EQU  $0080
ROM_START  EQU  $EE00
VECTORS    EQU  $FFDE
E          EQU   5
RS         EQU   4
IN_1       EQU   0
IN_2       EQU   1
IN_3       EQU   2
IN_4       EQU   3

$BASE 10T
$include   'QTQY_Registers.inc'

***********VARIABLES DE RAM**********
           ORG  RAM_START
CHAR       RMB  1
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
           MOV  #%00110000,DDRA       ;PTA5, PTA4 Y PTA3 SON SALIIDAS. PTA2, PTA1 Y PTA0 SON ENTRADAS


           CLR  PTA
           CLR  PTB
           JSR  RETARDO


**************************************************************************************************************************
INICIO_LCD:                           ;PREPARA AL MODULO LCD PARA MODO 8 BITS
           LDA  #%00101000
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
           ;LDA  #$01                 ;CLEAR DISPLAY
           ;JSR  ESCRIBE_IR
           LDA  #$0C                 ;DISPLAY ON
           JSR  ESCRIBE_IR

           LDA  #%10000000           ;SET DDRAM $00. Va a la posicion 0 de la primera fila
           JSR  LAMPARA_1
           JSR  ESTADO_1
           LDA  #%11000000           ;SET DDRAM $40. Va a la posicion 0 de la segunda fila
           JSR  LAMPARA_2
           JSR  ESTADO_2
           LDA  #%10010100           ;SET DDRAM $14. Va a la posicion 0 de la tercera fila
           JSR  LAMPARA_3
           JSR  ESTADO_3
           LDA  #%11010100           ;SET DDRAM $54. Va a la posicion 0 de la cuarta fila
           JSR  LAMPARA_4
           JSR  ESTADO_4
           JSR  RETARDO
           JSR  RETARDO
           bra  SALUDO
**************************************************************************************************************************
ESCRIBE_IR:                  ;SUBRUTINA QUE SIRVE PARA MANDARLE INSTRUCCIONES AL MODULO LCD
           BCLR  RS,PTA
           BSET  E,PTA
           STA   CHAR
           AND   #$F0
           STA   PTB
           JSR   DEMORA100
           BCLR  E,PTA
           CLR   PTB
           JSR   DEMORA100
           BSET  E,PTA
           LDA   CHAR
           NSA
           AND   #$F0
           STA   PTB
           JSR   DEMORA100
           BCLR  E,PTA
           JSR   DEMORA100
           CLR   PORTB
           BCLR  RS,PTA
           RTS
**************************************************************************************************************************
ESCRIBE_DR:                  ;SUBRUTINA QUE SIRVE PARA MANDARLE DATOS (CARACTERES) AL MODULO LCD
           BSET  RS,PTA
           BSET  E,PTA
           STA   CHAR
           AND   #$F0
           STA   PTB
           JSR   DEMORA100
           BCLR  E,PTA
           CLR   PTB
           JSR   DEMORA100
           BSET  E,PTA
           LDA   CHAR
           NSA
           AND   #$F0
           STA   PORTB
           JSR   DEMORA100
           BCLR  E,PTA
           JSR   DEMORA100
           CLR   PORTB
           BCLR  RS,PTA
           RTS
**************************************************************************************************************************
LAMPARA_1
           JSR  ESCRIBE_IR
           LDX  #$12
           LDA  TABLA,X   ;------------;L
           JSR  ESCRIBE_DR

           LDX  #$14
           LDA  TABLA,X   ;------------;a
           JSR  ESCRIBE_DR

           LDX  #$2D
           LDA  TABLA,X   ;------------;m
           JSR  ESCRIBE_DR

           LDX  #$1B
           LDA  TABLA,X   ;------------;p
           JSR  ESCRIBE_DR

           LDX  #$14
           LDA  TABLA,X   ;------------;a
           JSR  ESCRIBE_DR

           LDX  #$1C
           LDA  TABLA,X   ;------------;r
           JSR  ESCRIBE_DR

           LDX  #$14
           LDA  TABLA,X   ;------------;a
           JSR  ESCRIBE_DR

           LDX  #$24
           LDA  TABLA,X   ;------------;espacio
           JSR  ESCRIBE_DR

           LDX  #$01
           LDA  TABLA,X   ;------------;nro 1
           JSR  ESCRIBE_DR

           LDX  #$27
           LDA  TABLA,X   ;------------;dos puntos
           JSR  ESCRIBE_DR             ;termina siempre con este salto, sino borra la ultima letra
           RTS
ESTADO_1
           brset IN_1,PORTA,enc1           ;Si hay un 1 salta a la sub funcion enc1
           nop
           brclr IN_1,PORTA,apa1           ;Si hay un 0 salta a la sub funcion apa1
           rts
enc1
           JSR  ENCENDIDA
           RTS
apa1
           JSR  APAGADA
           RTS

LAMPARA_2
           JSR  ESCRIBE_IR
           LDX  #$12
           LDA  TABLA,X   ;------------;L
           JSR  ESCRIBE_DR

           LDX  #$14
           LDA  TABLA,X   ;------------;a
           JSR  ESCRIBE_DR

           LDX  #$2D
           LDA  TABLA,X   ;------------;m
           JSR  ESCRIBE_DR

           LDX  #$1B
           LDA  TABLA,X   ;------------;p
           JSR  ESCRIBE_DR

           LDX  #$14
           LDA  TABLA,X   ;------------;a
           JSR  ESCRIBE_DR

           LDX  #$1C
           LDA  TABLA,X   ;------------;r
           JSR  ESCRIBE_DR

           LDX  #$14
           LDA  TABLA,X   ;------------;a
           JSR  ESCRIBE_DR

           LDX  #$24
           LDA  TABLA,X   ;------------;espacio
           JSR  ESCRIBE_DR

           LDX  #$02
           LDA  TABLA,X   ;------------;nro 2
           JSR  ESCRIBE_DR

           LDX  #$27
           LDA  TABLA,X   ;------------;dos puntos
           JSR  ESCRIBE_DR
           RTS

ESTADO_2
           brset IN_2,PORTA,enc2           ;Si hay un 1 salta a la sub funcion enc1
           nop
           brclr IN_2,PORTA,apa2           ;Si hay un 0 salta a la sub funcion apa1
           rts
enc2
           JSR  ENCENDIDA
           RTS
apa2
           JSR  APAGADA
           RTS

LAMPARA_3
           JSR  ESCRIBE_IR
           LDX  #$12
           LDA  TABLA,X   ;------------;L
           JSR  ESCRIBE_DR

           LDX  #$14
           LDA  TABLA,X   ;------------;a
           JSR  ESCRIBE_DR

           LDX  #$2D
           LDA  TABLA,X   ;------------;m
           JSR  ESCRIBE_DR

           LDX  #$1B
           LDA  TABLA,X   ;------------;p
           JSR  ESCRIBE_DR

           LDX  #$14
           LDA  TABLA,X   ;------------;a
           JSR  ESCRIBE_DR

           LDX  #$1C
           LDA  TABLA,X   ;------------;r
           JSR  ESCRIBE_DR

           LDX  #$14
           LDA  TABLA,X   ;------------;a
           JSR  ESCRIBE_DR

           LDX  #$24
           LDA  TABLA,X   ;------------;espacio
           JSR  ESCRIBE_DR

           LDX  #$03
           LDA  TABLA,X   ;------------;nro 3
           JSR  ESCRIBE_DR

           LDX  #$27
           LDA  TABLA,X   ;------------;dos puntos
           JSR  ESCRIBE_DR
           RTS

ESTADO_3
           brset IN_3,PORTA,enc3           ;Si hay un 1 salta a la sub funcion enc1
           nop
           brclr IN_3,PORTA,apa3           ;Si hay un 0 salta a la sub funcion apa1
           rts
enc3
           JSR  ENCENDIDA
           RTS
apa3
           JSR  APAGADA
           RTS

LAMPARA_4
           JSR  ESCRIBE_IR
           LDX  #$12
           LDA  TABLA,X   ;------------;L
           JSR  ESCRIBE_DR

           LDX  #$14
           LDA  TABLA,X   ;------------;a
           JSR  ESCRIBE_DR

           LDX  #$2D
           LDA  TABLA,X   ;------------;m
           JSR  ESCRIBE_DR

           LDX  #$1B
           LDA  TABLA,X   ;------------;p
           JSR  ESCRIBE_DR

           LDX  #$14
           LDA  TABLA,X   ;------------;a
           JSR  ESCRIBE_DR

           LDX  #$1C
           LDA  TABLA,X   ;------------;r
           JSR  ESCRIBE_DR

           LDX  #$14
           LDA  TABLA,X   ;------------;a
           JSR  ESCRIBE_DR

           LDX  #$24
           LDA  TABLA,X   ;------------;espacio
           JSR  ESCRIBE_DR

           LDX  #$04
           LDA  TABLA,X   ;------------;nro 4
           JSR  ESCRIBE_DR

           LDX  #$27
           LDA  TABLA,X   ;------------;dos puntos
           JSR  ESCRIBE_DR
           RTS

ESTADO_4
           brset IN_4,PORTA,enc4           ;Si hay un 1 salta a la sub funcion enc1
           nop
           brclr IN_4,PORTA,apa4           ;Si hay un 0 salta a la sub funcion apa1
           rts
enc4
           JSR  ENCENDIDA
           RTS
apa4
           JSR  APAGADA
           RTS
ENCENDIDA
           LDX  #$24
           LDA  TABLA,X   ;------------;espacio
           JSR  ESCRIBE_DR

           LDX  #$0F
           LDA  TABLA,X   ;------------;E
           JSR  ESCRIBE_DR

           LDX  #$28
           LDA  TABLA,X   ;------------;n
           JSR  ESCRIBE_DR

           LDX  #$15
           LDA  TABLA,X   ;------------;c
           JSR  ESCRIBE_DR

           LDX  #$26
           LDA  TABLA,X   ;------------;e
           JSR  ESCRIBE_DR

           LDX  #$28
           LDA  TABLA,X   ;------------;n
           JSR  ESCRIBE_DR

           LDX  #$2A
           LDA  TABLA,X   ;------------;d
           JSR  ESCRIBE_DR

           LDX  #$17
           LDA  TABLA,X   ;------------;i
           JSR  ESCRIBE_DR

           LDX  #$2A
           LDA  TABLA,X   ;------------;d
           JSR  ESCRIBE_DR

           LDX  #$14
           LDA  TABLA,X   ;------------;a
           JSR  ESCRIBE_DR
           RTS
APAGADA
           LDX  #$24
           LDA  TABLA,X   ;------------;espacio
           JSR  ESCRIBE_DR

           LDX  #$24
           LDA  TABLA,X   ;------------;espacio
           JSR  ESCRIBE_DR

           LDX  #$2E
           LDA  TABLA,X   ;------------;A
           JSR  ESCRIBE_DR

           LDX  #$1B
           LDA  TABLA,X   ;------------;p
           JSR  ESCRIBE_DR

           LDX  #$14
           LDA  TABLA,X   ;------------;a
           JSR  ESCRIBE_DR

           LDX  #$16
           LDA  TABLA,X   ;------------;g
           JSR  ESCRIBE_DR

           LDX  #$14
           LDA  TABLA,X   ;------------;a
           JSR  ESCRIBE_DR

           LDX  #$2A
           LDA  TABLA,X   ;------------;d
           JSR  ESCRIBE_DR

           LDX  #$14
           LDA  TABLA,X   ;------------;a
           JSR  ESCRIBE_DR

           LDX  #$24
           LDA  TABLA,X   ;------------;espacio
           JSR  ESCRIBE_DR
           RTS
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
           DB  %01101101;m  X = $2D
           DB  %01000001;A  X = $2E
**************************************************************************************************************************
BOBO                       ;Rutina para los vectores no utilizados. Se pone "por las dudas"
           NOP
           RTI
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















