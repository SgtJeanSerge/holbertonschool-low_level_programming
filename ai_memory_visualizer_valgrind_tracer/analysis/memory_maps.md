# Memory Maps — AI Memory Visualizer

## Table of Contents

1. [Methodology](#1-methodology)
2. [Conventions](#2-conventions)
3. [stack_example.c](#3-stack_examplec)
4. [aliasing_example.c](#4-aliasing_examplec)
5. [heap_example.c (optional)](#5-heap_examplec-optional)
6. [AI Errors and Corrections](#6-ai-errors-and-corrections)
7. [Conclusion](#7-conclusion)

---

## 1. Methodology

### 1.1 Build and run

```
TODO: commands used to compile and run
```

### 1.2 AI tool used

- Tool / model:
- How it was used:

### 1.3 Verification process

TODO: how you checked the AI output (printed addresses, reading the code, gdb, ...)

---

## 2. Conventions

TODO: legend for your diagrams (how a stack frame, a heap block, a pointer, a freed block are drawn)

```
TODO: legend
```

---

## 3. stack_example.c

### 3.1 Program output

```
TODO: paste real output
```

### 3.2 Key execution points

| Step | Line(s) | Event | Memory change |
|------|---------|-------|---------------|
| 1    |         |       |               |
| 2    |         |       |               |

### 3.3 Step-by-step memory maps

#### Step 1 — TODO

```
STACK                              HEAP
+---------------------------+
|                           |
+---------------------------+
```

TODO: explanation

#### Step 2 — TODO

```
TODO
```

#### Step N — TODO

```
TODO
```

### 3.4 Variable lifetimes

| Variable | Function / frame | Storage | Lifetime starts | Lifetime ends |
|----------|------------------|---------|-----------------|---------------|
|          |                  |         |                 |               |

### 3.5 Observations from real addresses

TODO

---

## 4. aliasing_example.c

### 4.1 Program output

```
TODO: paste real output
```

### 4.2 Key execution points

| Step | Line(s) | Event | Memory change |
|------|---------|-------|---------------|
| 1    |         |       |               |
| 2    |         |       |               |

### 4.3 Step-by-step memory maps

#### Step 1 — TODO

```
STACK                              HEAP
+---------------------------+      +---------------------------+
|                           |      |                           |
+---------------------------+      +---------------------------+
```

TODO: explanation

#### Step N — TODO

```
TODO
```

### 4.4 Pointer aliasing

| Moment | Pointer | Value | Points to | Valid? |
|--------|---------|-------|-----------|--------|
|        |         |       |           |        |

### 4.5 Ownership

TODO: who owns the block, when ownership changes, who is responsible for freeing

### 4.6 Variable / object lifetimes

| Object | Storage | Lifetime starts | Lifetime ends |
|--------|---------|-----------------|---------------|
|        |         |                 |               |

### 4.7 Analysis of the invalid accesses

TODO: precise explanation (line, address, state of the block, why it is undefined behavior)

---

## 5. heap_example.c (optional)

### 5.1 Program output

```
TODO
```

### 5.2 Step-by-step memory maps

```
TODO
```

### 5.3 Ownership and deallocation

| Heap block | Allocated at | Owner | Freed at | Status at exit |
|------------|--------------|-------|----------|----------------|
|            |              |       |          |                |

### 5.4 Analysis

TODO

---

## 6. AI Errors and Corrections

### 6.1 Prompt given to the AI

```
TODO
```

### 6.2 Error #1

- **Program / step:**
- **What the AI said:**

  > TODO: quote

- **Why it is wrong / incomplete / misleading:**

  TODO

- **Correction:**

  TODO

- **How I verified it:**

  TODO

### 6.3 Error #2

- **Program / step:**
- **What the AI said:**

  > TODO

- **Why it is wrong:**

  TODO

- **Correction:**

  TODO

- **How I verified it:**

  TODO

---

## 7. Conclusion

TODO: what you learned about stack vs heap, lifetimes, aliasing, and about trusting AI output
