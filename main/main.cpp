#include <iostream>
#include <conio.h>
#include <string.h>

using namespace std;

/**
* DEFINI플O DAS ESTRUTURAS
*/

struct Cidade
{
    long codigo;
    string nome;
    char uf[2];
};

struct EspecialidadeMedica
{
    long codigo;
    string descricao;
};

struct CID
{
    long codigo;
    string descricao;
};

struct Medico
{
    long codigo;
    string nome;
    EspecialidadeMedica especialidadesMedicas;
    string endereco;
    string telefone;
    Cidade cidade;
};

struct Paciente
{
    string cpf;
    string nome;
    string endereco;
    Cidade cidade;
};

struct Medicamento
{
    long codigo;
    string descricao;
    int quant_estoque;
    int estoque_minimo;
    int estoque_maximo;
    float preco_unidade;
};

struct DateTime
{
    int dia;
    int mes;
    int ano;
    int hora;
    int minuto;
};

struct Consulta
{
    Paciente paciente;
    Medico medico;
    DateTime dataHora;
    CID cid;
    Medicamento Medicamentos[10];
    int qtde_medicamento[10];
};

/**
* FIM DAS STRUCT
*/


/**
* DEFINI플O DAS FUN합ES EX1
*/

void inserirCidade(struct Cidade cidades[], int maximo, int &constCidade)
{

    int i, codigo = 1;
    if(constCidade < 0) i = constCidade+1;
    else i = constCidade;
    for(;i < maximo && codigo > 0;)
    {
        system("cls");
        cout << "Informe o codigo da Cidade: (Insira 0 para fechar)\n";
        cin >> codigo;
        if(codigo > 0) {
            cidades[i].codigo = codigo;
            cout << "Informe o nome da Cidade: ";
            cin.ignore();
            getline( cin, cidades[i].nome );
            cout << "Informe o UF da Cidade: ";
            cin >> cidades[i].uf;
            i++;
        }
        system("cls");
    }
    constCidade = i;
}

void exibirCidades(struct Cidade cidades[], int constCidade)
{
    if(constCidade > 0) {
        cout << "\t\tCIDADE\t\n";
        cout << "Codigo\t|\tNome\t|\tUF\n";
        for(int i = 0; i < constCidade; i++)
        {
            cout << cidades[i].codigo << "\t|\t" << cidades[i].nome << "\t|\t" << cidades[i].uf << endl;
        }
    } else cout << "Lista vazia";
    getch();

}

void inserirEspecialidades(struct EspecialidadeMedica especialidades[], int maximo, int &constEspecialidade)
{

    int i, codigo = 1;
    if(constEspecialidade < 0) i = constEspecialidade+1;
    else i = constEspecialidade;
    for(;i < maximo && codigo > 0;)
    {
        system("cls");
        cout << "Informe o codigo da Especialidade: (Insira 0 para fechar)\n";
        cin >> codigo;
        if(codigo > 0) {
            especialidades[i].codigo = codigo;
            cout << "Informe a descricao da Especialidade: ";
            cin.ignore();
            getline( cin, especialidades[i].descricao );
            i++;
        }
        system("cls");
    }
    constEspecialidade = i;

}

void exibirEspecialidades(struct EspecialidadeMedica especialidades[], int constEspecialidade)
{
    if(constEspecialidade > 0) {
        cout << "\tESPECIALIDADE\t\n";
        cout << "Codigo\t|\tDesc\n";
        for(int i = 0; i < constEspecialidade; i++)
        {
            cout << especialidades[i].codigo << "\t|\t" << especialidades[i].descricao << endl;
        }
    } else cout << "Lista vazia";
    getch();

}

void inserirCID(struct CID cids[], const int maximo, int &constCID)
{

    int i, codigo = 1;
    if(constCID < 0) i = constCID+1;
    else i = constCID;
    for(;i < maximo && codigo > 0;)
    {
        system("cls");
        cout << "Informe o codigo da CID: (Insira 0 para fechar)\n";
        cin >> codigo;
        if(codigo > 0) {
            cids[i].codigo = codigo;
            cout << "Informe a descricao da CID: ";
            cin.ignore();
            getline( cin, cids[i].descricao );
            i++;
        }
        system("cls");
    }
    constCID = i;

}

void exibirCID(struct CID cids[], int constCID)
{

    if(constCID > 0) {
        cout << "\tCID\t\n";
        cout << "Codigo\t|\tDesc\n";
        for(int i = 0; i < constCID; i++)
        {
            cout << cids[i].codigo << "\t|\t" << cids[i].descricao << endl;
        }
    } else cout << "Lista vazia";
    getch();

}

