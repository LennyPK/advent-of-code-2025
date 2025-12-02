# Advent of Code 2025

My solutions for the [2025 Advent of Code](https://adventofcode.com).

## Running C++ Files on Linux, Mac, and Windows

> [!CAUTION]
> These instructions have been written with the help of AI and have not been verified.  
> The Linux instructions are the most likely to work as-is.

Open your terminal in the respective day folder. For example:

```bash
advent-of-code-2025/day-1 $
```

---

### Linux

#### Compile

```bash
g++ -g ./src/main.cpp -o main
```

#### Run

```bash
./main
```

---

### Mac

#### Compile and Run

```bash
g++ -o main src/main.cpp
./main
```

#### Prerequisites

* Install Xcode Command Line Tools:

```bash
xcode-select --install
```

---

### Windows

#### Using g++ (MinGW)

```cmd
g++ -o main.exe src/main.cpp
main.exe
```

#### Using Clang

```cmd
clang++ -o main.exe main.cpp
main.exe
```

#### Prerequisites

* Install MinGW, MSVC, or Clang from their respective official sources.
