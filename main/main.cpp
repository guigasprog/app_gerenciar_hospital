#include <iostream>
#include <conio.h>
#include <string.h>

using namespace std;

/**
* DEFINIÇÃO DAS ESTRUTURAS
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
    long cpf;
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
* DEFINIÇÃO DAS FUNÇÕES EX1
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

struct busca {
    bool achou;
    int pos;
};

busca buscaMedico (struct Medico medico[], int constMedico, int cod){
    int i = 0, f = constMedico;
    int media = (i + f) / 2;
    for (; f >= i && cod != medico[media].codigo; media = (i + f) / 2){
        if (cod > medico[media].codigo)
            i = media + 1;
        else
            f = media - 1;
    }
    if (cod == medico[media].codigo){
        return {true,media};
    }
    else return {false,media};
}

busca buscaEspecialidades (struct EspecialidadeMedica especialidade[], int constEspecialidade, int cod){
    int i = 0, f = constEspecialidade;
    int media = (i + f) / 2;
    for (; f >= i && cod != especialidade[media].codigo; media = (i + f) / 2){
        if (cod > especialidade[media].codigo)
            i = media + 1;
        else
            f = media - 1;
    }
    if (cod == especialidade[media].codigo){
        return {true,media};
    }
    else return {false,media};
}

busca buscaCidades (struct Cidade cidade[], int constCidade, int cod){
    int i = 0, f = constCidade;
    int media = (i + f) / 2;
    for (; f >= i && cod != cidade[media].codigo; media = (i + f) / 2){
        if (cod > cidade[media].codigo)
            i = media + 1;
        else
            f = media - 1;
    }
    if (cod == cidade[media].codigo){
        return {true,media};
    }
    else return {false,media};
}

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
                if(buscaMedico(medico, i, codigo).achou) {
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
            busca achou;
            do
            {
                int j = 0;
                cout << "Informe o id da especialidade: ";
                cin >> aux;
                achou = buscaEspecialidades(especialidade, constEspecialidade, aux);
                if(!achou.achou) {
                    system("cls");
                    cout << "Id informado nao encontrado!";
                } else {
                    medico[i].especialidadesMedicas = especialidade[achou.pos];
                    cout << "Especialidade selecionada: " << especialidade[achou.pos].descricao << endl;
                }
                getch();
                system("cls");
            } while(!achou.achou);
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
                achou = buscaCidades(cidade, constCidade, aux);
                if(!achou.achou) {
                    system("cls");
                    cout << "Id informado nao encontrado!";
                } else {
                    medico[i].cidade = cidade[achou.pos];
                    cout << "Cidade selecionada: " << cidade[achou.pos].nome << " " << cidade[achou.pos].uf << endl;
                }
                getch();
                system("cls");
            } while(!achou.achou);
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
                if(buscaMedico(medico, i, codigo).achou || buscaMedico(medicosExistente,constMedicoExistente,codigo).achou) {
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
            busca achou;
            do
            {
                int j = 0;
                cout << "Informe o id da especialidade: ";
                cin >> aux;
                achou = buscaEspecialidades(especialidade, constEspecialidade, aux);
                if(!achou.achou) {
                    system("cls");
                    cout << "Id informado nao encontrado!";
                } else {
                    medico[i].especialidadesMedicas = especialidade[achou.pos];
                    cout << "Especialidade selecionada: " << especialidade[achou.pos].descricao << endl;
                }
                getch();
                system("cls");
            } while(!achou.achou);
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
                achou = buscaCidades(cidade, constCidade, aux);
                if(!achou.achou) {
                    system("cls");
                    cout << "Id informado nao encontrado!";
                } else {
                    medico[i].cidade = cidade[achou.pos];
                    cout << "Cidade selecionada: " << cidade[achou.pos].nome << " " << cidade[achou.pos].uf << endl;
                }
                getch();
                system("cls");
            } while(!achou.achou);
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

/**
* DEFINICAO DAS FUNCOES EX3
*/

