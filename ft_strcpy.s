section .text
global _ft_strcpy

_ft_strcpy:
	push rax ; var for return
	push rcx ; counter
	push rdi ; dst - first param
	push rsi ; src - second param
	push rdx ; buffer
	cmp rdi, 0 ; dst == 0 ?
	je return ; jump if equal
	cmp rsi, 0 ; src == 0 ?
	je return ; jump if equal
	mov rcx, 0 ; i = 0
	mov rdx, 0 ; in here dl, dl = 8 bit = 1 char
	jmp cycle

increment:
	inc rcx ; i++;

cycle:
	mov dl, byte [rsi + rcx] ; dst[i] <- src[i]
	mov byte [rdi + rcx], dl
	cmp dl, 0 ; src[i] == '\0' ?
	jne increment ; i++;

return:
	mov rax, rdi ; return dst
	pop rdx
	pop rsi
	pop rdi
	pop rcx
	pop rax
	ret
