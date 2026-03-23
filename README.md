# Sukha 0.1
Sukha is a hobby project of a mini JIT (Just-In-Time) compiler.

https://en.wikipedia.org/wiki/Just-in-time_compilation

The compilation process is:
code > tokenization > parsing > opcode execution

We currently have 3 instructions:

pustack <value> — Pushes a value onto the stack, similar to the push instruction in x86 assembly
rstack — Remove the value from stack
ret — Simply returns 0

More updates will be coming over time.

# Compiling

make

# Usage

./sukha code.skh
