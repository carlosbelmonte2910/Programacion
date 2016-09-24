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
L          EQU   1
C          EQU   0
E          EQU   3
RWR        EQU   4
RS         EQU   5

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
           MOV  #%00111000,DDRA       ;PTA5, PTA4 Y PTA3 SON SALIIDAS. PTA2, PTA1 Y PTA0 SON ENTRADAS


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
CREACAR:                             ;Rutina que graba Yaz y Mu en la CGRAM

MU:
           LDA  #%01000000           ;Set CGRAM address 000000
           JSR  ESCRIBE_IR
           LDA  #%00000000
           JSR  ESCRIBE_DR
           LDA  #%00000000
           JSR  ESCRIBE_DR
           LDA  #%00010001
           JSR  ESCRIBE_DR
           LDA  #%00010001
           JSR  ESCRIBE_DR
           LDA  #%00010011
           JSR  ESCRIBE_DR
           LDA  #%00011101
           JSR  ESCRIBE_DR
           LDA  #%00010000
           JSR  ESCRIBE_DR
           LDA  #%00010000
           JSR  ESCRIBE_DR

YAZ:
           LDA  #%01001000           ;Set CGRAM address 001000
           JSR  ESCRIBE_IR
           LDA  #%00010101
           JSR  ESCRIBE_DR
           LDA  #%00010101
           JSR  ESCRIBE_DR
           LDA  #%00001110
           JSR  ESCRIBE_DR
           LDA  #%00011111
           JSR  ESCRIBE_DR
           LDA  #%00001110
           JSR  ESCRIBE_DR
           LDA  #%00010101
           JSR  ESCRIBE_DR
           LDA  #%00010101
           JSR  ESCRIBE_DR
           LDA  #%00000000
           JSR  ESCRIBE_DR

**************************************************************************************************************************
SALUDO:
           LDA  #$01                 ;CLEAR DISPLAY
           JSR  ESCRIBE_IR
           LDA  #$0C                 ;DISPLAY ON
           JSR  ESCRIBE_IR

           LDA  #%10000011           ;SET DDRAM $03. Va a la posicion 3 de la primera fila
           JSR  ESCRIBE_IR
           LDX  #$0B
           LDA  TABLA,X                ;R
           JSR  ESCRIBE_DR
           LDX  #$17
           LDA  TABLA,X                ;i
           JSR  ESCRIBE_DR
           LDX  #$15
           LDA  TABLA,X                ;c
           JSR  ESCRIBE_DR
           LDX  #$14
           LDA  TABLA,X                ;a
           JSR  ESCRIBE_DR

           LDX  #$1C
           LDA  TABLA,X                ;r
           JSR  ESCRIBE_DR
           LDX  #$2A
           LDA  TABLA,X                ;d
           JSR  ESCRIBE_DR
           LDX  #$1A
           LDA  TABLA,X                ;o
           JSR  ESCRIBE_DR
           LDX  #$24
           LDA  TABLA,X                ;Espacio
           JSR  ESCRIBE_DR
           LDX  #$2B
           LDA  TABLA,X                ;J
           JSR  ESCRIBE_DR
           LDX  #$14
           LDA  TABLA,X                ;a
           JSR  ESCRIBE_DR
           LDX  #$2C
           LDA  TABLA,X                ;v
           JSR  ESCRIBE_DR
           LDX  #$17
           LDA  TABLA,X                ;i
           JSR  ESCRIBE_DR
           LDX  #$26
           LDA  TABLA,X                ;e
           JSR  ESCRIBE_DR
           LDX  #$1C
           LDA  TABLA,X                ;r
           JSR  ESCRIBE_DR

           LDA  #%11000111           ;SET DDRAM $07. Va a la posicion 7 de la segunda fila
           JSR  ESCRIBE_IR

           LDX  #$29
           LDA  TABLA,X                ;B
           JSR  ESCRIBE_DR
           LDX  #$1A
           LDA  TABLA,X                ;o
           JSR  ESCRIBE_DR
           LDX  #$1C
           LDA  TABLA,X                ;r
           JSR  ESCRIBE_DR
           LDX  #$26
           LDA  TABLA,X                ;e
           JSR  ESCRIBE_DR
           LDX  #$19
           LDA  TABLA,X                ;l
           JSR  ESCRIBE_DR
           LDX  #$19
           LDA  TABLA,X                ;l
           JSR  ESCRIBE_DR
           LDX  #$17
           LDA  TABLA,X                ;i
           JSR  ESCRIBE_DR

           JSR  RETARDO                ;Retardo para dar tiempo a que se lea el nombre
           JSR  RETARDO
           JSR  RETARDO
           JSR  RETARDO
           JSR  RETARDO
           JSR  RETARDO
           JSR  RETARDO




           LDA  #$01                 ;CLEAR DISPLAY
           JSR  ESCRIBE_IR

           LDA  #%10000101           ;SET DDRAM $05. Va a la posicion 5 de la primera fila
           JSR  ESCRIBE_IR
                                     ;comienza a escribir
           LDX  #$0D
           LDA  TABLA,X              ;U
           JSR  ESCRIBE_DR
           LDX  #$0C
           LDA  TABLA,X              ;T
           JSR  ESCRIBE_DR
           LDX  #$13
           LDA  TABLA,X              ;N
           JSR  ESCRIBE_DR
           LDX  #$24
           LDA  TABLA,X
           JSR  ESCRIBE_DR           ;ESPACIO

           LDX  #$25
           LDA  TABLA,X              ;simbolo yaz utn
           JSR  ESCRIBE_DR
           LDX  #$24
           LDA  TABLA,X
           JSR  ESCRIBE_DR           ;ESPACIO
           LDX  #$10
           LDA  TABLA,X              ;F
           JSR  ESCRIBE_DR
           LDX  #$0B
           LDA  TABLA,X              ;R
           JSR  ESCRIBE_DR
           LDX  #$0C
           LDA  TABLA,X              ;T
           JSR  ESCRIBE_DR
