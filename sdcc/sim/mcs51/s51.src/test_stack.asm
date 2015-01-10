;--------------------------------------------------------
; File Created by SDCC : FreeWare ANSI-C Compiler
; Version 2.1.9Fa Sat Jan  8 13:27:23 2000

;--------------------------------------------------------
	.module test_stack
;--------------------------------------------------------
; publics variables in this module
;--------------------------------------------------------
	.globl _main
	.globl _jaj
;--------------------------------------------------------
; special function registers
;--------------------------------------------------------
;--------------------------------------------------------
; special function bits 
;--------------------------------------------------------
;--------------------------------------------------------
; internal ram data
;--------------------------------------------------------
	.area	DSEG    (DATA)
;--------------------------------------------------------
; overlayable items in internal ram 
;--------------------------------------------------------
	.area	OSEG	(OVR,DATA)
;--------------------------------------------------------
; Stack segment in internal ram 
;--------------------------------------------------------
	.area	SSEG	(DATA)
__start__stack:
	.ds	1

;--------------------------------------------------------
; indirectly addressable internal ram data
;--------------------------------------------------------
	.area	ISEG    (DATA)
;--------------------------------------------------------
; bit data
;--------------------------------------------------------
	.area	BSEG    (BIT)
;--------------------------------------------------------
; external ram data
;--------------------------------------------------------
	.area	XSEG    (XDATA)
;--------------------------------------------------------
; interrupt vector 
;--------------------------------------------------------
	.area	CODE (CODE)
__interrupt_vect:
	ljmp	__sdcc_gsinit_startup
	reti
	.ds	7
	reti
	.ds	7
	reti
	.ds	7
	reti
	.ds	7
	reti
	.ds	7
	reti
	.ds	7
;--------------------------------------------------------
; global & static initialisations
;--------------------------------------------------------
	.area GSINIT (CODE)
__sdcc_gsinit_startup:
	mov	sp,#7
	lcall	__sdcc_external_startup
	mov	a,dpl
	jz	__sdcc_init_data
	ljmp	__sdcc_program_startup
__sdcc_init_data:
;--------------------------------------------------------
; code
;--------------------------------------------------------
	.area CSEG (CODE)
__sdcc_program_startup:
	lcall	_main
;	return from main will lock up
	ljmp  .
	G$jaj$0$0 ==.
	C$test_stack.c$1$0$0 ==.
;  test_stack.c 1
;  -----------------------------------------
;   function jaj
;  -----------------------------------------
_jaj:
	ar2 = 0x02
	ar3 = 0x03
	ar4 = 0x04
	ar5 = 0x05
	ar6 = 0x06
	ar7 = 0x07
	ar0 = 0x00
	ar1 = 0x01
	C$test_stack.c$3$1$1 ==.
;  test_stack.c 3
	lcall  _jaj
00101$:
	C$test_stack.c$4$1$1 ==.
	XG$jaj$0$0 ==.
	ret  
	G$main$0$0 ==.
	C$test_stack.c$6$1$1 ==.
;  test_stack.c 6
;  -----------------------------------------
;   function main
;  -----------------------------------------
_main:
	C$test_stack.c$8$1$1 ==.
;  test_stack.c 8
	lcall  _jaj
00101$:
	C$test_stack.c$9$1$1 ==.
	XG$main$0$0 ==.
	ret  
	.area	CSEG    (CODE)
