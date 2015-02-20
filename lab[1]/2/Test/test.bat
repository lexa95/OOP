cd ../Release

2.exe  10
IF ERRORLEVEL 1 GOTO err

2.exe  11 4
IF NOT ERRORLEVEL 1 GOTO err

2.exe fdg
IF NOT ERRORLEVEL 1 GOTO err

2.exe  ""
IF NOT ERRORLEVEL 1 GOTO err

2.exe  4.2
IF NOT ERRORLEVEL 1 GOTO err

2.exe  333
IF NOT ERRORLEVEL 1 GOTO err

2.exe  -1
IF NOT ERRORLEVEL 1 GOTO err

2.exe 6 > ../Test/output.txt
IF ERRORLEVEL 1 GOTO err
cd ../Test/
FC /B output.txt 6.txt
IF ERRORLEVEL 1 GOTO err

cd ../Release
2.exe 50 > ../Test/output.txt
IF ERRORLEVEL 1 GOTO err
cd ../Test/
FC /B output.txt 50.txt
IF ERRORLEVEL 1 GOTO err

ECHO Program testing succeeded :-)
PAUSE
EXIT
:err
ECHO Program testing failed :-(
PAUSE
EXIT