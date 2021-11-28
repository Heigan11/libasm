section .text
global _ft_strcmp

; s1 = rdi, s2 = rsi

_ft_strcmp:
	push rbx ; buf
	push rcx ; counter
	push rdi ; s1
	push rsi ; s2
	xor rcx, rcx ; i = 0
	jmp cycle

increment:
	inc rcx ; i++;

cycle:
	mov al, byte [rdi + rcx] ; s1[i] -> buf
	mov bl, byte [rsi + rcx] ; s2[i] -> buf
	cmp al, 0 ; s1[i] == "\0" ?
	je return
	cmp bl, 0 ; s2[i] == "\0" ?
	je return
	cmp al, bl ; s1[i] == s2[i] ?
	je increment ; if s1[i] == s2[i] -> i++

return:
	sub rax, rbx ; s1[i] - s2[i]
	pop rsi
	pop rdi
	pop rcx
	pop rbx
	ret


