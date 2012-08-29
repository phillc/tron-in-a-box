var util = require('util');
var Map = require("./map");

function DoTurn(map) {
  var validMoves = [];

  if(!map.isWall(map.myX, map.myY - 1)) {
    validMoves.push("n");
  }
  if(!map.isWall(map.myX, map.myY + 1)) {
    validMoves.push("s");
  }
  if(!map.isWall(map.myX - 1, map.myY)) {
    validMoves.push("w");
  }
  if(!map.isWall(map.myX + 1, map.myY)) {
    validMoves.push("e");
  }

  if(validMoves.length == 0) {
    util.debug("crap, just move north")
    map.makeMove("n");
  } else {
    move = validMoves[Math.floor(Math.random() * validMoves.length)];
    util.debug("moving " + move)
    map.makeMove(move);
  }
}

Map.Play(DoTurn);
