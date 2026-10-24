A structured, project-based journey through Data Structures and Algorithms (DSA) using C — progressing from fundamental data structures and searching algorithms to graph theory, algorithmic optimization, file indexing, and production-inspired systems.

This repository is not a collection of random coding exercises or copied DSA solutions.

The goal is to develop strong problem-solving ability by implementing meaningful projects in C, understanding how algorithms work internally, choosing appropriate data structures, analyzing time and space complexity, and improving software design through practical development.

C is the primary language throughout this journey. Projects emphasize pointers, dynamic memory allocation, structs, modular programming, memory safety, and efficient data representation alongside DSA.
🎯 Goal
The primary goal of this repository is to become genuinely proficient in Data Structures and Algorithms through hands-on implementation in C.

Instead of studying algorithms only through lectures, notes, and isolated coding questions, this repository follows a progression in which concepts are introduced, implemented, tested, combined, and optimized through practical applications.

The long-term goal is to reach a point where I can:
- Understand fundamental and advanced data structures beyond their definitions.
- Implement common data structures from scratch using C.
- Select appropriate data structures for different problems.
- Design and implement algorithms independently.
- Analyze time complexity and auxiliary space complexity.
- Understand the trade-offs between alternative algorithms.
- Work confidently with pointers, structs, dynamic memory, and memory ownership.
- Build programs that manage structured data efficiently.
- Solve problems involving trees, graphs, recursion, and dynamic programming.
- Implement searching, sorting, indexing, and optimization techniques.
- Build persistent applications using file handling and indexing.
- Test edge cases and debug memory-related errors.
- Write modular, readable, maintainable C programs.
- Benchmark algorithms using different input sizes and distributions.
- Apply DSA concepts to larger systems rather than isolated demonstrations.
- Use AI for explanations, debugging, code review, and learning without replacing independent problem-solving.
🧠 Learning Philosophy
The repository follows a simple principle:

Understand → Design → Implement → Test → Analyze → Optimize → Document → Repeat

Projects are deliberately chosen so that they are:
- More meaningful than isolated syntax exercises.
- Small enough to understand completely.
- Large enough to introduce genuine programming problems.
- Connected to concepts learned in earlier projects.
- Progressively more challenging.
- Suitable for implementation in standard C.
- Useful preparation for subsequent projects.
- Designed to encourage independent reasoning.
The objective is not to use the most advanced data structure possible in every project. The objective is to understand which data structure is appropriate, why it is appropriate, and what trade-offs it introduces.

For example, a contact directory can begin with an array and linear search. The same application can later be extended using binary search, linked lists, or hashing. Comparing these implementations teaches more than simply writing one of them.
🏗️ Repository Structure
c-dsa-projects/
│
├── README.md
├── .gitignore
├── Makefile
│
├── 01-arrays-and-searching/
├── 02-linear-data-structures/
├── 03-trees-heaps-and-hashing/
├── 04-graphs-and-networks/
├── 05-algorithmic-problem-solving/
├── 06-files-and-algorithmic-systems/
├── 07-advanced-algorithms-and-optimization/
├── 08-capstone-projects/
│
├── common/
│   ├── input.c
│   └── input.h
│
├── tests/
├── benchmarks/
├── _experiments/
└── _notes/
Each numbered directory represents a stage in the learning journey.

Each project has its own directory, README, implementation files, and test cases as appropriate. Early projects can remain in a single main.c file; code can be split into .c and .h modules as the design becomes more complex.

A typical modular project may look like this:
01-arrays-and-searching/
└── 01-student-ranking-engine/
    ├── README.md
    ├── main.c
    ├── student.c
    ├── student.h
    ├── ranking.c
    ├── ranking.h
    └── test_cases.txt
The common/ directory is intended for genuinely reusable utilities. The tests/ and benchmarks/ directories hold test cases and performance experiments shared across projects where appropriate.
⚡ Quick Start / How to Run
1. Install a C compiler
Use GCC or Clang with support for the C17 standard.

On Windows, GCC can be installed through a suitable MinGW-w64 distribution or MSYS2. On Linux, GCC is generally available through the system package manager. Clang is another option.

Verify the installation:
gcc --version
2. Clone the repository
Replace the placeholder with the repository URL after creating it on GitHub.
git clone <YOUR_REPOSITORY_URL>
cd c-dsa-projects
3. Compile a project
For the Student Ranking Engine, assuming the initial implementation is contained in main.c:
gcc -std=c17 -Wall -Wextra -Wpedantic -g \
    01-arrays-and-searching/01-student-ranking-engine/main.c \
    -o student_ranking
