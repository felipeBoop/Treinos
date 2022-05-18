//condicionais tb são conhecidos como controle de fluxo
let velocity = 90;

if(velocity < 40){ //avalia se uma expressão retorna um valor verdadeiro
    console.log("Velocidade baixa");
}else if(velocity <= 100){
    console.log("Cuidado! Velocidade próximo a velocidade de risco");
}else{
    console.log("Velocidade de risco!");
}

(velocity > 100) ? console.log("velocidade maior que 100"): console.log("velocidade menor que 100");