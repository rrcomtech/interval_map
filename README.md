# Application Homework

Made by: Robert Richer
Date: 2024-07-19

## Prerequisites

Choose either a Nix-based setup (recommended) or a manual setup.

Nix Setup:

- `nix`

Manual Setup:

- `cmake`
- `gcc 13.2.0`
- `ninja` or `make`

## Files

- `src/test.cpp`: Test code with Google Test.
- `src/data-structure.hpp`: The interval map data structure.

## How to run the application

The nix shell already contains commands to run the test and the application:

```bash
nix-shell --pure --run "run && test"
```

Or manually compile everything:

```bash
mkdir cmake-build && cd cmake-build
cmake -GNinja ..
./tests
```
