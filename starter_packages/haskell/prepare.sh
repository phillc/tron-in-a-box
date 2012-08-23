#!/bin/sh

cd ..
rm -f haskell.zip
zip -x 'haskell/.git/*' -x 'haskell/old/*' -x 'haskell/*.sh' -x 'haskell/game.txt' -r haskell.zip  haskell 
