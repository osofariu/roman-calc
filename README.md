# Roman Calculator

## Compiling / Building

* To compile the code and run all tests type: make
  
    This will build all code, create roman_runner executable, and run all tests.

## Running

* To see usage, just run the program without arguments:

  $ ./roman_runner
  
      Usage: roman_runner [+ num num | - num num]

* Performing roman calculations

    Run the program with command-line arguments, as shown the the usage:
  
        ./roman_runner + X I
    
        X + I = XI
    
    The result of the roman calculation is written by the program to stdout; any errors are writte to stderr. 

## Code Organization

    The main executable is provided by roman_runner.c.  It uses roman_calculator.c to perform the roman
    arithmatic.
    
    roman_calculator.c uses roman_validation.c to validate both the input roman numerals (those upon which we
    perform the arithmetic operation) as well as on the numeral upon which the operation is performed.
     
    it also uses code provided by int_to_roman.c and roman_to_int.c to first convert each input numeral to
    decimal, perform the operation, and then convert that the decimal numer back to roman numeral format.
    
    both the validation and conversion rely on some operations provided by char_operations, which is an
    attempt to encapsulate some of the low-level character manipulation code into a sepate module.
