# AI Memory Visualizer

## Introduction

This document analyzes the runtime memory behavior of the programs
`stack_example.c`, `aliasing_example.c`, and `heap_example.c`.

The analysis distinguishes:

- stack frames and local variables;
- heap allocations;
- pointer values and aliases;
- object ownership;
- object lifetimes;
- invalid accesses and memory leaks.

The memory addresses shown during execution are examples from one run.
They may change between executions because of mechanisms such as ASLR and
compiler or operating-system decisions.

---

# 1. stack_example.c

## Purpose

`stack_example.c` demonstrates recursion, stack frames, local variables,
pointer aliases, and automatic object lifetimes.

The program calls:

```c
walk_stack(0, 3);
```

Each recursive call to `walk_stack` creates a new stack frame with its own
`marker` variable. Each call to `dump_frame` creates another temporary frame
containing:

- `local_int`;
- `local_buf`;
- `p_local`.

At each recursion depth, a new `marker` object exists independently:

```text
depth 0 -> marker = 0
depth 1 -> marker = 10
depth 2 -> marker = 20
depth 3 -> marker = 30
```

During each call to `dump_frame`, `p_local` receives the address of
`local_int`:

```c
p_local = &local_int;
```

Therefore, `p_local` and `&local_int` contain the same address and refer to
the same object inside that specific stack frame. This is pointer aliasing.

```text
STACK FRAME: dump_frame(depth)

local_int = 100 + depth
local_buf = character data
p_local ---------------------> local_int
```

Each recursive call owns an independent set of local variables. A pointer
created at one recursion depth does not refer to the `local_int` object of
another depth.

## Memory map at maximum recursion depth

```text
TOP OF STACK

+--------------------------------+
| dump_frame depth = 3           |
| local_int = 103                |
| local_buf = "D"                |
| p_local -> local_int           |
+--------------------------------+
| walk_stack depth = 3           |
| marker = 30                    |
+--------------------------------+
| walk_stack depth = 2           |
| marker = 20                    |
+--------------------------------+
| walk_stack depth = 1           |
| marker = 10                    |
+--------------------------------+
| walk_stack depth = 0           |
| marker = 0                     |
+--------------------------------+
| main                           |
+--------------------------------+

BOTTOM OF STACK
```

No heap allocation occurs in this program.

The stack grows while recursion enters deeper calls:

```text
walk_stack(0)
-> walk_stack(1)
-> walk_stack(2)
-> walk_stack(3)
```

It unwinds in reverse order:

```text
depth 3
-> depth 2
-> depth 1
-> depth 0
```

This follows LIFO behavior: last in, first out.

## Object lifetimes

`local_int`, `local_buf`, and `p_local` remain valid only while their
corresponding `dump_frame` call is active.

Each `marker` remains valid throughout its corresponding `walk_stack` call,
including the recursive call made from it.

When a function returns, the lifetime of its local objects ends. The bytes may
remain temporarily in the stack memory region, but those objects are no longer
valid and must not be accessed.

## AI explanation reviewed and corrected

An incorrect AI explanation would be:

> Local variables are physically erased from memory when the function ends.

This is misleading. The corrected explanation is:

> When the function returns, the lifetime of its local objects ends and its
> stack frame becomes inactive. The underlying bytes may remain temporarily,
> but accessing those expired objects is invalid.

---
# 2. aliasing_example.c

## Purpose

`aliasing_example.c` demonstrates heap allocation, pointer aliasing, ownership,
dangling pointers, and use-after-free errors.

The function:

```c
make_numbers(5);
```

allocates space in the heap for five integers and initializes them as:

```text
index:  0   1   2   3   4
value:  0  11  22  33  44
```

## Heap allocation

Inside `make_numbers`, the following allocation occurs:

```c
arr = (int *)malloc((size_t)n * sizeof(int));
```

Conceptual memory state:

```text
STACK                         HEAP

make_numbers
+------------------+         +-----------------------+
| n = 5            |         | 0 | 11 | 22 | 33 | 44 |
| i                |         +-----------------------+
| arr ------------------------------^
+------------------+
```

When `make_numbers` returns, its local variables `n`, `i`, and `arr` reach the
end of their lifetimes. The allocated heap block remains alive because it has
not yet been freed, and its address is returned to `main`.

## Pointer `a`

After:

```c
a = make_numbers(n);
```

the state is:

```text
STACK                         HEAP

main
+------------------+         +-----------------------+
| n = 5            |         | 0 | 11 | 22 | 33 | 44 |
| a -------------------------------^
| b = NULL         |
+------------------+
```

The pointer `a` does not contain the array itself. It contains the address of
the first integer in the allocated heap block.

