module Main where

import Tron.Protocol
import Tron.Board
import System.IO

-- main strategy
react :: Strategy
react board = head $ possibleMoves board

main = do
  playStdin react
