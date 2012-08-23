module Tron.Board where

import Data.List

-- a board is defined as a 2d array of spots
type Board = [[Spot]]

-- a spot can be one of:
data Spot = Wall | Blank | Player | Enemy 
            deriving (Show, Eq)

-- moves can go in these directions:
data Move = North | East | South | West 
            deriving (Show, Eq)

-- debugging
renderBoard :: Board -> IO ()
renderBoard rows = putStrLn $ concatMap renderRow rows

renderRow cols = concatMap renderCell cols ++ "\n"
renderCell Wall   = "#"
renderCell Blank  = " "
renderCell Player = "1"
renderCell Enemy  = "2"


-- game helpers

canMove move (x,y) board
    | move == North	= if y == 0 then False else (Blank == ((board !! (y-1)) !! x))
    | move == East	= if x+1 == (length (head board)) then False else (Blank == ((board !! y) !! (x+1)))
    | move == South	= if y+1 == (length board) then False else (Blank == ((board !! (y+1)) !! x))
    | move == West	= if x == 0 then False else (Blank == ((board !! y) !! (x-1)))

-- my position
me board = (maybe 0 id (findIndex (== Player) (head $ filter (any (== Player)) board)), maybe 0 id (findIndex (any (== Player)) board))

-- legal moves for a given board
possibleMoves board = (filter (\a -> canMove a (me board) board) [North, East, South, West]) ++ [North]
