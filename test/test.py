import caesarCipher

class CaesarCrypt(object):
    def __init__(self, key):
        self.key = key

    def encrypt(self, plaintext):
        return caesarCipher.encrypt(self.key, plaintext, len(plaintext))

    def decrypt(self, ciphertext):
        return caesarCipher.decrypt(self.key, ciphertext, len(ciphertext))

if __name__ == "__main__":
    myCrypt = CaesarCrypt(1)
    plaintext = "Hello World!"
    print("Plain text is:", plaintext)
    ciphertext = myCrypt.encrypt(plaintext)
    print("Cipher text is", ciphertext)
    recovered_plaintext = myCrypt.decrypt(ciphertext)
    print("New plaintext is", recovered_plaintext)
