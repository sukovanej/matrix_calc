# MatrixCalc

```bash
$ ./matrixcalc
matrix_calc, 2018 (c) Milan Suk | github.com/sukovanej 

Usage: matrix_calc input_filename [-o|--output output_file] 

 -h, --help    -- Show help
 -o, --output  -- Output file
 -e, --eval    -- Evaluate string input%
```

## Installation

I use cmake

```bash
$ git clone https://github.com/sukovanej/matrixcalc
$ cd matrixcalc
$ cmake --build ./bin --target matrixcalc -- -j 4
```

Tests can be built using `matrixcalc_test` target.

## Basic usage

Program could be used like a calculator although it is matrix evaluator.
The eval deals with scalar values as they were 1x1 matrices. Thus one can
evaluate expressions like:

```bash
$ matrixcalc -e "1 + 2"
3.000000
```

or 

```bash
$ matrixcalc -e "10 + 2 * (3 - 4 / (3 - 2)) + 1"
9.000000
```

Matrix is defined by its values. Every value in a row is separated using
a comma. Every line is separated by comma and a newline character `\n`.

For example

```
1, 2,
2, 3
```

## Variables

New variables are defined using `=` sign. Its content can shown by simply
typing the variable name as a new expression.

```bash
$ /matrixcalc -e "
A = 1, 2,
    2, 3
A
"
1.000000, 2.000000
2.000000, 3.000000
```

Every defined variable can be then used in an expression as well. For example
vector scalar product can be done by defining two transposed vectors as folow:

```bash
$ ./matrixcalc -e "
A = 1,1,
B = 3, 4
B * A
"
11.000000
```

In different order the scalar product should produce a 2x2 matrix. Lets check
it :).

```bash
$ ./matrixcalc -e "
A = 1,
    2
B = 3, 4
A * B
"
3.000000, 4.000000
6.000000, 8.000000
```

Of course every defined variable could be used by another var-definition.

```bash
$ ./matrixcalc -e "
A = 2, 3
B = (1, 0) + A
B
"
3.000000, 3.000000
```

## Matrix functions

I've just implemented `det` (determinant) and `trans` (transpose) operators. 
I'm planning user defined functions support also and more builtin functions.
For now this can be used.

```bash
./matrixcalc -e "
A = 1,  2,  33,
    34, 25, 16,
    7,  8,  9
 
trans(A)
trans(A) * A
det(A)
det(A) * A
"
 
1.000000, 34.000000, 7.000000
2.000000, 25.000000, 8.000000
33.000000, 16.000000, 9.000000
 
1206.000000, 908.000000, 640.000000
908.000000, 693.000000, 538.000000
640.000000, 538.000000, 1426.000000
 
2910.000000
 
2910.000000, 5820.000000, 96030.000000
98940.000000, 72750.000000, 46560.000000
20370.000000, 23280.000000, 26190.000000
```

## Reading input from a file

First argument is file path by default. 

```bash
$ echo "(1, 2) + (1, 1)" > test_input
$ matrixcalc test_input
2.000000, 3.000000
```