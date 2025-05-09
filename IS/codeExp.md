# Cryptography and Security Implementations

This repository contains various implementations of cryptographic algorithms and security concepts. Each file demonstrates different encryption techniques, hashing methods, and security protocols.

## Table of Contents
1. [Assignment 1: Bitwise Operations (ass1.cpp)](#assignment-1-bitwise-operations)
2. [Assignment 2: Transposition Cipher (ass2.cpp)](#assignment-2-transposition-cipher)
3. [Assignment 3: DES Encryption (ass3.java)](#assignment-3-des-encryption)
4. [Assignment 4: AES Encryption (ass4.java)](#assignment-4-aes-encryption)
5. [Assignment 5: RSA Encryption (ass5.java)](#assignment-5-rsa-encryption)
6. [Assignment 6: Diffie-Hellman Key Exchange (ass6.html)](#assignment-6-diffie-hellman-key-exchange)
7. [Assignment 7: MD5 Hashing (ass7.java)](#assignment-7-md5-hashing)

## Assignment 1: Bitwise Operations

**File:** `ass1.cpp`

### Description
This program demonstrates basic bitwise operations (AND, XOR) on each character of a string. It shows the results of applying bitwise AND and XOR operations with the value 127 (0x7F) to each character.

### Key Concepts
- **Bitwise AND (&):** Performs a logical AND operation on each pair of corresponding bits. Returns 1 only if both bits are 1.
- **Bitwise XOR (^):** Performs a logical XOR (exclusive OR) operation. Returns 1 if the bits are different, 0 if they're the same.
- **ASCII Value Manipulation:** The program shows how these operations affect each character's ASCII value.

### Usage
The program displays:
- The original character
- The result of applying AND with 127 (which preserves only the 7 least significant bits)
- The result of applying XOR with 127 (which inverts the 7 least significant bits)

## Assignment 2: Transposition Cipher

**File:** `ass2.cpp`

### Description
This program implements a columnar transposition cipher, a classic encryption technique that rearranges the characters of a message by writing it in rows of a fixed length and then reading it by columns.

### Key Concepts
- **Columnar Transposition:** A method that changes the order of characters without changing the characters themselves.
- **Padding:** The algorithm adds underscore characters ('_') to ensure the message length is a multiple of the key.
- **Matrix Transformation:** The encryption process involves converting rows to columns and vice versa.

### Functions
- **encrypt():** Takes plaintext and a key (number of columns), writes the text in rows, reads by columns.
- **decrypt():** Takes ciphertext and the key, reconstructs the original matrix and reads by rows.

### Example
The program encrypts the message "THISISENCRYPTEDCODE" using a key of 5, showing both the encrypted and decrypted results.

## Assignment 3: DES Encryption

**File:** `ass3.java`

### Description
This program demonstrates the Data Encryption Standard (DES) algorithm using Java's Cryptography APIs. DES is a symmetric-key block cipher that operates on 64-bit blocks.

### Key Concepts
- **DES Algorithm:** A symmetric encryption algorithm that uses a 56-bit key.
- **ECB Mode:** Electronic Codebook mode, where each block is encrypted independently.
- **PKCS5Padding:** A padding scheme used to ensure the plaintext is a multiple of the block size.

### Implementation Details
- Uses `KeyGenerator` to create a DES key
- Configures a `Cipher` object with "DES/ECB/PKCS5Padding"
- Demonstrates both encryption and decryption
- Uses Base64 encoding to represent the encrypted bytes as a string

### Note
DES is now considered insecure due to its small key size and has been replaced by more secure algorithms like AES.

## Assignment 4: AES Encryption

**File:** `ass4.java`

### Description
This program demonstrates the Advanced Encryption Standard (AES) algorithm, which is currently one of the most widely used symmetric encryption algorithms.

### Key Concepts
- **AES Algorithm:** A symmetric block cipher that operates on blocks of 128 bits and supports key sizes of 128, 192, or 256 bits.
- **ECB Mode:** Electronic Codebook mode (note: generally not recommended for secure applications).
- **Secret Key:** The implementation uses a string-derived key of 16 bytes (128 bits).

### Implementation Details
- Creates an AES key from a string, ensuring it's exactly 16 bytes
- Uses the `SecretKeySpec` class to create a secret key
- Configures a `Cipher` object with "AES/ECB/PKCS5Padding"
- Demonstrates both encryption and decryption
- Uses Base64 encoding to represent the encrypted bytes as a string

### Security Note
While this demonstrates AES functionality, using ECB mode isn't recommended for secure applications. CBC, GCM, or other modes with proper IV handling would be more secure.

## Assignment 5: RSA Encryption

**File:** `ass5.java`

### Description
This program demonstrates RSA encryption, an asymmetric cryptography algorithm that uses a pair of keys (public and private) for secure data transmission.

### Key Concepts
- **RSA Algorithm:** An asymmetric encryption algorithm based on the mathematical properties of large prime numbers.
- **Key Pair:** RSA uses two keys - a public key for encryption and a private key for decryption.
- **Public Key Cryptography:** The encryption key can be shared publicly, while the decryption key remains private.

### Implementation Details
- Generates a 2048-bit RSA key pair using `KeyPairGenerator`
- Encrypts a message using the public key
- Decrypts the message using the private key
- Uses "RSA/ECB/PKCS1Padding" as the transformation
- Uses Base64 encoding to represent the encrypted bytes as a string

### Applications
RSA is commonly used for secure data transmission, digital signatures, and key exchange in various security protocols like SSL/TLS.

## Assignment 6: Diffie-Hellman Key Exchange

**File:** `ass6.html`

### Description
This is an interactive web page that demonstrates the Diffie-Hellman key exchange protocol, which allows two parties to establish a shared secret over an insecure communication channel.

### Key Concepts
- **Diffie-Hellman Protocol:** A method for securely exchanging cryptographic keys over a public channel.
- **Modular Exponentiation:** The mathematical operation that makes the protocol secure.
- **Primitive Root:** A number with special properties in modular arithmetic.
- **Shared Secret:** A value that only the communicating parties can compute.

### Implementation Details
- Interactive HTML interface with inputs for:
  - Prime number (p)
  - Primitive root (g)
  - Alice's private key (a)
- Randomly generates Bob's private key
- Calculates public keys for both parties
- Demonstrates that both parties arrive at the same shared secret
- Uses custom `modPow()` function for efficient modular exponentiation

### Importance
The Diffie-Hellman key exchange is a fundamental building block of many secure communication protocols including SSL/TLS used in HTTPS.

## Assignment 7: MD5 Hashing

**File:** `ass7.java`

### Description
This program demonstrates the MD5 hashing algorithm, which generates a 128-bit hash value typically expressed as a 32-character hexadecimal number.

### Key Concepts
- **Cryptographic Hash Function:** A one-way function that maps data of arbitrary size to a fixed-size bit string.
- **MD5 Algorithm:** A widely used hash function that produces a 128-bit (16-byte) hash value.
- **Hexadecimal Representation:** The binary hash is converted to a more readable hexadecimal string.

### Implementation Details
- Uses Java's `MessageDigest` class for MD5 hashing
- Takes user input via console
- Converts the hash bytes to a hexadecimal string
- Displays the resulting MD5 hash

### Security Note
MD5 is now considered cryptographically broken and unsuitable for security applications. More secure alternatives include SHA-256, SHA-3, and BLAKE2.
