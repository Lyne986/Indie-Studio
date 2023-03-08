# Execute this script only on window in Visual Studio (WARNING : SOMETIMES VISUAL STUDIO DELETE CMAKE FOLDER)

Set-Location .\build
cmake .. -DCMAKE_MODULE_PATH=../cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_RUNTIME_OUTPUT_DIRECTORY=.
cmake --build .
msbuild .\bomberman.sln 
Set-Location .\Debug
cp bomberman.exe ../../
Set-Location ../../
./bomberman.exe