busca buscaPaciente (struct Paciente paciente[], int constPaciente, long cpf){
    int i = 0, f = constPaciente;
    int media = (i + f) / 2;
    for (; f >= i && cpf != paciente[media].cpf; media = (i + f) / 2){
        if (cpf > paciente[media].cpf)
            i = media + 1;
        else
            f = media - 1;
    }
    if (cpf == paciente[media].cpf){
        return {true,media};
    }
    else return {false,media};
}

void leituraPaciente (struct Paciente paciente[],
                    struct Cidade cidade[],
                    int maximo,
                    int &constPaciente,
                    int constCidade){
    if(constCidade > 0) {
        int i, aux;
        long cpf = 1;
        if(constPaciente < 0) i = constPaciente+1;
        else i = constPaciente;
        for(;i < maximo && cpf != 0;)
        {
            system("cls");
            cout << "Informe o cpf do Paciente: (Insira 0 para fechar)\n";
            cin.ignore();
            cin >> cpf;
            int j = 0;
            while(i > 0 && i != j) {
                if(buscaPaciente(paciente, i, cpf).achou) {
                    system("cls");
                    cout << "CPF ja inserido:\nInsira outro CPF (Insira 0 para fechar)\n";
                    cin.ignore();
                    cin >> cpf;
                    j=-1;
                }
                j++;
            }
            if(cpf != 0) {
                paciente[i].cpf = cpf;
                cout << "Informe o nome do Paciente: ";
                cin.ignore();
                getline( cin, paciente[i].nome );
                busca achou;
                cout << "Informe o endereco do Paciente: ";
                cin >> paciente[i].endereco;
                do
                {
                    int j = 0;
                    cout << "Informe o codigo da cidade: ";
                    cin >> aux;
                    achou = buscaCidades(cidade, constCidade, aux);
                    if(!achou.achou) {
                        system("cls");
                    cout << "Id informado nao encontrado!\n";
                } else {
                    paciente[i].cidade = cidade[achou.pos];
                    cout << "Cidade selecionada: " << cidade[achou.pos].nome << " " << cidade[achou.pos].uf << endl;
                }
                getch();
                system("cls");
            } while(!achou.achou);
            i++;
        }
        system("cls");
    }
    constPaciente = i;
    } else
    {
        system("cls");
        cout << "TABELA DE CIDADE VAZIA!\nINFORME PELO MENOS UMA CIDADE!\n";
        system("pause");
    }
    system("cls");
}

void leituraPaciente (struct Paciente paciente[],
                    struct Cidade cidade[],
                    int maximo,
                    int &constPaciente,
                    int constCidade,
                    struct Paciente pacienteExistente[],
                    int constPacienteExistente){
    if(constCidade > 0) {
        int i, aux;
        long cpf = 1;
        if(constPaciente < 0) i = constPaciente+1;
        else i = constPaciente;
        for(;i < maximo && cpf != 0;)
        {
            system("cls");
            cout << "Informe o cpf do Paciente: (Insira 0 para fechar)\n";
            cin.ignore();
            cin >> cpf;
            int j = 0;
            while(i > 0 && i != j || constPacienteExistente > j && cpf > 0) {
                if(buscaPaciente(paciente, i, cpf).achou
                   || buscaPaciente(pacienteExistente, constPacienteExistente, cpf).achou) {
                    system("cls");
                    cout << "CPF ja inserido:\nInsira outro CPF (Insira 0 para fechar)\n";
                    cin.ignore();
                    cin >> cpf;
                    j=-1;
                }
                j++;
            }
        if(cpf != 0) {
            paciente[i].cpf = cpf;
                cout << "Informe o nome do Paciente: ";
                cin.ignore();
                getline( cin, paciente[i].nome );
                busca achou;
                cout << "Informe o endereco do Paciente: ";
                cin >> paciente[i].endereco;
                do
                {
                    int j = 0;
                    cout << "Informe o codigo da cidade: ";
                    cin >> aux;
                    achou = buscaCidades(cidade, constCidade, aux);
                    if(!achou.achou) {
                        system("cls");
                    cout << "Id informado nao encontrado!\n";
                } else {
                    paciente[i].cidade = cidade[achou.pos];
                    cout << "Cidade selecionada: " << cidade[achou.pos].nome << " " << cidade[achou.pos].uf << endl;
                }
                getch();
                system("cls");
            } while(!achou.achou);
            i++;
        }
        system("cls");
    }
    constPaciente = i;
    } else
    {
        system("cls");
        cout << "TABELA DE CIDADE VAZIA!\nINFORME PELO MENOS UMA CIDADE!\n";
        system("pause");
    }
    system("cls");
}

