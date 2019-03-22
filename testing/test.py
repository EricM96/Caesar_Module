import sys
sys.path.append('../deliverable')
from caesarCrypt import CaesarCrypt

def main():
    crypt = CaesarCrypt(25)
    test_string = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    print(test_string)
    crypt.encrypt(test_string)
    print(test_string)
    crypt.decrypt(test_string)
    print(test_string)

if __name__ == "__main__":
    main()
