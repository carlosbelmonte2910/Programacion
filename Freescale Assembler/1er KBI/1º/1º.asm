RAM_INI         EQU     $0080
FLASH_INI       EQU     $EE00
VECTORES        EQU     $FFDE
LED_1           EQU     7
LED_2           EQU     6
LED_3           EQU     5
LED_4           EQU     4


$base   10t
$include   'QTQY_Registers.inc'

                org     FLASH_INI
start:
                rsp
                clra
                clrh
                clrx
                sei


                mov	#%10000000,CONFIG2
                mov	#%00001101,CONFIG1
                nop
                nop
                nop

                mov	#%00100000,OSCSC
                mov	#$81,OSCTRIM

                jsr	demora_qy
                jsr	demora_qy
                jsr	demora_qy
                jsr	demora_qy
                jsr	demora_qy
                jsr	demora_qy

                mov     #%11111111,DDRB
                mov	#%11111111,PORTB
                nop
                nop
                nop

                mov	#%00000010,kbscr
                mov	#%00000001,kbier
                mov	#%00000000,kbscr
                cli

start_00:

                bclr    led_1,PORTB
                jsr	demora_1000ms
                bset    led_1,PORTB
                jsr	demora_1000ms

                jmp     start_00
demora_qy:
                ldx	#$ff
dem_2:
                lda	#$ff
dem_1:
                deca
                bne	dem_1
                decx
