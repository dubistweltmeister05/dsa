# Embedded Software Engineer – DSA Mastery Checklist

Tick them off as you get comfortable implementing and using each of these.

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
