# PolyMorphicEncryptionEnginePOC
## Overview
This code creates encrypted code that decrypts and executes within RAM. This code is only a Proof of concept and prints out "Hello World".
For a more detailed explaination look at Detailed_Explination.md
## Installing & Running
 All of the files are compiled already and placed within the /bin directory. All of these were compiled on Ubunutu Linux using gcc and nasm.
 This code will not work on Windows.
 To run execute Setup(from setup.c) this will change the encryption key and data for the file Needs_Setup. Then running Needs_Setup will print "Hello World".
 Running Setup multiple times will change the encryption byte every time, you can prove this by looking at the checksum or by looking with a hex editor.  
 If you would like to compile this yourself look at Detailed_Explination.md
 
