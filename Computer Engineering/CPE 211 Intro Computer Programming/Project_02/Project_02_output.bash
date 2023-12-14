#!/bin/bash
rm $USER.out >& /dev/null
rm $USER.txt >& /dev/null
echo > $USER.txt
echo "Have your TA initial here ________________" >> $USER.txt
echo >> $USER.txt
echo "==============================" >> $USER.txt
pwd >> $USER.txt
echo "==============================" >> $USER.txt
ls -RF  >> $USER.txt
echo "==============================" >> $USER.txt
for x in *.txt
do
if [ $x != $USER.txt ]
then
ls $x    >> $USER.txt 
cat $x    >> $USER.txt 
fi
done
echo "==============================" >> $USER.txt
ls Part1a/*.txt >> $USER.txt
cat Part1a/*.txt >> $USER.txt >> $USER.txt
echo "==============================" >> $USER.txt
ls Part1a/Part1a_bk/*.cp >> $USER.txt
cat Part1a/Part1a_bk/*.cp >> $USER.txt
echo "==============================" >> $USER.txt
ls Part1b/Part1b_2/*.txt >> $USER.txt
cat Part1b/Part1b_2/*.txt >> $USER.txt
echo "==============================" >> $USER.txt
#clear
OSNAME=`uname -s`
#if [ $OSNAME == "SunOS" ]
#then
#    sdiff $USER.txt /home/work/cpe211data/Project_02/Project_02_mars.txt
if [ $OSNAME == "Linux" ]
then
    sdiff $USER.txt /home/work/cpe211data/Project_02/Project_02_$OSNAME.txt
else
    echo "host OS ($OSNAME) not recognized.  See TA"
fi

