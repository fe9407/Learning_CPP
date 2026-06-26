	.file	"matriz_random.cpp"
	.text
#APP
	.globl _ZSt21ios_base_library_initv
#NO_APP
	.section	.rodata
	.align 4
	.type	_ZL1n, @object
	.size	_ZL1n, 4
_ZL1n:
	.long	5
.LC0:
	.string	"Matriz A: \n\n"
.LC1:
	.string	"Matriz B: \n\n"
.LC2:
	.string	"Matriz C: \n\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB1984:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$384, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$0, -376(%rbp)
	jmp	.L2
.L5:
	movl	$0, -372(%rbp)
	jmp	.L3
.L4:
	call	rand@PLT
	movslq	%eax, %rdx
	imulq	$1374389535, %rdx, %rdx
	shrq	$32, %rdx
	sarl	$5, %edx
	movl	%eax, %ecx
	sarl	$31, %ecx
	subl	%ecx, %edx
	imull	$100, %edx, %ecx
	subl	%ecx, %eax
	movl	%eax, %edx
	movl	-372(%rbp), %eax
	movslq	%eax, %rsi
	movl	-376(%rbp), %eax
	movslq	%eax, %rcx
	movq	%rcx, %rax
	salq	$2, %rax
	addq	%rcx, %rax
	addq	%rsi, %rax
	movl	%edx, -336(%rbp,%rax,4)
	call	rand@PLT
	movslq	%eax, %rdx
	imulq	$1374389535, %rdx, %rdx
	shrq	$32, %rdx
	sarl	$5, %edx
	movl	%eax, %ecx
	sarl	$31, %ecx
	subl	%ecx, %edx
	imull	$100, %edx, %ecx
	subl	%ecx, %eax
	movl	%eax, %edx
	movl	-372(%rbp), %eax
	movslq	%eax, %rsi
	movl	-376(%rbp), %eax
	movslq	%eax, %rcx
	movq	%rcx, %rax
	salq	$2, %rax
	addq	%rcx, %rax
	addq	%rsi, %rax
	movl	%edx, -224(%rbp,%rax,4)
	addl	$1, -372(%rbp)
.L3:
	cmpl	$4, -372(%rbp)
	jle	.L4
	addl	$1, -376(%rbp)
.L2:
	cmpl	$4, -376(%rbp)
	jle	.L5
	movl	$0, -368(%rbp)
	jmp	.L6
.L11:
	movl	$0, -364(%rbp)
	jmp	.L7
