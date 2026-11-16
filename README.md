# PC Lab — Simplified Exam Practice

11 short programs based on the original Lab 2 (OpenMP) and Lab 3 (MPI) uploads. Practice writing them from memory. Use these only where permitted in your practical exam.

## Compile and run

OpenMP C:
```bash
gcc -fopenmp lab_2a.c -o lab_2a
./lab_2a
```
OpenMP C++:
```bash
g++ -fopenmp lab_2e.cpp -o lab_2e
./lab_2e
```
MPI C++ (requires MPI installed):
```bash
mpic++ lab_3a.cpp -o lab_3a
mpirun -np 4 ./lab_3a
```
Run `lab_3c.cpp` with `-np 4`, `lab_3d.cpp` with `-np 6`, and `lab_3e.cpp` with `-np 4` (or any process count >= 2).

## The patterns to memorize

- **OpenMP hello:** `#pragma omp parallel`; `omp_get_thread_num()`; `omp_get_num_threads()`.
- **OpenMP for:** `#pragma omp parallel for`; each iteration computes a separate result.
- **OpenMP reduction:** `reduction(max:maxVal)` or `reduction(+:sum)`.
- **OpenMP producer/consumer:** `atomic write/read` for ready flag; `critical` for shared inventory.
- **MPI skeleton:** `MPI_Init` -> `MPI_Comm_rank` -> `MPI_Comm_size` -> work -> `MPI_Finalize`.
- **MPI Scatter:** root gives one element to each process.
- **MPI Reduce:** processes combine values with `MPI_SUM` or `MPI_MAX`.
- **MPI ring:** each rank receives from the left, sends to the right; rank 0 sends first.

## Changes/limitations

- `lab_2c.c` uses fixed-capacity 20x20 arrays with user-supplied compatible dimensions, computes both sequential and parallel times. For tiny matrices, parallel timing may be slower and measurements can be too small to interpret.
- `lab_2b.c` has one producer and two consumers. It uses atomic read/write for signaling, so consumers do not read a shared flag unsafely. Print order can vary.
- `lab_2d.cpp` collects prime flags in an array, then prints in sorted order without needing `critical` or `sort`.
- `lab_3c.cpp` expects 4 processes; `lab_3d.cpp` expects 6; `lab_3e.cpp` needs 2 or more.
- OpenMP programs were compiled and run with GCC/G++ here. MPI compiler/runtime was not available for full MPI compile or runtime testing.
