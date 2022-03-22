var botaoAdicionar = document.querySelector("#adicionar-paciente");
botaoAdicionar.addEventListener("click", function(event) {
    event.preventDefault();

    var form = document.querySelector("#form-adiciona");

    var paciente = obtemPacienteDoFormulario(form);

    var pacienteTr = montaTr(paciente);

    var erros = validaPaciente(paciente); 

    if(erros.length > 0){

        exibreMensagensDeErro(erros);
        return;
    }

    var tabela = document.querySelector("#tabela-pacientes");

    tabela.appendChild(pacienteTr);
    
    form.reset();
    var ul = document.querySelector("#mensagens-erro");
    ul.innerHTML  = "";
});

function obtemPacienteDoFormulario(form) {

    var paciente = {
        nome: form.nome.value,
        peso: form.peso.value,
        altura: form.altura.value,
        gordura: form.gordura.value,
        imc: calculaImc(form.peso.value, form.altura.value)
    }

    return paciente;
}

function montaTr(paciente) {
    var pacienteTr = document.createElement("tr");
    pacienteTr.classList.add("paciente");

    pacienteTr.appendChild(montaTd(paciente.nome, "info-nome"));
    pacienteTr.appendChild(montaTd(paciente.peso, "info-peso"));
    pacienteTr.appendChild(montaTd(paciente.altura, "info-altura"));
    pacienteTr.appendChild(montaTd(paciente.gordura, "info-gordura"));
    pacienteTr.appendChild(montaTd(paciente.imc, "info-imc"));

    return pacienteTr;
}

function montaTd(dado, classe) {
    var td = document.createElement("td");
    td.classList.add(classe);
    td.textContent = dado;

    return td;
}

function validaPaciente(paciente){

    var erros = [];

    if(!validaPeso(paciente.peso)) erros.push("O peso é inválido!");
    if(!validaAltura(paciente.altura))  erros.push("A altura é inválida!");
    if(paciente.nome.length == 0) erros.push("O nome não pode ser em branco!");
    if(paciente.gordura.length == 0) erros.push("A porcentagem de gordura não pode ser em branco!");

    return erros;
}

function exibreMensagensDeErro(erros){
    var ul = document.querySelector("#mensagens-erro");
    ul.innerHTML = "";

    erros.forEach(function(erro){
        var li = document.createElement("li"); 
        li.textContent = erro;
        ul.appendChild(li);
    });
}

function adicionaPaciente(paciente){

    var pacienteTr = montaTr(paciente);
    var tabela = document.querySelector("#tabela-pacientes");
    tabela.appendChild(pacienteTr);

    // var pacienteAdd = document.querySelectorAll(".paciente");
    // var contador = 0;

    // for(var i = 0; i < pacienteAdd.length; i++){

    //     var pacienteOld = pacienteAdd[i];

    //     if((pacienteOld != undefined) && (contador == 0)){

    //         var tdNome = pacienteOld.querySelector(".info-nome");
    //         var nome = tdNome.textContent;
    //         console.log(nome);

    //         if(nome == paciente.nome){
    //             console.log("entrei aq");
    //             contador++;
    //         }
    //     }
    // }

    // console.log(nome);
    
    //console.log(contador);

    //monta o paciente
    
}