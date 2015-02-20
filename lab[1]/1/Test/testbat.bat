1.exe  
IF NOT ERRORLEVEL 1 GOTO err

1.exe 45t
IF NOT ERRORLEVEL 1 GOTO err

1.exe 45 4 4
IF NOT ERRORLEVEL 1 GOTO err

1.exe  ""
IF NOT ERRORLEVEL 1 GOTO err

1.exe inputFile1.txt output.txt text 1
IF ERRORLEVEL 1 GOTO err
FC /B output.txt outputFile1.txt
IF ERRORLEVEL 1 GOTO err

1.exe inputFile2.txt output.txt 123 abc
IF ERRORLEVEL 1 GOTO err
FC /B output.txt outputFile2.txt
IF ERRORLEVEL 1 GOTO err


ECHO Program testing succeeded :-)
PAUSE
EXIT

:err
ECHO Program testing failed :-(
PAUSE
EXIT