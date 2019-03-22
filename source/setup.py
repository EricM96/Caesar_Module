from distutils.core import setup, Extension

module = Extension("caesarCipher", sources = ["caesar.c"])

setup(name="caesarCipher",
      version="1.0",
      description="This package implements the methods for a Caesar Cipher class",
      ext_modules = [module])