## Aliasing

The assignment:

```c
b = a;
```

copies the pointer value, not the array.

Both pointers therefore contain the same address:

```text
a = 0x155e063e0
b = 0x155e063e0
```

Conceptual state:

```text
STACK                         HEAP

main
+------------------+
| a -------------------+
| b -------------------+-----> +-----------------------+
| n = 5            |          | 0 | 11 | 22 | 33 | 44 |
+------------------+          +-----------------------+
```

This is pointer aliasing. `a` and `b` are two different stack variables, but
they refer to the same heap object.

Therefore:

```text
a[2] = 22
b[2] = 22
```

Both expressions access the same third integer.

## State after `free(a)`

The instruction:

```c
free(a);
```

does not free the pointer variable `a`. It ends the lifetime of the heap block
whose address was stored in `a`.

After `free(a)`, both `a` and `b` still contain the old numerical address, but
that address no longer refers to a valid live object.

```text
STACK                         HEAP

main
+------------------+         +-----------------------+
| a -------------------X     | freed block           |
| b -------------------X     | lifetime has ended    |
| n = 5            |         +-----------------------+
+------------------+
```

Both pointers are now dangling pointers.

## Use-after-free read

The expression:

```c
b[2]
```

attempts to read the third integer from a heap object whose lifetime has already
ended.

The observed output was:

```text
reading b[2]=0
```

This result does not make the access valid. It is undefined behavior.

The program could print the old value, print another value, crash, or behave
differently during another execution.

## Use-after-free write

The instruction:

```c
b[3] = 1234;
```

attempts to write to the fourth integer of the same freed heap block.

This is a use-after-free write. It may corrupt allocator metadata, modify memory
that has been reused by another allocation, cause a later crash, or appear to
work accidentally.

The later output:

```text
wrote b[3]=1234
```

does not prove that the operation was valid.

## Lifetimes and ownership

The variables `a`, `b`, and `n` are local objects in the stack frame of `main`
and remain alive until `main` returns.

The variables `arr`, `i`, and the parameter `n` inside `make_numbers` exist only
during that function call.

The allocated integer block exists from the successful `malloc` call until
`free(a)`.

Although `a` and `b` are aliases, there must be only one clear responsibility
for deallocation. In this execution, `a` acts as the owning pointer and `b` as
a temporary non-owning alias.

Once the block is freed through `a`, no alias may legally access it.

## AI explanation reviewed and corrected

An incorrect AI explanation would be:

> After `free(a)`, only `a` becomes invalid. `b` can still access the array
> because it is a different pointer.

This is false.

The corrected explanation is:

> `free(a)` ends the lifetime of the heap object, not the lifetime of only one
> pointer variable. Since `a` and `b` contain the same address, neither pointer
> may be used to access that object after it is freed.

A vague explanation such as:

> `b` points somewhere invalid.

is incomplete.

The precise explanation is:

> `b` retains the former base address of the five-integer heap allocation.
> That allocation's lifetime ended at `free(a)`. Therefore, `b[2]` attempts to
> read the third integer and `b[3] = 1234` attempts to write the fourth integer
> of an object whose lifetime has ended.

## Safer pointer cleanup

A defensive cleanup pattern is:

```c
free(a);
a = NULL;
b = NULL;
```

This prevents accidental reuse of these two known pointer variables.

However, assigning `NULL` to one pointer does not automatically update other
aliases. The real solution is explicit ownership and strict lifetime control.

---
# 3. heap_example.c

## Purpose

`heap_example.c` demonstrates nested heap allocations, ownership relationships,
correct deallocation order, and a deliberate memory leak.

The structure is:

```c
typedef struct Person
{
    char *name;
    int age;
} Person;
```

A `Person` object contains an integer directly, but its `name` field points to
a separate dynamically allocated character array.

## Allocations performed by `person_new`

The call:

```c
alice = person_new("Alice", 30);
```

performs two independent heap allocations:

1. one allocation for the `Person` structure;
2. one allocation for the string `"Alice"`.

The call:

```c
bob = person_new("Bob", 41);
```

performs the same two kinds of allocations.

After both calls succeed, four live heap blocks exist.

```text
STACK                         HEAP

main
+------------------+         +-------------------------+
| alice -------------------->| Person                  |
| bob -----------+ |         | name ----------------+  |
+------------------+         | age = 30             |  |
                             +-----------------------|--+
                                                     |
                             +-----------------------v--+
                             | "Alice\0"                |
                             +--------------------------+

                             +--------------------------+
                             | Person                   |
                             | name ----------------+   |
                             | age = 41             |   |
                             +----------------------|---+
                                                    |
                             +----------------------v---+
                             | "Bob\0"                  |
                             +--------------------------+
```