void inserirMedicamentos(struct Medicamento medicamentos[], const int maximo, int &constMedicamento)
{

    int i, codigo = 1;
    if(constMedicamento < 0) i = constMedicamento+1;
    else i = constMedicamento;
    for(;i < maximo && codigo > 0;)
    {
        system("cls");
        cout << "Informe o codigo da Medicamento: (Insira 0 para fechar)\n";
        cin >> codigo;
        if(codigo > 0) {
            medicamentos[i].codigo = codigo;
            cout << "Informe a descricao do Medicamento: ";
            cin.ignore();
            getline( cin, medicamentos[i].descricao );
            cout << "Informe a qtde no estoque: ";
            cin >> medicamentos[i].quant_estoque;
            cout << "Informe o minimo no estoque: ";
            cin >> medicamentos[i].estoque_minimo;
            cout << "Informe o maximo no estoque: ";
            cin >> medicamentos[i].estoque_maximo;
            cout << "Informe o preco da unidade: ";
            cin >> medicamentos[i].preco_unidade;
            i++;
        }
        system("cls");
    }
    constMedicamento = i;

}

void exibirMedicamentos(struct Medicamento medicamentos[], int constMedicamento)
{

    if(constMedicamento > 0) {
        cout << "\t\t\t\tMedicamento\t\n";
        cout << "Codigo\t|\tDesc\t|\tQtde\t|\tMin\t|\tMax\t|\tPreco\n";
        for(int i = 0; i < constMedicamento; i++)
        {
            cout << medicamentos[i].codigo << "\t|\t" << medicamentos[i].descricao
            << "\t|\t" << medicamentos[i].quant_estoque
            << "\t|\t" << medicamentos[i].estoque_minimo
            << "\t|\t" << medicamentos[i].estoque_maximo
            << "\t|\t" << medicamentos[i].preco_unidade << endl;
        }
    } else cout << "Lista vazia";
    getch();

}

/**
* FIM DAS FUNCOES EX1
*/

/**
* DEFINICAO DAS FUNCOES EX2
*/

void leituraMedico (struct Medico medico[],
                    struct EspecialidadeMedica especialidade[],
                    struct Cidade cidade[],
                    int maximo,
                    int &constMedico,
                    int constEspecialidade,
                    int constCidade){
    if(constEspecialidade > 0 && constCidade > 0) {
        int i, codigo = 1, aux;
        if(constMedico < 0) i = constMedico+1;
        else i = constMedico;
        for(;i < maximo && codigo > 0;)
        {
            system("cls");
            cout << "Informe o codigo da Medico: (Insira 0 para fechar)\n";
            cin >> codigo;
            int j = 0;
            while(i > 0 && i != j) {
                if(codigo == medico[j].codigo) {
                    system("cls");
                    cout << "Codigo ja inserido:\nInsira outro codigo (Insira 0 para fechar)\n";
                    cin >> codigo;
                    j=-1;
                }
                j++;
            }
        if(codigo > 0) {
            medico[i].codigo = codigo;
            cout << "Informe o nome do Medico: ";
            cin.ignore();
            getline( cin, medico[i].nome );
            bool achou;
            do
            {
                int j = 0;
                cout << "Informe o id da especialidade: ";
                cin >> aux;
                while(aux != especialidade[j].codigo && j < constEspecialidade) {
                    j++;
                }
                achou = (j < constEspecialidade);
                if(!achou) {
                    system("cls");
                    cout << "Id informado nao encontrado!";
                    getch();
                    system("cls");
                } else {
                    medico[i].especialidadesMedicas = especialidade[j];
                    cout << "Especialidade selecionada: " << especialidade[j].descricao << endl;
                    getch();
                }
            } while(!achou);
            cout << "Informe o endereco do Medico: ";
            cin.ignore();
            getline( cin, medico[i].endereco );
            cout << "Informe o telefone do Medico: ";
            getline( cin, medico[i].telefone );
            do
            {
                int j = 0;
                cout << "Informe o id da cidade: ";
                cin >> aux;
                while(aux != cidade[j].codigo && j < constCidade) {
                    j++;
                }
                achou = (j < constCidade);
                if(!achou) {
                    system("cls");
                    cout << "Id informado nao encontrado!";
                    getch();
                    system("cls");
                } else {
                    medico[i].cidade = cidade[j];
                    cout << "Cidade selecionada: " << cidade[j].nome << " " << cidade[j].uf << endl;
                    getch();
                }
            } while(!achou);
            i++;
        }
        system("cls");
    }
    constMedico = i;
    } else
    {
        system("cls");
        cout << "TABELA DE ESPECIALIDADES OU CIDADE VAZIA!\nINFORME PELO MENOS UM DADO EM CADA!";
        getch();
        system("cls");
    }
}

