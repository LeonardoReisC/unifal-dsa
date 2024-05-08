# Car, Van, and Utility Vehicle Search Manager

## Objective:

The objective is to acquire knowledge of manipulation of lists with dynamic allocation (linked list) in an application that creates a stack and a queue as a result of the search in a main list of cars, vans, and utility vehicles.

## Description:

The application developed in the project should create a main linked list with the data read from an input file. Each line of the file should be stored in a node of the list. Then the application must build a stack and a queue from searches performed on the main list, without reallocating or duplicating the nodes of the main list, through the 2 selected options. In addition, functions for inserting and removing nodes from the main list must also be implemented.

## Data File:

It will contain an unlimited number of lines, where each line will contain the data of a vehicle: model, brand, type, year, mileage, engine power, fuel, gearbox, steering, color, number of doors, and license plate. An example text file is attached.

## Requirements:

The application must:

- present a menu to the user with options for inclusion, exclusion, searches, and report;
- perform searches in the created list allowing to configure the options with some characteristics: result in stack or queue, choice of the 1st option, and choice of the 2nd option;
- the result of the search must remain in memory until a new search is performed;
- options are chosen by the vehicle data;
- when the search is finished, display the data on the screen;
- perform the inclusion operation ordered by the vehicle's license plate;
- present the report of all clients on the computer screen;
- at the end of the execution, all structures must be deallocated.