The observed addresses confirm that the structures and their names are stored
in separate allocations:

```text
alice=0x120606340 name=0x1206061f0 age=30
bob=0x1206062e0 name=0x1206062f0 age=41
```

The exact addresses are specific to one execution and may change.

## Stack lifetimes inside `person_new`

During each call to `person_new`, its stack frame contains:

```text
name
age
i
len
p
```

The parameter `name` points to the string literal passed by `main`. The local
pointer `p` points to the newly allocated `Person` object.

When `person_new` returns, its parameters and local variables reach the end of
their lifetimes. The allocated structure and name string remain alive because
their addresses are returned or stored in another live heap object.

## Ownership relationships

After successful construction:

```text
alice owns:
    Person allocation for Alice
    name allocation containing "Alice"

bob owns:
    Person allocation for Bob
    name allocation containing "Bob"
```

More precisely, `alice` and `bob` in `main` are the root pointers used to reach
their corresponding allocation trees.

Each `Person` structure is responsible for the separate allocation referenced
by its `name` field.

## Correct deallocation of `bob`

The program releases Bob correctly:

```c
free(bob->name);
free(bob);
```

The name must be released before the structure because `bob->name` can only be
read safely while the `Person` object is still alive.

Conceptual transition:

```text
Before:

bob -> Person -> "Bob\0"

After free(bob->name):

bob -> Person -> freed name block

After free(bob):

bob -> freed Person block
```

After both calls, no live heap allocation belonging to Bob remains.

The local pointer variable `bob` still contains its former address unless it is
assigned `NULL`, but it must no longer be dereferenced.

## Deliberate leak involving `alice`

Alice is released through:

```c
person_free_partial(alice);
```

That function contains only:

```c
free(p);
```

It releases the `Person` structure but does not release the separate allocation
referenced by `p->name`.

Before the call:

```text
alice -> Person -> "Alice\0"
```

After `free(p)`:

```text
alice -> freed Person

unreachable heap block:
"Alice\0"
```

The allocation containing `"Alice"` is now leaked because the only stored
pointer that reached it was inside the freed `Person` structure.

The leak is not the `Person` object itself. That object was freed. The leaked
object is the character array allocated by:

```c
p->name = (char *)malloc(len + 1);
```

## Why the pointer becomes unreachable

Before freeing the structure, the name address is reachable through:

```text
alice -> alice->name
```

After the structure is freed, accessing `alice->name` would itself be invalid.
Because no other pointer stores the name address, the program has lost the
ability to call `free` on that allocation.

This is the causal chain:

```text
allocate Person
-> allocate name
-> store name pointer inside Person
-> free Person without freeing name
-> lose the only valid path to name
-> memory leak
```

## Failure path analysis

The condition:

```c
if (!alice || !bob)
```

calls `person_free_partial` for any successfully created object.

This cleanup is also incomplete. If `alice` or `bob` was fully constructed,
`person_free_partial` frees only the structure and leaks its `name` allocation.

Therefore, the partial-free function creates leaks both:

- during the normal cleanup of Alice;
- during the allocation-failure cleanup path.

## Correct cleanup function

A complete destructor would conceptually perform:

```c
if (p)
{
    free(p->name);
    free(p);
}
```

The correct order is:

```text
1. free nested owned allocations
2. free the containing structure
```

After the call, the caller should also set its known pointer to `NULL` when
continued use is possible:

```c
person_free(alice);
alice = NULL;
```

Setting the caller's pointer to `NULL` does not free memory by itself. It only
reduces the risk of accidental dereference after deallocation.

## AI explanation reviewed and corrected

An incomplete AI explanation would be:

> `person_free_partial` leaks Alice.

This is too vague because it does not identify which allocation remains live.

The precise correction is:

> `person_free_partial(alice)` frees the heap allocation containing the
> `Person` structure. It does not free the independent character array
> referenced by `alice->name`. Once the structure is freed, the only pointer to
> that character array is lost, so the allocation containing `"Alice\0"`
> becomes unreachable and is leaked.

Another misleading explanation would be:

> Freeing the structure automatically frees everything it points to.

This is false in C.

The corrected explanation is:

> `free` releases only the allocation whose base address is passed to it.
> It does not recursively inspect pointer fields or release other allocations.
> Every separately allocated owned object requires its own corresponding
> deallocation.

## Final memory state

At program termination:

```text
Bob's name allocation:    freed
Bob's Person allocation:  freed
Alice's Person allocation: freed
Alice's name allocation:  leaked
```

The remaining leaked block contains six bytes:

```text
'A' 'l' 'i' 'c' 'e' '\0'
```

---
