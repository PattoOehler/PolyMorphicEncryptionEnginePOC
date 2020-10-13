BITS 64


mov rax, 1 ; write
mov rdi, 1 ; std out
pop rsi; ;   location of hello world - 12 = the start of hello world
sub rsi, 12 

mov rdx, 12 ; length of hello world
syscall

mov rax, 60
mov rdi, 0
syscall


db "Hello World", 10
