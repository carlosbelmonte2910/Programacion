*******************************************************************************
* 			PROG_MODUL_QTQYA - ARCHIVO INCLUDE
* Contiene la Programacion de los Modulos del MC68HC908QTxxA/QYxxA
*******************************************************************************
prog_modulos:
;-------------- Programo el CONFIG --------------------------------------------

	mov	#%10000000,CONFIG2	;Configuracion del registro
;		   \\\\\\\\_____________;RSTEN= 0 Funcion inactiva en pin
;		    \\\\\\\_____________;OSCENINSTOP= 0 Oscilador desab en STOP
;		     \\\\\\_____________;none
;		      \\\\\_____________;none
;		       \\\\_____________;none
;		        \\\_____________;none
;		         \\_____________;IRQEN= 0 IRQ desabilitada
;		          \_____________;IRQPUD= 1 Pull Up desconectada


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


;	mov     #$20,oscsc	        ; OSCILLATOR STATUS & CONTROL REGISTER
;		   \\\\\\\\_____________;ECGST= Read Only
;		    \\\\\\\_____________;ECGON= 0 Oscilador Externo desabilitado
;		     \\\\\\_____________;ECFS0= 0 \ 00= Xtal Externo 8-32 MHz
;		      \\\\\_____________;ECFS1= 0 /
;		       \\\\_____________;ICFS0= 0 \ 10= Osc 12.8 MHz
;		        \\\_____________;ICSF1= 1 /
;		         \\_____________;OSCOPT0= 0 \ 00= Oscilador Interno
;		          \_____________;OSCOPT1= 0 /

	mov	#$81,OSCTRIM		;Ajuste Fino del Oscilador

;-------------- Programacion del OSCILADOR No Version A -----------------------
;	mov	#%00000000,OSCSTAT	; OSCILLATOR STATUS REGISTER
;
;------------------------------------------------------------------------------
	jsr	demora_qy		;Demora de 81,761 mseg
	jsr	demora_qy		;Demora de 81,761 mseg
	jsr	demora_qy		;Demora de 81,761 mseg
	jsr	demora_qy		;Demora de 81,761 mseg
	jsr	demora_qy		;Demora de 81,761 mseg
	jsr	demora_qy		;Demora de 81,761 mseg



	rts
