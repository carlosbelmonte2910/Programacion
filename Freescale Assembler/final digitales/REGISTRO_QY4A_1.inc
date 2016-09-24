;******************************************************************************
; 			REGISTRO_QY4A_1.INC - ARCHIVO INCLUDE
; Contiene las Definiciones de los Registros del MC68HC908QTA/QYA/8/4/2/1
;
; 			SyHDe - Soft y Hard Desarrollos
;******************************************************************************

;******************************************************************************
;---------------REGISTROS DE PUERTOS ENT/SAL-----------------------------------
;---------------PUERTO A-------------------------------------------------------
PTA	EQU	$0000	; Port A Data register
PORTA	EQU	$0000	; "
DDRA	EQU	$0004	; Port A Data Direction Register
PTAPUE  EQU	$000B	; Port A Pull Ups Enable

;---------------PUERTO B-------------------------------------------------------
PTB	EQU	$0001	; Port B Data register
PORTB	EQU	$0001	; "
DDRB	EQU	$0005	; Port B Data Direction Register
PTBPUE  EQU	$000C	; Port B Pull Ups Enable

;******************************************************************************
;---------------REGISTROS DEL MODULO KEYBOARD----------------------------------
KBSCR	EQU	$001A	; Keyboard Status & Control register
keyf	equ	3	;
ackk	equ	2	;
imaskk	equ	1	;
modek	equ	0	;

KBIER	EQU	$001B	; Keyboard interrupt enable register

;******************************************************************************
;---------------REGISTROS DE INTERRUPCION EXTERNA 1----------------------------
INTSCR	EQU	$001D   ; IRQ Status & Control Register
irqf	equ	3	;
ack	equ	2	;
imask	equ	1	;
mode	equ	0	;

;******************************************************************************
;---------------REGISTROS DE CONFIGURACION-------------------------------------
CONFIG1	EQU	$001F	; Configuration Register 1

CONFIG2	EQU	$001E	; Configuration Register 2

;******************************************************************************
;---------------REGISTROS DEL TIMER -------------------------------------------
TSC	EQU	$0020	; Timer Status & Control Register
tof	equ	7	;
toie	equ	6	;
tstop	equ	5	;
trst	equ	4	;

TCNTH	EQU	$0021	; Timer Counter Register High
TCNTL	EQU	$0022	; Timer Counter Register Low
TMODH	EQU	$0023	; Timer Counter Modulo Register High
TMODL	EQU	$0024	; Timer Counter Modulo Register Low

TSC0	EQU	$0025	; Timer Channel 0 Status & Control Register
ch0f	equ	7
ch0ie	equ	6	;
ms0b	equ	5	;
ms0a	equ	4	;
els0b	equ	3	;
els0a	equ	2	;
tov0	equ	1	;
ch0max	equ	0	;

TCH0H	EQU	$0026	; Timer Channel 0 Register High
TCH0L	EQU	$0027	; Timer Channel 0 Register Low

TSC1	EQU	$0028	; Timer Channel 1 Status & Control Register
ch1f	equ	7
ch1ie	equ	6	;
ms1b	equ	5	;
ms1a	equ	4	;
els1b	equ	3	;
els1a	equ	2	;
tov1	equ	1	;
ch1max	equ	0	;

TCH1H	EQU	$0029	; Timer Channel 1 Register High
TCH1L	EQU	$002A	; Timer Channel 1 Register Low

;******************************************************************************
;---------------REGISTROS DEL OSCILADOR----------------------------------------
OSCSC	EQU	$0036	;Oscillator Status and Control Register
ecgst	equ	0	;Read Only!!!!
ecgon	equ	1	;
ecfs0	equ	2	;
ecfs1	equ	3	;
icfs0	equ	4	;
icfs1	equ	5	;
oscopt0	equ	6	;
oscopt1	equ	7	;

OSCTRIM	EQU	$0038	;Oscillator Trim Register

OSCSTAT EQU	$0036	;Oscillator Status and Control (No Vers A Solo QY/QT)

;******************************************************************************
;---------------REGISTROS DEL ADC----------------------------------------------
ADSCR	EQU	$003C	; ADC Status & Control Register
coco	equ	7	;
aien	equ	6	;
adco	equ	5	;

ADRH	EQU	$003D	; ADC10 Data Register High
ADRL	EQU	$003E	; ADC10 Data Register Low
ADICLK	EQU	$003F	; ADC10 Clock Control Register

;******************************************************************************
;---------------REGISTROS DEL MODULO SIM---------------------------------------
BSR	EQU	$FE00	; Break Status Register
sbsw	equ	1	; break wait bit

SRSR	EQU	$FE01	; SIM Reset Status Register
por	equ	7	;
pin	equ	6	;
cop	equ	5	;
ilop	equ	4	;
ilad	equ	3	;
modrst	equ	2	;
lvi	equ	1	;

BRKAR	EQU	$FE02	; Break Auxiliary Register
bdcop	equ	0

BFCR	EQU	$FE03	; Break Flag Control Register
bcfe	equ	7	;

INT1	EQU	$FE04	; Interrupt Status Register 1

INT2	EQU	$FE05	; Interrupt Status Register 2

INT3	EQU	$FE06	; Interrupt Status Register 3

;******************************************************************************
;---------------REGISTROS DE LA MEMORIA FLASH----------------------------------
FLCR	EQU	$FE08	; FLASH Control Register

FLBPR	EQU	$FFBE	; FLASH Block Protect

;******************************************************************************
;---------------REGISTROS DEL MODULO BREAK------------------------------------
BRKH	EQU	$FE09	; Break address Hig Register

BRKL	EQU	$FE0A	; Break Address Low Register

BRKSCR	EQU	$FE0B	; Break Status & Control Register

;******************************************************************************
;---------------REGISTROS DEL MODULO LVI---------------------------------------
LVISR	EQU	$FE0C	; LVI Status Register

;******************************************************************************
;---------------REGISTROS DEL MODULO OSCILLATOR--------------------------------
IOSCTRM EQU	$FFC0	; Internal Oscillator Trim (Factory Prog Value Optional)

;******************************************************************************
;---------------REGISTROS DEL MODULO COP WATCHDOG------------------------------
COPCTL	EQU	$FFFF	; COP Control Register

;******************************************************************************
;******************************************************************************
; RUTINAS DE MANEJO DE LA MEMORIA FLASH SITUADAS EN LA ROM MONITOR (HC908QTQYx)
;******************************************************************************

PRGRNGE		EQU	$2809	;Programa un rango de direcciones de Flash
ERARNGE		EQU	$2806	;Borra una pagina de Memoria Flash
GETBYTE		EQU	$2800	;Recibe un Byte en Modo Monitordesde el Port
RDVRRNG		EQU	$2803	;Usa un Rango de la Flash y lo envia x el Port
DELNUS		EQU	$280C	;Rutina de Demora (usa parametros[A][X])

;******************************************************************************
;       SyHDe - Soft y Hard Desarrollos, 2000  - Derechos Reservados -
; Ud.uede usar este archivo gratuitamente mientras incluya este pie de pagina
;******************************************************************************