**************************************************************************************************************************
DALE       LDA  PTA                    ;CONTROLA SI SE PULSA "L" PARA PASAR DEL SALUDO A "PREPARE"
           STA  AUX
           BRCLR L,AUX,DALE


**************************************************************************************************************************
PREPARE:                            ;En esta subrutina se toma el periodo de referencia de la medicion

           LDA  #$01                 ;CLEAR DISPLAY
           JSR  ESCRIBE_IR

           LDX  #$0A
           LDA  TABLA,X              ;P
           JSR  ESCRIBE_DR
           LDX  #$1C                 ;r
           LDA  TABLA,X
           JSR  ESCRIBE_DR
           LDX  #$26                 ;e
           LDA  TABLA,X
           JSR  ESCRIBE_DR
           LDX  #$1B                 ;p
           LDA  TABLA,X
           JSR  ESCRIBE_DR
           LDX  #$14
           LDA  TABLA,X              ;a
           JSR  ESCRIBE_DR
           LDX  #$1C
           LDA  TABLA,X              ;r
           JSR  ESCRIBE_DR
           LDX  #$26
           LDA  TABLA,X              ;e
           JSR  ESCRIBE_DR
           LDX  #$1F
           LDA  TABLA,X              ;.
           JSR  ESCRIBE_DR
           LDX  #$24
           LDA  TABLA,X              ;ESPACIO
           JSR  ESCRIBE_DR
           LDX  #$12
           LDA  TABLA,X              ;L
           JSR  ESCRIBE_DR
           LDX  #$1E
           LDA  TABLA,X              ;u
           JSR  ESCRIBE_DR
           LDX  #$26
           LDA  TABLA,X              ;e
           JSR  ESCRIBE_DR
           LDX  #$16
           LDA  TABLA,X              ;g
           JSR  ESCRIBE_DR
           LDX  #$1A
           LDA  TABLA,X              ;o
           JSR  ESCRIBE_DR
           LDX  #$20
           LDA  TABLA,X              ;,
           JSR  ESCRIBE_DR

           LDA  #%11000000           ; Salta a linea 2
           JSR  ESCRIBE_IR


           LDX  #$1B
           LDA  TABLA,X              ;p
           JSR  ESCRIBE_DR
           LDX  #$1E
           LDA  TABLA,X              ;u
           JSR  ESCRIBE_DR
           LDX  #$19
           LDA  TABLA,X              ;l
           JSR  ESCRIBE_DR
           LDX  #$1D
           LDA  TABLA,X              ;s
           JSR  ESCRIBE_DR
           LDX  #$26
           LDA  TABLA,X              ;e
           JSR  ESCRIBE_DR
           LDX  #$24
           LDA  TABLA,X              ;ESPACIO
           JSR  ESCRIBE_DR
           LDX  #$15
           LDA  TABLA,X              ;c
           JSR  ESCRIBE_DR
           LDX  #$26
           LDA  TABLA,X              ;e
           JSR  ESCRIBE_DR
           LDX  #$1C
           LDA  TABLA,X              ;r
           JSR  ESCRIBE_DR
           LDX  #$1A
           LDA  TABLA,X              ;o
           JSR  ESCRIBE_DR
