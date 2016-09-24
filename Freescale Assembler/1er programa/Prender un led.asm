RAM_INI         EQU     $0080   ; DONDE COMIENZA LA MEMORIA RAM
FLASH_INI       EQU     $EE00   ; DONDE COMIENZA LA MEMORIA FLASH
VECTORES        EQU     $FFD0   ; Comienzo de vectores

$base 10t                       ; Base decimal por default
$Include 'QTQY_Registers.inc'

        org     FLASH_INI
start:
        rsp                     ; reseteo stack pointer
        clra                    ; Limpio registros
        clrh
        clrx
        sei                     ; deshabilito instrucciones porque no uso pulsador

        mov     #%10000000,CONFIG2      ;configuro el registro config2 mirar datasheet
        mov     #%00001001,CONFIG1      ;deshabilito el cop y el lvi trabaja con 5v
        nop
        
        mov     #%11111111,DDRB         ; todos los pines del puerto B como salida
        mov     #%11111111,PORTB        ; por el pin del puerto B sale 1
        
        
start_00:
         
        bclr            0,PORTB         ; pongo 0 en todos los pin 

demora:
        ldx             #$FF            ;cargo con todo 1 los bits del reg X. El ciclo de maq es[2]

delay_2:
        lda             #$FF            ;cargo con todo 1 los bits del reg A.  El ciclo de maq es[2]


delay_1:
        deca                            ; [1] Decrece A.
        bne             delay_1         ; [3] Branch si... compara con algo y salta si no es igual.
        decx                            ; [1] Decrece X.
        bne             delay_2         ; [3] 
        
        bset            0,PORTB         ; Para apagar el led
        bra             start_00        ; Sirve para saltar a la etiqueta
        
end
                      








