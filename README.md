# PolyMorphicEncryptionEnginePOC
## Overview
This code creates encrypted code that decrypts and executes within RAM. This code is only a Proof of concept and prints out "Hello World".

## Installing & Running
 All of the files are compiled already and placed within the /bin directory. All of these were compiled on Ubunutu Linux using gcc and nasm.
 This code will not work on Windows.
 To run execute Setup(from setup.c) this will change the encryption key and data for the file Needs_Setup. Then running Needs_Setup will print "Hello World".
 Running Setup again will change the encryption byte every time, you can prove this by looking at the checksum or by looking with a hex editor.  

 # Eplanation

  There are 3 files for this code Data.asm, Main.asm, and Setup.c.  
  Data.asm is Hello World in assembly, however since it does not know its location in memory it has to get that from the stack. (This code is not put in, the bytecode is in Setup.c, however this file is unused)
  Main.asm decrypts the code(within ram) and jumps to it.  This file cannot run without Setup.c because it decrypts and jumps to code that has not been put in yet.
  Setup.c Puts in the encrypted code and the decryption code into Needs_Setup(which comes from Main.asm)
  
 ## Compiling
  
  To compile for yourself, or change the code to be executed 