REV                                ;Revisa si la tecla 'cero' esta presionada
           LDA  PTA
           STA  AUX
           BRCLR C,AUX,REV         ;si esta presionada, va a CERO
                                   ;si no esta presionada, vuelve a REVISAR
**************************************************************************************************************************
           LDA  #$01         ;CLEAR DISPLAY
           JSR  ESCRIBE_IR

CERO       JSR  FRECUEN      ;Va a medir la frecuencia de referencia
           LDA  FRECH        ;Cuando vuelve guarda la frecuencia medida en REFH:REFL
           STA  REFH
           LDA  FRECL
           STA  REFL


**************************************************************************************************************************
           JSR   RETARDO
OPCIONES:                           ;Aquí el sistema pregunta si se desea medir capacitancia o inductancia
           LDA  #$01                 ;CLEAR DISPLAY
           JSR  ESCRIBE_IR

           LDX  #$0F
           LDA  TABLA,X                 ;E
           JSR  ESCRIBE_DR
           LDX  #$19
           LDA  TABLA,X              ;l
           JSR  ESCRIBE_DR
           LDX  #$17
           LDA  TABLA,X              ;i
           JSR  ESCRIBE_DR
           LDX  #$18
           LDA  TABLA,X              ;j
           JSR  ESCRIBE_DR

           LDX  #$14
           LDA  TABLA,X                ;a
           JSR  ESCRIBE_DR
           LDX  #$27
           LDA  TABLA,X              ;:
           JSR  ESCRIBE_DR
           LDX  #$24
           LDA  TABLA,X              ;espacio
           JSR  ESCRIBE_DR
           LDX  #$0E
           LDA  TABLA,X              ;C
           JSR  ESCRIBE_DR
           LDX  #$24
           LDA  TABLA,X              ;espacio
           JSR  ESCRIBE_DR
           LDX  #$1A
           LDA  TABLA,X              ;o
           JSR  ESCRIBE_DR
           LDX  #$24
           LDA  TABLA,X              ;espacio
           JSR  ESCRIBE_DR
           LDX  #$12
           LDA  TABLA,X              ;L
           JSR  ESCRIBE_DR
           LDX  #$21
           LDA  TABLA,X              ;?
           JSR  ESCRIBE_DR


SELECT
           LDA  PTA
           STA  AUX
           BRCLR L,AUX,SELC
           JMP  INDUC        ;Esta presionada la tecla L?
SELC       LDA  PTA
           STA  AUX
           BRCLR C,AUX,SELECT        ;Esta presionada la tecla C?
           JMP  CAPAC

**************************************************************************************************************************
******************Rutina donde se calcula el valor de inductancia*********************************************************

INDUC      JSR  MEDIR      ;Salta a MEDIR
           LDX  #$12       ;Carga X con la ubicacion de 'L'
           MOV  #$01,COSA  ; INDICA SI ES UN CAPACITOR O UN INDUCTOR LO MEDIDO. INDUCTOR: COSA = 1
           JSR  MSTR      ;Salta a la subrutina que muestra el valor de L
           JSR  RETARDO
           JSR  RETARDO
DAL1       LDA  PTA                    ;CONTROLA SI SE PULSA "L" PARA PASAR DE NUEVO A LAS OPCIONES
           STA  AUX
           BRCLR L,AUX,DAL1
           JSR  RETARDO
           JSR  RETARDO
           JMP  OPCIONES   ;Vuelve al menu de opciones

