#Digital Logic Circuit Simulator

This repository contains a C++ program developed as an assignment for the "Programmieren 2" course in the Technical Computer Science program at the Augsburg University of Applied Sciences. The goal of the project is to learn and apply the concepts of object-oriented programming, multiple inheritance, and virtual functions, as well as the usage of the `vector` class to create variable storage for objects. The program is designed to simulate digital logic circuits, such as simple logic gates (AND, OR, XOR), half adders, and full adders.

## Project Structure

The project consists of several files:

- `schnittstelle.h`: Contains the definition of the interface class and its associated functions.
- `baustein.h`: Contains the definition of the basic building block class and its associated functions.
- `oder2.h`, `und2.h`, `xor2.h`: Contains the definitions and implementations of the OR, AND, and XOR logic gate classes, respectively.
- `schaltung.h`: Contains the definition of the circuit class and its associated functions.
- `halbaddierer.h`: Contains the definition of the half adder class and its associated functions.
- `volladdierer.h`: Contains the definition of the full adder class and its associated functions.
- `main.cpp`: Contains the test functions to be implemented and called in the `main()` function.
    
## Learning Objectives
   
The main learning objectives of this project include:
    
- Understanding the fundamentals of object-oriented programming (OOP).
- Implementing multiple inheritance and virtual functions.
- Using the `vector` class to store objects.
- Simulating digital logic circuits using OOP.

Secondary learning objectives include:

- Introduction to logic and simple circuits.

## Compilation and Execution

To compile and run the program, follow these steps:

1.  Make sure you have a C++ compiler installed (e.g., g++).
    
2.  Open a terminal and navigate to the directory containing the source files.
    
3.  Compile the program using the following command:
    
    ```
    g++ -o digital_logic_circuit_simulator main.cpp
    ```
    
4.  Run the compiled program with:
    ```
    ./digital_logic_circuit_simulator
    ```
    

## Usage

When running the program, you can create instances of different digital logic circuit components, such as AND, OR, XOR gates, half adders, and full adders. You can connect these components to create more complex circuits and simulate their behavior.

## Contributing

Contributions to this project are welcome. If you have any suggestions for improvements or additional features, please feel free to open an issue or submit a pull request on the project's GitHub repository.

## License

This project is licensed under the Apache 2.0 License. See the LICENSE file for more information.

## Acknowledgments

We would like to thank the instructors and the teaching assistants of the "Programmieren 2" course for their guidance and support throughout the development of this project.

Additionally, we appreciate the contributions of fellow students and open source community members who have provided feedback and suggestions for improvement.

## Disclaimer

This project is meant for educational purposes only. While the program can be used to simulate digital logic circuits, it is not intended to replace any official tools or be used for any illegal activities. The creators of this project are not responsible for any misuse or consequences resulting from the use of the program.