void inclusaoNovosPacientes(struct Paciente paciente[],
                    struct Cidade cidade[],
                    int maximo,
                    int &constPaciente,
                    int constCidade){
    struct Paciente novosPacientes[maximo-constPaciente];
    int constNovosPacientes = -1;
    struct Paciente velhosPacientes[maximo];
    int constVelhosPacientes = constPaciente;
    for(int i = 0; i < constPaciente; i++)
    {
        velhosPacientes[i] = paciente[i];
    }
    leituraPaciente(novosPacientes, cidade, (maximo-constPaciente), constNovosPacientes, constCidade, paciente, constPaciente);
    int i = 0, j = 0, k = 0; // i (contador de S) j (contador de T) k (contador de A)
    for (;i < constPaciente && j < constNovosPacientes;k++){
        if (velhosPacientes[i].cpf < novosPacientes[j].cpf){
            paciente[k].cpf = velhosPacientes[i].cpf;
            paciente[k].nome = velhosPacientes[i].nome;
            paciente[k].endereco = velhosPacientes[i].endereco;
            paciente[k].cidade = velhosPacientes[i].cidade;
            i++;
            }
        else {
            paciente[k].cpf = novosPacientes[j].cpf;
            paciente[k].nome = novosPacientes[j].nome;
            paciente[k].endereco = novosPacientes[j].endereco;
            paciente[k].cidade = novosPacientes[j].cidade;
            j++;
        }
    }
    while (i < constVelhosPacientes){
        paciente[k].cpf = velhosPacientes[i].cpf;
        paciente[k].nome = velhosPacientes[i].nome;
        paciente[k].endereco = velhosPacientes[i].endereco;
        paciente[k].cidade = velhosPacientes[i].cidade;
        i++;
        k++;
    }
    while (j < constNovosPacientes){
        paciente[k].cpf = novosPacientes[j].cpf;
        paciente[k].nome = novosPacientes[j].nome;
        paciente[k].endereco = novosPacientes[j].endereco;
        paciente[k].cidade = novosPacientes[j].cidade;
        j++;
        k++;
    }
    constPaciente = k;
}

void exibirPacientes(struct Paciente paciente[], int constPaciente)
{

    if(constPaciente > 0) {
        cout << "\t\t\t\Paciente\t\n";
        cout << "CPF\t|\tNome\t|\tEndereco\t|\tCidade\n";
        for(int i = 0; i < constPaciente; i++)
        {
            cout << paciente[i].cpf << "\t|\t" << paciente[i].nome
            << "\t|\t" << paciente[i].endereco
            << "\t|\t" << paciente[i].cidade.nome << " " << paciente[i].cidade.uf << endl;
        }
    } else cout << "Tabela vazia";
    getch();

}

/**
* FIM DAS FUNCOES EX3
*/

/**
* DEFINICAO DAS FUNCOES EX4
*/