**************************************************************************************************************************
****************************Rutina donde se calcula el valor de capacitancia**********************************************
CAPAC      JSR  MEDIR      ;Salta a MEDIR
           LDX  #$0E       ;Carga X con la ubicacion de 'C'
           CLR  COSA  ; INDICA SI ES UN CAPACITOR O UN INDUCTOR LO MEDIDO. CAPACITOR: COSA = 0
           JSR  MSTR      ;Salta a la subrutina que muestra el valor de C
           JSR  RETARDO
           JSR  RETARDO
DAL2       LDA  PTA                    ;CONTROLA SI SE PULSA "L" PARA PASAR DE NUEVO A LAS OPCIONES
           STA  AUX
           BRCLR L,AUX,DAL2
           JSR  RETARDO
           JSR  RETARDO
           JMP  OPCIONES   ;Vuelve al menu de opciones
**************************************************************************************************************************
**************************************************************************************************************************
MEDIR      JSR  FRECUEN; Va a medir la frecuencia incognita y cuando vuelve la guarda en INCOGH:INCOGL
           LDA  FRECH

           STA  INCOGH

           LDA  FRECL

           STA  INCOGL

           LDA  INCOGH     ;Aqui va a dividir la de referecia por la de incognita
           STA  DSRM

           LDA  INCOGL
           STA  DSRL

           LDA  REFH       ;Va a multiplicar la de referencia por 1000
           STA  MDRH
           LDA  REFL
           STA  MDRL
           LDA  #$03
           STA  MNDH
           LDA  #$E8
           STA  MNDL
           JSR  MULTI

           LDA  PRODL   ;Ahora carga el dividendo
           STA  DNDL
           LDA  PRODML
           STA  DNDM
           LDA  PRODMH
           STA  DNDH
           JSR  DIVIDIR

           LDA  QM
           STA  MDRH
           STA  MNDH
           LDA  QL
           STA  MDRL
           STA  MNDL
           JSR  MULTI     ; Aqui va a elevar al cuadrado QM:QL
           JSR  RMILL     ;Resta 1000'000 del producto
           LDA  PRODH
           STA  MSB
           LDA  PRODMH
           STA  MHSB
           LDA  PRODML
           STA  MLSB
           LDA  PRODL
           STA  LSB
           JSR  CONVBCD
           RTS

**************************************************************************************************************************
**La siguiente subrutina muestra el valor en el display*******
**************************************************************************************************************************

RAN	   LDA  CMLMML
           CMP	#$00
           BNE	AUT
           MOV	#$FF,RANGO
           JMP	SGMST

LACE       LDX  #$0E
           LDA  TABLA,X
           JSR  ESCRIBE_DR
           JMP  MIGU

MSTR       CLR  RANGO
           CLR	MARK

           LDA  #$01                 ;CLEAR DISPLAY
           JSR  ESCRIBE_IR
           LDA  COSA
           CMP  #$01
CMDE       BNE  LACE        ;LACE es para el caso que sea un capacitor lo medido
           LDX  #$12
           LDA  TABLA,X
           JSR  ESCRIBE_DR     ;Escribe 'L'

MIGU       LDX  #$22
           LDA  TABLA,X
           JSR  ESCRIBE_DR   ;Escribe '='

           LDA  CMLMML
           CMP  #$00
           BEQ  NMS1
           STA  BYTE
           JSR  SACA

NMS1       LDA  UMLDML
           CMP	#$00
	   BEQ	RAN
AUT        STA  BYTE
           JSR  SACA

           LDA  COSA
           CMP  #$01
COMDE      BNE  COMAC        ;COMAC es para el caso que sea un capacitor lo medido

SGMST      LDA  DECEMIL      ;Sigue mostrando
           STA  BYTE
           JSR  SACA
           LDA	RANGO
           CMP	#$FF
           BNE	QES
           JMP  COMAC

QES        LDA  COSA
           CMP  #$01
CPEN       BNE  ESCP        ;ESCP es para el caso que sea un capacitor lo medido
           LDX  #$20
           LDA  TABLA,X
           JSR  ESCRIBE_DR   ;Escribe la coma
ESCP       LDA  CENTML
           STA  BYTE
           JSR  SACA
                      ; la precision es solo hasta dos digitos luego de la coma. Por eso no escribe el valor de UNDEC
           LDA  COSA
           CMP  #$01
