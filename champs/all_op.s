.name "# lol# \t 		#"
.comment "# mdr# 		#"

ld	-400 	, r2 	
ld %-400 , r3	
	
st r1	, r1
lab:	st r1, 1	

add r1, r1, r1
sub r1, r1, r1
and r1, r1, r1
and r1, %1, r1
and r1, 4, r1
and %1, r1, r1
and %1, %0, r1
and %1, 4, r1
and 4, r1, r1
and 4, %0, r1
and 4, 4, r1

or r1, r1, r1
or r1, %1, r1
or r1, 4, r1
or %1, r1, r1
or %1, %0, r1
or %1, 4, r1
or 4, r1, r1
or 4, %0, r1
or 4, 4, r1

xor r1, r1, r1
xor r1, %1, r1
xor r1, 4, r1
xor %1, r1, r1
xor %1, %0, r1
xor %1, 4, r1
xor 4, r1, r1
xor 4, %0, r1	#lol
xor 4, 4, r1
#lol

zjmp %10
zjmp %:lab	
zjmp %:lab2

ldi r1, r1, r1
ldi %10, r1, r1
ldi 10, r1, r1
ldi r1, %10, r1
ldi %10, %10, r1
ldi 10, %10, r1

sti r1, r1, r1
sti r1, %10, r1
lab2:	sti r1, 10, r1
sti r1, r1, %10
sti r1, %10, %10
sti r1, 10, %10

fork %:lab2
fork %:test1

lld -400,r2
lld %-400,r3

lldi r1, r1, r1
lldi %10, r1, r1
lldi 10, r1, r1
lldi r1, %10, r1
lldi %10, %10, r1
lldi 10, %10, r1
test1:	

lfork %:test1
mdr: lfork %:mdr
	
aff r1

