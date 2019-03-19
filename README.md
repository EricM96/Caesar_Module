# Caesar_Module
An extension of the cPython interpreter that implements the Caesar Cipher and wraps it in a Python object oriented interface.

## Instructions For Use
### On Linux
Import the CaesarCrypt class from test/test.py
### On Windows
Unfortunately I have not had the chance to build and test the C executable in Windows yet; however, in theory, it should be easily done 
as long as you have the Python `distutils` package installed. 
- navigate into the main directory of the repo using a cmd or powershell window
- issue the command `python3 setup.py build` to create an executable of the C code that Windows can use
- the CaesarCrypt object in test/test.py _*should*_ operate as expected now (again, I have not had the opportunity to test this myself 🤷‍♂️) 
