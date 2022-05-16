alert("Bem vindo! A seguir pediremos que informe alguns dados.");

let nome = prompt("Por favor, informe o seu nome: "); 
let idade = prompt("Por favor informe a sua idade: ");
let idadecm = confirm("Você confirma que  possui " + idade + " anos?");

alert("O nome de usúario digitado foi: " + nome 
     + "\ncom a idade de: " + idade 
     + "\nanos e sua confirmação de idade retornou: " + idadecm );