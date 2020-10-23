# tool-box
Here is some snippets that I use in my projects.

# Languages

## Arduino
These classes represents differents kind of hardware. Each class is one hardware and use standard function name to be used like *begin*, *read* or *write*.

### UART
This object is a software Serial communication. It's mostly an experimentation and is not fully working.

### Low Level Pin
This file defines MACROs to manipulate Arduino pins at a low level to increase code speed when short delay is necessary.

## C++
### Cipher
This class define an abstraction of a cipher and purpose a very simple and not secure xor cipher.

### Socket
The sockets classes are a binding of the C socket functions from unistd, so it's only working on unix system.

## C
### Format IO
This files provide a simple way to format and customize text sent to the standard output with color or style.

### UniTest
This files provide a simple set of function to make unit tests in C with equality functions, test function and test set functions.

## Java
### Nullable
It's a simple Java annotation allowing to indicate that a field, a parameter, a variable or a return value of a method can be null.

## PHP
### CSV
The CSV reader parses CSV file into an assotiative array, it maps the column name to the list of the value of each row.

### Captcha
This class allow to check the ReCaptcha validity with PHP

### Database
This class is a simple singleton to retrieve a PDO instance from a database.

### RSS
The RSS reader parses RSS file and allow to get general info and data from each news of the RSS flux.

### Redirect
This class provides static method to do secure redirection between pages.
