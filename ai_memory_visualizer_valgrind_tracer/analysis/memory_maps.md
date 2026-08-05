Here is the step-by-step memory breakdown for each program execution output, categorized by memory region, pointer relationships, and lifetimes.

---

### **1. `aliasing_example` Memory Map**

**Heap & Pointers:**

* **Allocation:** Memory allocated at heap address `0x55c0f5caf6b0`.
* **Pointer Aliasing:** Pointers `a` and `b` both store `0x55c0f5caf6b0`. They alias the exact same heap block (`a[2] == b[2] == 22`).

**Lifetime & Undefined Behavior Sequence:**

1. **Deallocation:** `free(a)` releases the heap block at `0x55c0f5caf6b0`.
2. **Dangling Pointer:** `b` was never set to `NULL`, leaving `b` as a **dangling pointer** pointing to freed memory.
3. **Use-After-Free (Read):** Reading `b[2]` fetches `-1618460917` (garbage data because the OS allocator reclaimed/overwrote the memory).
4. **Use-After-Free (Write):** Writing `b[3] = 1234` corrupts unallocated heap memory.

---

### **2. `crash_example` Memory Map**

**Execution State:**

* **Allocation:** `n = 0` triggers a pointer assignment to `NULL` (`0x0`).
* **Segmentation Fault:** Program attempts to dereference `0x0`.

**Memory Impact:**

* The memory address `0x0` lives outside the process's mapped virtual address space.
* The OS Memory Management Unit (MMU) catches the illegal memory access, generates a hardware interrupt, sends `SIGSEGV`, and terminates the process immediately (**core dumped**).

---

### **3. `heap_example` Memory Map**

**Heap Allocations & Struct Layout:**

* **`alice` struct:** Located at `0x560ae00686b0`
* Contains field `name` pointing to separate heap allocation `0x560ae00686d0` ("Alice").
* Primitive field `age = 30`.


* **`bob` struct:** Located at `0x560ae00686f0`
* Contains field `name` pointing to separate heap allocation `0x560ae0068710` ("Bob").
* Primitive field `age = 41`.



**Lifetimes & Memory Leak:**

* **Dynamic Lifetimes:** These structs remain alive on the heap until explicitly freed.
* **Deliberate Leak:** The program exits without calling `free()` on these blocks. The memory stays allocated until process termination (Valgrind will flag `0x560ae00686b0`, `0x560ae00686d0`, `0x560ae00686f0`, and `0x560ae0068710` as directly/indirectly lost).

---

### **4. `stack_example` Memory Map**

**Stack Growth Behavior:**

* The stack grows **downward** toward lower memory addresses as call depth increases:
* Depth 0 (`&local_int`): `0x7ffcd80d6684` (highest address)
* Depth 1 (`&local_int`): `0x7ffcd80d6654` ($\Delta = -0\text{x}30$ bytes)
* Depth 2 (`&local_int`): `0x7ffcd80d6624` ($\Delta = -0\text{x}30$ bytes)
* Depth 3 (`&local_int`): `0x7ffcd80d65f4` (lowest address)



**Stack Frame Anatomy (Per Frame Size: 48 bytes / $0\text{x}30$):**

```text
[ High Address ]
┌──────────────────────────────────────────────────┐
│ Stack Frame: depth=0                             │
│  - marker    @ 0x7ffcd80d66d4 (val: 0)           │
│  - local_buf @ 0x7ffcd80d6690 (val: 'A')         │
│  - local_int @ 0x7ffcd80d6684 (val: 100)         │
├──────────────────────────────────────────────────┤
│ Stack Frame: depth=1                             │
│  - marker    @ 0x7ffcd80d66a4 (val: 10)          │
│  - local_buf @ 0x7ffcd80d6660 (val: 'B')         │
│  - local_int @ 0x7ffcd80d6654 (val: 101)         │
├──────────────────────────────────────────────────┤
│ Stack Frame: depth=2                             │
│  - marker    @ 0x7ffcd80d6674 (val: 20)          │
│  - local_buf @ 0x7ffcd80d6630 (val: 'C')         │
│  - local_int @ 0x7ffcd80d6624 (val: 102)         │
├──────────────────────────────────────────────────┤
│ Stack Frame: depth=3                             │
│  - marker    @ 0x7ffcd80d6644 (val: 30)          │
│  - local_buf @ 0x7ffcd80d6600 (val: 'D')         │
│  - local_int @ 0x7ffcd80d65f4 (val: 103)         │
└──────────────────────────────────────────────────┘
[ Low Address ]

```

**Lifetimes & Scope:**

* **Automatic Storage Duration:** Local variables (`local_int`, `local_buf`, `marker`) are allocated on function entry (`[enter]`) and destroyed automatically on return (`[exit]`).
* As functions pop off the call stack (`depth=3` $\rightarrow$ `depth=0`), memory addresses are reclaimed by shrinking the stack pointer back up toward `0x7ffcd80d6684`.