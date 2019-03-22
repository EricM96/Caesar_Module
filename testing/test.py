# Importing classes in Python can be rather tricky. You have to first add the directory the file is
# stored in to Pythons path variable. The following two line demonstrates how this can be done.
import sys
sys.path.append('../deliverable')
from caesarCrypt import CaesarCrypt

def main():
    # the initialization arguement is the shift key. It can be any number between 1-25
    crypt = CaesarCrypt(25)
    test_string = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    print(test_string)
    # the C code encrypts and decrypts strings in place 
    crypt.encrypt(test_string)
    print(test_string)
    crypt.decrypt(test_string)
    print(test_string)

if __name__ == "__main__":
    main()
