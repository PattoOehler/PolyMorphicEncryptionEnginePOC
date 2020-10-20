# PolyMorphicEncryptionEnginePOC
## Overview
This code creates encrypted code that decrypts and executes within RAM. This code is only a Proof of concept and prints out "Hello World".

## Installing & Running
 All of the files are compiled already and placed within the /bin directory. All of these were compiled on Ubunutu Linux using gcc and nasm.
 This code will not work on Windows.
 To run execute Setup(from setup.c) this will change the encryption key and data for the file Needs_Setup. Then running Needs_Setup will print "Hello World".
 Running Setup again will change the encryption byte every time, you can prove this by looking at the checksum or by looking with a hex editor.  

 # Explanation

  There are 3 files for this code Data.asm, Main.asm, and Setup.c.  
  Data.asm is Hello World in assembly, however since it does not know its location in memory it has to get that from the stack. (This code is not put in, the bytecode is in Setup.c, however this file is unused) <br/>
  Main.asm decrypts the code(within ram) and jumps to it.  This file cannot run without Setup.c because it decrypts and jumps to code that has not been put in yet. <br/>
  Setup.c Puts in the encrypted code and the decryption code into Needs_Setup(which comes from Main.asm)
  
 ## Compiling
  
  To compile for yourself, you first need to compile Main.asm with "nasm -f elf64 -o Main.o Main.asm" <br/>
  Then run "ld -o Needs_Setup Main.o" to link
  then compile Setup.c with "gcc -o Setup Setup.c"
  You can then run Setup with "./Setup"
  And run Needs Setup "./Needs_Setup"
  
  if ./Needs_Setup creates an error of any kind, that means that the Locations of the ByteCodeBeginning_Location is off and/or Location_Encyrption_Value is off.
  To find the locations of these we need a fresh copy, so rerun all of the steps to compile the code, but don't execute anything.
  
  Run objdump -d Needs_Setup and look for subb $0x2, look at all the bytes around it and find that in "xxd Needs_setup" also in that find a long string of 1's (31 in hexadecimal).  Convert the location on the left side of the xxd output from hexadecimal to binary and put the locations of them both in Setup.c. Recompile and it will run.
  
