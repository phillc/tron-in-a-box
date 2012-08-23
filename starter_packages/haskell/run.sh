#!/bin/sh
MAP=$1
MAP=${MAP:=maps/u.txt}

OPPONENT=$2
OPPONENT=${OPPONENT:=example_bots/Chaser.jar}

#echo java -jar engine/Tron.jar $MAP "runghc MyTronBot.hs" "java -jar $OPPONENT" 0
java -jar engine/Tron.jar $MAP "runghc MyTronBot.hs" "java -jar $OPPONENT" 0
