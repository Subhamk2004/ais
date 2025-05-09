
# Information Security Assignments 📚🔐

This repository contains 7 assignments that demonstrate various cryptographic algorithms and concepts implemented in C++, Java, and HTML. Each section below outlines the theoretical background, implementation details, and how to run the respective assignment.

---

## 🔢 Assignment 1: Bitwise Operations in Cryptography (C++)

### 📖 Theory
Bitwise operations such as AND and XOR are fundamental in cryptographic applications. XOR is particularly useful due to its reversible nature, making it ideal for simple encryption schemes.

### 🧠 Code Explanation
- A hardcoded string is manipulated using `& 127` and `^ 127` operations.
- `AND with 127` clears the 8th bit of a character.
- `XOR with 127` flips all bits except the most significant one.
- Demonstrates how such operations can be used to obfuscate text.

### ▶️ How to Run
```bash
g++ ass1.cpp -o ass1 && ./ass1
```

---

## 🔐 Assignment 2: Columnar Transposition Cipher (C++)

### 📖 Theory
A transposition cipher rearranges characters of the plaintext. In the columnar variant, the plaintext is written row-wise into a matrix and read column-wise.

### 🧠 Code Explanation
- Pads the input with `_` to fit a matrix format.
- Encryption: reads characters column-wise based on a key (number of columns).
- Decryption: reverses the process to reconstruct the plaintext.

### ▶️ How to Run
```bash
g++ ass2.cpp -o ass2 && ./ass2
```

---

## 🔐 Assignment 3: DES (Java)

### 📖 Theory
DES (Data Encryption Standard) is a symmetric-key algorithm used to encrypt data in 64-bit blocks using a 56-bit key.

### 🧠 Code Explanation
- Uses Java's built-in cryptography libraries.
- Generates a DES key and encrypts/decrypts a hardcoded string (`Namaste India`).
- Uses ECB mode with PKCS5 padding.

### ▶️ How to Run
```bash
javac ass3.java && java ass3
```

---

## 🔐 Assignment 4: AES (Java)

### 📖 Theory
AES is a symmetric cipher algorithm that supports key sizes of 128, 192, or 256 bits. It's widely used for secure data encryption.

### 🧠 Code Explanation
- Manually specifies a 16-byte key (128-bit AES).
- Encrypts the string `AES encryption` and then decrypts it.
- Uses AES in ECB mode with Base64 for encoding.

### ▶️ How to Run
```bash
javac ass4.java && java ass4
```

---

## 🔐 Assignment 5: RSA (Java)

### 📖 Theory
RSA is an asymmetric encryption algorithm that uses a pair of public and private keys. It is primarily used for secure data transmission.

### 🧠 Code Explanation
- Generates an RSA key pair.
- Encrypts and decrypts a message using Java's cryptography libraries.
- Demonstrates the use of public/private key encryption.

### ▶️ How to Run
```bash
javac ass5.java && java ass5
```

---

## 🔐 Assignment 6: Diffie-Hellman Key Exchange (HTML)

### 📖 Theory
The Diffie-Hellman algorithm allows two parties to generate a shared secret over an insecure channel. It's foundational to public key cryptography.

### 🧠 Code Explanation
- HTML/CSS layout to visualize or explain the key exchange.
- Designed as a static webpage for theoretical explanation.
- Use a browser to view.

### ▶️ How to Run
Open `ass6.html` in any web browser.

---

## 🔐 Assignment 7: MD5 Hashing (Java)

### 📖 Theory
MD5 is a widely used hash function producing a 128-bit hash value. Though now considered insecure for cryptographic use, it’s still valuable for checksums.

### 🧠 Code Explanation
- Prompts user input.
- Hashes the input using MD5 and outputs the hexadecimal representation.
- Shows how to use `MessageDigest` in Java.

### ▶️ How to Run
```bash
javac ass7.java && java ass7
```

---

## ✅ Summary

This set of assignments covers a wide range of fundamental concepts in cryptography including:
- Symmetric & asymmetric encryption (DES, AES, RSA)
- Hashing (MD5)
- Classical ciphers (transposition)
- Key exchange (Diffie-Hellman)
- Bitwise manipulation for obfuscation

Each example provides a practical understanding of the respective cryptographic method.
