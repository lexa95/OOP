cd ../Release

4.exe  6
IF ERRORLEVEL 1 GOTO err

4.exe  
IF NOT ERRORLEVEL 1 GOTO err

4.exe 45t
IF NOT ERRORLEVEL 1 GOTO err

4.exe 45 4 4
IF NOT ERRORLEVEL 1 GOTO err

4.exe  ""
IF NOT ERRORLEVEL 1 GOTO err

4.exe 15 + 2 + 90 > ../Test/output.txt
IF ERRORLEVEL 1 GOTO err
cd ../Test/
FC /B output.txt 15+2+90.txt
IF ERRORLEVEL 1 GOTO err

cd ../Release

4.exe 15 + 5 - 90 > ../Test/output.txt
IF ERRORLEVEL 1 GOTO err
cd ../Test/
FC /B output.txt 15+5-90.txt
IF ERRORLEVEL 1 GOTO err


ECHO Program testing succeeded :-)
PAUSE
EXIT

:err
ECHO Program testing failed :-(
PAUSE
EXIT