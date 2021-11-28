section .text
global _ft_strlen

; rdi = s1

_ft_strlen:
	push rdi
	xor rax, rax ; i = 0
	jmp while
increment:
	inc rax ; i++;
while:
	cmp [rdi + rax], byte 0 ; str[i] == 0;
	jne increment
exit:
	pop rdi
	ret


