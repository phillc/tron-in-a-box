var util = require('util');

function MapState() {
  var width;
  var height;
  var board = [];

  var processFirstLine = function(line) {
    var mapSize = line.split(" ");
    width = mapSize[0];
    height = mapSize[1];
    this.processLine = processMapLine;
  }

  var processMapLine = function(line) {
    board.push(line);
  }

  return {
    isComplete: function() { return board.length == height },
    processLine: processFirstLine,
    createMap: function() {
      var longBoard = board.join("");
      var isWall = function(x, y) {
        return board[y][x] != " "
      }
      var makeMove = function(direction) {
        var code = { "n": 1,
                     "s": 3,
                     "e": 2,
                     "w": 4 }[direction]
        process.stdout.write('' + code + '\n');
      }
      var convertFromIndex = function(index) {
        var x = index % width;
        var y = Math.floor(index / width);
        return [x, y];
      }
      var p1Start = convertFromIndex(longBoard.indexOf("1"));
      var p2Start = convertFromIndex(longBoard.indexOf("2"));

      return {
        board: board,
        myX: p1Start[0],
        myY: p1Start[1],
        isWall: isWall,
        makeMove: makeMove
      }
    }
  }
}

exports.Play = function(turnFn) {
  var stdin = process.openStdin();
  var buffer = '';
  var currentState = MapState();

  var processLine = function(line) {
    currentState.processLine(line);

    if(currentState.isComplete()) {
      turnFn(currentState.createMap());
      currentState = MapState();
    }
  }

  stdin.on('data', function(chunk) {
    var eol;
    var line;
    buffer += chunk;

    while(buffer.indexOf("\n") >= 0) {
      eol = buffer.indexOf("\n");
      line = buffer.substring(0, eol);
      processLine(line.trim());
      buffer = buffer.substring(eol + 1);
    }
  });

  stdin.on('end', function() {
    util.debug('end of stdin, exiting');
    process.exit();
  });
}
