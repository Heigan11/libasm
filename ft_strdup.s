section .text
global _ft_strdup
extern	_ft_strlen
extern _malloc
extern	_ft_strcpy

; s1 = rdi

_ft_strdup:
	cmp rdi, 0 ; s1 == NULL ?
	je ret_null ; if s1 == NULL -> return(0)
	mov rbx, rdi ; save addres rdi(s1)

	call _ft_strlen ; rax = len s1

	push rdi
	mov rdi, rax
	call _malloc
	pop rdi
	cmp rax, 0 ; malloc == NULL ?
	je ret_null ; if s2 == NULL -> return(0) rax = s2

	mov rsi, rbx ; rsi <- s1
	mov	rdi, rax ; rdi <- s2
	call _ft_strcpy
	ret

ret_null:
	xor rax, rax
	ret
