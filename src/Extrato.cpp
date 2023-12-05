#include "Extrato.hpp"

void Extrato::informarExtrato(){
    for(auto i=0; i<transacoes.size();++i){
        if(transacoes[i]<0){
            std::cout<<"TRANSFERENCIA: -R$";
            std::cout<<-1*transacoes[i]<<std::endl;
        }
        else{
            std::cout<<"DEPOSITO:";
            std::cout<<transacoes[i]<<std::endl;
        }
    }
}

void Extrato::adicionarTransacao(double valor){
    transacoes.push_back(valor);
}

void Extrato::exportarExtratoDigital(std::string cc){
    std::ofstream saida ("./extrato"+cc+".txt");
     for(auto i=0; i<transacoes.size();++i){
        if(transacoes[i]<0){
            saida<<"TRANFERENCIA: -R$";
            saida<<-1*transacoes[i]<<std::endl;
        }else{
            saida<<"DEPOSITO: R$";
            saida<<transacoes[i]<<std::endl;
        }

    }
    saida.close();

}
