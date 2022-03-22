var btnAdicionar = document.querySelector("#buscar-paciente");

btnAdicionar.addEventListener("click", function(){

    var erroAjax = document.querySelector("#erro-ajax");
    var xhr = new XMLHttpRequest();

    xhr.open("GET", "https://api-pacientes.herokuapp.com/pacientes");
    xhr.addEventListener("load", function(){
    
        if(xhr.status == 200){
            erroAjax.classList.add("invisivel");
            var resposta = xhr.responseText;
            var pacientes = JSON.parse(resposta);

            pacientes.forEach(function(pacientes){
                adicionaPaciente(pacientes);
            }); 
        }else{
            console.log(xhr.status);
            console.log(xhr.responseText);
            erroAjax.classList.remove("invisivel");
        }

    });
    xhr.send();
});