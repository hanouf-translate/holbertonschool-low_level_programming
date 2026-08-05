
---

### **1. `aliasing_example**`

**The Line Where the Problem Arises:**

```c
free(a);

```

*(Followed by accessing `b[2]` or writing to `b[3]`)*

* **Explanation:** Since `a` and `b` hold the same memory address, calling `free(a)` deallocates the heap block that `b` is still pointing to. This leaves `b` as a **dangling pointer**. Reading or writing through `b` after this point triggers a **Use-After-Free** bug.

---

### **2. `crash_example**`

**The Line Where the Problem Arises:**

```c
*ptr = 10;  /* Assuming ptr was set to NULL (0x0) */

```

* **Explanation:** Dereferencing a `NULL` pointer attempts to read or write to address `0x0`, which is restricted memory outside your process space. The operating system's Memory Management Unit immediately intercepts this illegal access and triggers a **Segmentation Fault (`SIGSEGV`)**.

---

### **3. `heap_example**`

**The Line Where the Problem Arises:**

```c
return 0;  /* Exiting main without calling free() */

```

* **Explanation:** The program finishes execution without calling `free()` on the memory allocated for `alice`, `bob`, and their `name` strings. When the function returns without releasing these references, the memory becomes unreachable and results in a **Memory Leak**.

---

### **4. `stack_example**`

**The Line Where the Problem Arises:**

```c
recurse(depth + 1);  /* If missing a base case check like: if (depth > MAX) return; */

```

* **Explanation:** Every recursive function call pushes a new stack frame onto the call stack (allocating memory for `local_int`, `local_buf`, and `marker`). If recursion continues without a stopping condition, the stack grows past its memory boundary, causing a **Stack Overflow**.

-note: model used GIMINI