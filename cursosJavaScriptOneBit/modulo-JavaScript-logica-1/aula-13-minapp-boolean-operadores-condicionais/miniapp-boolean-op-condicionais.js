let dataPartidaEntrada = prompt("digite a data de saída (*formato DD/MM/YYYY*): " );
let dataPartida = moment(dataPartidaEntrada, "DD/MM/YYYY"); //conversão de texto para data!
let dataHoje = moment();
let dataDif = dataHoje - dataPartida;

let escolhaUsuario = prompt("Escolha vomo gostaria de exibir a data de partida\n1 - segundos\n 2 - Minutos\n 3 - Horas\n 4 - Dias");

switch(escolhaUsuario){ 
    case 1: let segundosDePartida = Math.round(dataDif / 1000); 
            alert("Tempo de vôo:" + segundosDePartida + " segundos");
            break;
    case 2: let minutosDePartida = Math.round((dataDif / 1000) / 60);
            alert("Tempo de vôo:" + minutosDePartida + " minutos");
            break;
    case 3: let HotasDePartida = Math.round((dataDif / 1000) / 3600);
            alert("Tempo de vôo:" + HotasDePartida + " horas");
            break;
    case 4:let DiasDePartida = Math.round(((dataDif / 1000) / 3600) / 24);
            alert("Tempo de vôo:" + DiasDePartida + " dias");
            break;
    default: alert("Opcao Invalida!");
}