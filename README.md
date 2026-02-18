# Embedded Software Engineer – DSA Mastery Checklist

Tick them off as you get comfortable implementing and using each of these.

---

## Contributing

If you’ve used this as your basepoint and added useful examples, fixes, or new embedded-focused DSA topics:

- Open a pull request against this original repo with a short description of what you changed or added.
- Keep implementations in C (or very close to bare-metal/RTOS C environments) and prefer static or bounded memory usage where possible.
- Follow the existing folder layout when adding new implementations (e.g., `arrays/`, `Linear_DS/`, `Trees/`, `RTOS/`, `DSP/`, etc.), and create a new subfolder per concept/checklist item you implement (for example, `arrays/2-D_arrays/`, `Linear_DS/queue/`).
- If you base an implementation on code or an article you found on the internet, you **must** include a comment with the original source link at the very top of your `.c`/`.h` file, for example:
	- `// Source: https://example.com/path-to-implementation`

This keeps the repo organized, attribution clear, and learning-focused.

---

## How to Use This Repo as Your Basepoint

1. **Fork this repository** into your own GitHub account so you can customize it and track your personal progress.
2. **Clone your fork locally** and open it in your editor/IDE.
3. **Use this checklist as your roadmap**: pick one topic at a time (e.g., arrays, ring buffers, FSMs) and focus on understanding + implementing it in C.
4. **Implement each item at least once in C**, preferably in a small, self-contained example under the relevant folder (e.g., `arrays/`, `linked_list/`, `RTOS/`). For each checklist topic you implement, create a dedicated subfolder inside the relevant top-level folder (e.g., `arrays/dynamic_arrays/`, `Linear_DS/circular_queue/`) and keep its `.c`/`.h` files there. Use static memory where it makes sense for embedded systems.
5. **Mark the checkbox** once you can implement, explain, and reuse that structure/algorithm confidently in an embedded context.
6. **Commit your solutions regularly** with clear messages so you (and others) can review how your understanding evolves over time.
7. Optionally, **add notes or a personal log** (e.g., in a separate markdown file) about gotchas, performance tradeoffs, and how each concept maps to real embedded problems you’ve seen.

Feel free to adapt folder structure, add new problems, or extend the checklist to match your target domain (bare metal, RTOS, drivers, DSP, networking, etc.).

---

## 1. Fundamentals

### Data Structures
- [ ] Arrays (static)
- [ ] Dynamic arrays
- [ ] Circular arrays
- [ ] Strings (null-terminated)
- [ ] Fixed-length buffers
- [ ] Structs
- [ ] Unions
- [ ] Bit-fields
- [ ] Bitmaps / Bitsets
- [ ] Pointers & pointer arithmetic
- [ ] Memory pools (basic)
- [ ] Buffer descriptors

### Algorithms
- [ ] Linear search
- [ ] Binary search
- [ ] Bit manipulation tricks
- [ ] CRC calculation
- [ ] Checksum algorithms
- [ ] Endianness conversion
- [ ] Fixed-point arithmetic
- [ ] Optimized memcpy / memmove logic

---

## 2. Linear Data Structures

### Data Structures
- [ ] Stack
- [ ] Queue
- [ ] Circular Queue
- [ ] Deque
- [ ] Singly Linked List
- [ ] Doubly Linked List
- [ ] Circular Linked List
- [ ] Priority Queue
- [ ] Static queue (array-based)
- [ ] Lock-free queue (conceptual)

### Algorithms
- [ ] Stack push/pop
- [ ] Queue enqueue/dequeue
- [ ] Producer–Consumer pattern
- [ ] Overflow/underflow handling
- [ ] Linked list insert/delete/search
- [ ] Fast/slow pointer technique

---

## 3. Trees

### Data Structures
- [ ] Binary Tree
- [ ] Binary Search Tree (BST)
- [ ] AVL Tree
- [ ] Red–Black Tree
- [ ] Trie
- [ ] Segment Tree
- [ ] Heap (Min/Max)

### Algorithms
- [ ] Preorder traversal
- [ ] Inorder traversal
- [ ] Postorder traversal
- [ ] Level-order traversal
- [ ] BST insert/delete
- [ ] Heapify
- [ ] Tree balancing
- [ ] Lowest Common Ancestor (LCA)
- [ ] Range queries

---

## 4. Hashing

