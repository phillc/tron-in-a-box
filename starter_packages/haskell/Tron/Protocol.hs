module Tron.Protocol where

import System.IO
import Data.List
import Tron.Board 


-- basic operations

-- parses a board of a hiven height
parseBoard :: Int -> [String] -> Board
parseBoard h lines = map (map readSpot) $ take h lines

-- transforms a lazy list of lines into a lazy list of boards
linesToBoards :: [String] -> [Board]
linesToBoards [] = []
linesToBoards lines = parseBoard height thisBoard : linesToBoards rest
    where (thisBoard, rest) = splitAt height $ tail lines
          height = read $ head $ words $ head lines

-- a strategy is a function from a board to the next move
type Strategy = Board -> Move

-- a game is the application of the a strategy on a list of boards, resulting with a list of moves
game :: Strategy -> [Board] -> [Move]
game strategy boards = map strategy boards

-- the game is played by parsing the input stream of boards and rendering the moves
play file strategy = hInteract file $ renderMoves . game strategy . linesToBoards . lines

-- moves are rendered as a lazy string of rendered moves terminated by new lines
renderMoves = concatMap $ newline . renderMove



-- protocol utilities

hInteract file f = do 
  s <- hGetContents file
  putStr (f s)


setBuffers = do
    hSetBuffering stdin LineBuffering
    hSetBuffering stdout LineBuffering

-- engine interaction require line-buffered stdin communication
playStdin strategy = do 
  setBuffers
  play stdin strategy


-- render and parse utilities

newline s = s ++ "\n"
renderMove North = "1"
renderMove East  = "2"
renderMove South = "3"
renderMove West  = "4"

readSpot '#' = Wall
readSpot ' ' = Blank
readSpot '1' = Player
readSpot '2' = Enemy



-- useful for standalone testing

savedGame = "game.txt"

loadGame name = openFile name ReadMode

loadBoard name = do
  fi <- loadGame name
  str <- hGetContents fi
  return $ head $ linesToBoards $ lines $ str

offline strategy= do
  fi <- loadGame savedGame
  play fi strategy