CMUL       BNE  NANOF        ;NANOF es para el caso que sea un capacitor lo medido
HAGMU      LDX  #$23
           LDA  TABLA,X
           JSR  ESCRIBE_DR   ;Escribe mu

           LDX  #$11
           LDA  TABLA,X
           JSR  ESCRIBE_DR   ;Escribe H
           RTS

NANOF      LDA	RANGO
           CMP	#$FF
           BEQ	LAPE
	   LDX  #$28
           LDA  TABLA,X
           JSR  ESCRIBE_DR   ;Escribe n
           LDX  #$10
           LDA  TABLA,X
           JSR  ESCRIBE_DR ;Escribe F

           RTS

LAPE	   LDA	COSA
	   CMP  #$01
           BEQ	HAGMU
           LDX  #$1B
           LDA  TABLA,X
           JSR  ESCRIBE_DR   ;Escribe p
           LDX  #$10
           LDA  TABLA,X
           JSR  ESCRIBE_DR ;Escribe F

           RTS


COMAC      LDA	RANGO
           CMP	#$FF
           BNE	LACO
           MOV	#$01,MARK
           LDA	CENTML
           STA	BYTE
           JSR	SACA

LACO       LDA  MARK
           CMP  #$00
           BNE  LAPE
           LDX  #$20
           LDA  TABLA,X
           JSR  ESCRIBE_DR   ;Escribe la coma
           LDA  RANGO
           CMP	#$FF
           BNE  SGMSS
           BEQ	ESCP
SGMSS      JMP  SGMST


SACA       LDA  MARK
           CMP  #$01
           BEQ  ESL        ;ES INDUCTOR? 
BAIT       LDA  BYTE
           STA  MSTRA
           AND  #$F0
           NSA
           ORA  #$30
           TAX

           JSR  ESCRIBE_DR ;Manda el nibble alto

           LDA  MARK
           CMP	#$00
           BEQ	SACAN
           LDX	#$20
           LDA	TABLA,X
           JSR  ESCRIBE_DR ;Escribe la coma

SACAN      LDA  MSTRA
           AND  #$0F
           ORA  #$30
           TAX
           JSR  ESCRIBE_DR ;Manda el nibble bajo
           RTS

ESL        LDA  COSA
           CMP  #$00
           BEQ  BAIT
           LDX	#$20
           LDA	TABLA,X
           JSR  ESCRIBE_DR  ;Escribe la coma

           LDA  BYTE      ;Manda el nibble alto
           STA  MSTRA
           AND  #$F0
           NSA
           ORA  #$30
           TAX
           BRA  SACAN           








**************************************************************************************************************************

**************************************************************************************************************************
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
****************************************************************************************************



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
FRECUEN    MOV	#%00110000,TSC ;detiene y reseta el TIM
           MOV  #%00110111,TSC ;elige que la señal de clock para el TIM sea externa

           CLR	  FRECH        ;inicializa FRECH:FRECL
	   CLR	  FRECL



RETAR1M    CLR    CONT
           CLR    OCONT
           LDA    #$04
           STA    OCONT
           MOV 	#%00010111,tsc ;comienza la cuenta
RETAR2M

	LDA    #$F0
	   STA	  CONT            ;carga en CONT un valor adecuado para que el retardo dure aprox. 1ms





RSTA       DBNZ	  CONT,RSTA    ;Decrementa el contador y si no da cero vuelve a consultar el desborde
RSTAB      DBNZ   OCONT,RETAR2M ;Decrementa OCONT y si no es cero vuelve a cargar CONT


SALE
           LDA    TCNTH          ;Copia el valor de TCNTH:TCNTL en FRECH:FRECL
           STA    FRECH
           LDA    TCNTL
           STA    FRECL
           MOV    #%00100111,TSC ;Detiene el TIM
           RTS    	      	 ;Sale de la subrutina


**************************************************************************************************************************
**************************************************************************************************************************
DIVIDIR
          CLR   AUXI
          CLR   DH
          CLR   DM
          CLR   DL
          CLRA
          CLC
          CLRX


          CLR   DNDAH	;DIVIDENDO AUXILIAR
          CLR   DNDAM
          CLR   DNDAL


          CLR   DSRH


