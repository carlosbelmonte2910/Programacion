start_00:
	mov	#$01,CONT0	;78=120dec
	mov	#$0F,aumento1
cambio:
	bset	0,portb
	jsr	retardo_1s
	bclr	0,portb
	jsr	retardo_1s
	sei
	mov	#$36,TSC
	nop
	nop
	inc	aumento1
	nop
	nop
	mov	#aumento1,TCH0L
	nop
	nop
	mov	#$06,TSC
	cli
	jsr	retardo_100ms
	dec	CONT0
	clra
	cbeq	CONT0,sigue_sigue
	bra	cambio
sigue_sigue:

bucle_a:
	bset	7,portb
	jsr	retardo_1s
	bclr	7,portb
	jsr	retardo_1s

	bra 	bucle_a

	bra	start_00



