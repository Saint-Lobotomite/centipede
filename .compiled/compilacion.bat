@REM Compilación y Enlace con biblioteca gráfica.
@cls
@echo ---------------------------------------------------
@echo  ESAT Curso 2025-2026 Asignatura PRG Primero
@echo ---------------------------------------------------
@echo  Proceso por lotes iniciado.
@echo ---------------------------------------------------
@echo off

setlocal enabledelayedexpansion

set "SOURCES="

for /r "..\source" %%f in (*cc) do (
    set "SOURCES=!SOURCES! %%f"
)

cl /nologo /Zi /GR- /EHs /MD /Fe:..\source\main\main.exe %SOURCES% ^
-I ..\Lib_Graph\ESAT_rev248\include ..\Lib_Graph\ESAT_rev248\bin\ESAT.lib   opengl32.lib user32.lib gdi32.lib shell32.lib Ws2_32.lib

endlocal

@echo ---------------------------------------------------
@echo  Proceso por lotes finalizado.
@echo ---------------------------------------------------