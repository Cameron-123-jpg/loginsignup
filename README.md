# login-signup

Fun little signup/login system I made that runs in the terminal.

**Important:** This is a proof-of-concept and **not secure**.  
Do **NOT** use this for real authentication. Passwords are stored in plaintext in `login.txt` in this repository by default — in production you must hash and salt passwords (e.g. use libsodium / Argon2id, bcrypt, etc.).

## Features
- Create accounts (email + password)
- Prevents duplicate emails
- Basic email validation (checks for `@`)
- Login by matching email and password against `login.txt`

## Build & run

Compile (replace `file.c` with your source file):
```bash
gcc file.c -o loginapp
./loginapp
```

This will create a login.txt file in the working directory which stores email and password pairs in the format:

email@example.com,plaintextpassword

## Security notes
	•	For real apps, never store plaintext passwords. Use a password-hashing library (libsodium, bcrypt, Argon2) and verify with the library on login.
	•	This program is for learning purposes only.
