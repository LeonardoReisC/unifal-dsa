# Image Processing with Pointers

## Objective:

The objective is to acquire knowledge of pointer arithmetic, processing images (matrices), and code modularization with functions in a library.

## Description:

The application developed in the project should load an image from an input file at the beginning and write an output file for each operation on the image. Each operation on the image must be encoded in a function using pointer arithmetic, and all functions must be organized into at least one function library. Functions may call each other if it is interesting to do so.

## Image File:

Each file must represent only one image, as explained in class, containing a header and the body. The header is formed by 4 data: the code "P2" on the first line, the values of the number of columns and number of rows on the second line separated by space, and the value of the number of shades of gray on the third line. The body of the file will be formed by the number of rows times the number of columns in shades of gray, and the values will be separated by spaces or line breaks, whichever is more convenient. These values will be placed from left to right and from top to bottom in a matrix of integer values, following the known orientation of the images.

## Requirements:

The application must:

- present a menu to the user with the options of the implemented operations, numbered, with the value zero indicating to exit the application;
- the source code must be commented and easy to understand;
- the project must read the image file as described above and write the files in the same format, allowing the output files to be read as input for a new execution of the application;
- operations on the input image must use pointer arithmetic and cannot use indices to manipulate any element of the matrix (indices of initial positions can only be used to start or finish the pointers created);
- the project must implement at least the following operations: negative image, vertical inversion, horizontal inversion, right rotation, and darkening of the edges;
- other operations can be implemented and will be considered as extra points;

***