DIV24
         LDA   DNDL
         STA   DL
         LDA   DNDM
         STA   DM
         LDA   DNDH
         STA   DH
         LDA   DNDL
         SUB   DSRL
         LDA   DNDM
         SBC   DSRM
         LDA   DNDH
         SBC   DSRH
         BCS   MULDO

         LDA   DNDL
         SUB   DSRL
         STA   RESL
         LDA   DNDM
         SBC   DSRM
         STA   RESM
         LDA   DNDH
         SBC   DSRH
         STA   RESH
         LDA   RESH
         CMP   #$00
         BEQ   SIG
         BNE   BUSCB
SIG      LDA   RESM
         CMP   #$00
         BEQ   SIG2
         BNE   BUSCB
SIG2     LDA   RESL
         CMP   #$00
         BEQ   IGUAL

BUSCB     LDA   DSRL
          PSHA
          LDA   DSRM
          PSHA
          LDA   DSRH

          LDX   #$01
          CLR   QH
          CLR   QM
          CLR   QL
BUSCA     CLC
          ROL   DSRL
          ROL   DSRM
          ROL   DSRH
          INCX
          BCS   ACOMODA
          CPX   #$19
          BNE   BUSCA

          RTS                 ;Retorna porque se quiso dividir entre cero

IGUAL     CLR   DNDH
          CLR   DNDM
          CLR   DNDL
          MOV   #$01,QL
          CLR   QM
          CLR   QH
          RTS

MULDO     CLR   QL
          CLR   QM
          CLR   QH
          MOV   DH,DNDH
          MOV   DM,DNDM
          MOV   DL,DNDL
          JMP   SALIR


ACOMODA   STX   AUXI
          STA   DSRH
          PULA
          STA   DSRM
          PULA
          STA   DSRL
                               ;AHORA EN A QUEDA GUARDADA LA POSICION DEL 1 MAS SIGNIFICATIVO DEL DSR
                               ;QUEDA ESE NUMERO GUARDADO EN AUXI

*********Esta parte hara el desplazamiento del dividendo hacia la derecha hacia dnda, segun el valor de auxi**************
          CLR   DNDAH
          CLR   DNDAM
          CLR   DNDAL
          LDA   AUXI
          SUB   #$01
CORRI     LSR   DNDH
          ROR   DNDM
          ROR   DNDL
          ROR   DNDAH
          ROR   DNDAM
          ROR   DNDAL
          DECA
          CMP   #$00
          BNE   CORRI

*******Ahora se esta listo para comparar**********
COMPA
           LDA   DNDL
           SUB   DSRL
           LDA   DNDM
           SBC   DSRM
           LDA   DNDH
           SBC   DSRH
           BCS   PONCE
           LDA   DNDL
           SUB   DSRL
           STA   DNDL
           LDA   DNDM
           SBC   DSRM
           STA   DNDM
           LDA   DNDH
           SBC   DSRH
           STA   DNDH
           LSL   DNDAL
           ROL   DNDAM
           ROL   DNDAH
           ROL   DNDL
           ROL   DNDM
           ROL   DNDH
           SEC
           ROL   QL
           ROL   QM
           ROL   QH
           DBNZ  AUXI,COMPA
           LSR   DNDH
           ROR   DNDM
           ROR   DNDL
           JMP   SALIR


PONCE     CLC                       ;PONE CERO EN EL COCIENTE
          ROL   QL
          ROL   QM
          ROL   QH
          LSL   DNDAL
          ROL   DNDAM
          ROL   DNDAH
          ROL   DNDL
          ROL   DNDM
          ROL   DNDH
          DBNZ  AUXI,COMPA
          LSR   DNDH
          ROR   DNDM
          ROR   DNDL

SALIR     RTS
**************************************************************************************************************************
**************************************************************************************************************************


MULTI     PSHX
          CLRX
          CLR   PRODL
          CLR   PRODML
          CLR   PRODMH
          CLR   PRODH
          CLR   MNDAL
          CLR   MNDAH

PRUEBA    LSR   MDRH
          ROR   MDRL
          INCX
          BCS   SUMA
DSPLZ     ASL   MNDL
          ROL   MNDH
          ROL   MNDAL
          ROL   MNDAH
          CPX   #$FF
          BNE   PRUEBA
          PULX
          RTS

