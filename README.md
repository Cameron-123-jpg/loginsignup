# loginsignup
Fun little signup/login system I made in terminal. Note, this is not safe, this is only a proof of concept. Always use hashes to store passwords, NEVER STORE IN PLAIN TEXT. Only created this to enhance my skills.

This program will create a file to store logins in the terminal, can then login using the terminal as well. Not many features. Again, this was only to test my skills. THIS IS NOT A REAL LOGIN SYSTEM

If you want to run it yourself, then open terminal and change your directory to where the file is located, then type 

`` gcc <fileName>
``

Then run 

`` a./out
``

This will create a login.txt file that stores all the login information. It checks for @ in the email, whether duplicate emails have already been used in the signup process, and also matches emails with passwords while logging in.
