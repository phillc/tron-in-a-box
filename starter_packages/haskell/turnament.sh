#!/bin/sh

(for i in maps/*; do 
  for o in example_bots/*.jar; do
    ./run.sh $i $o | tail -n 1
    echo -n "#" >&2
  done
    echo "T" >&2
done) | sort | uniq -c