The compilation command changes if the project is split into multiple source files.
4. Run the program
On Linux or macOS:
./student_ranking
On Windows PowerShell:
.\student_ranking.exe
5. Use memory and undefined-behavior checks
When supported by the compiler, sanitizers can help detect many memory errors and instances of undefined behavior:
gcc -std=c17 -Wall -Wextra -Wpedantic -g \
    -fsanitize=address,undefined \
    01-arrays-and-searching/01-student-ranking-engine/main.c \
    -o student_ranking
Sanitizers complement careful testing and code review; they do not replace them.
🗺️ Curriculum Roadmap
01 — Arrays and Searching
Goal: Build confidence in applying basic data structures and algorithms to useful programs.

Topics include:
- Arrays and strings.
- Structs and collections of records.
- Linear and binary search.
- Sorting algorithms.
- Filtering and aggregation.
- Duplicate detection.
- Basic time and space complexity.
- Input validation and boundary cases.
- Comparing alternative implementations.
Projects
01 — Student Ranking Engine

Manage student records, calculate average marks, rank students, handle ties, search by student ID, and display performance summaries.

02 — Inventory Search Engine

Maintain product records, search by ID or name, filter by category, and compare linear search with binary search.

03 — Duplicate Record Detector

Identify duplicate IDs, values, or records using straightforward comparison and sorting-based approaches.

04 — Leaderboard Manager

Maintain player scores, sort rankings, resolve ties, and display the top performers.

05 — Text Statistics Analyzer

Analyze character frequencies, word counts, and other basic text statistics using strings and arrays.

06 — Algorithm Benchmark Tool

Measure and compare the runtime of searching and sorting algorithms across different input sizes.

07 — Appointment Slot Manager

Maintain appointments, sort time intervals, detect overlaps, and identify scheduling conflicts.

08 — Mini Database Index Simulator

Build a small record lookup system and compare sequential search, sorted arrays, and binary search.
02 — Linear Data Structures
Goal: Understand dynamic memory management and structures that grow, shrink, and change during program execution.

Topics include:
- Pointers and pointer arithmetic.
- Dynamic memory allocation using malloc, calloc, realloc, and free.
- Structures and linked data.
- Singly and doubly linked lists.
- Circular linked lists.
- Stacks and queues.
- Deques and priority queues.
- Memory ownership and safe deallocation.
- Abstract data types and their interfaces.
Projects
09 — Contact Directory

Implement dynamic contact insertion, deletion, updating, and searching using linked lists.

10 — Undo/Redo Text Editor

Maintain editing operations and support undo and redo using stacks or linked structures.

11 — Print Queue Simulator

Simulate print jobs waiting to be processed, including job insertion, processing, and cancellation.

12 — Browser History Simulator

Support backward and forward navigation using a doubly linked list or two stacks.

13 — Customer Service Queue

Manage customer requests using FIFO queues and extend the system with priority-based handling.

14 — Expression Evaluator

Convert infix expressions to postfix notation and evaluate expressions using stacks.

15 — Memory Allocation Simulator

Simulate allocation requests, free blocks, and allocation strategies such as first fit and best fit.

16 — Task Dependency Executor

Represent pending tasks and their dependencies, then introduce queue-based processing of eligible tasks.

17 — LRU Cache Simulator

Implement a least-recently-used cache using a hash table and doubly linked list.
03 — Trees, Heaps and Hashing
Goal: Build systems that support efficient searching, insertion, deletion, priority handling, and hierarchical representation.

Topics include:
- Binary trees and binary search trees.
- Tree traversals.
- Recursive tree operations.
- Binary heaps and priority queues.
- Hash functions and collision resolution.
- Open addressing and separate chaining.
- Tries and prefix search.
- AVL trees and balanced search trees.
- Segment trees and Fenwick trees.
- Complexity trade-offs between different structures.
Projects
18 — Dictionary Lookup Tool

Store and retrieve words using a binary search tree or hash table.

19 — File and Folder Tree

Represent hierarchical directories and traverse them recursively.

20 — Priority Job Scheduler

Maintain jobs in a binary heap and process the highest-priority job efficiently.

21 — Search Autocomplete

Implement prefix-based word suggestions using a trie.

22 — Event Ranking System

Maintain event scores and retrieve the top-ranked entries using heaps.

23 — In-Memory Key-Value Store

Implement key-based lookup, insertion, update, and deletion using a hash table.

24 — Organizational Hierarchy Manager

Represent managers and employees as a tree and support hierarchical queries.

25 — Range Query Engine

Answer range sum or minimum queries using a segment tree or Fenwick tree.

26 — Balanced Search Index

