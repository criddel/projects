const GRID = [
      ["", "", "", "^", "", "", "", "", "", ""],
      ["", "", "v", "", "~", "", "", "", "", ""],
      ["", "v", "", "", "^", "^", "", "", "", ""],
      ["", "", "", "", "^", "^", "", "", "", ""],
      ["", "", "", "", "", "", "", "", "v", ""],
      ["", "", "", "", "", "", "", "", "", ""],
      ["", "", "", "", "", "", "", "", "", ""],
      ["", "^", "~", "~", "", "", "", "^", "", ""],
      ["", "^", "", "~", "~", "", "", "", "", ""],
      ["", "^", "", "", "~", "~", "", "", "", ""],
    ];

function countRows()  {
	return GRID.length;
}

function countColumns()  {
	return GRID[0].length;
}


function gridSize()  {
	return countColumns() + " x " + countRows();
}

function totalCells() {
	return countColumns() * countRows();
}

function convertColumn(n)  {
  return n.charCodeAt(0)-65;
}

function lightCell(n)  {
	if ((convertColumn(n) >= countColumns()) || (n[1] >= countRows())) 
		return false;
	return GRID[n[1]-1][convertColumn(n)];
}

function isRock(n)  {    
	return (lightCell(n) == '^');  
}

function isCurrent(n)  {    
	return (lightCell(n) == '~');  
}

function isShip(n)  {    
	return (lightCell(n) == 'v');  
} 

function lightRow(n)  {
	var array = [];
 	for (var i = 0; i < GRID[n].length; i++) {
		array.push(GRID[n-1][i]);
  	}
	return array;
}

function lightColumn(n)  {
	var array = [];
	for (var i = 0; i < GRID.length; i++) {
		array.push(GRID[i][convertColumn(n)]);
 	 }
	return array;
}

function allRocks() {
	var Array = [];
  	for (var i = 0; i < GRID.length; i++)  {  
    		for (var j = 0; j < GRID[0].length; j++) {
			if (GRID[i][j] == '^') Array.push(String.fromCharCode(65+j) + (i+1)); 
    		}
 	}
return Array;
}

function allCurrents() {
 	var Array = [];
 	for (var i = 0; i < GRID.length; i++)  {  
    		for (var j = 0; j < GRID[0].length; j++) {
      			if (GRID[i][j] == '~') Array.push(String.fromCharCode(65+j) + (i+1)); 
    		}
  	}
	return Array;
}

function allShips() {
	var Array = [];
		for (var i = 0; i < GRID.length; i++)  {  
 			for (var j = 0; j < GRID[0].length; j++) {
      				if (GRID[i][j] == 'v') Array.push(String.fromCharCode(65+j) + (i+1)); 
    		}
  	}
return Array;
}

function firstRock() {
	for (var i = 0; i < GRID.length; i++)  {  
		for (var j = 0; j < GRID[0].length; j++) {
			if (GRID[i][j] == '^') return String.fromCharCode(65+j) + (i+1); 
		}
	}
}

function firstCurrent() {
	return allCurrents()[0];
}

function shipReport() {
 	var Array = [];
 	Array.push(allShips()[0]);
 	Array.push(allShips()[allShips().length-1]);
 	return Array;
}

function howDangerous(n)  {
 	if (isRock(n)) return 100;
 	else if (isCurrent(n)) return 50;
 	else return 0;
}

function percentageReport()  {
	var rocks = allRocks.length/totalCells();
	var current = allCurrents.length/totalCells();
  	var Array = [rocks.toFixed(2), current.toFixed(2)];
  	return Array;
}

function safetyReport() {
  	var SafetyGrid = GRID;
  	for (var i = 0; i < SafetyGrid.length; i++)  {  
    		for (var j = 0; j < SafetyGrid[0].length; j++) {
      			if (SafetyGrid[i][j] == "^") SafetyGrid[i][j] = 100;
      			else if (SafetyGrid[i][j] == "~") SafetyGrid[i][j] = 50;
      			else SafetyGrid[i][j] = 0;
    		}  
  	}    
	return SafetyGrid;
}

function calcDistance(n, m)  {
  	var distance = Math.sqrt(Math.pow(((n.charCodeAt(0)-65) - (m.charCodeAt(0)-65)),2)+ Math.pow((n[1]-m[1]), 2));
  	return distance;
  
}

