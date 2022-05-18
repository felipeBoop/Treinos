let spaceship = "Elemental"
let velocity = 20

console.log(spaceship.length == 9 && velocity > 15);
//V && V == V

console.log(velocity > 10 && velocity < 19);
//V && F == F

console.log(velocity < 17 && spaceship == "Elemental");
//F && V == F

console.log(spaceship == "Golias" && velocity > 21);
//F && F == F
// qualquer falso no && == falso

console.log(spaceship,length == 9 || velocity > 15);
//V || V == V

//qualquer verdadeiro == verdadeiro

//NOT reverte a expressão =) 