void leituraMedico (struct Medico medico[],
                    struct EspecialidadeMedica especialidade[],
                    struct Cidade cidade[],
                    int maximo,
                    int &constMedico,
                    int constEspecialidade,
                    int constCidade,
                    struct Medico medicosExistente[],
                    int constMedicoExistente){
    if(constEspecialidade > 0 && constCidade > 0) {
        int i, codigo = 1, aux;
        if(constMedico < 0) i = constMedico+1;
        else i = constMedico;
        for(;i < maximo && codigo > 0;)
        {
            system("cls");
            cout << "Informe o codigo da Medico: (Insira 0 para fechar)\n";
            cin >> codigo;
            int j = 0;
            while(i > 0 && i != j || constMedicoExistente > j && codigo > 0) {
                if(codigo == medico[j].codigo || codigo == medicosExistente[j].codigo) {
                    system("cls");
                    cout << "Codigo ja inserido:\nInsira outro codigo (Insira 0 para fechar)\n";
                    cin >> codigo;
                    j=-1;
                }
                j++;
            }
        if(codigo > 0) {
            medico[i].codigo = codigo;
            cout << "Informe o nome do Medico: ";
            cin.ignore();
            getline( cin, medico[i].nome );
            bool achou;
            do
            {
                int j = 0;
                cout << "Informe o id da especialidade: ";
                cin >> aux;
                while(aux != especialidade[j].codigo && j < constEspecialidade) {
                    j++;
                }
                achou = (j < constEspecialidade);
                if(!achou) {
                    system("cls");
                    cout << "Id informado nao encontrado!";
                    getch();
                    system("cls");
                } else {
                    medico[i].especialidadesMedicas = especialidade[j];
                    cout << "Especialidade selecionada: " << especialidade[j].descricao << endl;
                    getch();
                }
            } while(!achou);
            cout << "Informe o endereco do Medico: ";
            cin.ignore();
            getline( cin, medico[i].endereco );
            cout << "Informe o telefone do Medico: ";
            getline( cin, medico[i].telefone );
            do
            {
                int j = 0;
                cout << "Informe o id da cidade: ";
                cin >> aux;
                while(aux != cidade[j].codigo && j < constCidade) {
                    j++;
                }
                achou = (j < constCidade);
                if(!achou) {
                    system("cls");
                    cout << "Id informado nao encontrado!";
                    getch();
                    system("cls");
                } else {
                    medico[i].cidade = cidade[j];
                    cout << "Cidade selecionada: " << cidade[j].nome << " " << cidade[j].uf << endl;
                    getch();
                }
            } while(!achou);
            i++;
        }
        system("cls");
    }
    constMedico = i;
    } else
    {
        system("cls");
        cout << "TABELA DE ESPECIALIDADES OU CIDADE VAZIA!\nINFORME PELO MENOS UM DADO EM CADA!";
        getch();
        system("cls");
    }
}

void inclusaoNovosMedicos(struct Medico medico[],
                    struct EspecialidadeMedica especialidade[],
                    struct Cidade cidade[],
                    int maximo,
                    int &constMedico,
                    int constEspecialidade,
                    int constCidade){
    struct Medico novosMedicos[maximo-constMedico];
    int constNovosMedicos = -1;
    struct Medico velhosMedicos[maximo];
    int constVelhosMedicos = constMedico;
    for(int i = 0; i < constMedico; i++)
    {
        velhosMedicos[i] = medico[i];
    }
    leituraMedico(novosMedicos, especialidade, cidade, (maximo-constMedico), constNovosMedicos, constEspecialidade, constCidade, medico, constMedico);
    int i = 0, j = 0, k = 0; // i (contador de S) j (contador de T) k (contador de A)
    for (;i < constMedico && j < constNovosMedicos;k++){
        if (velhosMedicos[i].codigo < novosMedicos[j].codigo){
            medico[k].codigo = velhosMedicos[i].codigo;
            medico[k].nome = velhosMedicos[i].nome;
            medico[k].especialidadesMedicas = velhosMedicos[i].especialidadesMedicas;
            medico[k].endereco = velhosMedicos[i].endereco;
            medico[k].telefone = velhosMedicos[i].telefone;
            medico[k].cidade = velhosMedicos[i].cidade;
            i++;
            }
        else {
            medico[k].codigo = novosMedicos[j].codigo;
            medico[k].nome = novosMedicos[j].nome;
            medico[k].especialidadesMedicas = novosMedicos[j].especialidadesMedicas;
            medico[k].endereco = novosMedicos[j].endereco;
            medico[k].telefone = novosMedicos[j].telefone;
            medico[k].cidade = novosMedicos[j].cidade;
            j++;
        }
    }
    while (i < constVelhosMedicos){
        medico[k].codigo = velhosMedicos[i].codigo;
        medico[k].nome = velhosMedicos[i].nome;
        medico[k].especialidadesMedicas = velhosMedicos[i].especialidadesMedicas;
        medico[k].endereco = velhosMedicos[i].endereco;
        medico[k].telefone = velhosMedicos[i].telefone;
        medico[k].cidade = velhosMedicos[i].cidade;
        i++;
        k++;
    }
    while (j < constNovosMedicos){
        medico[k].codigo = novosMedicos[j].codigo;
        medico[k].nome = novosMedicos[j].nome;
        medico[k].especialidadesMedicas = novosMedicos[j].especialidadesMedicas;
        medico[k].endereco = novosMedicos[j].endereco;
        medico[k].telefone = novosMedicos[j].telefone;
        medico[k].cidade = novosMedicos[j].cidade;
        j++;
        k++;
    }
    constMedico = k;
}