### Data Structures
- [ ] Hash Table
- [ ] Hash Map
- [ ] Hash Set
- [ ] Open addressing
- [ ] Separate chaining

### Algorithms
- [ ] Hash function design
- [ ] Collision resolution
- [ ] Load factor management
- [ ] Rehashing

---

## 5. Graphs

### Data Structures
- [ ] Adjacency List
- [ ] Adjacency Matrix

### Algorithms
- [ ] BFS
- [ ] DFS
- [ ] Topological Sort
- [ ] Dijkstra
- [ ] Bellman–Ford
- [ ] A* search
- [ ] Cycle detection
- [ ] Connected components

---

## 6. Sorting Algorithms

- [ ] Bubble Sort
- [ ] Selection Sort
- [ ] Insertion Sort
- [ ] Merge Sort
- [ ] Quick Sort
- [ ] Heap Sort
- [ ] Counting Sort
- [ ] Radix Sort

---

## 7. Searching Algorithms

- [ ] Linear Search
- [ ] Binary Search
- [ ] Ternary Search
- [ ] Jump Search
- [ ] Exponential Search

---

## 8. Memory-Oriented Structures (Embedded Gold)

### Data Structures
- [ ] Memory Pool
- [ ] Slab Allocator
- [ ] Object Pool
- [ ] Buddy Allocator
- [ ] Free-list
- [ ] Ring Allocator
- [ ] Static partition allocator

### Algorithms
- [ ] First-fit
- [ ] Best-fit
- [ ] Worst-fit
- [ ] Fragmentation handling
- [ ] Deterministic allocation strategies

---

## 9. RTOS & Concurrency

### Data Structures
- [ ] Semaphore
- [ ] Mutex
- [ ] Spinlock
- [ ] Event flags
- [ ] Mailbox
- [ ] Message Queue
- [ ] Task Control Block (TCB)
- [ ] Timer wheel

### Algorithms
- [ ] Priority scheduling
- [ ] Round-robin scheduling
- [ ] Rate Monotonic Scheduling (RMS)
- [ ] Earliest Deadline First (EDF)
- [ ] Priority inheritance
- [ ] Deadlock detection
- [ ] Producer–Consumer synchronization

---

## 10. Buffering & Communication

### Data Structures
- [ ] Ring Buffer
- [ ] Frame Buffer
- [ ] Packet Descriptor
- [ ] Scatter–Gather list
- [ ] Double buffering
- [ ] DMA buffer queue

### Algorithms
- [ ] Framing/Deframing
- [ ] Chunked data reassembly
- [ ] Flow control
- [ ] Sliding window protocol
- [ ] Retry logic
- [ ] Timeout handling

---

## 11. File System & Kernel Internals

- [ ] Inode tree concepts
- [ ] B-Tree
- [ ] B+ Tree
- [ ] Page cache structures
- [ ] Radix Tree
- [ ] Extent trees

---

## 12. State Machines (Must-Have)

### Data Structures
- [ ] FSM tables
- [ ] Transition tables
- [ ] Event queue

### Algorithms
- [ ] Event-driven FSM
- [ ] Hierarchical state machines
- [ ] Mealy machines
- [ ] Moore machines

---

## 13. DSP / Control Systems

- [ ] Circular buffers for sampling
- [ ] FIR filter structures
- [ ] IIR filter structures
- [ ] FFT algorithm basics
- [ ] Kalman filter (conceptual)
- [ ] Moving average filter

---

## 14. Compression & Encoding

- [ ] Run-Length Encoding (RLE)
- [ ] Huffman Coding
- [ ] LZ77 concept
- [ ] LZ4 concept
- [ ] Base64
- [ ] COBS encoding
- [ ] SLIP encoding
- [ ] CBOR parsing
- [ ] TLV parsing

---

## 15. Core Embedded Arsenal (Non-Negotiable)

If these are all ticked, you’re already dangerous:

- [ ] Arrays & pointers
- [ ] Ring buffers
- [ ] Linked lists
- [ ] Stack
- [ ] Queue
- [ ] Hash table
- [ ] Heap
- [ ] Insertion sort
- [ ] Merge sort
- [ ] Quick sort
- [ ] Memory pools
- [ ] Finite State Machines
- [ ] Producer–Consumer queues
- [ ] Bit manipulation

---

> Goal: Implement each structure at least once in C.  
> Bonus: Implement one version with dynamic allocation and one with **pure static memory**.
