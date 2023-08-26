	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 13, 0	sdk_version 13, 3
	.globl	_ft_swap                        ; -- Begin function ft_swap
	.p2align	2
_ft_swap:                               ; @ft_swap
Lfunc_begin0:
	.file	1 "/Users/anseungwon/dev/C-Practice/cs/stack" "call_by.c"
	.loc	1 4 0                           ; call_by.c:4:0
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #32
	.cfi_def_cfa_offset 32
	str	x0, [sp, #24]
	str	x1, [sp, #16]
Ltmp1:
	.loc	1 7 10 prologue_end             ; call_by.c:7:10
	ldr	x8, [sp, #24]
	.loc	1 7 9 is_stmt 0                 ; call_by.c:7:9
	ldr	w8, [x8]
	.loc	1 7 7                           ; call_by.c:7:7
	str	w8, [sp, #12]
	.loc	1 8 9 is_stmt 1                 ; call_by.c:8:9
	ldr	x8, [sp, #16]
	.loc	1 8 8 is_stmt 0                 ; call_by.c:8:8
	ldr	w8, [x8]
	.loc	1 8 3                           ; call_by.c:8:3
	ldr	x9, [sp, #24]
	.loc	1 8 6                           ; call_by.c:8:6
	str	w8, [x9]
	.loc	1 9 8 is_stmt 1                 ; call_by.c:9:8
	ldr	w8, [sp, #12]
	.loc	1 9 3 is_stmt 0                 ; call_by.c:9:3
	ldr	x9, [sp, #16]
	.loc	1 9 6                           ; call_by.c:9:6
	str	w8, [x9]
	.loc	1 10 1 is_stmt 1                ; call_by.c:10:1
	add	sp, sp, #32
	ret
Ltmp2:
Lfunc_end0:
	.cfi_endproc
                                        ; -- End function
	.globl	_main                           ; -- Begin function main
	.p2align	2
_main:                                  ; @main
Lfunc_begin1:
	.loc	1 13 0                          ; call_by.c:13:0
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #48
	.cfi_def_cfa_offset 48
	stp	x29, x30, [sp, #32]             ; 16-byte Folded Spill
	add	x29, sp, #32
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	mov	w8, #0
	str	w8, [sp, #16]                   ; 4-byte Folded Spill
	stur	wzr, [x29, #-4]
	sub	x0, x29, #8
	mov	w8, #3
Ltmp3:
	.loc	1 14 6 prologue_end             ; call_by.c:14:6
	stur	w8, [x29, #-8]
	sub	x1, x29, #12
	mov	w8, #4
	.loc	1 14 13 is_stmt 0               ; call_by.c:14:13
	stur	w8, [x29, #-12]
	.loc	1 15 2 is_stmt 1                ; call_by.c:15:2
	bl	_ft_swap
	.loc	1 16 29                         ; call_by.c:16:29
	ldur	w8, [x29, #-8]
                                        ; implicit-def: $x10
	mov	x10, x8
	.loc	1 16 32 is_stmt 0               ; call_by.c:16:32
	ldur	w9, [x29, #-12]
                                        ; implicit-def: $x8
	mov	x8, x9
	.loc	1 16 2                          ; call_by.c:16:2
	mov	x9, sp
	str	x10, [x9]
	str	x8, [x9, #8]
	.loc	1 0 0                           ; call_by.c:0:0
	adrp	x0, l_.str@PAGE
	add	x0, x0, l_.str@PAGEOFF
	.loc	1 16 2                          ; call_by.c:16:2
	bl	_printf
	ldr	w0, [sp, #16]                   ; 4-byte Folded Reload
	.loc	1 17 2 is_stmt 1                ; call_by.c:17:2
	ldp	x29, x30, [sp, #32]             ; 16-byte Folded Reload
	add	sp, sp, #48
	ret
Ltmp4:
Lfunc_end1:
	.cfi_endproc
                                        ; -- End function
	.section	__TEXT,__cstring,cstring_literals
l_.str:                                 ; @.str
	.asciz	"x = %d, y = %d\n"

	.section	__DWARF,__debug_abbrev,regular,debug
Lsection_abbrev:
	.byte	1                               ; Abbreviation Code
	.byte	17                              ; DW_TAG_compile_unit
	.byte	1                               ; DW_CHILDREN_yes
	.byte	37                              ; DW_AT_producer
	.byte	14                              ; DW_FORM_strp
	.byte	19                              ; DW_AT_language
	.byte	5                               ; DW_FORM_data2
	.byte	3                               ; DW_AT_name
	.byte	14                              ; DW_FORM_strp
	.ascii	"\202|"                         ; DW_AT_LLVM_sysroot
	.byte	14                              ; DW_FORM_strp
	.byte	16                              ; DW_AT_stmt_list
	.byte	23                              ; DW_FORM_sec_offset
	.byte	27                              ; DW_AT_comp_dir
	.byte	14                              ; DW_FORM_strp
	.byte	17                              ; DW_AT_low_pc
	.byte	1                               ; DW_FORM_addr
	.byte	18                              ; DW_AT_high_pc
	.byte	6                               ; DW_FORM_data4
	.byte	0                               ; EOM(1)
	.byte	0                               ; EOM(2)
	.byte	2                               ; Abbreviation Code
	.byte	46                              ; DW_TAG_subprogram
	.byte	1                               ; DW_CHILDREN_yes
	.byte	17                              ; DW_AT_low_pc
	.byte	1                               ; DW_FORM_addr
	.byte	18                              ; DW_AT_high_pc
	.byte	6                               ; DW_FORM_data4
	.ascii	"\347\177"                      ; DW_AT_APPLE_omit_frame_ptr
	.byte	25                              ; DW_FORM_flag_present
	.byte	64                              ; DW_AT_frame_base
	.byte	24                              ; DW_FORM_exprloc
	.byte	3                               ; DW_AT_name
	.byte	14                              ; DW_FORM_strp
	.byte	58                              ; DW_AT_decl_file
	.byte	11                              ; DW_FORM_data1
	.byte	59                              ; DW_AT_decl_line
	.byte	11                              ; DW_FORM_data1
	.byte	39                              ; DW_AT_prototyped
	.byte	25                              ; DW_FORM_flag_present
	.byte	63                              ; DW_AT_external
	.byte	25                              ; DW_FORM_flag_present
	.byte	0                               ; EOM(1)
	.byte	0                               ; EOM(2)
	.byte	3                               ; Abbreviation Code
	.byte	5                               ; DW_TAG_formal_parameter
	.byte	0                               ; DW_CHILDREN_no
	.byte	2                               ; DW_AT_location
	.byte	24                              ; DW_FORM_exprloc
	.byte	3                               ; DW_AT_name
	.byte	14                              ; DW_FORM_strp
	.byte	58                              ; DW_AT_decl_file
	.byte	11                              ; DW_FORM_data1
	.byte	59                              ; DW_AT_decl_line
	.byte	11                              ; DW_FORM_data1
	.byte	73                              ; DW_AT_type
	.byte	19                              ; DW_FORM_ref4
	.byte	0                               ; EOM(1)
	.byte	0                               ; EOM(2)
	.byte	4                               ; Abbreviation Code
	.byte	52                              ; DW_TAG_variable
	.byte	0                               ; DW_CHILDREN_no
	.byte	2                               ; DW_AT_location
	.byte	24                              ; DW_FORM_exprloc
	.byte	3                               ; DW_AT_name
	.byte	14                              ; DW_FORM_strp
	.byte	58                              ; DW_AT_decl_file
	.byte	11                              ; DW_FORM_data1
	.byte	59                              ; DW_AT_decl_line
	.byte	11                              ; DW_FORM_data1
	.byte	73                              ; DW_AT_type
	.byte	19                              ; DW_FORM_ref4
	.byte	0                               ; EOM(1)
	.byte	0                               ; EOM(2)
	.byte	5                               ; Abbreviation Code
	.byte	46                              ; DW_TAG_subprogram
	.byte	1                               ; DW_CHILDREN_yes
	.byte	17                              ; DW_AT_low_pc
	.byte	1                               ; DW_FORM_addr
	.byte	18                              ; DW_AT_high_pc
	.byte	6                               ; DW_FORM_data4
	.byte	64                              ; DW_AT_frame_base
	.byte	24                              ; DW_FORM_exprloc
	.byte	3                               ; DW_AT_name
	.byte	14                              ; DW_FORM_strp
	.byte	58                              ; DW_AT_decl_file
	.byte	11                              ; DW_FORM_data1
	.byte	59                              ; DW_AT_decl_line
	.byte	11                              ; DW_FORM_data1
	.byte	39                              ; DW_AT_prototyped
	.byte	25                              ; DW_FORM_flag_present
	.byte	73                              ; DW_AT_type
	.byte	19                              ; DW_FORM_ref4
	.byte	63                              ; DW_AT_external
	.byte	25                              ; DW_FORM_flag_present
	.byte	0                               ; EOM(1)
	.byte	0                               ; EOM(2)
	.byte	6                               ; Abbreviation Code
	.byte	36                              ; DW_TAG_base_type
	.byte	0                               ; DW_CHILDREN_no
	.byte	3                               ; DW_AT_name
	.byte	14                              ; DW_FORM_strp
	.byte	62                              ; DW_AT_encoding
	.byte	11                              ; DW_FORM_data1
	.byte	11                              ; DW_AT_byte_size
	.byte	11                              ; DW_FORM_data1
	.byte	0                               ; EOM(1)
	.byte	0                               ; EOM(2)
	.byte	7                               ; Abbreviation Code
	.byte	15                              ; DW_TAG_pointer_type
	.byte	0                               ; DW_CHILDREN_no
	.byte	73                              ; DW_AT_type
	.byte	19                              ; DW_FORM_ref4
	.byte	0                               ; EOM(1)
	.byte	0                               ; EOM(2)
	.byte	0                               ; EOM(3)
	.section	__DWARF,__debug_info,regular,debug
Lsection_info:
Lcu_begin0:
.set Lset0, Ldebug_info_end0-Ldebug_info_start0 ; Length of Unit
	.long	Lset0
Ldebug_info_start0:
	.short	4                               ; DWARF version number
.set Lset1, Lsection_abbrev-Lsection_abbrev ; Offset Into Abbrev. Section
	.long	Lset1
	.byte	8                               ; Address Size (in bytes)
	.byte	1                               ; Abbrev [1] 0xb:0xa6 DW_TAG_compile_unit
	.long	0                               ; DW_AT_producer
	.short	12                              ; DW_AT_language
	.long	50                              ; DW_AT_name
	.long	60                              ; DW_AT_LLVM_sysroot
.set Lset2, Lline_table_start0-Lsection_line ; DW_AT_stmt_list
	.long	Lset2
	.long	62                              ; DW_AT_comp_dir
	.quad	Lfunc_begin0                    ; DW_AT_low_pc
.set Lset3, Lfunc_end1-Lfunc_begin0     ; DW_AT_high_pc
	.long	Lset3
	.byte	2                               ; Abbrev [2] 0x2e:0x40 DW_TAG_subprogram
	.quad	Lfunc_begin0                    ; DW_AT_low_pc
.set Lset4, Lfunc_end0-Lfunc_begin0     ; DW_AT_high_pc
	.long	Lset4
                                        ; DW_AT_APPLE_omit_frame_ptr
	.byte	1                               ; DW_AT_frame_base
	.byte	111
	.long	104                             ; DW_AT_name
	.byte	1                               ; DW_AT_decl_file
	.byte	3                               ; DW_AT_decl_line
                                        ; DW_AT_prototyped
                                        ; DW_AT_external
	.byte	3                               ; Abbrev [3] 0x43:0xe DW_TAG_formal_parameter
	.byte	2                               ; DW_AT_location
	.byte	145
	.byte	24
	.long	121                             ; DW_AT_name
	.byte	1                               ; DW_AT_decl_file
	.byte	3                               ; DW_AT_decl_line
	.long	171                             ; DW_AT_type
	.byte	3                               ; Abbrev [3] 0x51:0xe DW_TAG_formal_parameter
	.byte	2                               ; DW_AT_location
	.byte	145
	.byte	16
	.long	124                             ; DW_AT_name
	.byte	1                               ; DW_AT_decl_file
	.byte	3                               ; DW_AT_decl_line
	.long	171                             ; DW_AT_type
	.byte	4                               ; Abbrev [4] 0x5f:0xe DW_TAG_variable
	.byte	2                               ; DW_AT_location
	.byte	145
	.byte	12
	.long	127                             ; DW_AT_name
	.byte	1                               ; DW_AT_decl_file
	.byte	5                               ; DW_AT_decl_line
	.long	164                             ; DW_AT_type
	.byte	0                               ; End Of Children Mark
	.byte	5                               ; Abbrev [5] 0x6e:0x36 DW_TAG_subprogram
	.quad	Lfunc_begin1                    ; DW_AT_low_pc
.set Lset5, Lfunc_end1-Lfunc_begin1     ; DW_AT_high_pc
	.long	Lset5
	.byte	1                               ; DW_AT_frame_base
	.byte	109
	.long	112                             ; DW_AT_name
	.byte	1                               ; DW_AT_decl_file
	.byte	12                              ; DW_AT_decl_line
                                        ; DW_AT_prototyped
	.long	164                             ; DW_AT_type
                                        ; DW_AT_external
	.byte	4                               ; Abbrev [4] 0x87:0xe DW_TAG_variable
	.byte	2                               ; DW_AT_location
	.byte	145
	.byte	120
	.long	132                             ; DW_AT_name
	.byte	1                               ; DW_AT_decl_file
	.byte	14                              ; DW_AT_decl_line
	.long	164                             ; DW_AT_type
	.byte	4                               ; Abbrev [4] 0x95:0xe DW_TAG_variable
	.byte	2                               ; DW_AT_location
	.byte	145
	.byte	116
	.long	134                             ; DW_AT_name
	.byte	1                               ; DW_AT_decl_file
	.byte	14                              ; DW_AT_decl_line
	.long	164                             ; DW_AT_type
	.byte	0                               ; End Of Children Mark
	.byte	6                               ; Abbrev [6] 0xa4:0x7 DW_TAG_base_type
	.long	117                             ; DW_AT_name
	.byte	5                               ; DW_AT_encoding
	.byte	4                               ; DW_AT_byte_size
	.byte	7                               ; Abbrev [7] 0xab:0x5 DW_TAG_pointer_type
	.long	164                             ; DW_AT_type
	.byte	0                               ; End Of Children Mark
Ldebug_info_end0:
	.section	__DWARF,__debug_str,regular,debug
Linfo_string:
	.asciz	"Apple clang version 14.0.3 (clang-1403.0.22.14.1)" ; string offset=0
	.asciz	"call_by.c"                     ; string offset=50
	.asciz	"/"                             ; string offset=60
	.asciz	"/Users/anseungwon/dev/C-Practice/cs/stack" ; string offset=62
	.asciz	"ft_swap"                       ; string offset=104
	.asciz	"main"                          ; string offset=112
	.asciz	"int"                           ; string offset=117
	.asciz	"pA"                            ; string offset=121
	.asciz	"pB"                            ; string offset=124
	.asciz	"nTmp"                          ; string offset=127
	.asciz	"x"                             ; string offset=132
	.asciz	"y"                             ; string offset=134
	.section	__DWARF,__apple_names,regular,debug
Lnames_begin:
	.long	1212240712                      ; Header Magic
	.short	1                               ; Header Version
	.short	0                               ; Header Hash Function
	.long	2                               ; Header Bucket Count
	.long	2                               ; Header Hash Count
	.long	12                              ; Header Data Length
	.long	0                               ; HeaderData Die Offset Base
	.long	1                               ; HeaderData Atom Count
	.short	1                               ; DW_ATOM_die_offset
	.short	6                               ; DW_FORM_data4
	.long	0                               ; Bucket 0
	.long	1                               ; Bucket 1
	.long	2090499946                      ; Hash in Bucket 0
	.long	-989697575                      ; Hash in Bucket 1
.set Lset6, LNames1-Lnames_begin        ; Offset in Bucket 0
	.long	Lset6
.set Lset7, LNames0-Lnames_begin        ; Offset in Bucket 1
	.long	Lset7
LNames1:
	.long	112                             ; main
	.long	1                               ; Num DIEs
	.long	110
	.long	0
LNames0:
	.long	104                             ; ft_swap
	.long	1                               ; Num DIEs
	.long	46
	.long	0
	.section	__DWARF,__apple_objc,regular,debug
Lobjc_begin:
	.long	1212240712                      ; Header Magic
	.short	1                               ; Header Version
	.short	0                               ; Header Hash Function
	.long	1                               ; Header Bucket Count
	.long	0                               ; Header Hash Count
	.long	12                              ; Header Data Length
	.long	0                               ; HeaderData Die Offset Base
	.long	1                               ; HeaderData Atom Count
	.short	1                               ; DW_ATOM_die_offset
	.short	6                               ; DW_FORM_data4
	.long	-1                              ; Bucket 0
	.section	__DWARF,__apple_namespac,regular,debug
Lnamespac_begin:
	.long	1212240712                      ; Header Magic
	.short	1                               ; Header Version
	.short	0                               ; Header Hash Function
	.long	1                               ; Header Bucket Count
	.long	0                               ; Header Hash Count
	.long	12                              ; Header Data Length
	.long	0                               ; HeaderData Die Offset Base
	.long	1                               ; HeaderData Atom Count
	.short	1                               ; DW_ATOM_die_offset
	.short	6                               ; DW_FORM_data4
	.long	-1                              ; Bucket 0
	.section	__DWARF,__apple_types,regular,debug
Ltypes_begin:
	.long	1212240712                      ; Header Magic
	.short	1                               ; Header Version
	.short	0                               ; Header Hash Function
	.long	1                               ; Header Bucket Count
	.long	1                               ; Header Hash Count
	.long	20                              ; Header Data Length
	.long	0                               ; HeaderData Die Offset Base
	.long	3                               ; HeaderData Atom Count
	.short	1                               ; DW_ATOM_die_offset
	.short	6                               ; DW_FORM_data4
	.short	3                               ; DW_ATOM_die_tag
	.short	5                               ; DW_FORM_data2
	.short	4                               ; DW_ATOM_type_flags
	.short	11                              ; DW_FORM_data1
	.long	0                               ; Bucket 0
	.long	193495088                       ; Hash in Bucket 0
.set Lset8, Ltypes0-Ltypes_begin        ; Offset in Bucket 0
	.long	Lset8
Ltypes0:
	.long	117                             ; int
	.long	1                               ; Num DIEs
	.long	164
	.short	36
	.byte	0
	.long	0
.subsections_via_symbols
	.section	__DWARF,__debug_line,regular,debug
Lsection_line:
Lline_table_start0:
