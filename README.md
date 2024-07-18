# Think Cell Application Homework

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

## How to run the application

First run the nix shell:

```bash
nix-shell --pure --run 
```

Then run the application:

```bash
mkdir cmake-build && cd cmake-build
cmake -G Ninja ..

```