void exibirMedicos(struct Medico medico[], int constMedico)
{

    if(constMedico > 0) {
        cout << "\t\t\t\Medico\t\n";
        cout << "Codigo\t|\tNome\t|\tEspecialidade\t|\tEndereco\t|\tTelefone\t|\tCidade\n";
        for(int i = 0; i < constMedico; i++)
        {
            cout << medico[i].codigo << "\t|\t" << medico[i].nome
            << "\t|\t" << medico[i].especialidadesMedicas.descricao
            << "\t|\t\t" << medico[i].endereco
            << "\t|\t" << medico[i].telefone
            << "\t|\t" << medico[i].cidade.nome << " " << medico[i].cidade.uf << endl;
        }
    } else cout << "Tabela vazia";
    getch();

}


/**
* FIM DAS FUNCOES EX2
*/

int main()
{
    //DECLARANDO VARIAVEIS
    const int maximo = 30, maximoEspecialidade = 22;

    struct Cidade cidades[maximo];
    struct EspecialidadeMedica especialidades[maximoEspecialidade];
    struct CID cids[maximo];
    struct Medicamento medicamentos[maximo];

    int constCidade = -1, constEspecialidade = -1, constCID = -1, constMedicamento = -1;

    struct Medico medicos[maximo], insercaoMedico[maximo];

    int constMedico = -1;

    //DECLARANDO AS FUN합ES]
    int i, j;
    do
    {
        cout << "Informe se deseja inserir ou exibir dados: \n(1 para Inserir, 2 para Exibir, 0 para fechar)\n";
        cin >> i;
        system("cls");
        if(i == 1) {
            cout << "Informe qual deseja inserir: \n(1 para Cidade, 2 para Especialidades, 3 para CID, 4 para Medicamentos e 5 para Medicos)\n";
            cin >> j;
            system("cls");
            if(j == 1) {
                inserirCidade(cidades, maximo, constCidade);
            } else if(j == 2) {
                inserirEspecialidades(especialidades, maximoEspecialidade, constEspecialidade);
            } else if(j == 3) {
                inserirCID(cids,maximo,constCID);
            } else if(j == 4) {
                inserirMedicamentos(medicamentos, maximo, constMedicamento);
            } else if(j == 5) {
                if(constMedico == -1) leituraMedico(medicos,especialidades,cidades,maximo,constMedico,constEspecialidade,constCidade);
                else inclusaoNovosMedicos(medicos,especialidades,cidades,maximo,constMedico,constEspecialidade,constCidade);
            } else {
                cout << "Codigo informado nao existe!";
                getch();
            }
        } else if(i == 2) {
            cout << "Informe qual deseja exibir: \n(1 para Cidade, 2 para Especialidades, 3 para CID, 4 para Medicamentos e 5 para Medico)\n";
            cin >> j;
            system("cls");
            if(j == 1) {
                exibirCidades(cidades, constCidade);
            } else if(j == 2) {
                exibirEspecialidades(especialidades, constEspecialidade);
            } else if(j == 3) {
                exibirCID(cids,constCID);
            } else if(j == 4) {
                exibirMedicamentos(medicamentos, constMedicamento);
            } else if(j == 5) {
                exibirMedicos(medicos, constMedico);
            } else {
                cout << "Codigo informado nao existe!";
                getch();
            }
        } else if(i > 0) {
            cout << "Codigo informado nao existe!";
            getch();
        }
        system("cls");
    } while(i != 0);
}
