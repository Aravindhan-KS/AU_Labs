✅ Compile & Run
yacc -d for.y
lex for.l
gcc y.tab.c lex.yy.c -o for -ll
./for
✅ Example Valid Input
for(i=0; i<10; i=i+1){}

Output:

Valid For Loop
❌ Example Invalid Input
for(i=0 i<10; i=i+1){}

Output:

Invalid For Loop