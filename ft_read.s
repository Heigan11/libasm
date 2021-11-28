section .text
global _ft_read
extern ___error

; fd = rdi, str = rsi, len = rdx

_ft_read:
	mov rax, 0x2000003 ; syscall read (3)
	syscall
	jc error ; if flag -> error
	jmp return ; if !flag -> return rax = len

error:
	push rax ; stack rax
	call ___error ; rax<-errno
	pop qword [rax] ; free rax
	xor rax, rax ; rax = 0
	dec rax ; rax = -1
	jmp return

return:
	ret
