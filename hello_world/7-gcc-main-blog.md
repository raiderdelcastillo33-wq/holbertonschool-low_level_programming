# What Happens When You Type `gcc main.c`

When we type:

```bash
gcc main.c
```

we are asking `gcc` to transform a C source file into an executable program.

At first, this command looks simple. However, several important steps happen behind it: preprocessing, compilation, assembly, and linking.

## Example source file

Imagine we have a file called `main.c`:

```c
#include <stdio.h>

/**
 * main - Entry point of the program.
 *
 * Return: Always 0.
 */
int main(void)
{
	printf("Hello, World\n");
	return (0);
}
```

This file is written in C. Humans can read it, but the computer cannot execute it directly. It must be translated into machine code.

## 1. Preprocessing

The first step is preprocessing.

The preprocessor handles lines that start with `#`, such as:

```c
#include <stdio.h>
```

This line tells the compiler to include information from the standard input/output library. This is necessary when we use functions like `printf`.

We can stop after the preprocessing step with:

```bash
gcc -E main.c -o main.i
```

This creates a file called `main.i`.

## 2. Compilation

After preprocessing, the compiler translates the C code into assembly code.

Assembly code is closer to machine language, but it is still readable by humans.

We can stop after the compilation step with:

```bash
gcc -S main.c
```

This creates a file called:

```bash
main.s
```

## 3. Assembly

The assembler converts the assembly code into object code.

Object code is machine code, but it is not yet a complete executable program.

We can create an object file with:

```bash
gcc -c main.c
```

This creates:

```bash
main.o
```

## 4. Linking

The final step is linking.

The linker connects our object code with the libraries needed by the program. For example, if our program uses `printf`, the linker connects our code with the standard C library.

After linking, we get an executable program.

When we run:

```bash
gcc main.c
```

the default executable name is:

```bash
a.out
```

We can run it with:

```bash
./a.out
```

## 5. Using a custom executable name

Instead of using the default name `a.out`, we can choose our own executable name with the `-o` option.

Example:

```bash
gcc main.c -o hello
```

Then we can run:

```bash
./hello
```

## Summary

When we type:

```bash
gcc main.c
```

the complete process is:

```text
main.c -> preprocessing -> compilation -> assembly -> linking -> a.out
```

So, `gcc main.c` does much more than compile one file. It runs a complete process that transforms C source code into an executable program.

Understanding this process helps us read compiler errors, debug programs, and become better C programmers.
