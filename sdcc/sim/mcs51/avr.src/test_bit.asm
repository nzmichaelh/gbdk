	ldi	r17,0
	sbi	0,0
	sbis	0,0
	ldi	r17,1
	cbi	0,0
	sbis	0,0
	ldi	r17,2
	nop
	
	ldi	r17,0
	cbi	0,0
	sbic	0,0
	ldi	r17,1
	sbi	0,0
	sbic	0,0
	ldi	r17,2
	nop
	
	clr	r0
	out	$3f,r0
	
	sec
	sen
	sez
	sei
	ses
	sev
	set
	seh

	;ld	sreg,$ff

	clc
	cln
	clz
	cli
	cls
	clv
	clt
	clh

	nop

	sbi	0,0
	sbi	0,1
	sbi	0,2
	sbi	0,3
	sbi	0,4
	sbi	0,5
	sbi	0,6
	sbi	0,7
	nop
	sbi	$10,4
	sbi	$1f,7
	nop
	cbi	0,0
	cbi	0,1
	cbi	0,2
	cbi	0,3
	cbi	0,4
	cbi	0,5
	cbi	0,6
	cbi	0,7

	nop
	