Implement a balanced search tree, such as an AVL tree, and compare its behavior with an ordinary binary search tree.
04 — Graphs and Networks
Goal: Model relationships, dependencies, routes, and networks using graph representations and traversal algorithms.

Topics include:
- Vertices and edges.
- Directed and undirected graphs.
- Weighted graphs.
- Adjacency matrices and adjacency lists.
- Breadth-first search (BFS).
- Depth-first search (DFS).
- Connected components.
- Cycle detection.
- Topological sorting.
- Dijkstra's shortest-path algorithm.
- Bellman–Ford and Floyd–Warshall.
- Minimum spanning trees.
- Disjoint-set union (DSU).
- Graph complexity and representation trade-offs.
Projects
27 — City Route Planner

Model a network of locations and find routes between them using BFS or Dijkstra's algorithm.

28 — Campus Navigation System

Represent campus buildings and paths as a graph and calculate routes between selected locations.

29 — Social Network Analyzer

Model users and their connections, explore reachable users, and analyze connectivity.

30 — Network Connectivity Checker

Identify disconnected components and determine whether locations remain connected.

31 — Course Prerequisite Planner

Represent course dependencies and generate a valid course order using topological sorting.

32 — Road Network Builder

Connect locations at minimum total cost using Kruskal's or Prim's minimum spanning tree algorithm.

33 — Network Failure Simulator

Remove selected connections and analyze how network connectivity changes.

34 — Maze Solver

Represent a maze as a grid and find a valid path using BFS, DFS, or backtracking.

35 — Dependency Resolution Engine

Resolve package or task dependencies and detect cycles that prevent a valid execution order.

36 — Delivery Route Optimizer

Plan routes across a network of delivery locations and compare shortest-path algorithms. Multi-stop route optimization can be added as an extension.
05 — Algorithmic Problem Solving
Goal: Develop the ability to design algorithms for problems that require more than basic data structures.

Topics include:
- Recursion and recurrence relations.
- Backtracking.
- Divide and conquer.
- Greedy algorithms.
- Dynamic programming.
- Memoization and tabulation.
- Branch and bound fundamentals.
- State-space search.
- Algorithm correctness.
- Optimization through pruning.
- Comparing alternative strategies.
Projects
37 — Sudoku Solver

Solve valid Sudoku puzzles using backtracking and constraint checking.

38 — N-Queens Solver

Place queens on a chessboard without conflicts and explore different search strategies.

39 — Meeting Room Allocator

Assign the minimum number of rooms required for a set of overlapping meeting intervals.

40 — Coin Change Optimizer

Find the minimum number of coins needed for a target amount using dynamic programming.

41 — Knapsack Planner

Select items under a weight constraint to maximize total value.

42 — Sequence Similarity Tool

Calculate the longest common subsequence between two sequences.

43 — Word Segmentation Engine

Determine whether a string can be split into valid dictionary words using dynamic programming.

44 — Optimal Task Selection

Select compatible tasks to maximize total reward, using an appropriate greedy or dynamic programming approach.

45 — Edit Distance Calculator

Calculate the minimum number of operations required to transform one string into another.

46 — Algorithm Puzzle Solver

Build a reusable search engine for small constraint-based problems, supporting state exploration, pruning, and configurable rules.
06 — Files and Algorithmic Systems
Goal: Extend in-memory algorithms into applications that process persistent data and larger datasets.

Topics include:
- File input and output.
- Text and binary files.
- Sequential and indexed record access.
- Persistent data structures.
- Data parsing and validation.
- File organization.
- Index maintenance.
- External merge sort.
- Record serialization.
- Handling large datasets.
Projects
47 — Persistent Contact Database

Store contacts in files and support insertion, retrieval, modification, and deletion across program runs.

48 — File Content Search Engine

Search text files for words or patterns and compare straightforward scanning with indexed searching.

49 — Duplicate File Finder

Identify files with identical contents using file processing and hashing, with appropriate verification of matches.

50 — External Sorting Tool

Sort datasets that exceed available memory using chunk-based sorting and external merge sort.

51 — Log Analysis Engine

Parse log files, filter records, group events, and calculate summary statistics.

52 — Data Compression Utility

Implement Huffman coding to compress and decompress data.

53 — Transaction Record Indexer

Store transaction records and maintain an index for efficient lookup by transaction ID.

54 — Persistent Key-Value Store

Build a basic disk-backed key-value store with record insertion, retrieval, updates, and an index.
07 — Advanced Algorithms and Optimization
Goal: Explore algorithmic efficiency, specialized data structures, and the performance characteristics of different implementations.