.L10:
	movl	-364(%rbp), %eax
	movslq	%eax, %rcx
	movl	-368(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	salq	$2, %rax
	addq	%rdx, %rax
	addq	%rcx, %rax
	movl	-336(%rbp,%rax,4), %ecx
	movl	-364(%rbp), %eax
	movslq	%eax, %rsi
	movl	-368(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	salq	$2, %rax
	addq	%rdx, %rax
	addq	%rsi, %rax
	movl	-224(%rbp,%rax,4), %eax
	cmpl	%eax, %ecx
	jle	.L8
	movl	-364(%rbp), %eax
	movslq	%eax, %rcx
	movl	-368(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	salq	$2, %rax
	addq	%rdx, %rax
	addq	%rcx, %rax
	movl	-336(%rbp,%rax,4), %ecx
	movl	-364(%rbp), %eax
	movslq	%eax, %rsi
	movl	-368(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	salq	$2, %rax
	addq	%rdx, %rax
	addq	%rsi, %rax
	movl	%ecx, -112(%rbp,%rax,4)
	jmp	.L9
.L8:
	movl	-364(%rbp), %eax
	movslq	%eax, %rcx
	movl	-368(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	salq	$2, %rax
	addq	%rdx, %rax
	addq	%rcx, %rax
	movl	-224(%rbp,%rax,4), %ecx
	movl	-364(%rbp), %eax
	movslq	%eax, %rsi
	movl	-368(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	salq	$2, %rax
	addq	%rdx, %rax
	addq	%rsi, %rax
	movl	%ecx, -112(%rbp,%rax,4)
.L9:
	addl	$1, -364(%rbp)
.L7:
	cmpl	$4, -364(%rbp)
	jle	.L10
	addl	$1, -368(%rbp)
.L6:
	cmpl	$4, -368(%rbp)
	jle	.L11
	leaq	.LC0(%rip), %rdx
	leaq	_ZSt4cout(%rip), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movl	$0, -360(%rbp)
	jmp	.L12
.L15:
	movl	$0, -356(%rbp)
	jmp	.L13
.L14:
	movl	-356(%rbp), %eax
	movslq	%eax, %rcx
	movl	-360(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	salq	$2, %rax
	addq	%rdx, %rax
	addq	%rcx, %rax
	movl	-336(%rbp,%rax,4), %eax
	leaq	_ZSt4cout(%rip), %rdx
	movl	%eax, %esi
	movq	%rdx, %rdi
	call	_ZNSolsEi@PLT
	movl	$32, %esi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_c@PLT
	addl	$1, -356(%rbp)
.L13:
	cmpl	$4, -356(%rbp)
	jle	.L14
	leaq	_ZSt4cout(%rip), %rax
	movl	$10, %esi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_c@PLT
	addl	$1, -360(%rbp)
.L12:
	cmpl	$4, -360(%rbp)
	jle	.L15
	leaq	.LC1(%rip), %rdx
	leaq	_ZSt4cout(%rip), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movl	$0, -352(%rbp)
	jmp	.L16
.L19:
	movl	$0, -348(%rbp)
	jmp	.L17
.L18:
	movl	-348(%rbp), %eax
	movslq	%eax, %rcx
	movl	-352(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	salq	$2, %rax
	addq	%rdx, %rax
	addq	%rcx, %rax
	movl	-224(%rbp,%rax,4), %eax
	leaq	_ZSt4cout(%rip), %rdx
	movl	%eax, %esi
	movq	%rdx, %rdi
	call	_ZNSolsEi@PLT
	movl	$32, %esi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_c@PLT
	addl	$1, -348(%rbp)
.L17:
	cmpl	$4, -348(%rbp)
	jle	.L18
	leaq	_ZSt4cout(%rip), %rax
	movl	$10, %esi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_c@PLT
	addl	$1, -352(%rbp)
.L16:
	cmpl	$4, -352(%rbp)
	jle	.L19
	leaq	.LC2(%rip), %rdx
	leaq	_ZSt4cout(%rip), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movl	$0, -344(%rbp)
	jmp	.L20
.L23:
	movl	$0, -340(%rbp)
	jmp	.L21
.L22:
	movl	-340(%rbp), %eax
	movslq	%eax, %rcx
	movl	-344(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	salq	$2, %rax
	addq	%rdx, %rax
	addq	%rcx, %rax
	movl	-112(%rbp,%rax,4), %eax
	leaq	_ZSt4cout(%rip), %rdx
	movl	%eax, %esi
	movq	%rdx, %rdi
	call	_ZNSolsEi@PLT
	movl	$32, %esi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_c@PLT
	addl	$1, -340(%rbp)
.L21:
	cmpl	$4, -340(%rbp)
	jle	.L22
	leaq	_ZSt4cout(%rip), %rax
	movl	$10, %esi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_c@PLT
	addl	$1, -344(%rbp)
.L20:
	cmpl	$4, -344(%rbp)
	jle	.L23
	movl	$0, %eax
	movq	-8(%rbp), %rdx
	subq	%fs:40, %rdx
	je	.L25
	call	__stack_chk_fail@PLT
.L25:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1984:
	.size	main, .-main
	.ident	"GCC: (GNU) 15.2.1 20250813"
	.section	.note.GNU-stack,"",@progbits
