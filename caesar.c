#include <Python.h>

static char *
cEncrypt(int key, char * plaintext, int len)
{
    for (int i = 0; i < len; ++i) {
        if ((int) plaintext[i] >= 65 && (int) plaintext[i] <= 90) {
            plaintext[i] = (char) ((int) plaintext[i] + key - 65) % 26 + 65;
        } else if ((int) plaintext[i] >= 97 && (int) plaintext[i] <= 122) {
            plaintext[i] = (char) ((int) plaintext[i] + key - 97) % 26 + 97;
        }
    }
    return plaintext;
}

static PyObject*
my_encrypt(PyObject* self, PyObject* args)
{
    int key, len;
    char* plaintext;

    if (!PyArg_ParseTuple(args, "isi", &key, &plaintext, &len)) {
        return -1;
    } else {
        return Py_BuildValue("s", cEncrypt(key, plaintext, len));
    }
}

static char *
cDecrypt(int key, char * ciphertext, int len)
{
    for (int i = 0; i < len; ++i) {
        if ((int) ciphertext[i] >= 65 && (int) ciphertext[i] <= 90) {
            int new_char = (int) ciphertext[i] - key - 65;
            if (new_char < 0) {
                new_char = new_char + 26;
            }
            new_char = new_char % 26 + 65;
            ciphertext[i] = (char) new_char;
        } else if ((int) ciphertext[i] >= 97 && (int) ciphertext[i] <= 122) {
            int new_char = (int) ciphertext[i] - key - 97;
            if (new_char < 0) {
                new_char = new_char + 26;
            }
            new_char = new_char % 26 + 97;
            ciphertext[i] = (char) new_char;
        }
    }
    return ciphertext;
}

static PyObject*
my_decrypt(PyObject* self, PyObject* args)
{
    int key, len;
    char* plaintext;

    if (!PyArg_ParseTuple(args, "isi", &key, &plaintext, &len)) {
        return -1;
    } else {
        return Py_BuildValue("s", cDecrypt(key, plaintext, len));
    }
}

static PyMethodDef caesarMethods[] = {
    {"encrypt", my_encrypt, METH_VARARGS, "Enrypts plaintext"},
    {"decrypt", my_decrypt, METH_VARARGS, "Decrypts ciphertext"},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef caesarCipher = {
    PyModuleDef_HEAD_INIT,
    "caesarCipher",
    "Caesar Module",
    -1,
    caesarMethods
};

PyMODINIT_FUNC
PyInit_caesarCipher(void)
{
    return PyModule_Create(&caesarCipher);
}
