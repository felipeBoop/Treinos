let vel = 0;
let velInicial = 0;

let nomePiloto = prompt("Informe o seu nome, piloto!");
let velocidadeDesejada = prompt("Informe a velocidade desejada!");

let sn_vel = confirm("Você deseja realmente esta velocidade?")? vel = velocidadeDesejada: vel = velInicial;

if(vel <= 0) {
    console.log("Nave está parada. Considere partir e aumentar a velocidade");
}else if(vel < 40) {
    console.log("Você esta devagar, podemos aumentar mais");
}else if(vel >= 40 && vel < 80) {
    console.log("Parece uma boa velocidade para se manter!");
}else if(vel >= 80 && vel < 100){
    console.log("velocidade alta considere diminuir.");
}else{
    console.log("velocidade perigosa. Controle automático forçado.")
}

console.log("Nome do piloto: " + nomePiloto
            + "\nvelocidade atual: " + vel);