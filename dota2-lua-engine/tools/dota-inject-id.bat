xcopy /y Injector.exe ..\..\Release\
cd ..\..\Release
.\Injector.exe --module-name dota2-lua-engine.dll --process-id 9348 --eject
timeout 1
.\Injector.exe --module-name dota2-lua-engine.dll --process-id 9348 --inject