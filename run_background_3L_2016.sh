#!/bin/bash
# reads signal input file and generates new file with BDT variable
#mkdir /cms/mchristos/ANN/Seesaw/2016/92X/outFiles/SeesawTMVAClassificationApplication$1/Background
source /cvmfs/sft.cern.ch/lcg/views/LCG_94/x86_64-slc6-gcc7-opt/setup.sh
export DISPLAY=localhost:0.0
mkdir outFiles/Application_$1 
echo $2
mkdir outFiles/Application_$1/$2
cp Application_2016.C outFiles/Application_$1/$2/Application_2016.C
sed -i "s/QQQ/$2/g;" outFiles/Application_$1/$2/Application_2016.C
sed -i "s/JJJ/$1/g;" outFiles/Application_$1/$2/Application_2016.C
root -l -q outFiles/Application_$1/$2/Application_2016.C