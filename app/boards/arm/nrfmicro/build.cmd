@echo off

::wsl 2 version
::--set-default Ubuntu-20.04

set PROJ_ROOT=~/zmk
set PROJ_DIR=%PROJ_ROOT%/app
set UF2=%~dp0..\..\..\build\zephyr\zmk.uf2

echo %UF2%

set startTime=%time%
bash -c "cd %PROJ_DIR% && export PATH=~/.local/bin:$PATH && west build --force -b nrfmicro -- -DSHIELD=corne_left -DKEYMAP=default" || exit
echo Start Time: %startTime%
echo Finish Time: %time%

echo .
echo Waiting for the UF2 drive. Press Reset twice...
:loop
if not exist e:\ goto :loop
timeout 1
copy %UF2% e:\