void exclusaoPacientes(struct Paciente pacientes[], int &constPaciente, int maximo)
{
    if(constPaciente > 0) {
        int cpf, cpfs[maximo], constCpfsExclusao, constPacienteExistente = constPaciente, i = 0;
        do
        {
            system("cls");
            cout << "Informe o cpf para exclusão: (0 para parar ou voltar) ";
            cin >> cpf;
            if(cpf != 0) {
                cpfs[i] = cpf;
                i++;
            }
        } while(cpf != 0 && i < maximo);
        constCpfsExclusao = i;
        if(constCpfsExclusao > 0) {
            struct Paciente pacienteExistentes[constPaciente];

            for(i = 0; i < constPaciente; i++)
            {
                pacienteExistentes[i] = pacientes[i];
            }
            i = 0;
            int j = 0, k = 0; // i (contador de Pacientes existente) j (contador de cpfs) k (contador de pacientes)
            for (;j < constCpfsExclusao && i < constPaciente; i++){
                if (pacienteExistentes[i].cpf != cpfs[j]){
                    pacientes[k].cpf = pacienteExistentes[i].cpf;
                    pacientes[k].nome = pacienteExistentes[i].nome;
                    pacientes[k].endereco = pacienteExistentes[i].endereco;
                    pacientes[k].cidade = pacienteExistentes[i].cidade;
                    k++;
                    }
                else {
                    j++;
                }
            }
            while (i < constPacienteExistente){
                pacientes[k].cpf = pacienteExistentes[i].cpf;
                pacientes[k].nome = pacienteExistentes[i].nome;
                pacientes[k].endereco = pacienteExistentes[i].endereco;
                pacientes[k].cidade = pacienteExistentes[i].cidade;
                i++;
                k++;
            }
            constPaciente = k;
        } else {
        cout << "NENHUM CPF INSERIDO PARA EXCLUSÃO";
        getch();
    }
    } else {
        cout << "NENHUM PACIENTE INSERIDO";
        getch();
    }
    system("cls");
}


int main()
{
    //DECLARANDO VARIAVEIS
    const int maximo = 30, maximoEspecialidade = 22;

    struct Cidade cidades[maximo];
    struct EspecialidadeMedica especialidades[maximoEspecialidade];
    struct CID cids[maximo];
    struct Medicamento medicamentos[maximo];

    int constCidade = -1, constEspecialidade = -1, constCID = -1, constMedicamento = -1;

    struct Medico medicos[maximo];

    int constMedico = -1;

    struct Paciente pacientes[maximo];

    int constPaciente = -1;

    //DECLARANDO AS FUNÇÕES
    int i, j;
    do
    {
        system("cls");
        cout << "Informe se deseja inserir ou exibir dados: \n(1 para Inserir, 2 para Exibir, 3 para Exclusao, 0 para fechar)\n";
        cin >> i;
        system("cls");

        if(i == 1) {
            do
            {
            cout << "Informe qual deseja inserir: \n(1 para Cidade, 2 para Especialidades, 3 para CID, 4 para Medicamentos, 5 para Medicos\ne 6 para Pacientes, 0 para voltar)\n";
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
            } else if(j == 6) {
                if(constPaciente == -1) leituraPaciente(pacientes, cidades,maximo,constPaciente,constCidade);
                else inclusaoNovosPacientes(pacientes,cidades,maximo,constPaciente,constCidade);
            } else if(j > 0) {
                cout << "Codigo informado nao existe!\n";
                system("pause");
                system("cls");
            }
            } while(j != 0);
        } else if(i == 3) {
            do
            {
            cout << "Informe qual deseja exclusao: \n(1 para Paciente, 0 para voltar)\n";
            cin >> j;
            system("cls");
            if(j == 1) {
                exclusaoPacientes(pacientes, constPaciente, maximo);
            }else if(j > 0) {
                cout << "Codigo informado nao existe!\n";
                system("pause");
                system("cls");
            }
            } while(j != 0);
        } else if(i == 2) {
            do
            {
            system("cls");
            cout << "Informe qual deseja exibir: \n(1 para Cidade, 2 para Especialidades, 3 para CID, 4 para Medicamentos, 5 para Medico\ne 6 para Pacientes, 0 para voltar)\n";
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
            } else if(j == 6) {
                exibirPacientes(pacientes,constPaciente);
            } else if(j > 0) {
                cout << "Codigo informado nao existe!";
                system("pause");
                system("cls");
            }
            } while (j != 0);
        } else if(i > 0) {
            cout << "Codigo informado nao existe!\n";
            system("pause");
        }
        system("cls");
    } while(i != 0);
}