SUMA      LDA   MNDL
          ADD   PRODL
          STA   PRODL
          LDA   MNDH
          ADC   PRODML
          STA   PRODML
          LDA   MNDAL
          ADC   PRODMH
          STA   PRODMH
          LDA   MNDAH
          ADC   PRODH
          STA   PRODH
          JMP   DSPLZ
**************************************************************************************************************************
**************************************************************************************************************************
RMILL     LDA   PRODL   ;RESTA 1'000'000 A PRODH:PRODMH:PRODML:PRODL
          SUB   #$40
          STA   PRODL
          LDA   PRODML
          SBC   #$42
          STA   PRODML
          LDA   PRODMH
          SBC   #$0F
          STA   PRODMH
          LDA   PRODH
          SBC   #$00
          STA   PRODH
          RTS
**************************************************************************************************************************
**************************************************************************************************************************
CONVBCD:                             ;Rutina que convierte un binario de 32 bit en BCD. Adaptada del libro de Ron Bishop


           CLR  UNDEC                ;Unidad y decena
           CLR  CENTML               ;Centena y unidad de mil
           CLR  DECEMIL              ;Decena de mil y centena de mil
           CLR  UMLDML               ;Unidad de millon y decena de millon
           CLR  CMLMML               ;Centena de millon y milena (?) de millon

           LDX  #$20
COMIEN
           LDA  UNDEC
           STA  B
           AND  #$0F
           SUB  #$05
           BMI  AT
           PSHA
           LDA  B
           ADD  #$03
           STA  B
           PULA
AT
           LDA  B
           AND  #$F0
           SUB  #$50
           BMI  BT
           PSHA
           LDA  B
           ADD  #$30
           STA  B
           PULA
BT
           PSHA
           LDA  B
           STA  UNDEC
           PULA

           LDA  CENTML        ;Comparar centenas y unidad de mil
           STA  B
           AND  #$0F
           SUB  #$05
           BMI  CT
           PSHA
           LDA  B
           ADD  #$03
           STA  B
           PULA
CT
           LDA  B
           AND  #$F0
           SUB  #$50
           BMI  DT
           PSHA
           LDA  B
           ADD  #$30
           STA  B
           PULA
DT
           PSHA
           LDA  B
           STA  CENTML
           PULA

           LDA  DECEMIL        ;Comparar decena de mil y centena de mil
           STA  B
           AND  #$0F
           SUB  #$05
           BMI  ET
           PSHA
           LDA  B
           ADD  #$03
           STA  B
           PULA
ET
           LDA  B
           AND  #$F0
           SUB  #$50
           BMI  FT
           PSHA
           LDA  B
           ADD  #$30
           STA  B
           PULA
FT
           PSHA
           LDA  B
           STA  DECEMIL
           PULA


           LDA  UMLDML        ;Comparar unidad de millon y decena de millon
           STA  B
           AND  #$0F
           SUB  #$05
           BMI  GT
           PSHA
           LDA  B
           ADD  #$03
           STA  B
           PULA
GT
           LDA  B
           AND  #$F0
           SUB  #$50
           BMI  HT
           PSHA
           LDA  B
           ADD  #$30
           STA  B
           PULA
HT
           PSHA
           LDA  B
           STA  UMLDML
           PULA



           LDA  CMLMML        ;Comparar centena DE MILLON Y MILENA (?) DE MILLON
           STA  B
           AND  #$0F
           SUB  #$05
           BMI  IT
           PSHA
           LDA  B
           ADD  #$03
           STA  B
           PULA
IT
           LDA  B
           AND  #$F0
           SUB  #$50
           BMI  JT
           PSHA
           LDA  B
           ADD  #$30
           STA  B
           PULA
JT
           PSHA
           LDA  B
           STA  CMLMML
           PULA



           ASL  LSB     ;Aqui rota los bits
           ROL  MLSB	;Medium-Low significant byte
           ROL  MHSB	;Medium_High significant byte
           ROL  MSB	;Most significant byte
           ROL  UNDEC
           ROL  CENTML
           ROL  DECEMIL
           ROL  UMLDML
           ROL  CMLMML
           DECX
           CPX  #$00
           BNE  COMI

           RTS            ;Retorno
COMI       JMP  COMIEN

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