Topics include:
- Advanced string matching.
- Knuth–Morris–Pratt (KMP).
- Rabin–Karp.
- Disjoint-set union.
- Advanced graph algorithms.
- Range-query structures.
- Compression and encoding.
- Memory allocation strategies.
- Benchmark design.
- Input distribution and performance.
- Profiling and optimization.
- Algorithmic trade-offs.
Projects
55 — String Search Benchmark

Implement and compare naive string matching, KMP, and Rabin–Karp.

56 — Graph Algorithm Laboratory

Compare shortest-path algorithms across appropriate graph types and input sizes.

57 — Dynamic Connectivity Simulator

Use disjoint-set union to process connectivity queries efficiently.

58 — Range Query Library

Implement and benchmark segment trees and Fenwick trees for different update and query workloads.

59 — Huffman Compression Benchmark

Evaluate compression ratios and runtime on different types of input data.

60 — Memory Pool Allocator

Implement a simple memory pool to study allocation overhead and memory reuse.

61 — Search Index Optimizer

Compare alternative index structures using lookup time, insertion cost, and memory consumption.

62 — Algorithm Benchmark Suite

Create a reusable benchmark framework that generates datasets, runs algorithms, records measurements, and compares results.
08 — Capstone Projects
Goal: Combine knowledge from previous phases to build substantial, original systems in C.

Capstones integrate multiple data structures, algorithms, file operations, testing strategies, and performance considerations.
Projects
63 — Transport and Railway Management Simulator

Model stations and routes, manage bookings, maintain queues, calculate shortest paths, and persist records.

64 — Mini Search Engine

Index documents, process search queries, support word and phrase search, and rank results using a defined relevance strategy.

65 — Operating System Algorithm Simulator

Simulate CPU scheduling, memory allocation, and page-replacement algorithms, with metrics for comparing strategies.

66 — Mini Database Engine

Build a basic record-storage engine with insertion, deletion, indexed lookup, and simple filtering. Introduce a B-tree or B+ tree as an extension.

67 — Network Routing Simulator

Model routers and weighted connections, calculate routes, simulate link failures, and compare routing strategies.
📈 Difficulty Progression
Basic C Programming
        ↓
Arrays and Strings
        ↓
Searching and Sorting
        ↓
Pointers and Dynamic Memory
        ↓
Linked Lists, Stacks and Queues
        ↓
Trees, Heaps and Hashing
        ↓
Graphs and Network Algorithms
        ↓
Recursion and Backtracking
        ↓
Greedy Algorithms and Dynamic Programming
        ↓
File Processing and Indexing
        ↓
Advanced Algorithms and Benchmarking
        ↓
Integrated Algorithmic Systems
        ↓
Original Capstone Projects
Each phase builds on concepts from earlier phases. Some concepts appear in multiple projects because repeated application is intentional.
🧩 Project Design Rules
1. No random projects
Every project must contribute to a specific learning objective or prepare for a subsequent phase.
2. Understand before implementing
Before writing code, understand the problem, expected behavior, constraints, and the algorithm you intend to use.
3. Implement important data structures yourself
For educational projects, implement the relevant data structures from scratch rather than relying entirely on prebuilt implementations.
4. Complexity matters
Document time and space complexity and explain how the chosen algorithm behaves as input size increases.
5. Memory management is part of the solution
Use pointers and dynamic allocation responsibly. Avoid memory leaks, dangling pointers, double frees, buffer overflows, and undefined behavior.
6. Prefer justified simplicity
Do not introduce a heap, tree, or graph when a simple array is sufficient. Complexity should be justified by the problem.
7. Reuse existing concepts
Later projects should combine and reinforce earlier concepts rather than repeatedly starting from scratch.
8. Grow the architecture gradually
Begin with simple programs. Introduce header files, modules, shared utilities, testing, and build automation when the project benefits from them.
9. Test more than the happy path
Test empty inputs, boundary values, duplicate records, invalid operations, and resource-allocation failures where relevant.
10. Compare alternatives
Where possible, implement two approaches to the same problem and compare their correctness, complexity, and measured performance.
11. AI is a learning tool, not a replacement
Use AI for explanations, debugging assistance, code review, and test-case generation. The final implementation and its reasoning should be understood independently.
12. Finish projects properly
A small, complete, tested, and documented project is more valuable than an unfinished implementation of an advanced algorithm.
🔄 Project Workflow
Every project should follow this workflow:

Understand → Define Requirements → Choose Data Structures → Design the Algorithm → Write Pseudocode → Implement → Test → Debug → Analyze Complexity → Optimize → Document → Commit
1. Problem definition: Describe the problem, inputs, outputs, and constraints.
2. Design: Choose appropriate data structures and explain the reasoning.
3. Algorithm: Write pseudocode and estimate time and space complexity.
4. Implementation: Develop the solution in C using appropriate functions and data types.
5. Testing: Validate expected behavior, boundary cases, and invalid inputs.
6. Debugging: Investigate logic errors, pointer errors, and memory-management problems.
7. Analysis: Explain the algorithm's complexity and correctness.
8. Optimization: Identify bottlenecks and compare alternative approaches.
9. Documentation: Record how the program works, how to run it, and its limitations.
10. Version control: Commit the completed work and document meaningful improvements.
🧪 Testing and Code Quality
Testing evolves alongside the curriculum.

Early projects can use carefully designed test cases and expected outputs. Later projects can introduce reusable tests and more systematic validation.

Important practices include:
- Compile with -Wall -Wextra -Wpedantic.
- Use debugging symbols during development.
- Use sanitizers when supported by the compiler.
- Test empty and single-element data structures.
- Test duplicate values and boundary conditions.
- Verify memory allocation and deallocation.
- Test insertion, deletion, and lookup operations independently.
- Check that algorithms return correct results for edge cases.
- Keep test data separate from implementation where appropriate.
- Benchmark algorithms using repeatable datasets.
Correctness comes before optimization. A fast algorithm that produces incorrect results is not a successful implementation.
📊 Algorithm Analysis and Benchmarking
One of the main objectives of this repository is to understand not only how algorithms work, but also how their performance changes with input size.

For relevant projects, record:
- Algorithm name.
- Input size.
- Input distribution.
- Expected time complexity.
- Auxiliary space complexity.
- Measured execution time.
- Correctness of the output.
- Observed bottlenecks.
For example, the Inventory Search Engine can compare linear search with binary search.
Algorithm	Best case	Average case	Worst case
Linear search	\(O(1)\)	\(O(n)\)	\(O(n)\)
Binary search	\(O(1)\)	\(O(\log n)\)	\(O(\log n)\)


Binary search requires sorted data and random-access indexing for the standard array implementation. Sorting the data also has a cost, so the total cost of sorting plus searching should be considered when evaluating a complete application.

Benchmarks should use multiple input sizes and appropriate repetitions. Measurements should be interpreted carefully because hardware, compiler optimizations, cache behavior, and input distribution can influence the results.
🧪 Experiments and 📝 Notes
_experiments/
A temporary playground for experimenting with:
- Pointer behavior.
- Dynamic allocation.
- Sorting algorithms.
- Recursion.
- Tree traversals.
- Hash functions.
- Graph representations.
- Algorithm optimizations.
- Sanitizers and debugging tools.
Experiments do not need to be polished or treated as standalone projects.
_notes/
A collection of personal reference notes, including:
- C pointers and memory management.
- Time and space complexity.
- Searching and sorting.
- Linked lists, stacks, and queues.
- Trees and heaps.
- Hash tables.
- Graph algorithms.
- Recursion and backtracking.
- Greedy algorithms.
- Dynamic programming.
- Common C debugging patterns.
- Algorithm templates and pseudocode.
Notes should explain concepts in my own words and include examples that I can reason through independently.
🎯 What Success Looks Like
Success means being able to receive a new algorithmic problem and independently:
1. Understand the requirements and constraints.
2. Identify the relevant data structures and algorithms.
3. Design a suitable representation of the problem.
4. Develop and justify an algorithm.
5. Estimate its time and space complexity.
6. Implement the solution in C.
7. Handle pointers and memory allocation correctly.
8. Test expected behavior and edge cases.
9. Debug logical and memory-related errors.
10. Compare alternatives and optimize when justified.
11. Document the implementation and its limitations.
12. Apply the learned concepts to larger, unfamiliar problems.
🚀 Final Objective
C Programming Fundamentals
          ↓
DSA Foundations
          ↓
Algorithmic Problem Solver
          ↓
Data Structure Implementer
          ↓
Algorithm Designer
          ↓
Systems and File Processing Developer
          ↓
Performance-Oriented C Programmer
          ↓
Advanced Algorithmic Systems Developer
          ↓
Independent Software Engineer
The ultimate objective is not to memorize a list of algorithms or complete a predetermined number of projects.

It is to develop the ability to reason about problems, choose appropriate data structures, design efficient algorithms, implement them correctly in C, and explain the trade-offs behind the resulting solution.

The principle behind this repository is simple: learn the concept, build something meaningful with it, understand the implementation, and improve it through evidence rather than guesswork.

One project at a time. One algorithm at a time. One improvement at a time.
