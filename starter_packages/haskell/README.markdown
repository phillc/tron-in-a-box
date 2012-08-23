Yet another haskell tron starter package
========================================

Why?
----

I personally found the haskell starter kit a bit confusing, and I needed some time to understand the protocol.

I also considered starting with http://github.com/ozataman/tronhs but after a while I preferred to roll out my own.

How?
----

Edit MyTronBot.hs and implement your strategy in the "react" function.

There are some utility functions in Tron/Board.hs, took from the official haskell starter.

Todo
----

I'm planning to extend the starter with support for a state monad, in order to be able to use knowledge from previous steps, and perhaps also extend the board
types in order to distinguish trails from walls.
