#ofor
open file or read

#how to use
sudo apt update
sudo apt install g++

git clone https://github.com/reznote1401-debug/ofor.git
cd ofor

g++ main.cpp ofor.cpp -o fm
sudo mv fm /usr/local/bin/

#run
fm fopen fileName (open file)
fm fadd fileName (add file or edit file)
Type (exit) when you are finished.
